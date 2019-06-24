#include "ListaEncadeada.h"

	ListaEncadeada::ListaEncadeada() {
		
		quantidade = 0;
		primeiro = NULL;
		
	}
		
	int ListaEncadeada::inserir(int chave) {
		
		try {
			
			No * novo = new No(chave); // cria n�
		
			if (novo == NULL)         // se n�o houver alocamento do n�
			return 0;
			
			novo->valor = chave;      // atribui a chave para o valor do n�
		
			// n�s para percorrer a lista encadeada:
			No * atual = primeiro;   // o n� atual � inicializado como o primeiro valor da lista
			No * anterior = NULL;    // o n� anterior � inicializado como nulo para percorrer a lista
			
			while (atual != NULL) {  // enquanto o valor atual for diferente de nulo
			
				anterior = atual;    // o n� anterior passa a ser o atual
				atual = atual->prox; // o n� atual � o pr�ximo, e assim sucessivamente
			
			}
			
			if (anterior == NULL)    // se o n� anterior continuar como nulo, significa que � o primeiro elemento da lista
				primeiro = novo;
			
			else                     // o pr�ximo do �ltimo valor anterior � o novo n�
				anterior->prox = novo; 
			
			novo->prox = atual;      // o novo valor � subsequente ao �ltimo valor que estava na lista
			
			ultimo = novo;           // o novo valor � o �ltimo
			
			quantidade++;           // incrementa a quantidade de itens na lista
			return 1;
			
		}
		
		catch (const exception &e) {
			
			cout << "Erro: N�o � poss�vel inserir itens." << endl; 
			
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
