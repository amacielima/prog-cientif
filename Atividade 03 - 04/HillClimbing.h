#include <iostream>
#include <stdlib.h>
#include <vector>

#include "InformedSearch.h"

using namespace std;

#ifndef hill_climbing
#define hill_climbing

	class HillClimbing : public InformedSearch
	{
		public:
			
		Graph * g;
		Node * currentState;
		Stack<int> * s;
		Stack<Node*> sn;
		Queue<int> * q;
		
		HillClimbing(Graph * g);
		
		int search ();
		
	};

#endif
