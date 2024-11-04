/***************************************************************************
* COMSC-210 | Lab 27 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);
void searchVillager(map<string, tuple<int, string, string>>&);
void displayVillagers(const map<string, tuple<int, string, string>>&);

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
            default:
                cout << "\nInvalid choice. Please select a valid option\n";
        }

        // Display the current villager details after each operation
        displayVillagers(villagerData);
    }

    return 0;
}

void addVillager(map<string, tuple<int, string, string>>& villagers)
{
    string name, species, catchphrase;
    int friendship;

    cout << "\n--- Add Villager ---\n";

    cout << "Villager name: ";
    getline(cin, name);

    cout << "Friendship level: ";
    cin >> friendship;
    cin.ignore(1000, '\n');

    cout << "Species: ";
    getline(cin, species);

    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    tuple<int, string, string> aVillager {friendship, species, catchphrase};
    villagers[name] = aVillager;
    cout << "\n" << name << "added.\n\n";
}

void deleteVillager(map<string, tuple<int, string, string>>& villagers)
{
    string name;

    cout << "\n--- Delete Villager ---\n";
    cout << "Enter the name of the villager to be deleted: ";
    getline(cin, name);

    auto it = villagers.find(name);
    if (it == villagers.end())
        cout << "Error: Villager " << name << " not found\n";
    else
        villagers.erase(it);
}

void increaseFriendship(map<string, tuple<int, string, string>>& villagers)
{
    string name;

    cout << "\n--- Increase Friendship ---\n";
    cout << "Enter the name of the villager to increase friendship: ";
    getline(cin, name);

    auto it = villagers.find(name);
    if (it == villages.end())
        cout << "Error: Villager " << name << " not found\n";
    else
        get<0>(villagers[name])++;
}