#include "Graph.h"

using namespace std;

	Graph::Graph (Node * n)
	{
		int goal[SQUARES] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
		this->initialState = n;
		this->list = new vector<Node>[Y];
		this->node_id = 0;
		this->v= Y;
		this->solution_id = -1;
	}
	
	void Graph::printInitialState()
	{
		
		for (int s = 0; s < SQUARES; s++) 
		{
			cout << initialState->v[s] << " ";	
		}
		
		cout << endl;
		
	}
	
	bool Graph::isGoal(int * squares)
	{
		
		int check = 0;
		
		for (int i = 1; i < SQUARES; i++)
		{
			if (i == squares[i-1])
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
	
	int Graph::emptySquare (int * squares) 
	{
		
		int empty = -1;
		
		for (int i = 0; i < SQUARES; i++)
		{
			if (squares[i] == 0)
				empty = i;
		}
		
		return (empty + 1);
		
	}
	
	Node * Graph::nextVertex() 
	{
		
		Node * first = NULL;
		
		bool flag = false;
		
		//cout << " n1 " << list->size() << endl;
		
		for (int i = 0; i < Y; i++)
		{
			//cout << " n2 " << list[i].size() << endl;
			
			for (int j = 0; j < list[i].size(); j++)
			{
				
				if (list[i][j].check == false && flag == false) // verifica qual o proximo no nao visitado
				{					
					
					flag = true;
					first = &list[i][j];
					//cout << "id " << first->id << endl;	

				}
				
				if (flag == true) 
				{
					//printAdjList();
					return first;	
				}
					
			}

		}
		
		//printAdjList();
		return first;
			
	}
	
	int Graph::createNodeId() 
	{
		
		node_id = node_id + 1;
		
		return (node_id);
		
	}
	
	void Graph::buildGraph()
	{
		
		Node * currentNode = initialState;	    // inicializa no atual
		int  * currentState = initialState->v;  // inicializa vetor
		
		int empty = emptySquare(currentState);  // verifica qual a peca vazia
		
		bool goal = isGoal(currentState);		// verifica se o estado inicial e o objetivo
		
		if(isGoal(currentState))
			solution_id = currentNode->id;
		
		//printAdjList();
		
		while (goal == false) 
		{

			/*
			
				Explicacoes do mecanismo de cada no segue o padrao dos comentarios
				da condicao "if (empty == 1)"
				
				Dado a posicao da peca vazia, o algoritmo troca as posicoes para cada 
				possibilidade de no a partir da posicao vazia.
				
				Cada posicao tem um numero de possibilidades subsequentes e a cada "if"
				as condicoes foram implementadas de acordo com cada situacao.
			
			*/
				
			if (empty == 1) 
			{

				/*
					
					Quando a posicao vazia = 1, ha duas possibilidades de troca de peca a partir dela.
				 	Para isso, dois nos sao criados, inicializando com o vetor de posicoes atual.
				 	Posteriormente, as posicoes dos nos sao trocadas dentro do objeto criado da classe Node.
				 	
				*/
				
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());

				na.changePosition(0,1); // troca posicao 0 com a posicao 1
				nb.changePosition(0,3); // troca posicao 0 com a posicao 3

				na.printSquares();
				nb.printSquares();
				
				// o no atual se torna o no anterior ao novo node 
				na.previous = currentNode;
				nb.previous = currentNode; 
				
				// o no atual recebe os dois novos nos criados como proximos
				currentNode->next.push_back(na); 
				currentNode->next.push_back(nb);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				
				//printAdjList();

			}
			
			if (empty == 2) 
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());
				Node nc(currentState, createNodeId());

				na.changePosition(1,0);
				nb.changePosition(1,4);
				nc.changePosition(1,2);
				
				na.printSquares();
				nb.printSquares();
				nc.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				nc.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				currentNode->next.push_back(nc);

				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				//cout<< "push back" << endl;
					
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				list[currentNode->id].push_back(nc);
				
				//printAdjList();
				
				//list[currentNode->id].check = true;
				
				//printAdjList();
			}
			
			if (empty == 3)
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());

				na.changePosition(2,1);
				nb.changePosition(2,5);

				na.printSquares();
				nb.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				
			}
			
			if (empty == 4) 
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());
				Node nc(currentState, createNodeId());

				na.changePosition(3,0);
				nb.changePosition(3,4);
				nc.changePosition(3,6);
				
				na.printSquares();
				nb.printSquares();
				nc.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				nc.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				currentNode->next.push_back(nc);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				//cout << "empty 4 current Id " << currentNode->id << endl;
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				list[currentNode->id].push_back(nc);
				
				//list[currentNode->id][0].check = true;
			}
			
			if (empty == 5)
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());
				Node nc(currentState, createNodeId());
				Node nd(currentState, createNodeId());

				na.changePosition(4,1);
				nb.changePosition(4,3);
				nc.changePosition(4,5);
				nd.changePosition(4,7);
				
				na.printSquares();
				nb.printSquares();
				nc.printSquares();
				nd.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				nc.previous = currentNode;
				nd.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				currentNode->next.push_back(nc);
				currentNode->next.push_back(nd);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				list[currentNode->id].push_back(nc);
				list[currentNode->id].push_back(nd);
			
			}
			
			if (empty == 6) 
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());
				Node nc(currentState, createNodeId());

				na.changePosition(5,2);
				nb.changePosition(5,4);
				nc.changePosition(5,8);
				
				na.printSquares();
				nb.printSquares();
				nc.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				nc.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				currentNode->next.push_back(nc);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				list[currentNode->id].push_back(nc);
				
			}
			
			if (empty == 7) 
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());

				na.changePosition(6,3);
				nb.changePosition(6,7);

				na.printSquares();
				nb.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				
			}
			
			if (empty == 8) 
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());
				Node nc(currentState, createNodeId());

				na.changePosition(7,6);
				nb.changePosition(7,4);
				nc.changePosition(7,8);
				
				na.printSquares();
				nb.printSquares();
				nc.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				nc.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				currentNode->next.push_back(nc);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				list[currentNode->id].push_back(nc);
				
			}
			
			if (empty == 9) 
			{
				Node na(currentState, createNodeId());
				Node nb(currentState, createNodeId());

				na.changePosition(8,5);
				nb.changePosition(8,7);

				na.printSquares();
				nb.printSquares();
				
				na.previous = currentNode;
				nb.previous = currentNode;
				
				currentNode->next.push_back(na);
				currentNode->next.push_back(nb);
				
				currentNode->check = true;
				//list[currentNode->id].push_back(*currentNode);
				
				list[currentNode->id].push_back(na);
				list[currentNode->id].push_back(nb);
				
			}
							
			//cout << "verif node" << endl;
			Node * n = nextVertex();
		
			currentNode = n;
			//cout << "proximo no ";
			//currentNode->printSquares();		
			currentState = n->getSquares();
			empty = emptySquare(currentState);
			
			//list[currentNode->id].push_back(*currentNode); // insere o nó a ser explorado em um novo item na lista de adjacência
			
			goal = isGoal(currentState);
			
			if(isGoal(currentState))
				solution_id = currentNode->id;
			//goal = isGoal(currentState);

					
		}
		
	}

	void Graph::printAdjList() 
	{
		
		cout << "\t :::::::::::: Lista de Adjacencia :::::::::::: " << endl;
		
		for (int i = 0; i < Y; i++)
		{
			cout << "\tNode " << i;
			
			for (int j = 0; j < list[i].size(); j++)
			{
				cout << " " << list[i][j].id;	
			}
			
			cout << endl;
			
		}
		
	}
