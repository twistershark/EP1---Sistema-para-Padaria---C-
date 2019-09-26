#include "venda.hpp"
#include "carrinho.hpp"
#include "vectorprodutos.hpp"
#include <iostream>
#include <vector>

using namespace std;



Venda::Venda(Cliente * cliente){
	system("clear");



	cout << cliente->get_nome() << endl;


	cout << "==================================================" << endl;
	cout << "\n \n";
	cout << "\t \t  MODO VENDA \t \t \t \t";
	cout << "\n \n";
	cout << "==================================================" << endl;
	cout << "\n \n \n ";

	VectorProdutos vector;

	vector.mostraProdutos();
	
	Carrinho carrinho;
	carrinho.add_produto();
}

Venda::~Venda(){
	// Destrutor da Classe Venda
}

