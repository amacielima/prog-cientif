	#include "Fila.h"

	
	int Fila::remover() {
		
		try {
			
			No * rem = primeiro;
			
			//if (rem == NULL) // se n�o houver itens na fila
			//return 0;
			
			primeiro = rem->prox;
			
			rem->valor = 0;
			rem->prox = NULL;
			
			quantidade--;
			
			return 1;
			
		}
		
		catch (const exception &e) {
			
			cout << "Erro: N�o � poss�vel retirar itens da fila." << endl;; 
			
		}
	
		
	}
	
