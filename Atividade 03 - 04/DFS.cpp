#include "DFS.h"

	DFS::DFS (Graph * g) 
	{
		this->s = new Stack<int>();
		//this->sn = new Stack<Node*>();
		this->q = new Queue<int>();		
		this->g = g;
		//this->currentState = g->initialState;
	}
	
	void DFS::initSearch()
	{
		
		/* Percorre a lista de adjacencia e aplica o dfs para cada no da grafo */
		
		q->enqueue(0);		 // coloca na fila o no inicial
		bool flag = false;
		
		for (int i = 0; i < g->v; i++)
		{
			
			for (int j = 0; j < g->list[i].size(); j++) 
			{
				try
				{
					if (search(&g->list[i][j]))
					{
						flag = true;
						break;
					}
				}
				
				catch (exception &e)
				{
					cout << "Error: " << e.what() << endl;
				}
				
			}
			
			if(flag)
				break;
			
		}
		
	}

	int DFS::search (Node * n)
	{
		bool flag = false;
		n->found = true;
		
		// insere o id na pilha de inteiro e o id na pilha com ponteiros para o no
		s->push(n->id);
		sn.push(n);
		
		// enfileira o id para imprimir o percurso da busca no final
		q->enqueue(n->id);
		
		// enquanto a fila esta vazia
		while(!s->isEmpty()) 
		{
			
			// pega o primeiro elemento da pilha de nos
			n = sn.getTop();
			
			s->pop();
			sn.pop();
			
			// verifica objetivo
			if (n->isGoal() == true) 
			{
				return 1;
			}

			// para cada no adjancente ao no atual
			for (int i = 0; i < n->next.size(); i++) 
			{
				
				// visite e enfileire os nos encontrados
				if (n->next[i].found == false)
				{
					
					s->push(n->next[i].id);
					sn.push(&n->next[i]);
					
					q->enqueue(n->next[i].id);
					//currentState->next[i].found = true;
					flag = true;
				}
			
			}

			// caso nenhum elemento nao visitado for encontrado
			if (!flag)
			{
				// desempilha no atual
				s->pop();
				sn.pop();
				
				// verifica se a lista esta vazia e sai da funcao
				if (s->isEmpty())
					return 0;
				
			}

			flag = false;
			
		}
		
		return 0;
	
	}
