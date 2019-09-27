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
	void set_socio(Cliente *);
	char get_socio();
	void totaldacompra();


private:
	vector<Produtos *> carrinho;
	vector<int> quantidades;
	
	char socio;	
};

#endif