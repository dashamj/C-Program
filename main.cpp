#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//functions prototypes
void addParts(int&, int);
void removeParts(int&, int);


//structure
struct Bin {
  string part;
  int number;
};

int main()
{
  Bin inventory[10];
  string parts[10] = {"Valve", "Bearing", "Bushing", "Coupling", "Flange", "Gear", "Gear Housing", "Vacuum Gripper", "Cable", "Rod"};
  int amount[10] = { 10, 5, 15, 21, 7, 5, 5, 25, 18,12 };

  //Assign the values of the structure
  for (int i = 0; i < 10; i++) {
    inventory[i].part = parts[i];
    inventory[i].number = amount[i];
  }
  int choice;
  do {
    cout << setw(20) << "Part Description" << setw(20) << "Number of Parts" << endl;
    for (int i = 0; i < 10; i++) {
      cout << setw(2) << i + 1 << ". " << left << setw(15) << inventory[i].part << right << setw(15) << inventory[i].number << endl;
    }
    cout << "11. Quit" << endl;
    cout << "Select what part of the inventory bin you want to work with: ";
    cin >> choice;
    cout << endl;
    //Checks if the user is adding or removing parts
    for (int i = 0; i < 10; i++) {
      // keeps on running as long as the number of parts are within 0 - 30
        if (choice == i + 1) {
          cout << "Would you like to add or remove parts. \n";
          cout << "1. Add Parts\n";
          cout << "2. Remove Parts\n";
          int aorchoice;
          // keeps running till user enters a valid choice
          do{
           cout << "Enter a valid choice: ";
           cin >> aorchoice;
          } while(aorchoice < 1 || aorchoice > 2);
          // adding or subtrating
          int numParts;
          if (aorchoice == 1) {
           //int numParts;
           //adding
           do {
           cout << "How many " << inventory[i].part << " parts would you like to add: ";
           cin >> numParts;
           if (inventory[i].number + numParts > 30){
           cout << "The bin cannot hold that amount of " << inventory[i].part << " parts\n" << endl;
           } else {
           addParts(inventory[i].number, numParts);
           cout << endl;
           }
           } while (inventory[i].number + numParts > 30);
          } else if (aorchoice == 2) {
           //int numParts;
           //subtracting
           do {
           cout << "How many " << inventory[i].part <<" parts would you like to remove: ";
           cin >> numParts;
           if (inventory[i].number - numParts < 0){
           cout << "The bin doesn't have enough " << inventory[i].part << " parts\n" << endl;
           } else {
           removeParts(inventory[i].number, numParts);
           cout << endl;
           }
           } while (inventory[i].number - numParts < 0);
          }
          
        }
    }
  } while (choice != 11);

return 0;
}

// functions
void addParts(int& bin, int part) {
  bin += part;
}

void removeParts(int& bin, int part) {
  bin -= part;
}