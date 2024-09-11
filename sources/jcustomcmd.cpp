#include <iostream>
#include <cstdlib>
#include <string>
#define say return
#define what 0

using namespace std;

int main() {
	string ready4use = "now your system is ready to be \"jstmax!-used\"!";
	string err = "an error occurred, funny thing is that i don't want or have time to create a way to check logs so.. i guess \"fuck you, try again\" is the right answer this time?\n";
	string withroot = "[!] remember to run as root/with root privileges!!\n\n";
	string noroot = "[!] remember to NOT run as root/with root privileges!!\n\n";

	cout << "enter custom command: ";
	string customCmd; cin >> customCmd;
	int returnCustomCmd = system(customCmd.c_str());
	if (returnCustomCmd == 0) {
		cout << "\ncommand executed correctly!\n";
		say what;
	}
	else {
		cout << err << endl; say what;
	}
}