#include <iostream>
#include <stdlib.h>
#include <vector>

#include "BlindSearch.h"

using namespace std;

#ifndef dfs
#define dfs

	class DFS : public BlindSearch
	{
		public:
			
		Graph * g;
		Stack<int> * s;		// pilha com as posicoes encontrados
		Stack<Node*> sn;	// pilha com os nos encontrados
		Queue<int> * q;		// fila para armazenar a ordem de visitacao
		
		DFS(Graph * g);		// construtor
		
		void initSearch();	 // funcao que chama a busca dfs para cada no do grafo
		int search (Node *); // implementacao dfs
		
		//~DFS();				// destrutor
		
	};

#endif
