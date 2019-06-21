#include <iostream>
#include <stdlib.h>

#define MAX 10

using namespace std;

#ifndef fila 
#define fila

	class Fila {
		
		public:
			
		int inicio;
		int fim;
		char v[MAX];
		
		Fila(); // construtor
		int enfileirar (char chave);	
		int desenfileirar ();	
		void imprimeFila ();
		
	};

#endif
