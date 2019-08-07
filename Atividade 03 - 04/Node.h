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
		vector<Node> next; 			// pr�ximos n�s ao n� em quest�o
		Node * previous;   			// n� anterior
		int v[SQUARES];    			// vetor com as pe�as do jogo pertencente ao n�
		bool visited; 	   			// flag para sinalizar visita��o (BFS)
		bool check;        			// flag para sinalizar visita��o na lista de adjac�ncia
		bool found;		   			// /flag para sinalizar visita��o (DFS)
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
