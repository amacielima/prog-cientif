#include <iostream>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

#ifndef informed_search
#define informed_search

	class InformedSearch 
	{
		public:
		
		InformedSearch() {};		// construtor vazio
		
		virtual int search () {};	// nas classes derivadas sao implementadas o seu metodo de busca
		
	};

#endif

