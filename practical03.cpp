#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    Publication() : title("Unknown"), price(0.0f) {}

    // Parameterized constructor
    Publication(const string& t, float p) : title(t), price(p) {}

    // Function to get data
    virtual void getData() {
        cout << "Enter title: ";
        cin >> ws; // To handle leading whitespaces
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    // Function to display data
    virtual void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    // Virtual destructor
    virtual ~Publication() {}
};

class Book : public Publication {
private:
    int pageCount;

public:
    // Default constructor
    Book() : Publication(), pageCount(0) {}

    // Parameterized constructor
    Book(const string& t, float p, int pc) : Publication(t, p), pageCount(pc) {}

    // Function to get data
    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    // Function to display data
    void displayData() const override {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    // Default constructor
    Tape() : Publication(), playTime(0.0f) {}

    // Parameterized constructor
    Tape(const string& t, float p, float pt) : Publication(t, p), playTime(pt) {}

    // Function to get data
    void getData() override {
        Publication::getData();
        cout << "Enter play time (in minutes): ";
        cin >> playTime;
    }

    // Function to display data
    void displayData() const override {
        Publication::displayData();
        cout << "Play Time: " << playTime << " minutes" << endl;
    }
};

int main() {
    Publication* pubArray[2];

    try {
        // Dynamic allocation for Book
        pubArray[0] = new Book();
        cout << "\nEnter details for Book:\n";
        pubArray[0]->getData();

        // Dynamic allocation for Tape
        pubArray[1] = new Tape();
        cout << "\nEnter details for Tape:\n";
        pubArray[1]->getData();
    } catch (exception& e) {
        cerr << "Exception caught: " << e.what() << endl;

        // Reset data members to zero values if an exception occurs
        for (int i = 0; i < 2; ++i) {
            if (pubArray[i]) {
                delete pubArray[i];
                pubArray[i] = nullptr;
            }
        }

        pubArray[0] = new Book("Unknown", 0.0f, 0);
        pubArray[1] = new Tape("Unknown", 0.0f, 0.0f);
    }

    cout << "\nDisplaying Publication Details:\n";
    for (int i = 0; i < 2; ++i) {
        pubArray[i]->displayData();
        delete pubArray[i];
    }

    return 0;
}
