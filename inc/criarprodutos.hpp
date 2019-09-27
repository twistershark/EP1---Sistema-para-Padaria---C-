#ifndef CRIARPRODUTOS_HPP
#define CRIARPRODUTOS_HPP

#include "produtos.hpp"
#include <vector>

class CriarProdutos : public Produtos{

public:
	CriarProdutos();
	~CriarProdutos();

	string CriarCategorias();


};

#endif