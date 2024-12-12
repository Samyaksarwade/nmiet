#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to print an array
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Integer array
    int intArr[] = {29, 10, 14, 37, 14};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Original integer array: ";
    printArray(intArr, intSize);

    selectionSort(intArr, intSize);

    cout << "Sorted integer array:   ";
    printArray(intArr, intSize);

    // Float array
    float floatArr[] = {3.1, 2.4, 5.7, 1.9, 4.6};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    cout << "\nOriginal float array: ";
    printArray(floatArr, floatSize);

    selectionSort(floatArr, floatSize);

    cout << "Sorted float array:   ";
    printArray(floatArr, floatSize);

    return 0;
}
