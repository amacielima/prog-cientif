	#include "Fila.h"

	
	int Fila::remover() {
		
		try {
			
			No * rem = primeiro;
			
			//if (rem == NULL) // se não houver itens na fila
			//return 0;
			
			primeiro = rem->prox;
			
			rem->valor = 0;
			rem->prox = NULL;
			
			quantidade--;
			
			return 1;
			
		}
		
		catch (const exception &e) {
			
			cout << "Erro: Não é possível retirar itens da fila." << endl;; 
			
		}
	
		
	}
	
