#include "Pilha.h"
using namespace std;
	
	int Pilha::remover() {
		
		try {
		
			No * rem = ultimo; // item a ser removido da pilha é o último
			
			//if (rem == NULL)
			//	return 0;
			
			No * anterior = NULL;
			No * atual = primeiro;
			
			// percorre a lista até o final		
			while (atual != NULL && atual != rem) {
			
				anterior = atual;
				atual = atual->prox;
			
			}
			
			//if (atual != rem)
			//	return 0;
			
			if (anterior != NULL)   // se o valor anterior ao último não é nulo, o valor anterior é o último
				ultimo = anterior;
			
			else
				ultimo = primeiro;  // se o valor anterior ao último é nulo, só há um valor na pilha
			
			anterior->prox = NULL;  // o próximo valor do anterior é nulo
	
			quantidade--;           // decrementa quantidade de itens na lista
			
		}
		
		catch (const exception &e) {
			
			cout << "Erro: Não é possível desempilhar itens da pilha." << endl; 
			
		}
			
		return 1;
	}
