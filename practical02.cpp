#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;  // Date of Birth
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicense;

    static int studentCount; // Static member to keep track of the number of students

public:
    // Default Constructor
    Student()
        : name("Unknown"), rollNumber(0), className("Unknown"), division('X'), dob("Unknown"),
          bloodGroup("Unknown"), contactAddress("Unknown"), phoneNumber("Unknown"), drivingLicense("Unknown") {
        studentCount++;
    }

    // Parameterized Constructor
    Student(const string& name, int rollNumber, const string& className, char division,
            const string& dob, const string& bloodGroup, const string& contactAddress,
            const string& phoneNumber, const string& drivingLicense)
        : name(name), rollNumber(rollNumber), className(className), division(division),
          dob(dob), bloodGroup(bloodGroup), contactAddress(contactAddress), phoneNumber(phoneNumber),
          drivingLicense(drivingLicense) {
        studentCount++;
    }

    // Copy Constructor
    Student(const Student& other)
        : name(other.name), rollNumber(other.rollNumber), className(other.className),
          division(other.division), dob(other.dob), bloodGroup(other.bloodGroup),
          contactAddress(other.contactAddress), phoneNumber(other.phoneNumber),
          drivingLicense(other.drivingLicense) {
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Member function to display student details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Driving License: " << drivingLicense << endl;
    }

    // Static member function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Inline setter function using this pointer
    void setName(const string& name) {
        this->name = name;
    }

    // Exception handling during dynamic memory allocation
    static Student* createStudentDynamic() {
        try {
            return new Student();
        } catch (bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return nullptr;
        }
    }

    // Friend class for accessing private members
    friend class StudentManager;
};

int Student::studentCount = 0; // Initialize static member

class StudentManager {
public:
    // Friend class function to modify student's private members
    void updateContactDetails(Student& student, const string& address, const string& phone) {
        student.contactAddress = address;
        student.phoneNumber = phone;
    }
};

int main() {
    // Creating student objects using parameterized constructor
    Student s1("John Doe", 1, "10th", 'A', "01/01/2005", "O+", "123 Elm Street", "1234567890", "DL12345");
    Student s2("Jane Smith", 2, "10th", 'B', "05/05/2005", "A+", "456 Oak Street", "0987654321", "DL67890");

    // Display details of students
    cout << "Student 1 Details:" << endl;
    s1.display();

    cout << "\nStudent 2 Details:" << endl;
    s2.display();

    // Using static member function
    cout << "\nTotal Students: " << Student::getStudentCount() << endl;

    // Using dynamic memory allocation
    Student* s3 = Student::createStudentDynamic();
    if (s3) {
        s3->setName("Dynamic Student");
        cout << "\nDynamic Student Details:" << endl;
        s3->display();
        delete s3; // Clean up dynamic memory
    }

    // Using friend class to update details
    StudentManager manager;
    manager.updateContactDetails(s1, "789 Pine Street", "1122334455");

    cout << "\nUpdated Student 1 Details:" << endl;
    s1.display();

    // Display total student count after deletion
    cout << "\nTotal Students After Deletion: " << Student::getStudentCount() << endl;

    return 0;
}
