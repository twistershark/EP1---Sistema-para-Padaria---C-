#include "menu.hpp"
#include "verificador.hpp"
#include "escolha.hpp"
#include <iostream>
#include <string>


using namespace std;

Menu::Menu(){

	// Declaração de variáveis para o Menu
	int valor = 0;
	// Fim da declaração de variáveis para o Menu


		system("clear");
		cout << "=======================================================================" << endl;
		cout << "\n \n";
		cout << "\t \t \t  SISTEMA DA PADARIA \t \t \t \t";
		cout << "\n \n";
		cout << "=======================================================================" << endl;
		cout << "\n \n \n \n \n";
		cout << "\tMenu de opções: (digite o número correspondente a sua escolha)\n \n";
		cout << "\t \t (1) - Modo Venda\n";
		cout << "\t \t (2) - Modo Estoque\n";
		cout << "\t \t (3) - Modo Recomendação\n";
		cout << "\t \t (0) - Sair\n";
		cout << "\t \t Sua Escolha: ";
		cin >> valor;
		cout << "\n \n \n \n";

		Escolha escolha(valor);
 
}

Menu::~Menu(){
	// Destrutor
}