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

Cliente::Cliente(string nome_in, string cpf_in){
	nome = nome_in;
	cpf = cpf_in;
}

Cliente::~Cliente(){
	// Destrutor da classe cliente
}