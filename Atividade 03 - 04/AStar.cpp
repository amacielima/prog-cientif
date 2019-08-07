#include "AStar.h"

	AStar::AStar (Graph * g) 
	{
		this->q = new Queue<int>();		
		this->g = g;
		this->currentState = g->initialState;
	}
	
	int AStar::search()
	{
		try
		{
			
			currentState->cost = (g->solution_id - currentState->id) + currentState->calcHamming();
			
			bool f = false;
			// insere o no atual na fila OPEN
			open.enqueue(currentState);
	
			// adiciona o no atual na fila do caminho
			q->enqueue(currentState->id);
			
			// enquanto OPEN nao esta vazio
			while(!open.isEmpty())
			{
				
				// encontra qual o no na open list com o menor custo
				for (int f = 0; f < open.size; f++)
				{
					
					if (open.v[f]->cost <= currentState->cost)
					{
						currentState = open.v[f];
					}
							
				}
				
				// verifica se e o objetivo
				if (currentState->isGoal())
				{
					return 1;
				}
				
				// remove no atual do OPEN
				open.dequeue();
				open.size = open.size - 1;
				
				// adiciona no CLOSED
				closed.enqueue(currentState);
				
				// para cada no sucessor
				for (int i = 0; i < currentState->next.size(); i++) 
				{
					Node * n_open = NULL;
					Node * n_closed = NULL;
					
					// verifica se o no sucessor i esta na lista CLOSE
					for (int f = 0; f < closed.size; f++)
					{
						
						if (closed.v[f]->id == currentState->next[i].id)
						{
							n_closed = closed.v[f];
						}
								
					}
					
					// se nao estiver, continua a busca
					if(!n_closed)
						continue;
						
					// verifica se o no sucessor i esta na lista OPEN
					for (int f = 0; f < open.size; f++)
					{
						
						if (open.v[f]->id == currentState->next[i].id)
						{
							n_open = open.v[f];
						}
								
					}
					
					currentState->next[i].cost = (g->solution_id - currentState->next[i].id) + currentState->next[i].calcHamming();
										
					// se nao estiver, coloque em OPEN
					if (!n_open)
					{
						open.enqueue(&currentState->next[i]);	
					}
					
					// caso o custo for menor, construa o caminho
					else if (currentState->cost < (g->solution_id - currentState->next[i].id))
					{
						currentState->next[i].previous = currentState;
					}

					// f(n) = g(n) + h(n)
					// o custo do no atual é a diferença entre a distância entre o nó atual e (i) + a diferença entre o atual e o objetivo
					//currentState->next[i].cost = (currentState->next[i].id - currentState->id) + (g->solution_id - currentState->next[i].id);
					/*
					Node * n_open = NULL;
				
					// verifica se o no sucessor i esta na lista OPEN
					for (int f = 0; f < open.size; f++)
					{
						
						if (open.v[f]->id == currentState->next[i].id)
						{
							n_open = open.v[f];
						}
								
					}
					
					// se o no atual for melhor em custo do que o encontrado
					if (n_open)
					{
						if (currentState->cost < n_open->cost)
							continue;
							
						else
							break;	
					}
					
					Node * n_closed = NULL;
					
					// verifica se o no sucessor i esta na lista CLOSE
					for (int f = 0; f < closed.size; f++)
					{
						
						if (closed.v[f]->id == currentState->next[i].id)
						{
							n_closed = closed.v[f];
						}
								
					}
					
					// se o no atual for melhor em custo do que o encontrado
					if (n_closed)
					{
						if (currentState->cost < n_closed->cost)
							continue;
						
						else
							break;
					}
					*/
					/*
					// remove node da lista open
					for (int f = 0; f < open.size; f++)
					{
						
						if (open.v[f]->id == currentState->id)
						{
							open.v[f] = 0;
							open.size = open.size - 1;
						}
								
					}
					*/
					/*
					// remove node da lista closed
					for (int f = 0; f < closed.size; f++)
					{
						
						if (closed.v[f]->id == currentState->next[i].id)
						{
							closed.v[f] = 0;
							closed.size = closed.size - 1;
						}
								
					}
					*/
					//currentState->next[i].previous = currentState;

					// adiciona no ao open
					//open.enqueue(&currentState->next[i]);
					//q->enqueue(currentState->next[i].id);
					//q->print();
					
					cout << "open ";
					open.print();
		
					cout << "close ";
					closed.print();
				
				}

				// adiciona no atual ao closed
				//closed.enqueue(currentState);
				
				//cout << "open ";
				//open.print();
		
				//cout << "close ";
				//closed.print();
				
			}
			
			//q->enqueue(currentState->id);
				
		}
		
		catch(exception &e)
		{
			cout << "Error: " << e.what() << endl;	
		}
		
		/*
		for (int i = 0; i < g->v; i++)
		{
			
			for (int j = 0; j < g->list[i].size(); j++)
			{
				Node p = g->list[i][j];
				q->enqueue(p.previous->id);	
			}
			
			cout << endl;
			
		}
		*/		
	}
