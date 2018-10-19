#include <iostream>
#include <fstream>
#include <vector>
#include "subconjunto.h"

using namespace std;

void iniciaMatriz(vector <vector <bool> >& Matriz){
    for(int i = 0; i < Matriz.size(); i++){
        for (int j = 0; j < Matriz[i].size(); j++){
            Matriz[i][j] = false;
        }
    }
}

int returnIndiceMin(Subset Subsets[], int m){
    float currentWeight = Subsets[0].getWeight()/Subsets[0].getCurrentSize();
    int currentWeightIndex = 0;
    for (int i = 1; i < m; i++){
        cout << "travei" << endl;
        if (currentWeight > Subsets[i].getWeight()/Subsets[i].getCurrentSize()){
            currentWeightIndex = i;
            currentWeight = Subsets[i].getWeight()/Subsets[i].getCurrentSize();
        }
    }
    //Subsets[currentWeightIndex].setWeight(1000);
    cout << currentWeightIndex << endl;
    return currentWeightIndex;
}

void trataInput(){
    int n, m, auxWeight, auxQtdElementos, auxElemento;
    ifstream inputSCP;
    inputSCP.open("scp.txt");
    inputSCP >> n >> m;
    cout << n << "  " << m << endl << endl;
    Subset Subsets[m];
    vector < vector<bool> > matrizElementos;

    matrizElementos.resize(m);
    for(int i = 0; i < n; i++){
        matrizElementos[i].resize(n);
    }
    iniciaMatriz(matrizElementos);

    for(int i = 0; i < m; i++){
        inputSCP >> auxWeight;
        Subsets[i].setWeight(auxWeight);
    }
    for (int i = 0; i < n; i++){
        inputSCP >> auxQtdElementos;
        for(int j = 0; j < auxQtdElementos; j++){
            inputSCP >> auxElemento;
            matrizElementos[auxElemento-1][i] = true;
        }
    }
    cout << "Printy boi 0" << endl;
    //int teste = returnIndiceMin(Subsets, m);
    //cout << teste << endl;
    //cout << Subsets[teste].getWeight();
    cout << "Printy boi 1" << endl;
}
