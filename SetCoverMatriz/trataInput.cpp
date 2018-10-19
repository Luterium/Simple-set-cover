#include <iostream>
#include <fstream>
#include "subconjunto.h"

using namespace std;

void trataInput(){
    int n, m, auxWeight;
    ifstream inputSCP;
    inputSCP.open("scp.txt");
    inputSCP >> n >> m;
    cout << n << "  " << m << endl << endl;
    Subset Subsets[m];
    for(int i = 0; i < m; i++){
        inputSCP >> auxWeight;
        Subsets[i].setWeight(auxWeight);
    }
    int k = 0;
    for(int i = 0; i < m; i++){
        cout << Subsets[i].getWeight() << " ";
        k++;
        if(k==12){
            k = 0;
            cout << endl;
        }
    }
    inputSCP.close();
}
