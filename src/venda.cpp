#include "venda.hpp"
#include "vectorprodutos.hpp"
#include <iostream>
#include <vector>

using namespace std;


Venda::Venda(){
	system("clear");

	cout << "==================================================" << endl;
	cout << "\n \n";
	cout << "\t \t  MODO VENDA \t \t \t \t";
	cout << "\n \n";
	cout << "==================================================" << endl;
	cout << "\n \n \n ";

	VectorProdutos vector;

	vector.mostraProdutos();

}

Venda::~Venda(){
	// Destrutor da Classe Venda
}
