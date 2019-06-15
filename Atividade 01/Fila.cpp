	#include "Fila.h"
	
	Fila::Fila() {
	
		inicio = 0;
		fim = 0;
		
		int i;
		
		for (i=0; i < MAX; i++)
			v[i] = 0;
	
	}
	
	int Fila::enfileirar (char chave) {
	
		if (fim == MAX-1)
		return 0;
		
		v[fim] = chave;
		fim++;
				
	}
	
	int Fila::desenfileirar () {
	
		v[inicio] = 0;
		inicio++;
		
	}
	
	void Fila::imprimeFila () {
	
		int i;
		
		for (i = inicio; i < fim; i++)
		printf(" %c ", v[i]);

		puts("");
	
	}
	
