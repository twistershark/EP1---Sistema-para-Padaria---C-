#include <iostream>


class ModoVenda(){

	public:
		ModoVenda(long int cpf);

		~ModoVenda();


	private:
		ModoVenda();
		
		long int cpf_verificador;	
};