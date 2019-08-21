#include <iostream>
#include <math.h>
using namespace std;

	double integ_a (double x)
	{
		return exp(x);
	}
	
	double integ_b (double x)
	{
		return sqrt(1 - pow(x,2));
	}
	
	double integ_c (double x)
	{
		return exp(pow(-x,2));
	}
	
	double regra_retangulo (double f, double a, double b)
	{
		return (b - a) * f;
	}
	
	double regra_trapezoidal (double fa, double fb, double a, double b)
	{
		return (b - a) * ((fa + fb) / 2);
	}

	double regra_simpson (double f, double fa, double fb, double a, double b)
	{
		return ((b - a) * ((fa + (4 * f) + fb)/ 6));
	}
	
	double integ_a_ordem2 (double x)
	{
		return exp(x);
	}
	
	double integ_a_ordem4 (double x)
	{
		return exp(x);
	}
	
	double integ_b_ordem2 (double x)
	{
		return -(1 / pow((1 - pow(x,2)), 3/2));
	}
	
	double integ_b_ordem4 (double x)
	{
		return -(((12 * pow(x,2)) + 3)/(pow((1 - pow(x,2)), 7/2)));
	}
	
	double integ_c_ordem2 (double x)
	{
		return (2 * exp(pow(x,2))) * ((2 * pow(x,2)) + 1);
	}
	
	double integ_c_ordem4 (double x)
	{
		return ((4 * exp(pow(x,2))) * ((4 * pow(x,4)) + (12 * pow(x,2)) + 3));
	}
	
	double erro_aprox_regra_ret (double h, double f)
	{
		return ((pow(h,3) * f)/ 24);
	}
	
	double erro_aprox_regra_trap (double h, double f)
	{
		return -((pow(h,3) * f)/ 12);
	}
	
	double erro_aprox_regra_simp (double h, double f)
	{
		return -((pow(h,5) * f)/ 90);
	}
	
	double quad_adap_a (double a, double b, double r_simp, double erro, double max)
	{
		
		double c = (a + b) / 2; // posicao pivo
		double h = b - a;		// intervalo
		double e = (c + b) / 2; // posicao da esquerda
		double d = (a + c) / 2; // posicao da direita
		
		double fd = integ_a(d); // valor da integral na posicao da direita
		double fe = integ_a(e); // valor da integral na posicao da esquerda
		
		double fa = integ_a(a);
		double fb = integ_b(b);
		double fc = integ_c(c);
		
		double dir = (h / 12) * (fa + (4 * fd) + fc); // divide o intervalo h em duas partes: do original h/6 se torna h/6 * h/2
		double esq = (h / 12) * (fc + (4 * fe) + fb);
		
		r_simp = regra_simpson(fc, fa, fb, a, b); 	// valor obtida pela regra de simpson
		double t = dir + esq;
		
		if (max <= 0 || fabs(r_simp - t) <= 15 * erro) // se a quantidade maxima de interacoes ou erro for aproximado, retorne o resultado
		{
			return r_simp + ((r_simp - t) / 15);
		}
		
		return quad_adap_a(a, b, r_simp, erro/2, max-1);
	
	}
	
	double quad_adap_b (double a, double b, double r_simp, double erro, double max)
	{
		
		double c = (a + b) / 2; // posicao pivo
		double h = b - a;		// intervalo
		double e = (c + b) / 2; // posicao da esquerda
		double d = (a + c) / 2; // posicao da direita
		
		double fd = integ_b(d); // valor da integral na posicao da direita
		double fe = integ_b(e); // valor da integral na posicao da esquerda
		
		double fa = integ_a(a);
		double fb = integ_b(b);
		double fc = integ_c(c);
		
		double dir = (h / 12) * (fa + (4 * fd) + fc); // divide o intervalo h em duas partes: do original h/6 se torna h/6 * h/2
		double esq = (h / 12) * (fc + (4 * fe) + fb);
		
		r_simp = regra_simpson(fc, fa, fb, a, b); // valor obtida pela regra de simpson
		double t = dir + esq;
		
		if (max <= 0 || fabs(r_simp - t) <= 15 * erro) // se a quantidade maxima de interacoes ou erro for aproximado, retorne o resultado
		{
			return r_simp + ((r_simp - t) / 15);
		}
		
		return quad_adap_b(a, b, r_simp, erro/2, max-1);
	
	}
	
	double quad_adap_c (double a, double b, double r_simp, double erro, double max)
	{
		
		double c = (a + b) / 2; // posicao pivo
		double h = b - a;		// intervalo
		double e = (c + b) / 2; // posicao da esquerda
		double d = (a + c) / 2; // posicao da direita
		
		double fd = integ_c(d); // valor da integral na posicao da direita
		double fe = integ_c(e); // valor da integral na posicao da esquerda
		
		double fa = integ_a(a);
		double fb = integ_b(b);
		double fc = integ_c(c);
		
		double dir = (h / 12) * (fa + (4 * fd) + fc); // divide o intervalo h em duas partes: do original h/6 se torna h/6 * h/2
		double esq = (h / 12) * (fc + (4 * fe) + fb);
		
		r_simp = regra_simpson(fc, fa, fb, a, b); // valor obtida pela regra de simpson
		
		double t = dir + esq;
		
		if (max <= 0 || fabs(r_simp - t) <= 15 * erro) // se a quantidade maxima de interacoes ou erro for aproximado, retorne o resultado
		{
			return r_simp + ((r_simp - t) / 15);
		}
		
		return quad_adap_c(a, b, r_simp, erro/2, max-1);
	
	}
	
	int main(int argc, char** argv) 
	{
		
		double a = 0;
		double b = 1;
		
		double h = 1;
		double Xo = 0.5;
		
		double erro = 0.0000000001;
		
		cout << "\n\t |::::: INTEGRACAO NUMERICA :::::| \n" << endl;
		
		cout << "\tRegra do Ponto Medio / Retangulos - Integral A: " << regra_retangulo(integ_a((a+b)/2), a, b) << endl;
		cout << "\tRegra do Ponto Medio / Retangulos - Integral B: " << regra_retangulo(integ_b((a+b)/2), a, b) << endl;
		cout << "\tRegra do Ponto Medio / Retangulos - Integral C: " << regra_retangulo(integ_c((a+b)/2), a, b) << endl << endl;
		
		cout << "\tRegra Trapezoidal - Integral A: " << regra_trapezoidal(integ_a(a), integ_a(b), a, b) << endl;
		cout << "\tRegra Trapezoidal - Integral B: " << regra_trapezoidal(integ_b(a), integ_b(b), a, b) << endl;
		cout << "\tRegra Trapezoidal - Integral C: " << regra_trapezoidal(integ_c(a), integ_c(b), a, b) << endl << endl;
		
		cout << "\tRegra de Simpson - Integral A: " << regra_simpson(integ_a(a+b/2), integ_a(a), integ_a(b), a, b) << endl;
		cout << "\tRegra de Simpson - Integral B: " << regra_simpson(integ_b(a+b/2), integ_b(a), integ_b(b), a, b) << endl;
		cout << "\tRegra de Simpson - Integral C: " << regra_simpson(integ_c(a+b/2), integ_c(a), integ_c(b), a, b) << endl << endl;
		
		cout << "\t |:::: ERRO DE APROXIMACAO :::::| " << endl;
		cout << "\t Com h = " << h << " e Xo = " << Xo << "\n" << endl;
		
		cout << "\tRegra do Ponto Medio / Retangulos - Integral A: " << erro_aprox_regra_ret(h, integ_a_ordem2(Xo)) << endl;
		cout << "\tRegra do Ponto Medio / Retangulos - Integral B: " << erro_aprox_regra_ret(h, integ_b_ordem2(Xo)) << endl;
		cout << "\tRegra do Ponto Medio / Retangulos - Integral C: " << erro_aprox_regra_ret(h, integ_c_ordem2(Xo)) << endl << endl;
		
		cout << "\tRegra Trapezoidal - Integral A: " << erro_aprox_regra_trap(h, integ_a_ordem2(Xo)) << endl;
		cout << "\tRegra Trapezoidal - Integral B: " << erro_aprox_regra_trap(h, integ_b_ordem2(Xo))  << endl;
		cout << "\tRegra Trapezoidal - Integral C: " << erro_aprox_regra_trap(h, integ_c_ordem2(Xo))  << endl << endl;
		
		cout << "\tRegra de Simpson - Integral A: " << erro_aprox_regra_simp(h, integ_a_ordem4(Xo)) << endl;
		cout << "\tRegra de Simpson - Integral B: " << erro_aprox_regra_simp(h, integ_b_ordem4(Xo)) << endl;
		cout << "\tRegra de Simpson - Integral C: " << erro_aprox_regra_simp(h, integ_c_ordem4(Xo)) << endl << endl;
		
		cout << "\t |:::: QUADRATURA ADAPTATIVA :::::| " << endl;
		cout << "\tIntegral A: " << quad_adap_a(a, b, regra_simpson(integ_a(a+b/2), integ_a(a), integ_a(b), a, b), erro, 15) << endl;
		cout << "\tIntegral B: " << quad_adap_b(a, b, regra_simpson(integ_b(a+b/2), integ_b(a), integ_b(b), a, b), erro, 15) << endl;
		cout << "\tIntegral C: " << quad_adap_c(a, b, regra_simpson(integ_c(a+b/2), integ_c(a), integ_c(b), a, b), erro, 15) << endl << endl;
		
		return 0;
	}
