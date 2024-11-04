/***************************************************************************
* COMSC-210 | Lab 27 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    // declarations
    map<string, tuple<int, string, string>> villagerData;

    // Create three tuples of villagers
    tuple<int, string, string> villager1 {5, "Alligator", "Snap to It!"};
    tuple<int, string, string> villager2 {8, "Cat", "Nice fit"};
    tuple<int, string, string> villager3 {7, "Dog", "Puppy Love"};

    // insert elements into the map
    villagerData["Audie"] = villager1;
    villagerData["Raymond"] = villager2;
    villagerData["Marshal"] = villager3;

    int choice;

    while (true)
    {
        // Display menu
        cout << "Menu:\n"
             << "1. Add Villager\n"
             << "2. Delete Villager\n"
             << "3. Increase Friendship\n"
             << "4. Decrease Friendship\n"
             << "5. Search for Villager\n"
             << "6. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice)
        {
            case 1:
                addVillager(villagerData);
                break;
            case 2:
                deleteVillager(villagerData);
                break;
            case 3:
                increaseFriendship(villagerData);
                break;
            case 4:
                decreaseFriendship(villagerData);
                break;
            case 5:
                searchVillager(villagerData);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                return 0;
        }
    }
}