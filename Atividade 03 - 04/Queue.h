#include <iostream>
#include <stdlib.h>

#define MAX 100

using namespace std;

#ifndef queue 
#define queue

	template <class T>
	class Queue {
		
		private:
			
		int init;
		int end;
		
		public:
		
		T v[MAX];
		int size;
		
		Queue()
		{
			init = 0;
			end = 0;
			size = 0;
			
			for (int i = 0; i < MAX; i++)
				v[i] = 0;
		}
		
		int enqueue (T key)
		{
			if (end == MAX-1)
				return 0;
			
			size++;
			
			v[end] = key;
			end++;		
		}
			
		int dequeue ()
		{
			v[init] = 0;
			init++;
			size--;
		}	
		
		void print ()
		{
			for (int i = init; i < end; i++)
				cout << " " << v[i];
	
			puts("");
		}
		
		bool isEmpty()
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
		
	};

#endif
