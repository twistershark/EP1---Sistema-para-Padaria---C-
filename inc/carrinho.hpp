#ifndef CARRINHO_HPP
#define CARRINHO_HPP
#include <vector>
#include "produtos.hpp"

class Carrinho{

public:

	void add_produto();
	void totaldacompra();
	vector<Produtos> carrinho;

};

#endif