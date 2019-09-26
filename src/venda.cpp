#include "venda.hpp"
#include "vectorprodutos.hpp"
#include "cliente.hpp"
#include "produtos.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<Produtos> carrinho;

Venda::Venda(Cliente * cliente){
	system("clear");

	cout << "==================================================" << endl;
	cout << "\n \n";
	cout << "\t \t  MODO VENDA \t \t \t \t";
	cout << "\n \n";
	cout << "==================================================" << endl;
	cout << "\n \n \n ";

	VectorProdutos vector;

	vector.mostraProdutos();
	add_produto();
	salvarcompras(cliente);

}

void Venda::add_produto(){

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

	// Adicionando produtos ao Carrinho

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
	char e;
	cin >> e;
	if(toupper(e) == 'S'){
		add_produto();
	}
	else if(toupper(e) == 'N'){
		totaldacompra();
	}
}

void Venda::totaldacompra(){
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

void Venda::salvarcompras(Cliente* cliente){
	cliente->escrever_dados();
}