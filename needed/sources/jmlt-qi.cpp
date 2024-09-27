#include <iostream>
#include <string>
using namespace std;

int main() {
	menu:
	cout << "\n[I]nstall JMLT";
	cout << "\n[U]ninstall JMLT";
	cout << "\n[Q]uit";

	cout << "\n\nSelect operation: ";

	string operation; cin >> operation;
	if (operation == "I" || operation == "i") {
		system("clear");
		cout << "[i] Work directory created at ~/jmlt-temp\n";
		system("mkdir ~/jmlt-temp && cd ~/jmlt-temp");

		cout << "[i] Installing dependancies\n";
		system("sudo pacman -S figlet gcc wget git");
		system("wget https://github.com/MaxWasTakenYT/JMLT/raw/refs/heads/main/needed/pacmany");
		system("wget https://github.com/MaxWasTakenYT/JMLT/raw/refs/heads/main/needed/yayy");
		system("chroot +x ./pacmany && chroot +x ./yayy");
		system("sudo mv ./pacmany /usr/bin/pacmany");
		system("sudo mv ./yayy /usr/bin/yayy");

		cout << "[i] Building JMLT\n";
		system("wget https://raw.githubusercontent.com/MaxWasTakenYT/JMLT/main/JMLT.cpp && g++ -o jmlt JMLT.cpp");

		cout << "[i] Adding JMLT to PATH (using /usr/bin)\n";
		system("chmod +x ./jmlt && sudo mv ./jmlt /usr/bin/jmlt");

		cout << "[i] Cleaning up (deleting work directory)\n";
		system("rm ~/jmlt-temp/JMLT.cpp && rmdir ~/jmlt-temp");

		cout << "[i] Installated successfully\n\n";
		goto menu;
	}
	else if (operation == "U" || operation == "u") {
		system("clear");
		cout << "[i] Removing JMLT from PATH (using /usr/bin)\n";
		system("sudo rm /usr/bin/jmlt");

		cout << "[?] Also remove 'pacmany' and 'yayy': ";
		string rempy; cin >> rempy;
		if (rempy == "Y" || rempy == "y") {
			cout << "\n[i] Removing 'pacmany' and 'yayy' from PATH (using /usr/bin)";
			system("sudo rm /usr/bin/pacmany && sudo rm /usr/bin/yayy");
			cout << "\n [i] Uninstalled successfully\n\n";
			goto menu;
		}
		else {
			cout << "\n [i] Uninstalled successfully\n\n";
			goto menu;
		}
	}
	else if (operation == "Q" || operation == "q") {
		system("clear");
		return 0;
	}
}
