#include "Pilha.h"
#define MAX 10
using namespace std;

	Pilha::Pilha () {
			
		topo = -1;
	
		int i;
	
		for(i=0; i < MAX; i++)
			v[i] = 0;
		
	}
	
	int Pilha::empilhar (char chave) {
	
		if (topo == MAX-1)
		return 0;
		
		topo++;
		v[topo] = chave;
		
		return 1;

	}
	
	int Pilha::desempilhar () {
	
		if (topo == -1)
		return 0;
	
		v[topo] = 0;
		topo--;
		
		return 1;
		
	}
	
	void Pilha::imprimePilha () {
	
		int i;
		
		for(i= 0; i < topo+1; i++)
		printf(" %c ", v[i]);
	
		puts("");
		
	}
	
	
