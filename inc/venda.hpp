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
	//void salvarcompras(Cliente *);
	vector<Produtos *> carrinho;
	vector<int> quantidades;
private:
	char socio;	
};

#endif