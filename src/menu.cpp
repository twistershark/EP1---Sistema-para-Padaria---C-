#include "menu.hpp"
#include "verificador.hpp"
#include <iostream>


using namespace std;

Menu::Menu(){

	int escolha = -1;
	while(escolha != 0){

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
		cin >> escolha;
		cout << "\n \n \n \n";

		switch (escolha){
			case 1:
				long int temp_cpf;
				cout << "Digite o CPF do cliente: ";
				cin >> temp_cpf;
				Verificador cliente(temp_cpf);
			break;
			case 2:
				// iniciar modo estoque
			break;
			case 3:
				// inicar modo recomendação 
			break;
			default:
				cout << "Escolha inválida!";
		}



	} 



};

Menu::~Menu(){
	cout << "\nFIM\n";
}