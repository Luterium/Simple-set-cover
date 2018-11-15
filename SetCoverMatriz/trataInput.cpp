#include <iostream>
#include <fstream>
#include <vector>
#include "subconjunto.h"

using namespace std;


int returnIndiceMin(Subset Subsets[], int m, float& totalWeight, vector <int>& subconjuntosEscolhidos){
    float currentWeight = Subsets[0].getWeight()/Subsets[0].getCurrentSize();
    int currentWeightIndex = 0;
    int currentWeightSize = 0;
    for (int i = 1; i < m; i++){
        if (currentWeight > Subsets[i].getWeight()/Subsets[i].getCurrentSize()){
            currentWeightIndex = i;
            currentWeight = Subsets[i].getWeight()/Subsets[i].getCurrentSize();
            currentWeightSize = Subsets[i].getCurrentSize();
        }
        else if(currentWeight == Subsets[i].getWeight()/Subsets[i].getCurrentSize() && currentWeightSize < Subsets[i].getCurrentSize())
        {
            currentWeightIndex = i;
            currentWeight = Subsets[i].getWeight()/Subsets[i].getCurrentSize();
            currentWeightSize = Subsets[i].getCurrentSize();
        }
    }
    totalWeight += Subsets[currentWeightIndex].getWeight();
    subconjuntosEscolhidos.push_back(currentWeightIndex);
    return currentWeightIndex;
}

void workColumn(vector<vector <bool> >& matrizElementos, Subset Subsets[], int m, int index){
    for(int i = 0; i < m; i++){
        if(matrizElementos[i][index] == true){
            Subsets[i].decrementSize();
            matrizElementos[i][index] = false;
        }
    }
}

void workMatrix(vector<vector <bool> >& matrizElementos,int& elementosDescobertos, Subset Subsets[], int m, int n, int indiceMin){
    for(int i = 0; i < n; i++){
        if (matrizElementos[indiceMin][i] == true){
            workColumn(matrizElementos, Subsets, m, i);
            elementosDescobertos--;
        }
    }
}



void trataInput(){
    int n, m, auxWeight, auxQtdElementos, auxElemento;
    float totalWeight = 0;
    ifstream inputSCP;
    inputSCP.open("scp.txt");
    inputSCP >> n >> m;
    Subset Subsets[m];
    vector < vector<bool> > matrizElementos(m,vector<bool>(n,false));
    int elementosDescobertos = n;
    vector <int> subconjuntosEscolhidos;

    for(int i = 0; i < m; i++){
        inputSCP >> auxWeight;
        Subsets[i].setWeight(auxWeight);
    }

    for (int i = 0; i < n; i++){
        inputSCP >> auxQtdElementos;
        for(int j = 0; j < auxQtdElementos; j++){
            inputSCP >> auxElemento;
            Subsets[auxElemento-1].incrementSize();
            matrizElementos[auxElemento-1][i] = true;
        }
    }
    while(elementosDescobertos)
    workMatrix(matrizElementos, elementosDescobertos, Subsets, m, n, returnIndiceMin(Subsets, m, totalWeight, subconjuntosEscolhidos));

    cout << "Total cover cost: " << totalWeight << endl << endl;
    cout << "Subconjuntos escolhidos: ";
    for(unsigned int i = 0; i < subconjuntosEscolhidos.size(); i++){
        cout << subconjuntosEscolhidos[i]+1 << " ";
    }

    for(int i = 0; i < m; i++){
        matrizElementos[i].clear();
    }
    matrizElementos.clear();
    inputSCP.close();
}
