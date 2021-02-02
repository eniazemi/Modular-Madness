#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "instructions.h"
#include "Operations.h"
#include "Process.h"
using namespace std;


int main()
{

string komanda, lloji_komandes, emri_komandes, operacioni, emri_modulit1, emri_modulit2, teksti_fillestar, teksti_moduluar1, teksti_final;
vector<string> Operacionet, Emrat_Moduleve, Lista_Teksteve, Lista_Inputeve;
int perseritja = 0;

instruksionet();

while (komanda.compare("quit") != 0) {									//to make the program continue until 'quit' is typed
	getline(cin, komanda);										//to get the full line written by the user

	int nr_simobleve_te_komandes = numri_simboleve(komanda);		//to count the symbols of the first word given by the user
	lloji_komandes = komanda.substr(0, nr_simobleve_te_komandes);		//to select only the first given word


	if (lloji_komandes.compare("module") == 0) {				// when the first given word is 'module', the following words are <module name> and <operation>
		string emri = komanda.erase(0, nr_simobleve_te_komandes + 1);	//these lines of code take the module name given by the user and store it in the vector 'Emrat_Moduleve'
		int nr_simboleve_te_emrit = numri_simboleve(emri);
		emri_komandes = emri.substr(0, nr_simboleve_te_emrit);
		Emrat_Moduleve.push_back(emri_komandes);

		string funksioni = emri.erase(0, nr_simboleve_te_emrit + 1);	//these lines of code add the given operation to the vector 'Operacionet'
		int nr_simboleve_te_operacionit = numri_simboleve(funksioni);
		operacioni = funksioni.substr(0, nr_simboleve_te_operacionit);
		Operacionet.push_back(operacioni);

	}

	else if (lloji_komandes.compare("connect") == 0) {				//when the first word is 'connect', a connection between two previously declared modules is being made. The two following words are both module names
		string emrat = komanda.erase(0, nr_simobleve_te_komandes + 1);

		int nr_simboleve_te_modulit1 = numri_simboleve(emrat);
		emri_modulit1 = emrat.substr(0, nr_simboleve_te_modulit1);		//to get <module1 name>

		string emri = emrat.erase(0, nr_simboleve_te_modulit1 + 1);
		int nr_simboleve_te_modulit2 = numri_simboleve(emri);
		emri_modulit2 = emri.substr(0, nr_simboleve_te_modulit2);		//to get <module2 name>
	}

	else if (lloji_komandes.compare("process") == 0) {					//if the first given word is 'process', the string following it should be processed
		teksti_fillestar = komanda.erase(0, nr_simobleve_te_komandes + 1);
		Lista_Inputeve.push_back(teksti_fillestar);					//stores input strings in the vector 'Lista_Inputeve'

		teksti_moduluar1 = procesi(Operacionet, Emrat_Moduleve, teksti_fillestar, emri_modulit1, Lista_Inputeve);			//processes the string into the first connected module
		teksti_final = procesifinal(Operacionet, Emrat_Moduleve, teksti_moduluar1, emri_modulit2, Lista_Inputeve);			//processes the string one more time into the second module
		Lista_Teksteve.push_back(teksti_final);						//stores the output strings
		if (perseritja < 16) {								//limits the number of output (processed) strings to 16 times
			for (size_t i = 0; i < Lista_Teksteve.size(); i++) {
				cout << Lista_Teksteve[i] << " ";
				perseritja++;
			}
			cout << endl;
		}
		else {												//when the 16 times are reached
			cout << "Maximum capacity has been reached. Type 'clear' to start over :(" << endl;

		}
		cout << endl;
	}

	else if (lloji_komandes.compare("clear") == 0) {		//starts the program over without restarting
		Operacionet.clear();
		Emrat_Moduleve.clear();
		Lista_Teksteve.clear();
		perseritja = 0;

	}
}

return 0;
}
