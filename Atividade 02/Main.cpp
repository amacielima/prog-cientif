#include <iostream>

#include "No.h"
#include "ListaEncadeada.h"
#include "Fila.h"
#include "Pilha.h"

using namespace std;


	int main () {
	
		Pilha p;
		
		cout << "\n	Pilha: ";
		p.inserir(1);
		p.inserir(3);
		p.inserir(5);
		p.inserir(7);
		p.inserir(9);
		
		p.imprimirLista();
		
		cout << "	Primeiro elemento: " << p.primeiro->valor << endl;
		cout << "	Ultimo elemento: " << p.ultimo->valor << endl << endl;
	
		p.remover();
		p.remover();
				
		cout << "	Pilha: ";
		p.imprimirLista();
		
		cout << "	Primeiro elemento: " << p.primeiro->valor << endl;
		cout << "	Ultimo elemento: " << p.ultimo->valor << endl;

		puts("-----------------------------------------------------");

		Fila f;
		
		cout << "\n	Fila: ";
		f.inserir(0);
		f.inserir(2);
		f.inserir(4);
		f.inserir(6);
		f.inserir(8);
		
		f.imprimirLista();
		
		cout << "	Primeiro elemento: " << f.primeiro->valor << endl;
		cout << "	Ultimo elemento: " << f.ultimo->valor << endl << endl;
	
		f.remover();
		f.remover();
		f.remover();
				
		cout << "	Fila: ";
		f.imprimirLista();
		
		cout << "	Primeiro elemento: " << f.primeiro->valor << endl;
		cout << "	Ultimo elemento: " << f.ultimo->valor << endl;
		
		return 0;
		
	}
