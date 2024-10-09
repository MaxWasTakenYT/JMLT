#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    system("clear");

mainMenu:
    system("figlet JMLT");
    cout << "\nRunning version T6!";
    cout << "\n\nMain menu;";
    cout << "\n[J] Prepare for \"jstmax! use\"";
    cout << "\n[C] Enter a custom command";
    cout << "\n[P] Runs pacmany";
    cout << "\n[Y] Runs yayy";
    cout << "\n[Q] Quits JMLT";
    cout << "\n\n*waiting for input* \\( @w@)/";
    char menuSel; cin.get(menuSel);

    if (menuSel == 'J' || menuSel == 'j') {
        system("clear");
        system("figlet \"JM-Use\"");
        cout << "\ncontinue?\n";
        string juA; cin >> juA;
        if (juA == "y" || juA == "Y") {
            system("sudo pacman -S --noconfirm figlet tldr fish reflector fastfetch");
            cout << "\nRun a full system upgrade?\n";
            string doFsu; cin >> doFsu;
            if (doFsu == "y" || doFsu == "Y") {
                system("sudo pacman -Syu --noconfirm");
                goto mainMenu;
            }
            else {
                goto mainMenu;
            }
        }
        else {
            goto mainMenu;
        }

    }
    else if (menuSel == 'C' || menuSel == 'c') {
        system("clear");
        system("figlet \"jC.CMD\"");
        cout << "~> "; string jccmd; cin >> jccmd;
        system(jccmd.c_str());
        goto mainMenu;
    }
    else if (menuSel == 'P' || menuSel == 'p') {
        system("clear");
        system("pacmany"); return 0;
    }
    else if (menuSel == 'Y' || menuSel == 'y') {
        system("clear");
        system("yayy"); return 0;
    }
    else if (menuSel == 'Q' || menuSel == 'q') {
        system("clear");
        return 0;
    }
    else {
        system("clear");
        cout << "Unknown option, try again.\n"; goto mainMenu;
    }
}
