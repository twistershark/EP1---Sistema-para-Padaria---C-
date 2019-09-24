#include "criarprodutos.hpp"


#include <fstream>
#include <iostream>

using namespace std;

CriarProdutos::CriarProdutos(){
	string nome_in;
	float preco_in;
	int quantidade_in;
	int categoria_in;
	cout << "Insira a categoria, nome do produto, preço e quantidade para ser inserido no estoque." << endl;
	cout << "(1) Salgados \t (2) Bebidas \t (3) Doces" << endl;
	cout << "Digite o número associado a categoria do produto: ";
	cin >> categoria_in;
	cout << "Nome: ";
	cin >> nome_in;
	cout << "Preço: R$ ";
	cin >> preco_in;
	cout << "Quantidade: ";
	cin >> quantidade_in;
	cout << "\n\n";

	Produtos produto(categoria_in, nome_in, preco_in, quantidade_in);

	std::cout << "Produto adicionado ao estoque com sucesso!\n";
}
CriarProdutos::~CriarProdutos(){
	// Destrutor da classe CriarProdutos
}