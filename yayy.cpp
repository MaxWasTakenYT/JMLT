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

	cout << "welcome to \"yay-yes\" (or jm-yayy)\n";
	cout << noroot;
	cout << "package name?: ";
	string pkgName; cin >> pkgName;
	cout << "-S, -Sy or -Syu?: ";
	string pmh2d; cin >> pmh2d;
	if (pmh2d == "-S" || pmh2d == "-s") {
		cout << "installing package..";
		string pkg2inst = "yay -S " + pkgName;
		int pmyres = system(pkg2inst.c_str());
		if (pmyres == 0) { cout << "package installed successfully!"; }
		else { cout << err << endl; }
		say what;
	}
	else if (pmh2d == "-Sy" || pmh2d == "-sy") {
		cout << "installing package..";
		string pkg2inst = "sudo yay -Sy " + pkgName;
		int pmyres = system(pkg2inst.c_str());
		if (pmyres == 0) { cout << "package installed successfully!"; }
		else { cout << err << endl; }
		say what;
	}
	else if (pmh2d == "-Syu" || pmh2d == "-syu") {
		cout << "installing package..";
		string pkg2inst = "sudo yay -Syu " + pkgName;
		int pmyres = system(pkg2inst.c_str());
		if (pmyres == 0) { cout << "package installed and full system update ended successfully!"; }
		else { cout << err << endl; }
		say what;
	}
}