#include <iostream>
#include <stdlib.h>

#include "ListaEncadeada.h"

using namespace std;

#ifndef pilha 
#define pilha

	class Pilha : public ListaEncadeada {
		
		public:
		
		Pilha() {}; // construtor vazio
		
		int remover ();
		
	};

#endif
