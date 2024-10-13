#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string menu() {
	system("figlet JMLT");
    cout << "\nRunning version T7b!";
    cout << "\n\nMain menu;";
    cout << "\n[j] Prepare for \"jstmax! use\"";
    cout << "\n[c] Enter a custom command";
    cout << "\n[p] Runs pacmany";
    cout << "\n[y] Runs yayy";
    cout << "\n[q] Quits JMLT";
    cout << "\n\nEnter a selection: ";
    string menuSel;
	cin >> menuSel;
	return menuSel;
}

int main() {
	menu();
    system("clear"); // Clears the screen for good measure
	
	string menuSel = menu(); // Getting input from user	for menu selection
	// Declaring variables (to get input inside the switch)
	string juA; string jccmd;
	switch (menuSel[0]) {
		case 'j':
			system("clear");
        	system("figlet \"JM-Use\"");
        	cout << "\nContinue?\n";
        	cin >> juA;
        	if (juA == "y" || juA == "Y") {
            system("sudo pacman -Syu --noconfirm figlet tldr fish reflector fastfetch lolcat");
            // TODO: Add packages with yay (e.g. rustdesk)
			}
			break;
		case 'c':
		// Probably gonna remove this, pretty useless and bad overall for security
			system("clear");
        	system("figlet \"jC.CMD\"");
        	cout << "~> ";
        	getline(cin, jccmd);
        	system(jccmd.c_str());
			break;
		case 'p':
		// Exits JMLT and runs pacmany
			system("clear");
        	system("pacmany"); 
        	return 0;
			break;
		case 'y':
		// Exits JMLT and runs yayy
			system("clear");
        	system("yayy"); 
        	return 0;
			break;
		case 'q':
		// Exits JMLT
			return 0;
			break;
		default:
		// Goes to menu() if user enters an invalid input
        	system("clear");
        	cout << "Unknown option, try again.\n"; 
        	main();
			break;
	}
}
