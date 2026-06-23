//Name: Chew Chiu Xian
//Matric Number: A23CS0061
//Test2Q2

////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 2
//// Name: Chew Chiu Xian
//// Matric No: A23CS0061
//// Date / Day: 4/1/2024
///////////////////////////////////////////////////////////////////////

// Task 7. Directives, library, header, etc.
#include <iostream>
#include <iomanip>
using namespace std;

// Task 6. Function prototypes
double calculateLateFees(int);
void displayMenu();
void displayLibraryInfo();
void getUserInput(int&);

// Task 1. Function calculateLateFees
double calculateLateFees(int day) {
	double fees;
	if (day <= 7) {
		fees = day * 0.5;
	}
	else if (day > 7 && day <= 14) {
		fees = (7 * 0.5) + ((day - 7) * 1.0);
	}
	else if (day > 14) {
		fees = (7 * 0.5) + (7 * 1.0) + ((day - 14) * 2.0);
	}
	return fees;
}

// Task 2. Function displayMenu
void displayMenu() {
	cout << "1. Calculate Late Fees" << endl;
	cout << "2. Display Library Information" << endl;
	cout << "3. Quit\n";
}

// Task 3. Function displayLibraryInfo
void displayLibraryInfo() {
	cout << "************ Library Information ************\n";
	cout << "Library Name: UTM Library\n";
	cout << "Address: Skudai, Johor" << endl;
	cout << "Contact: (123) 456 7890" << endl;
}

// Task 4. Function getUserInput with reference parameter
void getUserInput(int& day) {
	cout << "Enter the number of days the book is overdue: ";
	cin >> day;
}

// Task 5. Main function
int main() {
	int day = 0, choice;
	double latefee;

	do {
		cout << "************ Library Book Checkout System ************" << endl;
		displayMenu(); 
		cout << "Enter your choice (1-3): ";
		cin >> choice;
		
		switch (choice) {

		case 1: getUserInput(day);
			latefee = calculateLateFees(day);
			cout << "Late fees: RM" << fixed << setprecision(2) << latefee << endl;
			break;

		case 2: displayLibraryInfo();
			break;

		case 3: break;

		default: cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
			break;

		}

	} while (choice != 3); 

	cout << "Exiting the program. Thank you!" << endl;
}
