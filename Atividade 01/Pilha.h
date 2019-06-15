#include <iostream>
#include <stdlib.h>

#define MAX 10

using namespace std;

#ifndef pilha 
#define pilha

	class Pilha {
		
		public:
			
		char v[MAX];
		int topo;	
		
		Pilha();
		int empilhar (char chave);	
		int desempilhar ();	
		void imprimePilha ();
		
	};

#endif
