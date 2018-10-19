#pragma once
#include <iostream>
#include <vector>

void trataInput();
using namespace std;

class Subset{
private:
	int weight;
	int currentSize;
	vector<int> elementos;

public:
	//Construtores
	Subset();
	Subset(int, int);

	//Métodos acessores

	void setWeight(int);
	int getWeight();
	void setCurrentSize(int);
	int getCurrentSize();
	void setElementos(vector<int>);
	vector<int> getElementos();

	// Métodos necessários
	void decrementSize();
	void adicionaElemento(int);
	int returnElement(int);
	int returnElementSize();
};
