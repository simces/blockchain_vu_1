#include "functions.hpp"
using namespace std;

int main(){

    int choice;

    cout << "Choose testing method: " << endl
    << "---------------------------" << endl
    << "1. Manual input. " << endl
    << "2. File input. " << endl
    << "3. Comparison. " << endl
    << "4. Collision test. " << endl
    << "5. Difference test. " << endl
    << "---------------------------" << endl;

    choiceCheck(choice, 5);

    if(choice == 1) consoleInput();
    else if(choice == 2) fileInput();
    else if(choice == 3) comparison();
    else if(choice == 4) collisions();
    else if(choice == 5) difference();

}