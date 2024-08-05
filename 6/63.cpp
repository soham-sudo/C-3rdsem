#include <iostream>
#include <algorithm>
using namespace std;
template <class x>
class array {
    x* data;
    int size;

public:
    array(int s) {
        size = s;
        data = new x[s];
    }

    x& operator[](int i) {
        if (i < 0 || i > size - 1) {
            throw i;
        } else {
            return data[i];
        }
    }

    x maxelement() {
        x m = data[0];
        for (int i = 0; i < size; i++) {
            m = max(m, data[i]);
        }
        return m;
    }
};

int main() {
    try {
        int n;
        cout << "Enter the size of the integer array: ";
        cin >> n;

        // Create an array of integers
        array<int> intArray(n);

        // Input elements
        for (int i = 0; i < n; i++) {
            cout << "Enter element " << i << ": ";
            cin >> intArray[i];
        }

        // Find and print the maximum element
        int maxInt = intArray.maxelement();
    cout << "Maximum element in the integer array: " << maxInt << std::endl;
    } catch (int index) {
        std::cerr << "Index " << index << " is out of bounds." << std::endl;
    }

    return 0;
}
