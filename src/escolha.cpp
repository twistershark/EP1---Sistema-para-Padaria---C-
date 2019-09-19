#include "escolha.hpp"
#include "verificador.hpp"
#include <string>
#include <iostream>

using namespace std;

Escolha::Escolha(){
	cout << "Criado objeto da classe Escolha" << endl;
}

Escolha::Escolha(int escolha){
	if (escolha == 1){
		string temp_cpf;

		cout << "Digite o CPF do cliente: ";
		cin >> temp_cpf;
		Verificador verify(temp_cpf);
	}
}

Escolha::~Escolha(){
	cout << "Destruído objeto da classe Escolha" <<  endl;
}