#include "Node.h"

	Node::Node(int * state, int id)
	{
		this->id = id;
		this->previous = NULL;
		this->visited = false; // para busca bfs
		this->check = false;   // para inserir os nós do grafo
		this->found = false;   // para busca dfs
		this->cost = 0;

		// inicializa vetor com as peças de acordo com o parâmetro
		for (int s = 0; s < SQUARES; s++) 
		{
			v[s] = state[s];
			//cout << v[s] << " ";
	
		}
		
		this->h = calcHamming();
			
	}

	void Node::printSquares()
	{
		
		cout << "\t";
		
		for (int s = 0; s < SQUARES; s++) 
		{
			cout << v[s] << " ";	
		}
		
		cout << "\tid " << id  << "\t hamming: " << calcHamming()-1 << endl;
		
	}
	
	int * Node::getSquares()
	{
		return this->v;
	}
	
	void Node::changePosition(int pos_a, int pos_b)
	{
		int aux = v[pos_a];
		v[pos_a] = v[pos_b];		
		v[pos_b] = aux;
	}
	
	bool Node::isGoal()
	{
		
		int check = 0;
		
		for (int i = 1; i < SQUARES; i++)
		{
			if (i == v[i-1])
				check = check + 1;
		}
		
		if (check == 8) 
		{
			return true;	
		}
		
		else
		{
			return false;
		}
		
	}
	
	int Node::calcHamming()
	{
		
		int h = 0;
		
		for (int i = 0; i < SQUARES; i++)
		{
			if (i == 8 && v[i] != 0)
			{
				h = h + 1;
			}
			
			if (!(i+1 == v[i]))
				h = h + 1;
		}
		
		return h;
		
	}
