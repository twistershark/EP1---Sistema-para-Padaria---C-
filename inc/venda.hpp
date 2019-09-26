#ifndef VENDA_HPP
#define VENDA_HPP
#include "cliente.hpp"
#include "produtos.hpp"

class Venda{

public:
	Venda(Cliente *);
	void add_produto();
	void totaldacompra();
	void salvarcompras(Cliente *);
private:
	std::vector<Produtos *> carrinho;
};

#endif