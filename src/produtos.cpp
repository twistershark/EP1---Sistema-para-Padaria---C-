#include "produtos.hpp"
#include <string>
#include <fstream>

using namespace std;

Produtos::Produtos(){
	//Cronstrutor
}

Produtos::Produtos(int categoria, string nome, float preco, int quantidade){
	this->categoria = categoria;
	this->nome = nome;
	this->preco = preco;
	this->quantidade = quantidade;

	Produtos::guardar_produto(categoria, nome, preco, quantidade);
}

Produtos::~Produtos(){
	// Destrutor
}

void Produtos::set_nome(string nome){
	this->nome = nome;
}

void Produtos::set_preco(float preco){
	this->preco = preco;
}

void Produtos::set_quantidade(int quantidade){
	this->quantidade = quantidade;
}

void Produtos::set_categoria(int categoria){
	this->categoria = categoria;
}

string Produtos::get_nome(){
	return nome;
} 

float Produtos::get_preco(){
	return preco;
}

int Produtos::get_quantidade(){
	return quantidade;
}

int Produtos::get_categoria(){
	return categoria;
}

void Produtos::guardar_produto(int categoria, string nome, float preco, int quantidade){
	ofstream produto;
	string endereco = ".//db//produtos//";
	endereco.append(nome);
	endereco.append(".txt");
	produto.open(endereco);

	if(produto.is_open()){
    	produto << categoria << endl;
    	produto << nome << endl;
    	produto << fixed << setprecision(2) << preco << endl;
    	produto << quantidade << endl;
    	produto.close();
  }


}