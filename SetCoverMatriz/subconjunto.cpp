#include "subconjunto.h"

using namespace std;

Subset::Subset(){}

Subset::Subset(int weight, int size){
	this->weight = weight;
	currentSize = size;
}

void Subset::setWeight(int weight){
	this->weight = weight;
}

int Subset::getWeight(){
	return weight;
}

void Subset::setCurrentSize(int size){
	currentSize = size;
}

int Subset::getCurrentSize(){
	return currentSize;
}

void Subset::setElementos(vector <int> ele){
    for(int i = 0; i < ele.size(); i++)
        elementos[i] = ele[i];
}

vector<int> Subset::getElementos(){
    return elementos;
}

void Subset::decrementSize(){
    currentSize--;
}

void Subset::adicionaElemento(int elemento){
    elementos.push_back(elemento);
}

int Subset::returnElement(int i){
    return elementos[i];
}

int Subset::returnElementSize(){
    return elementos.size();
}
