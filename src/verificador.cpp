#include "verificador.hpp"
#include "cliente.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Verificador::Verificador(string entrada_cpf){
	string cpf = entrada_cpf;
	cpf.append(".txt");
	string endereco = ".//db//clientes//";
	endereco.append(cpf);

	fstream arquivo_cliente;
	arquivo_cliente.open(endereco);
	if (arquivo_cliente.is_open()){
		
	}
	else{
		system("clear");
		string temp_nome;
		cout << "============================================================" << endl;
		cout << "\t\t\tCadastro de novo Usuário\t\t\t" << endl;
		cout << "============================================================" << endl;
		cout << "Digite o nome do novo cliente: ";
		cin >> temp_nome;
		Cliente cliente(temp_nome, entrada_cpf);
		
	}
}