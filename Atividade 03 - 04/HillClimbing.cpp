#include "HillClimbing.h"

	HillClimbing::HillClimbing (Graph * g) 
	{
		this->s = new Stack<int>();
		this->q = new Queue<int>();		
		this->g = g;
		this->currentState = g->initialState;
	}
	
	int HillClimbing::search()
	{
	
		try
		{
			bool flag = false;
			bool flag_null = false;
		
			q->enqueue(0);
			sn.push(currentState);
			
			if (currentState->isGoal())
			{
				q->enqueue(currentState->id);
				return 1;
			}
	
			
			while (!flag_null)
			{
				
				currentState = sn.getTop();
						
				if (currentState->isGoal())
				{
					return 1;
				}	
				
				for (int i = 0; i < currentState->next.size(); i++) 
				{
					
					if ((i == currentState->next.size()-1) && flag == false)
					{
						flag_null = true;
						//break;
					}
					
					if ( ( currentState->next[i].calcHamming() < currentState->calcHamming() ) && flag == false)
					{
						
						q->enqueue(currentState->next[i].id);
						sn.pop();
						sn.push(&currentState->next[i]);
						
						flag = true;
						
					}					
					
				}
				
				if(!flag)
					flag_null = true;
				
				flag = false;
				
				if (flag_null)
				{
					q->print();
					cout << "\nO algoritmo HillClimbing parou a busca." << endl;
					//break;
					return 0;
				}
				
			}
			
		}
		
		catch (exception &e)
		{
			cout << "Error: " << e.what() << endl;	
		}
		
	}
