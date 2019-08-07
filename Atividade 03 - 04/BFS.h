#include <iostream>
#include <stdlib.h>

#include "BlindSearch.h"

using namespace std;

#ifndef bfs
#define bfs

	class BFS : public BlindSearch
	{
		
		public:
			
		Graph * g;
		Node * currentState;		
		Queue<int> * q;

			
		BFS(Graph *);		// construtor
		
		int search ();		// implementacao do bfs
		
		//~BFS();				// destrutor
		
	};

#endif
