/*
#include "Stack.h"
using namespace std;

	template <class T>
	Stack<T>::Stack () 
	{
			
		top = -1;
	
		int i;
	
		for(i=0; i < MAX; i++)
			v[i] = 0;
		
	}
	
	template <class T>
	int Stack<T>::push (T key) 
	{
	
		if (top == MAX-1)
		return 0;
		
		top++;
		v[top] = key;
		
		return 1;

	}
	
	template <class T>	
	int Stack<T>::pop () 
	{
	
		if (top == -1)
		return 0;
	
		v[top] = 0;
		top--;
		
		return 1;
		
	}
	
	template <class T>	
	void Stack<T>::print () 
	{
	
		int i;
		
		for (i = 0; i < top + 1; i++)
			cout << " " << v[i];
	
		puts("");
		
	}

	template <class T>	
	bool Stack<T>::isEmpty() 
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
	*/
	

