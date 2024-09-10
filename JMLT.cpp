#include <iostream>
#include <cstdlib>
#include <string>
#define say return
#define what 0

using namespace std;

int main(int argc, char* argv[]) {
    cout << "welcome to jstmax's linux toolbox (JMLT 4short)\n";
    cout << "insert your username: "; string username; cin >> username; cout << endl;
    cout << "every option is available on the github repo's readme.md\n\n";

    if (argc > 1) {
        string option = argv[1];
        if (option == "-jmuse" || option == "--prepare-for-jstmax-use") {
            cout << "[!] NOTE: since i code on windows, i cannot\n check if the user is root,\n to run '-jmuse', run the program as root.\n";
            cout << "preparing for \"jstmax!-use\"..\n";
            string path = "cd /home/" + username;
            system(path.c_str());
            int returnCode = system("sudo pacman -Sy --noconfirm firefox reflector tldr fastfetch");
            if (returnCode == 0) {
                cout << "run a full system update? (y/n)\n: "; string fsuChoice; cin >> fsuChoice;
                if (fsuChoice == "y" || fsuChoice == "Y") {
                    cout << "running a full system update..\n";
                    int fsuRes = system("sudo pacman -Syu --noconfirm");
                    if (fsuRes == 0) {
                        cout << "now your system is ready to be \"jstmax!-used\"";
                    }
                    else {
                        cout << "an error occurred, funny thing is that i don't want or have time to create a way to check logs so.. i guess \"fuck you, try again\" is the right answer this time?\n";
                    }
                    cout << "now your system is ready to be \"jstmax!-used\"";
                }
                else {
                    cout << "now your system is ready to be \"jstmax!-used\"";
                }
            }
            else {
                cout << "an error occurred, funny thing is that i don't want or have time to create a way to check logs so.. i guess \"fuck you, try again\" is the right answer this time?\n";
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
                cout << "an error occurred, funny thing is that i don't want or have time to create a way to check logs so.. i guess \"fuck you, try again\" is the right answer this time?\n";
            }
        }

        // else if (argc > 3 && (string(argv[3]) == "-hi" || string(argv[3]) == "--hello")) {}

        else {
            cout << "unknown option: " << option << "check github for available options.\n";
        }
    }
    say what;
}