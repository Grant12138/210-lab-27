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
void print_id(string const& lab_desc);

int main()
{
    print_id("Lab 27: Villager Map");

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
    displayVillagers(villagerData);

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
        cout << "\n";
        displayVillagers(villagerData);
    }

    return 0;
}

/********************************************************************
 * FUNCTION: Add a villager to the map container
 *
 * @param villagers
 *
 * return NONE;
 */
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
    cout << name << " added.\n";
}

/******************************************************
 * FUNCTION: delete a villager from the map container
 *
 * @param villagers
 *
 * return NONE;
 */
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

/**************************************************
 * FUNCTION: increase the friendship level of a specified villager by 1
 *
 * @param villagers
 *
 * return NONE;
 */
void increaseFriendship(map<string, tuple<int, string, string>>& villagers)
{
    string name;

    cout << "\n--- Increase Friendship ---\n";
    cout << "Enter the name of the villager to increase friendship: ";
    getline(cin, name);

    auto it = villagers.find(name);
    if (it == villagers.end())
        cout << "Error: Villager " << name << " not found\n";
    else
        get<0>(villagers[name])++;
}

/******************************************************************
 * FUNCTION: decrease the friendship level of a specified villager by 1
 *
 * @param villagers
 *
 * return NONE;
 */
void decreaseFriendship(map<string, tuple<int, string, string>>& villagers)
{
    string name;

    cout << "\n--- Decrease Friendship ---\n";
    cout << "Enter the name of the villager to decrease friendship: ";
    getline(cin, name);

    auto it = villagers.find(name);
    if (it == villagers.end())
        cout << "Error: Villager " << name << " not found\n";
    else
        get<0>(villagers[name])--;
}

/*****************************************************************
 * FUNCTION: search for a specified villager by their name and display their information
 *
 * @param villagers
 *
 * return NONE;
 */
void searchVillager(map<string, tuple<int, string, string>>& villagers)
{
    string name;

    cout << "\n--- Search Villager ---\n";
    cout << "Enter the name of the villager to be searched: ";
    getline(cin, name);

    auto it = villagers.find(name);
    if (it == villagers.end())
        cout << "Error: Villager " << name << " not found\n";
    else
    {
        cout << "Name: " << name << "\n";
        cout << "Friendship level: " << get<0>(villagers[name]) << "\n";
        cout << "Species: " << get<1>(villagers[name]) << "\n";
        cout << "Catchphrase: " << get<2>(villagers[name]) << "\n";
    }
}

/************************************************
 * FUNCTION: display the details of all the villagers
 *
 * @param villagers
 *
 * return NONE;
 */
void displayVillagers(const map<string, tuple<int, string, string>>& villagers)
{
    if (villagers.empty())
    {
        cout << "No villagers to display yet\n";
        return;
    }

    cout << "Villager details:\n";
    for (const auto& pair : villagers)
        cout << pair.first << " [" << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]\n";
    cout << "\n";
}

void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}