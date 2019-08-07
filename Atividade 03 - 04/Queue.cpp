/*	#include "Queue.h"
	
	Queue::Queue() 
	{
	
		init = 0;
		end = 0;
		size = 0;
		
		for (int i = 0; i < MAX; i++)
			v[i] = 0;
	
	}
	
	int Queue::enqueue (int key) 
	{
	
		if (end == MAX-1)
			return 0;
		
		size++;
		
		v[end] = key;
		end++;
				
	}
	
	int Queue::dequeue () 
	{
	
		v[init] = 0;
		init++;
		size--;
		
	}
	
	void Queue::print () 
	{
		
		for (int i = init; i < end; i++)
			cout << " " << v[i];

		puts("");
	
	}
	bool Queue::isEmpty () 
	{
		
		if (size <= 0) 
		{
			return true;
		}
		
		else 
		{
			return false;	
		}
	
	}
	*/
