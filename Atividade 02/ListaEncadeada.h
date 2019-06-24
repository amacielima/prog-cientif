#include <iostream>
#include <stdlib.h>
#include "No.h"

using namespace std;

#ifndef lista
#define lista

	class ListaEncadeada {
		
		public:
		
		// atributos
		int quantidade; // quantidade de itens na lista
		No * primeiro;  // ponteiro para o primeiro elemento
		No * ultimo;    // ponteiro para o �ltimo elemento
		
		// m�todos
		ListaEncadeada (); // construtor
		
		int inserir(int);
		
		// implementa��o insuficiente na classe base, utiliza��o de funcao do tipo virtual
		// cada classe derivada ter� a sua pr�pria implementa��o do m�todo
		virtual remover() {};
				
		void imprimirLista();
				
		~ListaEncadeada(); // destrutor
		
	};

#endif
