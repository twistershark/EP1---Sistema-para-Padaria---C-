#include "cliente.hpp"
#include <iostream>
#include <string>

using namespace std;



void Cliente::set_nome(string nome){
	this->nome = nome;
}

void Cliente::set_cpf(string cpf){
	this->cpf = cpf;
}

string Cliente::get_nome(){
	return nome;
}

string Cliente::get_cpf(){
	return cpf;
}

void Cliente::set_quant_compras_catSal(int catSal_in){
	totalComprasCatSal = catSal_in;
}

int Cliente::get_quant_compras_catSal(){
	return totalComprasCatSal;
}

void Cliente::set_quant_compras_catDoc(int catDoc_in){
	totalComprasCatDoc = catDoc_in;
}

int Cliente::get_quant_compras_catDoc(){
	return totalComprasCatDoc;
}

void Cliente::set_quant_compras_catBeb(int catBeb_in){
	totalComprasCatBeb = catBeb_in;
}
		
int Cliente::get_quant_compras_catBeb(){
	return totalComprasCatBeb;
}



Cliente::Cliente(string nome_in, string cpf_in){
	nome = nome_in;
	cpf = cpf_in;
	totalComprasCatSal = 0;
	totalComprasCatDoc = 0;
	totalComprasCatBeb = 0;
}

Cliente::Cliente(string nome_in, string cpf_in, int catSal_in, int catDoc_in, int catBeb_in){
	nome = nome_in;
	cpf = cpf_in;
	totalComprasCatSal = catSal_in;
	totalComprasCatDoc = catDoc_in;
	totalComprasCatBeb = catBeb_in;
}

Cliente::~Cliente(){
	// Destrutor da classe cliente
}

void Cliente::escrever_dados(){
	
}

