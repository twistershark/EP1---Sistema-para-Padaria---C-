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

	string endid = to_string(temp_id);
	string endereco = "./db/produtos/";
	endereco.append(endid);
	endereco.append(".txt");
	
	arquivo.open(endereco);
	if(arquivo.is_open()){
		while (arquivo >> temp_id >> temp_cat >> temp_nome >> temp_preco >> temp_quant){
			
			quantidade_estoque = temp_quant;
			temp_quant = compra_quantidade;
			this->quantidades.push_back(quantidade_estoque);
			this->carrinho.push_back(new Produtos(temp_id, temp_cat, temp_nome, temp_preco, temp_quant));
		}
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
	
	int teste = 0;
	char entrada = getInput<char>();
	if(toupper(entrada) == 'S'){
		
		//FINALIZAR COMPRA

		for (unsigned int j = 0; j < this->carrinho.size(); j++){
			
			// ANALISANDO QUANTIDADE EM ESTOQUE

			if(this->quantidades[j] < this->carrinho[j]->get_quantidade()){
				teste = 1;				
			}
		}

		//CASO TENHO QUANTIDADE SUFICIENTE NO ESTOQUE
		if(teste == 0){

			for(unsigned int w = 0; w < this->carrinho.size(); w++){
				int remover = this->quantidades[w] - this->carrinho[w]->get_quantidade();
				this->carrinho[w]->set_quantidade(remover);
				this->carrinho[w]->escrever_dados(); 
			}
			
			cout << "\n\n\n CPF: " << get_cpf() << endl;
			/*ofstream salvarCatCompradas;
			string path = "./db/compras/" + get_cpf() + ".txt";

			salvarCatCompradas.open(path);
			if(salvarCatCompradas.is_open()){
				for(unsigned int k = 0; k < this->carrinho.size(); k++){
					for(int z = 1; z <= this->quantidades[k]; z++){
						salvarCatCompradas << this->carrinho[k]->get_categoria() << endl;	
					} // fim do loop de quantidade
						
				}// fim do loop de cada produto
				cout << "\n\n\n\nFUNCIONOU!1\n\n\n";
			}*/// fim do if is open

			cout << "Compra finalizada com sucesso!" << endl;
				//FIM DA COMPRA
			}else if(teste == 1){
				cout << "ERRO! Você comprou uma quantidade maior do que a presente no estoque. Finalizando compra..." << endl;
			}
	} // Compra finalizada	

	else if(toupper(entrada) == 'N'){
		cout << "Deseja adicionar mais algum produto? (1 = Sim / 2 = Finalizar programa):";
		int escolha = getInput<int>();
		
		if (escolha == 1){
			add_produto();
		}
		else if(escolha == 2){
			//Fazer nada
		}


		else{ // Entrada inválida
			do{
				cout << "Escolha inválida! digite novamente 1 ou 2: ";
				escolha = getInput<int>();
			}while(escolha < 1 || escolha > 2);
			if (escolha == 1){
			add_produto();
			}
			else if(escolha == 2){
				//Fazer nada
			}
		}
	}

} //Fim do método TotalCompras

