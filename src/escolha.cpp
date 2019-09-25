#include "escolha.hpp"
#include "verificador.hpp"
#include "criarprodutos.hpp"
#include <string>
#include <iostream>
#include "venda.hpp"
using namespace std;

Escolha::Escolha(){
	// construtor
}

Escolha::Escolha(int escolha){
	if (escolha == 1){
		string temp_cpf;

		cout << "Digite o CPF do cliente: ";
		cin >> temp_cpf;
		Verificador verify(temp_cpf);
	}
	else if (escolha == 2){
		system("clear");
		int esc = 0;
		cout << "Digite o número associado a sua escolha" << endl;
		cout << "(1) Adicionar novo produto\n(2) Editar estoque de produto existente" << endl;
		cin >> esc;
		if(esc == 1){
			CriarProdutos novo;
		}
		else if (esc == 2){
			// editar estoque
		}
	}
}


Escolha::~Escolha(){
	// destrutor
}