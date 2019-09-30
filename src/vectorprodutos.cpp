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
	int contador_id = 0;
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
	int quantidade;
	float preco;
	string categoria;
	string nome;
	string texto;

	for(int i = 1; i <= contador_id; i++){

		pasta.open("./db/produtos/" + to_string(i) + ".txt");
		if(pasta.is_open()){
			for(int linha = 1; getline(pasta, texto) && linha <=5; linha++){
				if(linha == 1) id = stoi(texto);
				if(linha == 2) categoria = texto;
				if(linha == 3) nome = texto;
				if(linha == 4) preco = stof(texto);
				if(linha == 5) quantidade = stoi(texto);
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
	cout << "(ID)Nome  **  Preço  **  Quantidade(estoque)\n" << endl;
	for (unsigned int i = 0; i < listaprodutos.size(); i++){
		cout << "(" << listaprodutos[i].get_id() << ")" 
		<<listaprodutos[i].get_nome() << "  **  " << "R$ " << fixed << setprecision(2) << listaprodutos[i].get_preco() << "  **  " << listaprodutos[i].get_quantidade() << endl;
	}
}

void VectorProdutos::atualizarQuantidade(){
	cout << "\t*** Lista de Produtos ***\n" << endl;
	cout << "(ID)Nome\t\tQuantidade\n" << endl;
	for (unsigned int i = 0; i < listaprodutos.size(); i++){
		cout << "(" << listaprodutos[i].get_id() << ")" 
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

void VectorProdutos::mostraProdutos(vector<string>& recomendacao){
	cout << "\t*** Lista de Produtos ***\n" << endl;
	cout << "(ID)Nome  **  Preço  **  Quantidade(estoque)\n" << endl;

	int contador = 1;
	while(contador <= 10){
		for(unsigned int ppp = 0; ppp < recomendacao.size(); ppp++){ // para cada categoria
			for(unsigned int jjj = 0; jjj < listaprodutos.size(); jjj++){ // testando cada produto
				if(listaprodutos[jjj].get_categoria() == recomendacao[ppp]){
					if (contador <=10){
						contador += 1;
						cout << "(" << listaprodutos[jjj].get_id() << ")" 
						<<listaprodutos[jjj].get_nome() << "  **  " << "R$ " << fixed << setprecision(2) << listaprodutos[jjj].get_preco() <<
	 					"  **  " << listaprodutos[jjj].get_quantidade() << endl;
					}	
				}
					
				else{
					continue;
				}
			}	
		}
	}		
}

