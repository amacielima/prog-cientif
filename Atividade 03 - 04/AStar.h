#include <iostream>
#include <stdlib.h>
#include <list>

#include "InformedSearch.h"

using namespace std;

#ifndef a_star
#define a_star

	class AStar : public InformedSearch
	{
		public:
			
		Graph * g;
		Node * currentState;
		Queue<Node*> open;		// fila de prioridade
		Queue<Node*> closed;	// fila de prioridade
		Queue<int> * q;
		
		AStar(Graph * g);
		
		int search ();
		
	};

#endif
