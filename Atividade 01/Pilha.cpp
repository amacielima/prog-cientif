#include "Pilha.h"
#define MAX 10
using namespace std;

	Pilha::Pilha () {
		
		// inicializa o topo como -1, para que quando o primeiro elemento for inserido na fila, o topo � incrementado e inicia como zero
		topo = -1;
	
		int i;
		
		// inicializa todas as posi��es do vetor para zero
		for(i=0; i < MAX; i++)
			v[i] = 0;
		
	}
	
	int Pilha::empilhar (char chave) {
	
		// verifica se a pilha est� cheia
		if (topo == MAX-1)
		return 0;
		
		// se n�o, incrementa o topo e insere a chave na posi��o
		topo++;
		v[topo] = chave;
		
		return 1;

	}
	
	int Pilha::desempilhar () {
	
		// se a pilha estiver vazia, n�o h� elementos para desempilhar
		if (topo == -1)
		return 0;
	
		// caso contr�rio, a posi��o do topo fica como zero
		v[topo] = 0;
		
		// o novo topo � a posi��o anterior do topo da pilha
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
	
	
