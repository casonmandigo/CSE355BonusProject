#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Initialize vars:
#define LENGTH 30					// Length of the string used as a "Seed" for the generator
int n = 13;							// How many lines the program will generate

// Rules
vector <int> p1 = { 1,1,1 };		// 0
vector <int> p2 = { 1,1,0 };		// 1
vector <int> p3 = { 1,0,1 };		// 0
vector <int> p4 = { 1,0,0 };		// 1
vector <int> p5 = { 0,1,1 };		// 1
vector <int> p6 = { 0,1,0 };		// 0
vector <int> p7 = { 0,0,1 };		// 1
vector <int> p8 = { 0,0,0 };		// 0

// Predefine functions:
void outState(int *, int);
void printRules();

int main()
{
	// Print welcome message:
	cout << "Welcome to Cason Mandigo's Rule 90 Cellular Automato Generator\n";
	cout << "\n";
	
	// Print out the rules for rule 90 ceulluar Automata:
	printRules();
	cout << "\n";

	// Initialize Serpinski Traingle creating array
	int Serpinski[30];
	for (int i = 0; i < 14; i++)
	{
		Serpinski[i] = 0;
	}
	Serpinski[14] = 1;
	for (int i = 15; i < 30; i++)
	{
		Serpinski[i] = 0;
	}

	// Create State and Update state arrays
	int state[LENGTH];
	int updateState[LENGTH];

	// Initialize starting state to serpinski traingle string
	for (int i = 0; i < LENGTH; i++)
	{
		state[i] = Serpinski[i];
	}

	// Print first line (Serpinski Traingle Initial String
	cout << "\n";
	outState(state, LENGTH);

	// Loop to generate/update the State and Update State arrays then print them
	for (int i = 0; i < n; i++)
	{
		// Erarse the old state
		for (int j = 0; j < LENGTH; j++)
		{
			updateState[j] = 0;
		}

		// Create the new state
		for (int j = 1; j < LENGTH - 1; j++)
		{	
			// Create an array with the current patter (pulled from the current state)
			int f1 = state[j - 1];
			int f2 = state[j];
			int f3 = state[j + 1];

			vector <int> curPattern;
			curPattern.push_back(f1);
			curPattern.push_back(f2);
			curPattern.push_back(f3);

			// Compare the current state to the rules to set the cell's value in Update State
			if (curPattern == p1)
			{
				updateState[j] = 0;
			}
			else if (curPattern == p2)
			{
				updateState[j] = 1;
			}
			else if (curPattern == p3)
			{
				updateState[j] = 0;
			}
			else if (curPattern == p4)
			{
				updateState[j] = 1;
			}
			else if (curPattern == p5)
			{
				updateState[j] = 1;
			}
			else if (curPattern == p6)
			{
				updateState[j] = 0;
			}
			else if (curPattern == p7)
			{
				updateState[j] = 1;
			}
			else if (curPattern == p8)
			{
				updateState[j] = 0;
			}
		}

		// Update the current state
		for (int j = 0; j < LENGTH; j++)
		{
			state[j] = updateState[j];
		}

		// Print the new current state
		outState(state, LENGTH);

	}

	cout << "\n";
	cout << "Press enter to exit program: ";
	cout << "\n";

	cin.ignore();		// waits until enter has been hit
	return 0;
}

void outState(int *s, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (s[i] == 1)
		{
			cout << '$';
		}
		else if (s[i] == 0)
		{
			cout << '-';
		}
	}
	cout << "\n";
}

void printRules()
{
	cout << "The rules that define the Rule 90 Celluar Automata are as follows: \n";
	cout << "Rule 1: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p1[i];
		cout << " ";
	}
	cout << ", sets cell to: 0 \n";

	cout << "Rule 2: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p2[i];
		cout << " ";
	}
	cout << ", sets cell to: 1 \n";

	cout << "Rule 3: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p3[i];
		cout << " ";
	}
	cout << ", sets cell to: 0 \n";

	cout << "Rule 4: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p4[i];
		cout << " ";
	}
	cout << ", sets cell to: 1 \n";

	cout << "Rule 5: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p5[i];
		cout << " ";
	}
	cout << ", sets cell to: 1 \n";

	cout << "Rule 6: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p6[i];
		cout << " ";
	}
	cout << ", sets cell to: 0 \n";

	cout << "Rule 7: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p7[i];
		cout << " ";
	}
	cout << ", sets cell to: 1 \n";

	cout << "Rule 8: ";
	for (int i = 0; i < 3; i++)
	{
		cout << p8[i];
		cout << " ";
	}
	cout << ", sets cell to: 0 \n";
}