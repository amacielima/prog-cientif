#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

	double integ_ex_1 (double x)
	{
		return (4 / (1 + pow(x,2))); // integral exercicio 1
	}
	
	double integ_ex_2 (double x, double y, double z)
	{
		return (pow(z,2) + pow((sqrt(pow(x,2) + pow(y,2)) - 3), 2)); // formula toroide exercicio 2
	}
	
	bool check_area_integ_2 (double x, double y, double z)
	{
		return ((pow(z,2) + pow((sqrt(pow(x,2) + pow(y,2)) - 3), 2)) <= 1.0); // verifica se esta dentro do toroide
	}
	
	double monte_carlo_integ_ex_1 (int n)
	{
		
		double total = 0;		// variavel para acumular o valor de monte carlo pelos numeros aleatorios
		srand(time(NULL)); 		// inicializa semente para gerar valores aleatorios
		
		for (int i = 0; i < n; i++)
		{
		
			double x = rand()%100; 			// calcula aleatorio desta iteracao			
			total = total + integ_ex_1(x);  // acumula no valor total o resultado da funcao da integral sendo x o numero aleatorio
			
		}
	 
		return total / n; // retorna somatorio dividido pelo numero de amostras
	}
	
	double est_erro (double f1, double f2, int n, int v)
	{
		return (v * sqrt((f1 - f2) / n)); // multiplica o volume pela raiz da somatoria das funcoes em potencia 1 e 2 divido por n
	}
	
	double monte_carlo_integ_ex_2 (int n)
	{
		
		double total = 0;		// variavel para acumular o valor de monte carlo pelos numeros aleatorios
		srand(time(NULL)); 		// inicializa semente para gerar valores aleatorios
		int div = 0;
		
		while (div != n)        // enquanto os valores aleatorios nao entrarem na condicao do toroide a partir das n amostras
		{
		
			double x = rand()%4 + (-1); 	// valor aleatorio para x entre 1 e 4
			double y = rand()%8 + (-3);     // valor aleatorio para y entre -3 e 4
			double z = rand()%2 + (-1);		// valor aleatorio para z entre -1 e 1
					
			if(check_area_integ_2(x,y,z)) // verifica se os valores obtidos se enquadram na condicao do toroide
			{   		 
				total = total + integ_ex_2(x, y, z); // caso positivo acumula na variavel total
				div = div + 1;						 // incrementa na valor do divisor
			}
			
		}
	 
		return total / div; // retorna somatorio dividido pelo numero de amostras validas
	}
	
	int main(int argc, char** argv) 
	{
		
		// V da equacao do exercicio 1
		int a = 0;
		int b = 4;
		
		vector <int> v; // vetor com numero de amostras para experimentos
		v.push_back(10);
		v.push_back(100);
		v.push_back(1000);
		v.push_back(10000);
					
		cout << "\n\t|-----> Metodo de Monte Carlo - Exercicio 1" << endl;
		cout << " \t\tV = " << (b - a) << endl << endl; // volume do exercicio 1
		
		for (int i = 0; i < v.size(); i++)
		{

			cout << "\t\tn = " << v[i] << endl;
			
			double mc_ex1 = monte_carlo_integ_ex_1(v[i]); // calcula o somatorio da funcao pelos valores aleatorios dividido pelo numero de amostras
			
			cout << "\t\tMonte Carlo = " << (b - a) * mc_ex1 << endl; // multiplica o volume da area o valor do somatorio divido pelas amostras
				
			cout << "\t\tErro = " << est_erro(mc_ex1, pow(mc_ex1, 2), v[i], (b - a)) << endl << endl; // aplica a formula para calcular o erro de aproximacao
			
		}
		
		// variaveis do exercicio 2
		int V = (1 * 4) * (- 3 * 4) * (- 1 * 1); // limites do eixo x * limites do eixo y * limites do eixo z
		
		cout << "\n\t|-----> Metodo de Monte Carlo - Exercicio 2" << endl;
		cout << "\t\tV = " << V << endl << endl;
		
		for (int i = 0; i < v.size(); i++)
		{

			cout << "\t\tn = " << v[i] << endl;
			
			double mc_ex2 = monte_carlo_integ_ex_2(v[i]);  // calcula o somatorio da funcao pelos valores aleatorios dividido pelo numero de amostras
			
			cout << "\t\tMonte Carlo = " << V * mc_ex2 << endl; // multiplica o volume da area o valor do somatorio divido pelas amostras
				
			cout << "\t\tErro = " << est_erro(mc_ex2, pow(mc_ex2, 2), v[i], V) << endl << endl; // aplica a formula para calcular o erro de aproximacao
			
		}
	
		return 0;
		
	}
