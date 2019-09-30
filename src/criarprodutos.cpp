#include "criarprodutos.hpp"
#include "produtos.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

//TEMPLATE

template <typename T1>

T1 getInput(){
    while(true){
    T1 valor;
    cin >> valor;
    if(cin.fail()){
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "Entrada inválida! Insira novamente: " << endl;
    }
    else{
        cin.ignore(32767,'\n');
        return valor;
    }
    }
}
//FIM DO TEMPLATE



CriarProdutos::CriarProdutos(){
	

	system("clear");

	cout << "\t*** MODO CRIAÇÃO DE PRODUTOS ***\n" << endl;
	
	string cat_produto = CriarCategorias();

	cout << "\n\nInsira o nome do produto\n";
	
	cout << "Nome: ";
	string nome_in;
	getline(cin >> ws, nome_in);
	
	cout << "Preço: R$ ";
	float preco_in = getInput<float>();
	
	cout << "Quantidade: ";
	int quantidade_in = getInput<int>();
	
	cout << "\n\n";

	Produtos produto;
	produto.Criar_Produtos(cat_produto, nome_in, preco_in, quantidade_in);

	//system("clear");
	
	cout << "Produto adicionado ao estoque com sucesso!\n";
	
	cout << "Deseja adicionar outro produto? (1) Sim / (2) Não:" << endl;
	
	int escolha = getInput<int>();
	if (escolha == 1){
		CriarProdutos();
	}
	else if(escolha == 2){

	}
	else {
		do{
			cout << "\nEntrada inválida! Insira o número 1 ou 2: ";
			escolha = getInput<int>();
		}while(escolha < 1 || escolha > 2);
	}
}


CriarProdutos::~CriarProdutos(){
	// Destrutor da classe CriarProdutos
}



string CriarProdutos::CriarCategorias(){
	
	// ABRIR ARQUIVO COM NOME DAS CATEGORIAS JÁ CRIADAS 
	vector<string> categorias;
	
	 // ***** CORRIGIR DEPOIS DE IMPLEMENTAR
	string nome_cat;
	fstream cat;
	cat.open("./db/etc/categorias.txt");
	if(cat.is_open()){
		while(cat >> nome_cat){
			categorias.push_back(nome_cat);
		}
		cat.close();
	}
	
	// LISTANDO CATEGORIAS PARA O USUÁRIO

	cout << "\n*** Lista de Categorias já criadas ***\n";
	
	for(unsigned int i = 0; i < categorias.size(); i++){
		cout << "-> " << categorias[i] << endl << endl;
	}

	
	
	
	// CRIANDO OU REUTILIZANDO CATEGORIA JÁ CRIADA

	cout << endl;
	cout << "Escreva o nome da categoria que deseja utilizar ou criar." << endl;
	cout << "Caso seja mais de uma categoria, separe as categorias com um ESPAÇO." << endl;
	cout << "Categorias: ";

	string entrada;
	getline(cin >> ws, entrada);

	vector<string> catIndividual;
	vector<int> verific;

	// transformando entrada para uppercase
	for(unsigned int l = 0; l < entrada.length(); l++){
		entrada[l] = toupper(entrada[l]);	
	}

	istringstream iss(entrada);
	for(string entrada; iss >> entrada;){
		catIndividual.push_back(entrada);
	}

	for(unsigned int wq = 0; wq < catIndividual.size(); wq++){
		verific.push_back(count(categorias.begin(), categorias.end(), catIndividual[wq]));
		if(verific[wq] == 0){
			categorias.push_back(catIndividual[wq]);
		}
	}

	//Salvando no arquivo
	cat.open("./db/etc/categorias.txt");
	if(cat.is_open()){
		for(unsigned int pv = 0; pv < categorias.size(); pv++){
			cat << categorias[pv] << endl;
		}
		cat.close();
	}

	return entrada;
}
