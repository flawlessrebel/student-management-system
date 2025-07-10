#include <iostream>
#include "../include/utils.h"

using namespace std;

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}