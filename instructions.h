#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

void instruksionet() {														//the necessary instructions for running the program
	cout << setw(120) << setfill('-') << "-" << endl;
	cout << "INSTRUCTIONS FOR RUNNING THE PROGRAM:" << endl;
	cout << endl;
	cout << "-For inserting modules, type 'module <name> <action>'. The selected action can be: echo, delay, reverse or noop" << endl;
	cout << "-For connecting two modules, type 'connect <module_name1> <module_name2>'." << endl;
	cout << "-To process the string, type 'process <//userinput//>'." << endl;
	cout << "-For quitting, type 'quit'." << endl;
	cout << "-Type 'clear' to clear all the modules and start over!" << endl;
	cout << "P.S. The connect can only be made for 2 modules at the same time." << endl;
	cout << "Please write in all lowercase!" << endl;
	cout << setw(120) << setfill('-') << "-" << endl;
}
