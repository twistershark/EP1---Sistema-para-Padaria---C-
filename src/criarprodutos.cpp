#include "criarprodutos.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

CriarProdutos::CriarProdutos(){
	
	string nome_in;
	float preco_in;
	int quantidade_in;
	int escolha = 0;

	system("clear");

	cout << "\t*** MODO CRIAÇÃO DE PRODUTOS ***\n" << endl;
	
	vector<string> cat_produto = CriarCategorias();

	cout << "\n\nInsira o nome do produto\n";
	
	cout << "Nome: ";
	getline(cin >> ws, nome_in);
	
	cout << "Preço: R$ ";
	cin >> preco_in;
	
	cout << "Quantidade: ";
	cin >> quantidade_in;
	
	cout << "\n\n";

	Produtos produto;
	produto.Criar_Produtos(cat_produto, nome_in, preco_in, quantidade_in);

	system("clear");
	
	cout << "Produto adicionado ao estoque com sucesso!\n";
	
	cout << "Deseja adicionar outro produto? (1) Sim / (2) Não:" << endl;
	
	cin >> escolha;
	if (escolha == 1){
		CriarProdutos();
	}
	else if(escolha == 2){

	}
}


CriarProdutos::~CriarProdutos(){
	// Destrutor da classe CriarProdutos
}



vector<string> CriarProdutos::CriarCategorias(){
	
	// ABRIR ARQUIVO COM NOME DAS CATEGORIAS JÁ CRIADAS 
	vector<string> cat_criar;
	vector<string> cat_produto;
	vector<string> categorias;
	

	string nome_cat;
	fstream cat;
	cat.open("./db/etc/categorias.txt");
	if(cat.is_open()){
		while(cat >> nome_cat){
			categorias.push_back(nome_cat);
		}
	}
	
	// LISTANDO CATEGORIAS PARA O USUÁRIO

	cout << "\n*** Lista de Categorias já criadas ***\n";
	
	for(unsigned int i = 0; i < categorias.size(); i++){
		cout << "-> " << categorias[i] << endl << endl;
	}

	
	
	// CRIANDO OU REUTILIZANDO CATEGORIA JÁ CRIADA

	cout << "Para você utilizar alguma categoria já criada ou criar uma nova, basta escrever o nome da categoria (NÃO USE ESPAÇOS): ";

	string entrada = "1";

	getline(cin >> ws, entrada);

	while(entrada != "0"){
		
		// transformando entrada para uppercase
		for(unsigned int l = 0; l < entrada.length(); l++){
			entrada[l] = toupper(entrada[l]);	
		}
        
    	// fim da transformação

		unsigned int verificador = 0;

		for (unsigned int k = 0; k < categorias.size(); k++){

			if(entrada == categorias[k]){
				cat_produto.push_back(entrada);
			}else if(entrada != categorias[k]){
				verificador += 1;
			}
		
		}

		if(verificador == categorias.size()){
			cat_criar.push_back(entrada);
		}
	
	cout << "Caso deseje usar mais de uma categoria no mesmo produto, digite o nome da próxima categoria. Caso contrário, digite zero: " << endl;
	getline(cin >> ws, entrada);
	
	}

	// CRIANDO PASTAS DAS NOVAS CATEGORIAS

	CriarPastas(cat_criar);

	return cat_produto;
	
	//
}


void CriarProdutos::CriarPastas(vector<string>& categorias_new){

	for (unsigned int i = 0; i < categorias_new.size(); i++){
		string path = "mkdir teste";
		//path += tostring(categorias_new[i]);
		system(("mkdir ./db/produtos/" + categorias_new[i]).c_str());
	}

}