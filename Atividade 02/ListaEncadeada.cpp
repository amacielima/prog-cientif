#include "ListaEncadeada.h"

	ListaEncadeada::ListaEncadeada() {
		
		quantidade = 0;
		primeiro = NULL;
		
	}
		
	int ListaEncadeada::inserir(int chave) {
		
		try {
			
			No * novo = new No(chave); // cria nó
		
			if (novo == NULL)         // se não houver alocamento do nó
			return 0;
			
			novo->valor = chave;      // atribui a chave para o valor do nó
		
			// nós para percorrer a lista encadeada:
			No * atual = primeiro;   // o nó atual é inicializado como o primeiro valor da lista
			No * anterior = NULL;    // o nó anterior é inicializado como nulo para percorrer a lista
			
			while (atual != NULL) {  // enquanto o valor atual for diferente de nulo
			
				anterior = atual;    // o nó anterior passa a ser o atual
				atual = atual->prox; // o nó atual é o próximo, e assim sucessivamente
			
			}
			
			if (anterior == NULL)    // se o nó anterior continuar como nulo, significa que é o primeiro elemento da lista
				primeiro = novo;
			
			else                     // o próximo do último valor anterior é o novo nó
				anterior->prox = novo; 
			
			novo->prox = atual;      // o novo valor é subsequente ao último valor que estava na lista
			
			ultimo = novo;           // o novo valor é o último
			
			quantidade++;           // incrementa a quantidade de itens na lista
			return 1;
			
		}
		
		catch (const exception &e) {
			
			cout << "Erro: Não é possível inserir itens." << endl; 
			
		}
				
	}
	
	void ListaEncadeada::imprimirLista() {
		
		No * atual = primeiro;
		
		while (atual != NULL) {
		
			cout << " " << atual->valor << " ";
			atual = atual->prox;
		
		}
	
		puts("");
		
	}
	
	ListaEncadeada::~ListaEncadeada() {
		
		quantidade = 0;
		primeiro = NULL;
		ultimo = NULL;
		
	}
