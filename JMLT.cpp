#include <iostream>
#include <cstdlib>
#include <string>
#define say return
#define what 0

using namespace std;

int main(int argc, char* argv[]) {
    cout << "welcome to jstmax's Linux Toolbox! (JMLT 4 short)\n";
    cout << "insert your username: "; string username; cin >> username; cout << endl;
    cout << "every option is available on the github repo's readme.md!\n\n";
    string ready4use = "now your system is ready to be \"jstmax!-used\"!";
    string err = "an error occurred, funny thing is that i don't want or have time to create a way to check logs so.. i guess \"fuck you, try again\" is the right answer this time?\n";
    string withroot = "[!] remember to run as root/with root privileges!!\n\n";
    string noroot = "[!] remember to NOT run as root/with root privileges!!\n\n";

    if (argc > 1) {
        string option = argv[1];
        if (option == "-jmuse" || option == "--prepare-for-jstmax-use") {
            cout << withroot;
            cout << "preparing for \"jstmax!-use\"..\n";
            string homePath = "cd /home/" + username;
            system(homePath.c_str());
            int returnCode = system("sudo pacman -Sy --noconfirm firefox reflector tldr fastfetch");
            if (returnCode == 0) {
                cout << "run a full system update? (y/n)\n: "; string fsuChoice; cin >> fsuChoice;
                if (fsuChoice == "y" || fsuChoice == "Y") {
                    cout << "running a full system update..\n";
                    int fsuRes = system("sudo pacman -Syu --noconfirm");
                    if (fsuRes == 0) {
                        cout << ready4use;
                    }
                    else {
                        cout << err;
                    }
                    cout << ready4use;
                }
                else {
                    cout << ready4use;
                }
            }
            else {
                cout << err;
            }
        }

        else if (argc > 2 && (string(argv[2]) == "-cmd" || string(argv[2]) == "--custom-command")) {
            cout << "enter custom command: ";
            string customCmd;
            cin >> customCmd;
            int returnCustomCmd = system(customCmd.c_str());
            if (returnCustomCmd == 0) {
                cout << "\ncommand executed correctly!\n";
            }
            else {
                cout << err;
            }
        }

        else if (argc > 3 && (string(argv[3]) == "-pmy" || string(argv[3]) == "--pacman-yes")) {
            cout << "welcome to \"pacman-yes\" (or jm-pacmany)\n";
            cout << withroot;
            cout << "package name?: ";
            string pkgName; cin >> pkgName;
            cout << "-S, -Sy or -Syu?: ";
            string pmh2d; cin >> pmh2d;
            if (pmh2d == "-S" || pmh2d == "-s") {
                cout << "installing package..";
                string pkg2inst = "sudo pacman -S " + pkgName;
                int pmyres = system(pkg2inst.c_str());
                if (pmyres == 0) { cout << "package installed successfully!"; }
                else { cout << err; }
            }
            else if (pmh2d == "-Sy" || pmh2d == "-sy") {
                cout << "installing package..";
                string pkg2inst = "sudo pacman -Sy " + pkgName;
                int pmyres = system(pkg2inst.c_str());
                if (pmyres == 0) { cout << "package installed successfully!"; }
                else { cout << err; }
            }
            else if (pmh2d == "-Syu" || pmh2d == "-syu") {
                cout << "installing package..";
                string pkg2inst = "sudo pacman -Syu " + pkgName;
                int pmyres = system(pkg2inst.c_str());
                if (pmyres == 0) { cout << "package installed and full system update ended successfully!"; }
                else { cout << err; }
            }
        }
        else if (argc > 4 && (string(argv[4]) == "-yy" || string(argv[3]) == "--yay-yes")) {
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
                else { cout << err; }
            }
            else if (pmh2d == "-Sy" || pmh2d == "-sy") {
                cout << "installing package..";
                string pkg2inst = "sudo yay -Sy " + pkgName;
                int pmyres = system(pkg2inst.c_str());
                if (pmyres == 0) { cout << "package installed successfully!"; }
                else { cout << err; }
            }
            else if (pmh2d == "-Syu" || pmh2d == "-syu") {
                cout << "installing package..";
                string pkg2inst = "sudo yay -Syu " + pkgName;
                int pmyres = system(pkg2inst.c_str());
                if (pmyres == 0) { cout << "package installed and full system update ended successfully!"; }
                else { cout << err; }
            }
        }

        else {
            cout << "unknown option: " << option << "check github for available options.\n";
        }
    }
    say what;
}
