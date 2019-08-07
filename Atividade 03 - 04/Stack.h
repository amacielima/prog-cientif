#include <iostream>
#include <stdlib.h>

#define MAX 100

using namespace std;

#ifndef stack
#define stack

	template <class T>
	class Stack {
		
		private:
			
		T v[MAX];
		
		public:
		
		int top;
		
		Stack()
		{
				
			top = -1;
		
			int i;
		
			for(i=0; i < MAX; i++)
				v[i] = 0;
			
		}		
		
		int push (T key)
		{
		
			if (top == MAX-1)
			return 0;
			
			top++;
			v[top] = key;
			
			return 1;
	
		}	
		
		int pop ()
		{
		
			if (top == -1)
			return 0;
		
			v[top] = 0;
			top--;
			
			return 1;
			
		}
		
		void print () 
		{
		
			int i;
			
			for (i = 0; i < top + 1; i++)
				cout << " " << v[i];
		
			puts("");
			
		}
		
		bool isEmpty()
		{
			if (top == -1)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
		
		T getTop()
		{
			return v[top];
		}
		
	};

#endif
