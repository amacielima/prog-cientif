#include <iostream>
#include "Pilha.h"
#include "Fila.h"

/*

	Nome: Amanda Maciel de Lima
	PEL216 - Programação Científica
	Modificado em: 15-Jun-2019

*/

	int main () {
	
		Pilha p;

		p.empilhar('A');
		p.empilhar('m');
		p.empilhar('a');
		p.empilhar('n');
		p.empilhar('d');
		p.empilhar('a');	
		
		cout << "Pilha: ";
		p.imprimePilha();
		
		p.desempilhar();
		p.desempilhar();
		
		cout << "Pilha: ";
		p.imprimePilha();
		
		cout << "" << endl;
		
		Fila f;
		
		f.enfileirar('A');
		f.enfileirar('m');
		f.enfileirar('a');
		f.enfileirar('n');
		f.enfileirar('d');
		f.enfileirar('a');
		
		cout << "Fila: ";
		f.imprimeFila();
		
		f.desenfileirar();
		f.desenfileirar();
		
		cout << "Fila: ";
		f.imprimeFila();
		
		return 0;
		
	}
