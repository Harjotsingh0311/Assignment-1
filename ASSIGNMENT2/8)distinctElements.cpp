#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Using unordered_set to store unique elements
    unordered_set<int> distinct;

    for (int i = 0; i < n; i++) {
        distinct.insert(arr[i]);
    }

    cout << "Total number of distinct elements = " << distinct.size() << endl;

    return 0;
}