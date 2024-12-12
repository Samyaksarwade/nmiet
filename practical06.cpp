#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Structure to hold personal records
struct PersonalRecord {
    string name;
    string dob; // Date of birth
    string phone;

    // Overloading < operator for sorting by name
    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }

    // Display record
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phone << endl;
    }
};

// Function to search for a record by name
void searchRecord(const vector<PersonalRecord>& records, const string& name) {
    auto it = find_if(records.begin(), records.end(), [&name](const PersonalRecord& record) {
        return record.name == name;
    });

    if (it != records.end()) {
        cout << "Record found: " << endl;
        it->display();
    } else {
        cout << "Record with name '" << name << "' not found." << endl;
    }
}

int main() {
    vector<PersonalRecord> records;

    // Adding some records
    records.push_back({"Alice", "1995-06-15", "123-456-7890"});
    records.push_back({"Bob", "1990-12-20", "987-654-3210"});
    records.push_back({"Charlie", "1985-03-10", "555-555-5555"});

    // Display original records
    cout << "Original records:" << endl;
    for (const auto& record : records) {
        record.display();
    }

    // Sorting records by name
    sort(records.begin(), records.end());

    // Display sorted records
    cout << "\nSorted records:" << endl;
    for (const auto& record : records) {
        record.display();
    }

    // Searching for a record
    string searchName;
    cout << "\nEnter name to search: ";
    cin >> searchName;
    searchRecord(records, searchName);

    return 0;
}
