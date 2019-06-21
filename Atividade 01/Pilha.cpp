#include "Pilha.h"
#define MAX 10
using namespace std;

	Pilha::Pilha () {
		
		// inicializa o topo como -1, para que quando o primeiro elemento for inserido na fila, o topo é incrementado e inicia como zero
		topo = -1;
	
		int i;
		
		// inicializa todas as posições do vetor para zero
		for(i=0; i < MAX; i++)
			v[i] = 0;
		
	}
	
	int Pilha::empilhar (char chave) {
	
		// verifica se a pilha está cheia
		if (topo == MAX-1)
		return 0;
		
		// se não, incrementa o topo e insere a chave na posição
		topo++;
		v[topo] = chave;
		
		return 1;

	}
	
	int Pilha::desempilhar () {
	
		// se a pilha estiver vazia, não há elementos para desempilhar
		if (topo == -1)
		return 0;
	
		// caso contrário, a posição do topo fica como zero
		v[topo] = 0;
		
		// o novo topo é a posição anterior do topo da pilha
		topo--;
		
		return 1;
		
	}
	
	void Pilha::imprimePilha () {
	
		int i;
		
		// varre o vetor imprimindo os componentes da pilha
		for(i= 0; i < topo+1; i++)
			printf(" %c ", v[i]);
	
		puts("");
		
	}
	
	
