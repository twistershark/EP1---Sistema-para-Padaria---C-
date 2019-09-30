#include "venda.hpp"
#include "vectorprodutos.hpp"
#include "cliente.hpp"
#include "produtos.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

string Venda::get_cpf(){
	return cpf;
}

void Venda::set_infocliente(Cliente* cliente){
	this->socio = cliente->get_socio();
}

char Venda::get_socio(){
	return socio;
}

Venda::Venda(Cliente * cliente, vector<string>& recomendados){
	this->cpf = cliente->get_cpf();
	set_infocliente(cliente);

	system("clear");

	cout << "==================================================" << endl;
	cout << "\n \n";
	cout << "\t \t  MODO RECOMENDAÇÃO \t \t \t \t";
	cout << "\n \n";
	cout << "==================================================" << endl;
	cout << "\n \n \n ";

	VectorProdutos vector;

	vector.mostraProdutos(recomendados);
	add_produto();

}

Venda::Venda(Cliente * cliente){
	this->cpf = cliente->get_cpf();
	set_infocliente(cliente);

	system("clear");

	cout << "==================================================" << endl;
	cout << "\n \n";
	cout << "\t \t  MODO VENDA \t \t \t \t";
	cout << "\n \n";
	cout << "==================================================" << endl;
	cout << "\n \n \n ";

	VectorProdutos vector;

	vector.mostraProdutos();
	add_produto();


}

void Venda::add_produto(){
	cin.clear();
	
	string temp_cat;
	string temp_nome;
	float temp_preco;
	int temp_quant;

	cout << "\nDigite o ID do produto que o cliente deseja comprar: ";

	int temp_id = getInput<int>();

	cout << "Quantidade desse produto que o cliente deseja comprar: ";

	int compra_quantidade = getInput<int>();
	int quantidade_estoque = 0;
	

	// Adicionando produtos ao Carrinho
	fstream arquivo;

	string fileText;
	string endid = to_string(temp_id);
	string endereco = "./db/produtos/";
	endereco.append(endid);
	endereco.append(".txt");
	
	arquivo.open(endereco);
	if(arquivo.is_open()){

		for(int lines = 1; getline(arquivo, fileText) && lines <=5; lines++){
			if(lines == 1) temp_id = stoi(fileText);
			if(lines == 2) temp_cat = fileText;
			if(lines == 3) temp_nome = fileText;
			if(lines == 4) temp_preco = stof(fileText);
			if(lines == 5) temp_quant = stoi(fileText);
		}
			
		quantidade_estoque = temp_quant;
		temp_quant = compra_quantidade;
		this->quantidades.push_back(quantidade_estoque);
		this->carrinho.push_back(new Produtos(temp_id, temp_cat, temp_nome, temp_preco, temp_quant));
		
	}

	cout << "\nProduto adicionado ao carrinho com sucesso!" << endl;
	cout << "Deseja adicionar outro produto ao carrinho? (S/n): ";
	char e = getInput<char>();
	
	if(toupper(e) == 'S'){
		add_produto();
	}
	else if(toupper(e) == 'N'){
		totaldacompra();
	}
	else{
		cout << "Entrada inválida! Digite novamente (S/n): ";

		e = getInput<char>();
		if(toupper(e) == 'S'){
		add_produto();
		}
		else if(toupper(e) == 'N'){
		totaldacompra();
	}
	}
}

void Venda::totaldacompra(){
	system("clear");

	// PRODUTOS NO CARRINHO

	cout << "\t Produtos no carrinho:\n" << endl;
	cout << "  Nome\tQuantidade\tPreco\n\n";
	for (unsigned int i = 0; i < this->carrinho.size(); i++){
		cout << "-> " << this->carrinho[i]->get_nome() << "\t\t" << this->carrinho[i]->get_quantidade() << "\t" << this->carrinho[i]->get_preco() << endl;
		cout << endl;
	}

	//TOTAL DE COMPRAS

	float total = 0;
	float calculo = 0;
	for (unsigned int i = 0; i < this->carrinho.size(); i++){
		calculo = this->carrinho[i]->get_preco() * this->carrinho[i]->get_quantidade();
		total += calculo;
	}
	cout << "O total da compra é de R$ ";
	cout << total;
	cout << endl;

	if (this->socio == 'S'){
		cout << "Cliente é sócio! Por tanto, o valor total da compra com desconto de 15% é: ";
		total = total - total * 0.15;
		cout << total;
	}

	// PROCESSO DE FINALIZAÇÃO DE COMPRA

	cout << "\n\nDeseja concluir a compra de todos os produtos no carrinho? (S/n): " << endl;
	
	cin.clear();
	
	int test = 0;
	char in = getInput<char>();
	if(toupper(in) == 'S'){
		
		//FINALIZAR COMPRA

		for (unsigned int j = 0; j < this->carrinho.size(); j++){
			
			// ANALISANDO QUANTIDADE EM ESTOQUE

			if(this->quantidades[j] < this->carrinho[j]->get_quantidade()){
				test = 1;				
			}
		}

		//CASO TENHO QUANTIDADE SUFICIENTE NO ESTOQUE
		if(test == 0){


			vector<string> categoriasjuntas;
			ifstream getexistente;
			string temp_recebecat;
			string path_1 = "./db/compras/" + get_cpf() + ".txt";
			getexistente.open(path_1);
			if (getexistente.is_open()){
				while(getexistente >> temp_recebecat){
					categoriasjuntas.push_back(temp_recebecat);
				}
				getexistente.close();
			}

			for(unsigned int cont1 = 0; cont1 < this->carrinho.size(); cont1++){
					for(int cont2 = 1; cont2 <= this->carrinho[cont1]->get_quantidade(); cont2++){
						categoriasjuntas.push_back(this->carrinho[cont1]->get_categoria());	
					} // fim do loop de quantidade
				}// fim do loop de cada produto




			ofstream purchaseInfo;
			string path = "./db/compras/" + get_cpf() + ".txt";

			purchaseInfo.open(path);
			if(purchaseInfo.is_open()){
				for (unsigned int ask = 0; ask < categoriasjuntas.size(); ask++){
					purchaseInfo << categoriasjuntas[ask] << endl;
				}
				
			} // fim do if is open

			for(unsigned int t = 0; t < this->carrinho.size(); t++){
				int remover = this->quantidades[t] - this->carrinho[t]->get_quantidade();
				this->carrinho[t]->set_quantidade(remover);
				this->carrinho[t]->escrever_dados(); 
			}
			

			cout << "Compra finalizada com sucesso!" << endl;
				//FIM DA COMPRA
			}else if(test == 1){
				cout << "ERRO! Você comprou uma quantidade maior do que a presente no estoque. Finalizando compra..." << endl;
			}
	} // Compra finalizada	

	else if(toupper(in) == 'N'){
		cout << "Deseja adicionar mais algum produto? (1 = Sim / 2 = Finalizar programa):";
		int choice = getInput<int>();
		
		if (choice == 1){
			add_produto();
		}
		else if(choice == 2){
			//Fazer nada
		}


		else{ // Entrada inválida
			do{
				cout << "Escolha inválida! digite novamente 1 ou 2: ";
				choice = getInput<int>();
			}while(choice < 1 || choice > 2);
			if (choice == 1){
			add_produto();
			}
			else if(choice == 2){
				//Fazer nada
			}
		}
	}

} //Fim do método TotalCompras

