#include <iostream>
#include <cstdlib>
#include <string>
#define say return
#define what 0

using namespace std;

/*
READ, CODE CONTRIBUTORS!:
After you created the option, TEST IT! And, if it works, add a .cpp file in the 'sources' dir with the option's code.
*/

int main(int argc, char* argv[]) {
    cout << "welcome to jstmax's Linux Toolbox! (JMLT 4 short)\n\n";

    string ready4use = "now your system is ready to be \"jstmax!-used\"!";
    string err = "An error occurred. Please try again.\n";
    string withroot = "[!] remember to run as root/with root privileges!!\n\n";
    string noroot = "[!] remember to NOT run as root/with root privileges!!\n\n";

    if (argc > 1) {
        string option = argv[1];
        if (option == "-ju" || option == "--prepare-for-jstmax-use") {
            cout << withroot;
            cout << "prepare for \"jstmax!-use\"? (y/n): ";
            string prepYoN; cin >> prepYoN;
            if (prepYoN == "y" || prepYoN == "Y") {
                cout << "\npreparing for \"jstmax!-use\"..\n";
                int returnCode = system("sudo pacman -Sy --noconfirm firefox reflector tldr fastfetch");
                if (returnCode == 0) {
                    cout << "run a full system update? (y/n): ";
                    string fsuChoice; cin >> fsuChoice;
                    if (fsuChoice == "y" || fsuChoice == "Y") {
                        cout << "running a full system update..\n";
                        int fsuRes = system("sudo pacman -Syu --noconfirm");
                        if (fsuRes == 0) {
                            cout << ready4use << endl;
                        }
                        else {
                            cout << err;
                        }
                    }
                    else {
                        cout << ready4use << endl;
                    }
                }
                else {
                    cout << err;
                }
            }
            else {
                cout << "aborting..\n";
            }
        }
        else if (option == "-c" || option == "--custom-command") {
            if (argc > 2) {
                cout << "enter custom command: ";
                string customCmd;
                cin.ignore();
                getline(cin, customCmd);
                int returnCustomCmd = system(customCmd.c_str());
                if (returnCustomCmd == 0) {
                    cout << "\ncommand executed correctly!\n";
                }
                else {
                    cout << err;
                }
            }
            else {
                cout << "no command provided.\n";
            }
        }
        else if (option == "-pmy" || option == "--pacman-yes") {
            cout << withroot;
            cout << "package name?: ";
            string pkgName; cin >> pkgName;
            cout << "-S, -Sy or -Syu?: ";
            string pmh2d; cin >> pmh2d;

            string pkg2inst;
            if (pmh2d == "-S" || pmh2d == "-s") {
                pkg2inst = "sudo pacman -S " + pkgName;
            }
            else if (pmh2d == "-Sy" || pmh2d == "-sy") {
                pkg2inst = "sudo pacman -Sy " + pkgName;
            }
            else if (pmh2d == "-Syu" || pmh2d == "-syu") {
                pkg2inst = "sudo pacman -Syu " + pkgName;
            }
            else {
                cout << "unknown pacman command: " << pmh2d << endl;
                say what;
            }

            int pmyres = system(pkg2inst.c_str());
            if (pmyres == 0) {
                cout << "package operation completed successfully!\n";
            }
            else {
                cout << err;
            }
        }
        else if (option == "-yy" || option == "--yay-yes") {
            cout << noroot;
            cout << "package name?: ";
            string pkgName; cin >> pkgName;
            cout << "-S, -Sy or -Syu?: ";
            string pmh2d; cin >> pmh2d;

            string pkg2inst;
            if (pmh2d == "-S" || pmh2d == "-s") {
                pkg2inst = "yay -S " + pkgName;
            }
            else if (pmh2d == "-Sy" || pmh2d == "-sy") {
                pkg2inst = "yay -Sy " + pkgName;
            }
            else if (pmh2d == "-Syu" || pmh2d == "-syu") {
                pkg2inst = "yay -Syu " + pkgName;
            }
            else {
                cout << "unknown yay command: " << pmh2d << endl;
                say what;
            }

            int pmyres = system(pkg2inst.c_str());
            if (pmyres == 0) {
                cout << "package operation completed successfully!\n";
            }
            else {
                cout << err;
            }
        }
        else {
            cout << "every option is available on the github repo's readme.md!\n";
            cout << "unknown option.\n";
        }
    }
    else {
        cout << "No arguments provided.\n";
    }
    say what;
}
