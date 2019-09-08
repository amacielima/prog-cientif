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
		
		double x = func_eq_a(a) / deriv_eq_a(a);
		
		cout << "Taxa de Aprendizado: " << t << endl;
		cout << "-----------------------------------------------------------" << endl;
		
		while (x >= t)
		{
			x = func_eq_a(a) / deriv_eq_a(a);
			a = a - x;
		}
		
		cout << "\tEquacao A" << "\n\tRaiz: " << a << endl;
		
		double y = func_eq_b(a) / deriv_eq_b(a);
		
		while (y >= t)
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
		
			
		#pragma omp parallel for
		for (double i = 0.1; i <= 1.0; i = i + 0.1)
		{
			const clock_t ini = clock();
			newtonRaphson(xo, i);	
			
			cout << "Tempo: " << float(clock () - ini) / CLOCKS_PER_SEC << endl;
			cout << "-----------------------------------------------------------" << endl;
					
		}	

		return 0;
	}
