#include "venda.hpp"
#include "verificador.hpp"
#include "cliente.hpp"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Verificador::Verificador(string entrada_cpf){
	
	string cpf = entrada_cpf;
	cpf += ".txt";
	string endereco = ".//db//clientes//";
	endereco += cpf;

	fstream arquivo_cliente;
	arquivo_cliente.open(endereco);
	if (arquivo_cliente.is_open()){
		char socio;
		string nome;
		string cpf;
		string texto;
		char e = 'p';
		
		for(int linha = 1; getline(arquivo_cliente, texto) && linha <=3; linha++){
			if(linha == 1) socio = texto[0];
			if(linha == 2) nome = texto;
			if(linha == 3) cpf = texto;
		}

		if (socio == 'S'){
			cout << "Dados carregados com sucesso! Esse cliente é sócio!" << endl;
			Cliente cliente(socio, nome, cpf);
			cout << "Pressione ENTER para continuar..." << endl;
			getchar(); getchar();
			Venda venda;
		}
		else if(socio == 'N'){
			cout << "Dados carregados com sucesso! Esse cliente não é sócio" << endl;
			cout << "Cliente deseja se tornar sócio agora? (S/n): ";
			cin >> e;
			if(toupper(e) == 'S'){
				socio = 'S';
			} else if (toupper(e) == 'N'){
				socio = 'N';
			}
			Cliente cliente(socio, nome, cpf);
			Venda venda;
		}
	}

	// CADASTRO DE NOVOS USUÁRIOS CASO O CLIENTE AINDA NÃO ESTEJA CADASTRADO

	else{
		system("clear");
		string temp_nome;
		char e = 'k';
		char temp_socio;
		cout << "============================================================" << endl;
		cout << "\t\t\tCadastro de novo Usuário\t\t\t" << endl;
		cout << "============================================================" << endl;
		cout << "Digite o nome do novo cliente: ";
		getline(cin >> ws, temp_nome);
		cout << "Esse Cliente deseja se tornar sócio? (S/n): ";
  		cin >> e;
  			if (toupper(e) == 'S'){
  				temp_socio = 'S';
  			} else if(toupper(e) == 'N'){
  				temp_socio = 'N';
  			}


		Cliente cliente(temp_socio, temp_nome, entrada_cpf);
		Venda venda;
	}


}
