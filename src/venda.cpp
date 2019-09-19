#include "venda.hpp"
#include <iostream>

using namespace std;


Venda::Venda(){
	system("clear");

	int escolha = 0;

	cout << "=======================================================================" << endl;
	cout << "\n \n";
	cout << "\t \t \t  MODO VENDA \t \t \t \t";
	cout << "\n \n";
	cout << "=======================================================================" << endl;
	cout << "\n \n \n \n \n";
	cout << "\tCategorias de produtos: (digite o número correspondente a sua escolha)\n \n";
	cout << "\t \t (1) - Salgados\n";
	cout << "\t \t (2) - Doces\n";
	cout << "\t \t (3) - Bebidas\n";
	cout << "\t \t Sua Escolha: ";
	cin >> escolha;
	cout << "\n \n \n \n";

	switch (escolha){
		case 1:
			venda_salgados();
		break;
		case 2:
			venda_doces();
		break;
		case 3:
			venda_bebidas();
		break;
	}

}

Venda::~Venda(){
	// Destrutor da Classe Venda
}

void Venda::venda_salgados(){

	system("clear");

	cout << "=======================================================================" << endl;
	cout << "\n \n";
	cout << "\t \t \t  CATEGORIA SALGADOS \t \t \t \t";
	cout << "\n \n";
	cout << "=======================================================================" << endl;
	cout << "\n \n \n \n \n";

}

void Venda::venda_doces(){

}

void Venda::venda_bebidas(){

}