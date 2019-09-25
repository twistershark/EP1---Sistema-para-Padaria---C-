#include "criarprodutos.hpp"
#include "menu.hpp"


#include <fstream>
#include <iostream>
#include <string>

using namespace std;

CriarProdutos::CriarProdutos(){
	string nome_in;
	float preco_in;
	int quantidade_in;
	int categoria_in;
	int escolha = 0;
	cout << "Insira a categoria, nome do produto,\npreço e quantidade para ser inserido no estoque." << endl;
	cout << "(1) Salgados \t (2) Bebidas \t (3) Doces" << endl;
	cout << "Digite o número associado a categoria do produto: ";
	cin >> categoria_in;
	cout << "Nome: ";
	getline(cin >> ws, nome_in);
	cout << "Preço: R$ ";
	cin >> preco_in;
	cout << "Quantidade: ";
	cin >> quantidade_in;
	cout << "\n\n";

	Produtos produto(categoria_in, nome_in, preco_in, quantidade_in);

	system("clear");
	cout << "Produto adicionado ao estoque com sucesso!\n";
	cout << "Deseja adicionar outro produto? (1) Sim / (2) Não:" << endl;
	cin >> escolha;
	if (escolha == 1){
		CriarProdutos();
	}
	else if(escolha == 2){
		Menu(); 
	}
}
CriarProdutos::~CriarProdutos(){
	// Destrutor da classe CriarProdutos
}