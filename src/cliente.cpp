#include "cliente.hpp"
#include <iostream>
#include <string>


Cliente::Cliente(){
	set_nome("");
	set_cpf(0);
}
Cliente::Cliente(std::string nome, long int cpf){
	set_nome(nome);
	set_cpf(cpf);
}
Cliente::Cliente(long int cpf, std::string nome){
	set_cpf(cpf);
	set_nome(nome);
}

