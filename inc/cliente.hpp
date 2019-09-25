#ifndef CLIENTE_HPP
#define CLIENTE_HPP
  
#include <string>
#include "gravadados.hpp"

using namespace std;

class Cliente : public GravaDados{

	public:
		
		Cliente();
		Cliente(char socio, string nome, string cpf);
		~Cliente();

		void set_socio(char a);
		char get_socio();

		void set_nome(string nome);
		string get_nome();

		void set_cpf(string cpf);
		string get_cpf();

		void escrever_dados();

	private:
		char socio;
		string nome;
		string cpf;

};

#endif