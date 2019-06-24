#include <iostream>
#include <stdlib.h>

#define MAX 10

using namespace std;

#ifndef no
#define no

	class No {
		
		public:
		
		int valor;
		No * prox;
		
		No (int); // construtor
		
		~No(); // destrutor
			
	};

#endif

