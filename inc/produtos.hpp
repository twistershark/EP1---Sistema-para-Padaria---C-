#ifndef PRODUTOS_HPP
#define PRODUTOS_HPP

#include <string>

using namespace std;

class Produtos{

public:
	Produtos();
	Produtos(int id, string categoria, string nome, float preco, int quantidade);
	Produtos(string categoria, string nome, float preco, int quantidade);
	~Produtos();

	void set_id(int id);
	int get_id();

	void set_nome(std::string nome);
	string get_nome();

	void set_preco(float preco);
	float get_preco();

	void set_quantidade(int quantidade);
	int get_quantidade();

	void set_categoria(string categoria);
	string get_categoria();

	void guardar_produto(int id, string categoria, string nome, float preco, int quantidade);

private:
	int id;
	string nome;
	float preco;
	int quantidade;
	string categoria;

};

#endif