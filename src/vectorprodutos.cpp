#include "vectorprodutos.hpp"
#include "produtos.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//TEMPLATE

template <typename T1>

T1 getInput(){
    while(true){
    T1 valor;
    cin >> valor;
    if(cin.fail()){
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "Entrada inválida! Insira novamente: " << endl;
    }
    else{
        cin.ignore(32767,'\n');
        return valor;
    }
    }
}
//FIM DO TEMPLATE


VectorProdutos::VectorProdutos(){
	// Descobrir quantidade de produtos

	ifstream contador;
	int contador_id;
	contador.open("./db/etc/contadorid.txt");
	if (contador.is_open()){
		while(contador >> contador_id){
			contador_id = contador_id -1;
		}
		contador.close();
	}
	//Fim da descoberta de quantidade de produtos

	ifstream pasta;
	int id;
	string categoria;
	int quantidade;
	string nome;
	float preco;

	for(int i = 1; i <= contador_id; i++){

		pasta.open("./db/produtos/" + to_string(i) + ".txt");
		if(pasta.is_open()){
			while(pasta >> id >> categoria >> nome >> preco >> quantidade){

			}
			listaprodutos.push_back(Produtos(id, categoria, nome, preco, quantidade));
			pasta.close();
		}	
	}
	
}

VectorProdutos::~VectorProdutos(){
	// Destrutor
}

void VectorProdutos::mostraProdutos(){
	cout << "\t*** Lista de Produtos ***\n" << endl;
	cout << "Categoria\t(ID)Nome\t\tPreço\n" << endl;
	for (unsigned int i = 0; i < listaprodutos.size(); i++){
		cout << listaprodutos[i].get_categoria() << "\t\t" << "(" << listaprodutos[i].get_id() << ")" 
		<<listaprodutos[i].get_nome() << "\t\t" << "R$ " << fixed << setprecision(2) << listaprodutos[i].get_preco() << endl;
	}
}

void VectorProdutos::atualizarQuantidade(){
	cout << "\t*** Lista de Produtos ***\n" << endl;
	cout << "Categoria\t(ID)Nome\t\tQuantidade\n" << endl;
	for (unsigned int i = 0; i < listaprodutos.size(); i++){
		cout << listaprodutos[i].get_categoria() << "\t\t" << "(" << listaprodutos[i].get_id() << ")" 
		<<listaprodutos[i].get_nome() << "\t\t" << listaprodutos[i].get_quantidade() << endl;
	}
	cout << "\nDigite o ID do produto no qual deseja atualizar: ";

	
	int temp_id = getInput<int>();
	
	
	for (unsigned int i = 0; i < listaprodutos.size(); i++){
		if (listaprodutos[i].get_id() == temp_id){

			cout << "Quantidade atual do produto *" + listaprodutos[i].get_nome() + "* é de: " 
			+ to_string(listaprodutos[i].get_quantidade()) << endl;

			cout << "Digite quantas unidades desse produto você deseja adicionar ao estoque: ";
			
			int temp_quant = getInput<int>();
			
			
			temp_quant = temp_quant + listaprodutos[i].get_quantidade();
			listaprodutos[i].set_quantidade(temp_quant);

			listaprodutos[i].escrever_dados();
		}
	}
	cout << "Deseja atualizar estoque de outro produto? (S/n): ";
	
	char e = getInput<char>();
	
	
	if(toupper(e) == 'S'){
		atualizarQuantidade();
	}
	else if(toupper(e) == 'N'){

	}
}