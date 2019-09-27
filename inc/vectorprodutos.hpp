#ifndef VECTORPRODUTOS_HPP
#define VECTORPRODUTOS_HPP
#include "produtos.hpp"
#include <vector>

using namespace std;

class VectorProdutos{

public:
	VectorProdutos();
	~VectorProdutos();
	void mostraProdutos();
	void atualizarQuantidade();
private:
	vector<Produtos> listaprodutos;

};

#endif