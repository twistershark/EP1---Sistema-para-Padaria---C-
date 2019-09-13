#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>  
#include <string>
#include <fstream>



class Cliente{

	public:
		
		void set_nome();
		string get_nome(){ 
			return nome;
		};

		void set_cpf();
		long int get_cpf();


	private:
		std::string nome;
		long int cpf;
};

