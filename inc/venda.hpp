#ifndef VENDA_HPP
#define VENDA_HPP
#include "cliente.hpp"
#include "produtos.hpp"
#include <vector>

using namespace std;

class Venda{

public:
	Venda(Cliente *);
	void add_produto();
	void set_infocliente(Cliente *);
	char get_socio();
	void totaldacompra();

	void set_cpf(Cliente *);
	string get_cpf();


private:
	vector<Produtos *> carrinho;
	vector<int> quantidades;
	
	string cpf;

	char socio;	
};

#endif