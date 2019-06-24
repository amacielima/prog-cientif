#include "No.h"

	No::No(int v) {
		
		valor = v;
		prox = NULL;
		
	}
	
	No::~No () {
		
		valor = 0;
		prox = NULL;
		
	}
