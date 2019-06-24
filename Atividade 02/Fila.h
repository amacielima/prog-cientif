#include <iostream>
#include <stdlib.h>

#include "ListaEncadeada.h"

using namespace std;

#ifndef fila 
#define fila	

	class Fila : public ListaEncadeada {
		
		public:
		
		Fila() {}; // construtor vazio
		
		int remover();
		
	};

#endif
