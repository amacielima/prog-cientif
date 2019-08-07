#include <iostream>
#include <stdlib.h>
#include <list>

#include "Node.h"

#define MAX 100
#define Y 40 	// numero de vertices do grafo

using namespace std;

#ifndef graph
#define graph

	class Graph 
	{
		
		private:		
		int goal; 		// vetor com a solucao do jogo
		int node_id;	// incrementador de nos pertencentes ao grafo

		public:
			
		Node * initialState; // estado inicial
		vector<Node> * list; // lista de adjancencia
		int v;				 // numero de vertices
		int solution_id;	 // id do no objetivo
				
		Graph(Node *);					// construtor
		void printInitialState();		// imprime estado inicial
		int createNodeId();				// incrementa id a cada no criado
		bool isGoal(int *);				// verifica objetivo
		int emptySquare(int *);			// verifica qual a posicao da peca vazia de um vetor
		void buildGraph();				// funcao de construcao
		void printAdjList();			// imprime lista de adjacencia
		Node * nextVertex();			// funcao para verificar qual no popular com suas variacoes
		
		~Graph();
		
	};

#endif

