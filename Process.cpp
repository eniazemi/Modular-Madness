#include <iostream>
#include<string>
#include<vector>
#include"Operations.h"
#include "Process.h"
using namespace std;

string procesi(vector<string> Operacionet, vector<string> Emrat_Moduleve, string teksti_fillestar, string emri_modulit1, vector<string> Lista_Inputeve) { //returns string processed by the first module in the connection, depending on the operation selected by the user
	string txt;
	int pozita;
	for (size_t i = 0; i < Emrat_Moduleve.size(); i++)
	{
		if (Emrat_Moduleve[i] == emri_modulit1)
			pozita = i;
	}

	for (size_t j = 0; j < Operacionet.size(); j++)
	{
		if (pozita == j) {

			if (Operacionet[j] == "echo") {
				return echo(teksti_fillestar);
			}
			else if (Operacionet[j] == "reverse") {
				return reverse(teksti_fillestar);
			}
			else if (Operacionet[j] == "delay") {
				return delay(teksti_fillestar, Lista_Inputeve);
			}
			else if (Operacionet[j] == "noop") {
				return noop(teksti_fillestar);
			}
		}
	}
}


string procesifinal(vector<string> Operacionet, vector<string> Emrat_Moduleve, string teksti_moduluar1, string emri_modulit2, vector<string> Lista_Inputeve) { //takes as input the output of the function 'procesi' and processes it again, this time for the second connected module
	int pozita;
	cout << endl;
	for (size_t i = 0; i < Emrat_Moduleve.size(); i++)
	{
		if (Emrat_Moduleve[i] == emri_modulit2) {
			pozita = i;
			break;
		}
	}
	for (size_t j = 0; j < Operacionet.size(); j++)
	{
		if (j == pozita) {
			if (Operacionet[j] == "echo") {
				return echo(teksti_moduluar1);
			}
			else if (Operacionet[j] == "reverse") {
				return reverse(teksti_moduluar1);
			}
			else if (Operacionet[j] == "delay") {
				return delay(teksti_moduluar1, Lista_Inputeve);
			}
			else if (Operacionet[j] == "noop") {
				return noop(teksti_moduluar1);
			}
		}
	}
}
