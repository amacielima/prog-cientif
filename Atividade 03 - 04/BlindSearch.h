#include <iostream>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

#ifndef blind_search
#define blind_search

	class BlindSearch 
	{
		public:
		
		BlindSearch() {}; 			// construtor vazio
		
		virtual int search () {};	// nas classes derivadas sao implementadas o seu metodo de busca
		
	};

#endif

