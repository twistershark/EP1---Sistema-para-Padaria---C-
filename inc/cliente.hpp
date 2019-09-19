#ifndef CLIENTE_HPP
#define CLIENTE_HPP
  
#include <string>
#include "gravadados.hpp"

using namespace std;

class Cliente : public GravaDados{

	public:
		
		Cliente();
		Cliente(string nome, string cpf);
		Cliente(string nome_in, string cpf_in, int catSal_in, int catDoc_in, int catBeb_in);
		~Cliente();

		void escrever_dados();

		void set_nome(string nome);
		string get_nome();

		void set_cpf(string cpf);
		string get_cpf();

		void set_quant_compras_catSal(int catSal_in);
		int get_quant_compras_catSal();

		void set_quant_compras_catDoc(int catDoc_in);
		int get_quant_compras_catDoc();

		void set_quant_compras_catBeb(int catBeb_in);
		int get_quant_compras_catBeb();

	private:
		string nome;
		string cpf;
		int totalComprasCatSal;
		int totalComprasCatDoc;
		int totalComprasCatBeb;
};

#endif