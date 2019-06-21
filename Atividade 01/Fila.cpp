	#include "Fila.h"
	
	Fila::Fila() {
	
		// inicializa as variáveis de início e fim
		inicio = 0;
		fim = 0;
		
		int i;
		
		// varre o vetor colocando todas as suas posições para zero
		for (i=0; i < MAX; i++)
			v[i] = 0;
	
	}
	
	int Fila::enfileirar (char chave) {
	
		// verifica se a fila está cheia
		if (fim == MAX-1)
		return 0;
		
		// caso contrário, insere o valor no final da fila e depois incrementa
		v[fim] = chave;
		fim++;
				
	}
	
	int Fila::desenfileirar () {
	
		// coloca na posicao que indica o início o valor zero
		v[inicio] = 0;
		
		// o novo valor de início será o próximo que será atendido na fila
		inicio++;
		
	}
	
	void Fila::imprimeFila () {
	
		int i;
		
		// percorre o vetor de caracteres contidos na fila
		for (i = inicio; i < fim; i++)
		printf(" %c ", v[i]);

		puts("");
	
	}
	
