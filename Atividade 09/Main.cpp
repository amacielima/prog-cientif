#include <iostream>
#include <ctime>
#include <omp.h>
using namespace std;

	double func_eq_a (double x) // equacao a - original
	{
		return x * x;
	}
	
	double func_eq_b (double x) // equacao b - original
	{
		return (x * x * x) - ( 2 * (x * x)) + 2;
	}
	
	double deriv_eq_a (double x) // equacao a - derivada
	{
		return (2 * x);
	}
	
	double deriv_eq_b (double x) // equacao b - derivada
	{
		return ((3 * (x * x)) - 4 * x);
	}
	
	void newtonRaphson (double a, double t)
	{
		double b = a; // copia do valor a para o segundo calculo
		
		double x = func_eq_a(a) / deriv_eq_a(a); // funcao original / funcao derivada
		
		cout << "Taxa de Aprendizado: " << t << endl;
		cout << "-----------------------------------------------------------" << endl;
		
		while (x >= t) // enquanto x nao for maior ou igual a taxa de aprendizado
		{
			x = func_eq_a(a) / deriv_eq_a(a);
			a = a - x;
		}
		
		cout << "\tEquacao A" << "\n\tRaiz: " << a << endl;
		
		double y = func_eq_b(a) / deriv_eq_b(a); // funcao original / funcao derivada
		
		while (y >= t) // enquanto x nao for maior ou igual a taxa de aprendizado
		{
			y = func_eq_b(a) / deriv_eq_b(a);
			b = b - y;
		}
		
		cout << "\n\tEquacao B" << "\n\tRaiz: " << b << endl;
		
		cout << "-----------------------------------------------------------" << endl;
		
	}

	int main(int argc, char** argv) 
	{
		
		double xo = 2;
		
		cout << "-----------------------------------------------------------" << endl;
		cout << ":::::::::::::::::::::: Newton-Raphson :::::::::::::::::::::" << endl;
		cout << "-----------------------------------------------------------" << endl;
		
		// paraleliza a execucao do for pelo OpenMP
		#pragma omp parallel for
		for (double i = 0.1; i <= 1.0; i = i + 0.1)
		{
			const clock_t ini = clock(); // contabiliza o inicio da iteracao
			
			newtonRaphson(xo, i);	// executa o metodo de Newton-Raphson
			
			cout << "Tempo: " << float(clock () - ini) / CLOCKS_PER_SEC << endl; // contabiliza o tempo de execucao da iteracao
			cout << "-----------------------------------------------------------" << endl;
					
		}

		return 0;
	}
