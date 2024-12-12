#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Creating a map with state names as keys and populations as values
    map<string, long long> statePopulations;

    // Initializing the map with some example states and their populations
    statePopulations["California"] = 39538223;
    statePopulations["Texas"] = 29145505;
    statePopulations["Florida"] = 21538187;
    statePopulations["New York"] = 20201249;
    statePopulations["Pennsylvania"] = 13002700;
    statePopulations["Illinois"] = 12812508;
    
    // Prompting the user for a state name
    string stateName;
    cout << "Enter the name of a state: ";
    getline(cin, stateName);  // Using getline to allow for multi-word state names
    
    // Searching for the state in the map
    auto search = statePopulations.find(stateName);
    
    // If state is found, display the population
    if (search != statePopulations.end()) {
        cout << "The population of " << stateName << " is " << search->second << endl;
    } else {
        cout << "State not found!" << endl;
    }

    return 0;
}
