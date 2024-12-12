#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloading operator+ for addition of two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading operator* for multiplication of two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overloading operator>> for input of a complex number
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overloading operator<< for output of a complex number
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) {
            out << "+";
        }
        out << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, sum, product;

    cout << "Enter the first complex number:" << endl;
    cin >> c1;
    cout << "Enter the second complex number:" << endl;
    cin >> c2;

    sum = c1 + c2;
    product = c1 * c2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
