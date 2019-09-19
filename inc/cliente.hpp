#ifndef CLIENTE_HPP
#define CLIENTE_HPP
  
#include <string>

using namespace std;

class Cliente{

	public:
		
		Cliente();
		Cliente(string nome, string cpf);
		~Cliente();

		void set_nome(string nome);
		string get_nome();

		void set_cpf(string cpf);
		string get_cpf();


	private:
		string nome;
		string cpf;
};

#endif