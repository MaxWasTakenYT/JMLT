#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    system("figlet pacmany");

    cout << "\nPackage name?\n";
    string pkgA; cin >> pkgA;
    string pkgB = "sudo pacman -S --noconfirm " + pkgA;
    system(pkgB.c_str());

    cout << "\nRun a full system upgrade?\n";
    string sysA; cin >> sysA;
    if (sysA == "y" || sysA == "Y") {
        system("sudo pacman -Syu --noconfirm");
    }
    else {
        return 0;
    }
}
