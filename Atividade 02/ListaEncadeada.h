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
		No * ultimo;    // ponteiro para o último elemento
		
		// métodos
		ListaEncadeada (); // construtor
		
		int inserir(int);
		
		// implementação insuficiente na classe base, utilização de funcao do tipo virtual
		// cada classe derivada terá a sua própria implementação do método
		virtual remover() {};
				
		void imprimirLista();
				
		~ListaEncadeada(); // destrutor
		
	};

#endif
