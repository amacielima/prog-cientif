#include "BFS.h"

	BFS::BFS (Graph * g) 
	{
		this->q = new Queue<int>();		
		this->g = g;
		this->currentState = g->initialState;	
	}


	int BFS::search ()
	{
		
		try
		{
			// insere raiz do grafo na fila
			q->enqueue(currentState->id);
			
			// percorre a lista de adjacencia de acordo com os nos visitados
			for (int i = 0; i < g->v; i++)
			{
				
				for (int j = 0; j < g->list[i].size(); j++) 
				{
				
					if (g->list[i][j].isGoal() == true) 
					{
						q->enqueue(g->list[i][j].id);
						return 1;
					}
				
					if (g->list[i][j].visited == false)
					{
						g->list[i][j].visited = true;
						q->enqueue(g->list[i][j].id);
					}
				
				}
				
			}
		}
		
		catch (exception &e)
		{
			cout << "Error: " << e.what() << endl;
		}	
		
		return 1;
		
	}

