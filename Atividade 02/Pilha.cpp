#include "Pilha.h"
using namespace std;
	
	int Pilha::remover() {
		
		try {
		
			No * rem = ultimo; // item a ser removido da pilha � o �ltimo
			
			//if (rem == NULL)
			//	return 0;
			
			No * anterior = NULL;
			No * atual = primeiro;
			
			// percorre a lista at� o final		
			while (atual != NULL && atual != rem) {
			
				anterior = atual;
				atual = atual->prox;
			
			}
			
			//if (atual != rem)
			//	return 0;
			
			if (anterior != NULL)   // se o valor anterior ao �ltimo n�o � nulo, o valor anterior � o �ltimo
				ultimo = anterior;
			
			else
				ultimo = primeiro;  // se o valor anterior ao �ltimo � nulo, s� h� um valor na pilha
			
			anterior->prox = NULL;  // o pr�ximo valor do anterior � nulo
	
			quantidade--;           // decrementa quantidade de itens na lista
			
		}
		
		catch (const exception &e) {
			
			cout << "Erro: N�o � poss�vel desempilhar itens da pilha." << endl; 
			
		}
			
		return 1;
	}
