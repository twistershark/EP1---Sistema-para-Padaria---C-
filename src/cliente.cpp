#include "menu.hpp"
#include "cliente.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Cliente::set_socio(char a){
	this->socio = a;
}

char Cliente::get_socio(){
	return socio;
}

void Cliente::set_nome(string nome){
	this->nome = nome;
}

string Cliente::get_nome(){
	return nome;
}

void Cliente::set_cpf(string cpf){
	this->cpf = cpf;
}

string Cliente::get_cpf(){
	return cpf;
}

Cliente::Cliente(char socio_in, string nome_in, string cpf_in){
	socio = socio_in;
	nome = nome_in;
	cpf = cpf_in;

	escrever_dados();

}

Cliente::~Cliente(){
	escrever_dados();
}

void Cliente::escrever_dados(){
	ofstream file;
	file.open("./db/clientes/" + cpf + ".txt");
	if(file.is_open()){
		file << socio << endl;
		file << nome << endl;
		file << cpf << endl;
		file.close();
	}
}
