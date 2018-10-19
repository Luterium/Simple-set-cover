#include <iostream>
#include <fstream>
#include <vector>
#include "subconjunto.h"

using namespace std;


int returnIndiceMin(Subset Subsets[], int m, float& totalWeight){
    float currentWeight = Subsets[0].getWeight()/Subsets[0].getCurrentSize();
    int currentWeightIndex = 0;
    for (int i = 1; i < m; i++){
        if (currentWeight > Subsets[i].getWeight()/Subsets[i].getCurrentSize()){
            currentWeightIndex = i;
            currentWeight = Subsets[i].getWeight()/Subsets[i].getCurrentSize();
        }
    }
    totalWeight += Subsets[currentWeightIndex].getWeight();
    Subsets[currentWeightIndex].setWeight(1000);
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

void workMatrix(vector<vector <bool> >& matrizElementos,vector<bool>& elementosCobertos, Subset Subsets[], int m, int n, int indiceMin){
    for(int i = 0; i < n; i++){
        if (matrizElementos[indiceMin][i] == true){
            workColumn(matrizElementos, Subsets, m, i);
            elementosCobertos.pop_back();
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
    vector <bool> elementosCobertos(n, false);

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

    while(elementosCobertos.size())
    workMatrix(matrizElementos, elementosCobertos, Subsets, m, n, returnIndiceMin(Subsets, m, totalWeight));

    cout << "Total cover cost: " << totalWeight << endl << endl;

    for(int i = 0; i < m; i++){
        matrizElementos[i].clear();
    }
    matrizElementos.clear();
}
