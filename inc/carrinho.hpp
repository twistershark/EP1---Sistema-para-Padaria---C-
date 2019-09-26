#ifndef CARRINHO_HPP
#define CARRINHO_HPP
#include <vector>
#include "produtos.hpp"
#include "cliente.hpp"

class Carrinho{

public:
	void add_produto();
	void totaldacompra();
	vector<Produtos> carrinho;

};

#endif