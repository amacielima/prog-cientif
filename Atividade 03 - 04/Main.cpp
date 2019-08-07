#include <iostream>

#include "BFS.h"
#include "DFS.h"
#include "HillClimbing.h"
#include "AStar.h"

int main (int argc, char** argv) 
{
	
	//int array[SQUARES] = {1, 2, 3, 4, 5, 6, 7, 0, 8};   // estado inicial
	//int array[SQUARES] = {0, 1, 3, 4, 2, 5, 7, 8, 6};   // estado inicial *
	int array[SQUARES] = {1, 2, 3, 4, 0, 6, 7, 5, 8};   // estado inicial
	
	cout << "------------------------------------------------------------" << endl;
	
	Node * n = new Node(array, 0); // define o no com estado inicial
	//n->printSquares();
	
	Graph * g = new Graph(n); 	   // inicia a arvore/grafo a partir do no inicial
	//g->printInitialState();
	
	g->buildGraph();			   // constroi arvore/grafo 
	
	cout << "------------------------------------------------------------" << endl;
	
	g->printAdjList();			   // imprime lista de adjacencia
	
	cout << "------------------------------------------------------------" << endl;
	
	cout<< "\nBFS: ";
	BFS b(g);
	b.search();
	b.q->print();
	
	cout<< "\nDFS: ";
	DFS d(g);
	d.initSearch();
	d.q->print();
		
	cout<< "\nHillClimbing: ";
	HillClimbing h(g);
	if(h.search())
		h.q->print();
	
	cout<< "\nA*: ";
	AStar a(g);
	a.search();
	a.q->print();
	
	return 0;
}
