#include<string>
#include<vector>
#include "Operations.h"
using namespace std;

int numri_simboleve(string komanda) { //counts the number of characters in a word (stops counting when an 'empty space' appears)
	int rez = 0;
	for (size_t i = 0; i < komanda.length(); i++) {
		if (komanda[i] != ' ')
			rez++;
		else
			break;
	}
	return rez;
}

string echo(string str) { //doubles the given string
	return str + str;
}

string reverse(string str) { //reverses the given string
	int nr_simboleve_tekstit = numri_simboleve(str);
	reverse(str.begin(), str.end());
	return str;
}

string delay(string str, vector<string> Lista_Inputeve) { //returns the previous input string given by the user (the initial output is 'hello')

	for (size_t i = 0; i < Lista_Inputeve.size(); i++) {
		if (Lista_Inputeve.size() == 1) {
			return "hello";
		}
		else if (Lista_Inputeve[i] == str || Lista_Inputeve[i] == reverse(str) || Lista_Inputeve[i] == str.substr(0, str.length() / 2)) {
			return Lista_Inputeve[i - 1];
		}
	}
}

string noop(string noop) {								//returns the given string without processing it, is necessary to connect the modules
	return noop;
}
