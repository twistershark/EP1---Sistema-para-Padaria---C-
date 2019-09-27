#include "criarprodutos.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

CriarProdutos::CriarProdutos(){
	string nome_in;
	float preco_in;
	int quantidade_in;
	string categoria_in;
	int escolha = 0;
	cout << "Insira o nome da categoria, nome do produto,\npreço e quantidade para ser inserido no estoque." << endl;
	cout << "Digite o nome da categoria do produto: ";
	getline(cin >> ws, categoria_in);
	cout << "Nome: ";
	getline(cin >> ws, nome_in);
	cout << "Preço: R$ ";
	cin >> preco_in;
	cout << "Quantidade: ";
	cin >> quantidade_in;
	cout << "\n\n";

	Produtos produto;
	produto.Criar_Produtos(categoria_in, nome_in, preco_in, quantidade_in);

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