#include "carrinho.hpp"
#include "produtos.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "cliente.hpp"

using namespace std;


void Carrinho::add_produto(){

	int temp_id;
	string temp_cat;
	string temp_nome;
	float temp_preco;
	int temp_quant;

	cout << "\nDigite o ID do produto que o cliente deseja comprar: ";
	cin >> temp_id;
	cout << "Quantidade desse produto que o cliente deseja comprar: ";
	int compra_quantidade = 0;
	cin >> compra_quantidade;

	fstream arquivo;
	string endereco = "./db/produtos/";
	endereco += temp_id;
	endereco += ".txt";
	arquivo.open(endereco);
	if(arquivo.is_open()){
		while (arquivo >> temp_id >> temp_cat >> temp_nome >> temp_preco >> temp_quant){
			temp_quant = compra_quantidade;
			carrinho.push_back(Produtos(temp_id, temp_cat, temp_nome, temp_preco, temp_quant));
		}
	}

	cout << "\nProduto adicionado ao carrinho com sucesso!" << endl;
	cout << "Deseja adicionar outro produto ao carrinho? (S/n): ";
	char e = 'p';
	cin >> e;
	if(toupper(e) == 'S'){
		add_produto();
	}
	else if(toupper(e) == 'N'){
		totaldacompra();
	}
}

void Carrinho::totaldacompra(){
	system("clear");

	// Produtos no carrinho

	cout << "\t Produtos no carrinho:\n" << endl;
	cout << "Nome\tQuantidade\tPreco\n";
	for (unsigned int i = 0; i < carrinho.size(); i++){
		cout << carrinho[i].get_nome() << "\t" << carrinho[i].get_quantidade() << "\t" << carrinho[i].get_preco() << endl;
	}

	//Total de compras

	float total = 0;
	float calculo = 0;
	for (unsigned int i = 0; i < carrinho.size(); i++){
		calculo = carrinho[i].get_preco() * carrinho[i].get_quantidade();
		total += calculo;
	}
	cout << "O total da compra é R$ ";
	cout << total;


	
	cout << "\nDeseja efetuar a compra de todos os produtos no carrinho?";
	}