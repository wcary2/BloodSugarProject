#include <iostream>
#include <string>
#include <iomanip>
#include "LList.h"
#include "Week.h"
#include <regex>


using namespace std;
int main() {
	bool full = false;
	int currentWeek = 1;
	int weekIndex = 0;
	bool multi = false;
	

	Week weeks[2];

	
	do {
		cout << endl <<  "Week " << weekIndex + 1 << " Day " << weeks[weekIndex].getDay() << endl;
		cout << "Please enter bloodsugar or command ('h' OR 'help' for help): " << endl;
		string command = "";
		cin >> command;
		
		if (command == "help" || command == "h") {
			cout << endl << endl
				<< "'N' or 'Next' for next day'" << endl
				<< "'D' or 'Day' for summary of the current day" << endl
				<< "'W' or 'Week' for Summary of current week" << endl
				<< "Or enter number for your blood sugar to record it" << endl
				<< endl;
			continue;
		}
		if (command == "Next" || command == "N") {
			if (weeks[weekIndex].nextDay()) {
				weekIndex++;
				continue;
			}
			else {
				continue;
			}
		}

		if (command == "Day" || command == "D") {
			weeks[weekIndex].printDay();
			weeks[weekIndex].print();
			continue;
		}
		if (command == "Week" || command == "W") {
			weeks[weekIndex].print();
			weekIndex++;
			continue;
		}
		
		try {
			float entry = stof(command);
			if (entry > 0)
				if (entry == INFINITY) {
					weeks[weekIndex].nextEntry(FLT_MAX);
				}
				weeks[weekIndex].nextEntry(entry);
		}
		catch(exception &e){
			cerr << "Please enter a valid command" << endl << endl;
		}
	} while (weekIndex <= 1);
	cout << "SPACE FULL" << endl;
	cin >> currentWeek;
}