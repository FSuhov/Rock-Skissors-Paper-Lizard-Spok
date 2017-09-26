#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

class WrongIndex : public std::runtime_error 
{
public:
	WrongIndex(const std::string& message) : std::runtime_error(message) {}
};

class MyArray
{
	int* array; 
	int capacity;	
public:
	MyArray() 
	{
		capacity = 100; 
		array = new int[capacity]();		
	}
	~MyArray() { delete[]array; capacity = 0; } 

	int& operator[](int idx) 
	{
		if (idx >= capacity || idx < 0) {throw WrongIndex("I did not find it");} 
		return array[idx];		
	}

	const int operator[](const int idx) const 
	{
		if (idx >= capacity || idx < 0) { throw WrongIndex("I did not find it"); }
		return array[idx];
	}
	
	int getCapacity() { return capacity; } 
};


int main()
{
	MyArray X; 	
	MyArray Y; 
		
	for (int i = 0; i < 100; i++) Y[i] = i; 

	bool run = true; 
	while (run) 
	{
		int a, b; 
		cout << "Input an index and a value [Q to quit]: ";
		if (scanf("%d", &a) && scanf("%d", &b))  
		{
			try { X[a] = b; } 
			catch (WrongIndex errorX) {} 
			try { Y[a] = -1; } 
			catch (WrongIndex errorX) {}
		}		
		else 
		{
			char n;
			do {
				n = getchar();
				if (n == 'q' || n == 'Q') run = false;
			} while (n != '\n');
		}		
	}	

	int counter = 0; 
	for (int i = 0; i < 100; i++) if (Y[i] == -1) counter++;
	cout << "You stored this many values: " << counter << endl;
	cout << "The index-value pairs are: " << endl;
	for (int i = 0; i < 100; i++) 
	{
		if (Y[i] == -1) cout << i << " => " << X[i] << endl;
	}

	run = true; 
	do 
	{
		char choice[255]; 
		int n; 
		cout << "Input an index for me to look up [Q to quit]: ";
		cin >> choice;
		if (choice[0] == 'Q' || choice[0] == 'q') {	run = false; }
		else
		{
			n = atoi(choice);			
			try 
			{
				if (X[n]) cout << "Found it - the value stored at " << n << " is " << X[n] << endl;
				else cout << "I did not find it" << endl;
			}
			catch (WrongIndex errorX) { cout << errorX.what() << endl; }			
		}
	} while (run);
	
	return 0;
}