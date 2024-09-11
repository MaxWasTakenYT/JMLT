#include <iostream>
#include <cstdlib>
#include <string>
#define say return
#define what 0

using namespace std;

/*
READ ME! FOR CODE CONTRIBUTORS:
To add a new option, you'll need to create a new option string too, here's an example;
else if (argc > 5) {
    string optioneo = argv[5];
    if (optionyy == "-eo" || optionyy == "--example-option") {
        // And here you'll create the actual code
    }
Note: After you created the option, TEST IT! And, if it works, then add a .cpp file in the 'sources' dir with the option's code
                                                                    then create the pull request as usual and wait for a merge.
*/

int main(int argc, char* argv[]) {
    cout << "welcome to jstmax's Linux Toolbox! (JMLT 4 short)\n\n";

    string ready4use = "now your system is ready to be \"jstmax!-used\"!";
    string err = "an error occurred, funny thing is that i don't want or have time to create a way to check logs so.. i guess \"fuck you, try again\" is the right answer this time?\n";
    string withroot = "[!] remember to run as root/with root privileges!!\n\n";
    string noroot = "[!] remember to NOT run as root/with root privileges!!\n\n";

    if (argc > 1) {
        string optionju = argv[1];
        if (optionju == "-ju" || optionju == "--prepare-for-jstmax-use") {
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
            else if (argc > 2) {
                string optionc = argv[2];
                if (optionc == "-c" || optionc == "--custom-command") {
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
            }
            else if (argc > 3) {
                string optionpmy = argv[3];
                if (optionpmy == "-pmy" || optionpmy == "--pacman-yes") {
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
                        else { cout << err << endl; }
                        say what;
                    }
                    else if (pmh2d == "-Sy" || pmh2d == "-sy") {
                        cout << "installing package..";
                        string pkg2inst = "sudo pacman -Sy " + pkgName;
                        int pmyres = system(pkg2inst.c_str());
                        if (pmyres == 0) { cout << "package installed successfully!"; }
                        else { cout << err << endl; }
                        say what;
                    }
                    else if (pmh2d == "-Syu" || pmh2d == "-syu") {
                        cout << "installing package..";
                        string pkg2inst = "sudo pacman -Syu " + pkgName;
                        int pmyres = system(pkg2inst.c_str());
                        if (pmyres == 0) { cout << "package installed and full system update ended successfully!"; }
                        else { cout << err << endl; }
                        say what;
                    }
                }
            }
            else if (argc > 4) {
                string optionyy = argv[4];
                if (optionyy == "-yy" || optionyy == "--yay-yes") {
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
            }

            else {
                cout << "aborting.." << endl; say what;
            }
        }

        

        else {
            cout << "every option is available on the github repo's readme.md!\n";
            cout << "unknown option.\n";
        }
    }
    say what;
}
