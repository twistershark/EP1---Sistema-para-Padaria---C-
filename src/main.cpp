#include <iostream>
#include <fstream>
#include <string>

#include "produtos.hpp"
#include "venda.hpp"
#include "cliente.hpp"
#include "vectorprodutos.hpp"
#include "criarprodutos.hpp"

using namespace std;

int main(){

	vector<Produtos> carrinho;
	// INICIO DO SISTEMA DA PADARIA

	// MENU

	int escolha = -1;

	system("clear");
	cout << "=======================================================================" << endl;
	cout << "\n \n";
	cout << "\t \t \t  SISTEMA DA PADARIA \t \t \t \t";
	cout << "\n \n";
	cout << "=======================================================================" << endl;
	cout << "\n \n \n \n \n";
	cout << "\tMenu de opções: (digite o número correspondente a sua escolha)\n \n";
	cout << "\t \t (1) - Modo Venda\n";
	cout << "\t \t (2) - Modo Estoque\n";
	cout << "\t \t (3) - Modo Recomendação\n";
	cout << "\t \t (0) - Sair\n";
	cout << "\t \t Sua Escolha: ";
	
	cin >> escolha;
	
	cout << "\n \n \n \n";
	

	// FIM MENU

	// INICIO SWITCH CASE DO MENU
	
	switch(escolha){
		
		case 0:
			return 0;
			break;

		case 1:{
		
		string cpf;
		cout << "Digite o CPF do cliente: ";
		cin >> cpf;

		// VERIFICANDO SE O CLIENTE JÁ EXISTE
			string end_cpf = cpf;
			end_cpf += ".txt";
			string end_clientes = "./db/clientes/";
			end_clientes += end_cpf;

			// TENTANDO ABRIR ARQUIVO PARA VER SE RETORNA TRUE

			ifstream arq_cliente;
			arq_cliente.open(end_clientes);
			if (arq_cliente.is_open()){
				
				//PEGANDO OS DADOS DO ARQUIVO E OS UTILIZANDO PARA INSTANCIAR UM OBJETO DA CLASSE CLIENTE
				char temp_socio;
				string temp_nome;
				string temp_cpf;
				string texto;
				
				char e;
				
				// ATRIBUINDO VALORES DO ARQUIVO À VARIÁVEIS TEMPORÁRIAS
				for(int linha = 1; getline(arq_cliente, texto) && linha <=3; linha++){
					if(linha == 1) temp_socio = texto[0];
					if(linha == 2) temp_nome = texto;
					if(linha == 3) temp_cpf = texto;
				}

				if (temp_socio == 'S'){
					cout << "Dados carregados com sucesso! Esse cliente é sócio!" << endl;
					
					//Instanciando um cliente que já é sócio
					
					Cliente* cliente = new Cliente(temp_socio, temp_nome, temp_cpf);

					cout << "Pressione ENTER para continuar..." << endl;
					getchar(); getchar(); // Pausando o sistema

					Venda venda(cliente);
				}

				else if(temp_socio == 'N'){

					cout << "Dados carregados com sucesso! Esse cliente não é sócio" << endl;
					cout << "Cliente deseja se tornar sócio agora? (S/n): ";
					cin >> e;
					if(toupper(e) == 'S'){
						temp_socio = 'S';
					} else if (toupper(e) == 'N'){
						temp_socio = 'N';
					}

					// Instanciando Cliente

					Cliente* cliente = new Cliente(temp_socio, temp_nome, temp_cpf);

					Venda venda(cliente);
				}
			}

			// CADASTRO DE NOVOS CLIENTES

			else{

				system("clear");

				string temp_nome;	
				char temp_socio;

				cout << "============================================================" << endl;
				cout << "\t\t\tCadastro de novo Usuário\t\t\t" << endl;
				cout << "============================================================" << endl;
				cout << "Digite o nome do novo cliente: ";
				
				getline(cin >> ws, temp_nome);
				
				cout << "Esse Cliente deseja se tornar sócio? (S/n): ";
		  		
		  		char e;
		  		cin >> e;
		  			if (toupper(e) == 'S'){
		  				temp_socio = 'S';
		  			} else if(toupper(e) == 'N'){
		  				temp_socio = 'N';
		  			}

		  		// INSTANCIANDO O NOVO CLIENTE

				Cliente* cliente = new Cliente(temp_socio, temp_nome, cpf);
				Venda venda(cliente);
			}

			break;
		}
		case 2:{

			system("clear");

			int esc = 0;
			cout << "Digite o número associado a sua escolha" << endl;
			cout << "(1) Adicionar novo produto\n(2) Editar estoque de produto existente" << endl;
			cin >> esc;
			if(esc == 1){
				CriarProdutos novo;
			}
			else if (esc == 2){
				VectorProdutos atualizar;
				atualizar.atualizarQuantidade();
			}
			break;
		}
		default:
			cout << "opção errada\n";
			break;
	}
	// FIM DO SWITCH CASE DO MENU
}