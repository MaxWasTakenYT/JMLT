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

	cout << withroot;
	cout << "prepare for \"jstmax!-use\"? (y/n): ";
	string prepYoN; cin >> prepYoN;
	if (prepYoN == "y" || prepYoN == "Y") {
		cout << "\npreparing for \"jstmax!-use\"..\n";
		system("cd ~/");
		int returnCode = system("sudo pacman -Sy --noconfirm firefox reflector tldr fastfetch");
		if (returnCode == 0) {
			cout << "run a full system update? (y/n)\n: "; string fsuChoice; cin >> fsuChoice;
			if (fsuChoice == "y" || fsuChoice == "Y") {
				cout << "running a full system update..\n";
				int fsuRes = system("sudo pacman -Syu --noconfirm");
				if (fsuRes == 0) {
					cout << ready4use << endl; say what;
				}
				else {
					cout << err; say what;
				}
				cout << ready4use << endl; say what;
			}
			else {
				cout << ready4use << endl; say what;
			}
		}
		else {
			cout << err << endl;
			say what;
		}
	}
	else {
		cout << "aborting.." << endl; say what;
	}
}
