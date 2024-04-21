/* 
* Daniel Buck
* CS-210
* March 19, 2024
*/

#include <iostream>
#include <iomanip>
using namespace std;

void displayTime(int hours, int minutes, int seconds);

//declare variables
int hours;
int minutes;
int seconds;
int choice;

int setHours() {
	//Prompt user to enter the hour of the day
	cout << "Enter Hours: ";
	cin >> hours;
	//Error checking to make sure hours are between 0-23
	while ((hours < 0) || (hours > 23)) {
		cout << "Invalid Entry. Enter Hours: ";
		cin >> hours;
	}
	return hours;
}

int setMinutes() {
	//Prompt user to enter minutes
	cout << "Enter Minutes: ";
	cin >> minutes;
	//Error checking to make sure minutes are between 0-59
	while ((minutes < 0) || (minutes > 59)) {
		cout << "Invalid Entry. Enter Minutes: ";
		cin >> minutes;
	}
	return minutes;
}

int setSeconds() {
	//Prompt user to enter the seconds
	cout << "Enter Seconds: ";
	cin >> seconds;
	//Error checking to make sure seconds are between 0-59
	while ((seconds < 0) || (seconds > 59)) {
		cout << "Invalid Entry. Enter Seconds: ";
		cin >> seconds;	
	}
	return seconds;
}

//Based on the users choice, modify the current time or exit the program
void modifyTime(int choice) {
	switch (choice) {
	case 1:
		if (hours < 23) {             //Hours cannot be greater than 23(11PM)
			hours = hours + 1;
		}
		else if (hours == 23) {
			hours = 0;
		}
		break;

	case 2:
		if (minutes < 59) {           //Minutes cannot be greater than 59
			minutes = minutes + 1;
		}
		else if (minutes == 59) {
			minutes = 0;
			hours = hours + 1;
			if (hours == 24) {
				hours = 0;
			}
		}
		break;

	case 3:
		if (seconds <59) {            //Seconds cannot be greater than 59
			seconds = seconds + 1; 
		}
		else if (seconds == 59) {
			seconds = 0;
			minutes = minutes + 1;
			if (minutes == 60) {
				minutes = 0;
				hours = hours + 1;
				if (hours == 24) {
					hours = 0;
				}
			}
		}
		break;
	}
	displayTime(hours, minutes, seconds);
}

//Display the options menu to the user
void displayMenu() {
	int menuChoice;
	bool quit = false;
	while (quit == false) {
		cout << setfill('*') << setw(26) << "" << endl;
		cout << setfill(' ') << setw(25) << left << "* 1 - Add One Hour" << '*' << endl;
		cout << setfill(' ') << setw(25) << left << "* 2 - Add One Minute" << '*' << endl;
		cout << setfill(' ') << setw(25) << left << "* 3 - Add One Second" << '*' << endl;
		cout << setfill(' ') << setw(25) << left << "* 4 - Exit Program" << '*' << endl;
		cout << setfill('*') << setw(26) << "" << endl;
		cout << endl;
		cout << "Enter Choice: ";
		cin >> menuChoice;

		if (menuChoice == 4) {
			quit = true;
		}

		modifyTime(menuChoice);
	}
}

//Display both clocks to the user
void displayTime(int hours, int minutes, int seconds) {
	//Line 1
	cout << setfill('*');
	cout << setw(26) << left << "" << "    ";
	cout << setw(26) << right << "" << endl;
	
	//Line 2
	cout << setfill(' ');
	cout << setw(7) << left << '*' << "12-Hour Clock";
	cout << setw(6) << right << '*';
	cout << setw(5) << right << '*';
	cout << setw(19) << right << "24-Hour Clock";
	cout << setw(6) << right << '*' << endl;

	//Line 3: 12-Hour Clock
	cout << setw(7) << left << '*';

	if (hours == 0) {
		cout << right << setfill('0') << setw(2) << "12:" << setw(2) << minutes << ':' << setw(2) << seconds << " A M";            //If hour is 12AM
	}
	else if (hours < 12) {
		cout << right << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes << ':' << setw(2) << seconds << " A M";     //If hour is AM but not 12
	}
	else if (hours == 12) {
		cout << right << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes << ':' << setw(2) << seconds << " P M";     //If hour is 12PM
	}
	else {
		cout << right << setfill('0') << setw(2) << hours - 12 << ':' << setw(2) << minutes << ':' << setw(2) << seconds << " P M";//If hour is PM but not 12
	}
	//Line 3: 24-Hour Clock
	cout << setfill(' ');
	cout << setw(7) << right << '*' << "    ";
	cout << setw(9) << left << '*';
	cout << setw(13) << right << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes << ':' << setw(2) << seconds;
	cout << setfill(' ');
	cout << setw(9) << right << '*' << endl;

	//Line 4
	cout << setfill('*');
	cout << setw(26) << left << "" << "    ";
	cout << setw(26) << right << "" << endl;
}

//Consolidated main function which gives a clear overview of the overall program function
int main() {
	setHours();
	setMinutes();
	setSeconds();
	displayTime(hours, minutes, seconds);
	displayMenu();
}
