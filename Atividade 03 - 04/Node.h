#include <iostream>
#include <stdlib.h>
#include <vector>

#define SQUARES 9

using namespace std;

#ifndef node
#define node

	class Node
	{		
		public:
		
		int id;
		vector<Node> next; 			// próximos nós ao nó em questão
		Node * previous;   			// nó anterior
		int v[SQUARES];    			// vetor com as peças do jogo pertencente ao nó
		bool visited; 	   			// flag para sinalizar visitação (BFS)
		bool check;        			// flag para sinalizar visitação na lista de adjacência
		bool found;		   			// /flag para sinalizar visitação (DFS)
		int h;			   			// funcao heuristia para busca informada
		int cost;					// total do custo para o algoritmo A*
			
		Node (int *, int); 				// contrutor
		void printSquares();			// imprime as pecas armanzenadas
		int * getSquares();				// captura o vetor atual
		void changePosition(int, int); 	// usada no classe Graph para criar a arvore/grafo
		bool isGoal();				   	// verifica objetivo
		int calcHamming();			  	// calcula heuristica hamming
		
	};

#endif
