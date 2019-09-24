#ifndef PRODUTOS_HPP
#define PRODUTOS_HPP

#include <string>

class Produtos{

public:
	Produtos();
	Produtos(int categoria, std::string nome, float preco, int quantidade);
	~Produtos();

	void set_nome(std::string nome);
	std::string get_nome();

	void set_preco(float preco);
	float get_preco();

	void set_quantidade(int quantidade);
	int get_quantidade();

	void set_categoria(int categoria);
	int get_categoria();

	void guardar_produto(int categoria, std::string nome, float preco, int quantidade);

private:
	std::string nome;
	float preco;
	int quantidade;
	int categoria;

};

#endif