#include "recomendacao.hpp"
#include "produtos.hpp"
#include "venda.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

Recomendacao::Recomendacao(){


	string cpf;
	cout << "Digite o CPF do cliente (somente números): ";
	cin >> cpf;

	string end_cliente = "./db/clientes/" + cpf + ".txt";

	ifstream arq_cliente;
	arq_cliente.open(end_cliente);
	if (arq_cliente.is_open()){
				
		char temp_socio;
		string temp_nome;
		string temp_cpf;
		string texto;
				
		for(int linha = 1; getline(arq_cliente, texto) && linha <=3; linha++){
			if(linha == 1) temp_socio = texto[0];
			if(linha == 2) temp_nome = texto;
			if(linha == 3) temp_cpf = texto;
		}

		
	Cliente* cliente = new Cliente(temp_socio, temp_nome, temp_cpf);


	string nomeCategoria;
	string caminhoCompras = "./db/compras/" + cpf + ".txt";


	vector<string> categoriasEntrada;
	fstream arquivoCompras;
	string verification;
	arquivoCompras.open(caminhoCompras);
	if(arquivoCompras.is_open()){					
		while(arquivoCompras >> nomeCategoria){
			categoriasEntrada.push_back(nomeCategoria);
		}
	}

	// Carregando vector com categorias existentes
	vector<string> categoriasExistentes;
	fstream arquivoCategorias;
	arquivoCategorias.open("./db/etc/categorias.txt");
	if(arquivoCategorias.is_open()){
		string gettingCategorias;
		while(arquivoCategorias >> gettingCategorias){
			categoriasExistentes.push_back(gettingCategorias);	
		}
	}
	// Verificando categoria com mais compra

	vector<int> contadorCompras;
	vector<int> copiaContadorCompras;
	for (unsigned int lp = 0; lp < categoriasExistentes.size(); lp++){
		contadorCompras.push_back(count(categoriasEntrada.begin(), categoriasEntrada.end(),
		 categoriasExistentes[lp]));
		copiaContadorCompras.push_back(count(categoriasEntrada.begin(), categoriasEntrada.end(),
		 categoriasExistentes[lp]));
	}


	//Ordenando vector do maior para o menor


	sort(contadorCompras.rbegin(), contadorCompras.rend());

	vector<string> recomendados;

	for (unsigned int lpp = 0; lpp < categoriasExistentes.size(); lpp++){
		for (unsigned int ppl = 0; ppl < categoriasExistentes.size(); ppl++){
			if(contadorCompras[lpp] == copiaContadorCompras[ppl]){
				recomendados.push_back(categoriasExistentes[ppl]);
			}
		}
	}

	Venda venda(cliente, recomendados);
	}
}