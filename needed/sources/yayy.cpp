#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    system("figlet YAYy");

    cout << "\nPackage name?\n";
    string pkgA; cin >> pkgA;
    string pkgB = "yay -S --noconfirm " + pkgA;
    system(pkgB.c_str());

    cout << "\nRun a full system upgrade?\n";
    string sysA; cin >> sysA;
    if (sysA == "y" || sysA == "Y") {
        system("yay -Syu --noconfirm");
    }
    else {
        return 0;
    }
}
