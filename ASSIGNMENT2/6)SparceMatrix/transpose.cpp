#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void display(const vector<vector<int>>& triplet) {
    for (auto &row : triplet) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}


vector<vector<int>> transpose(const vector<vector<int>>& triplet) {
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonZero = triplet[0][2];

    
    vector<vector<int>> trans(nonZero + 1, vector<int>(3, 0));

    // First row: swap rows and cols
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    // Swap row <-> column for each non-zero element
    for (int i = 1; i <= nonZero; i++) {
        trans[i][0] = triplet[i][1];  // row becomes column
        trans[i][1] = triplet[i][0];  // column becomes row
        trans[i][2] = triplet[i][2];  // value stays same
    }

    // Sort transposed triplet by (row, col)
    sort(trans.begin() + 1, trans.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });

    return trans;
}

int main() {
    
    vector<vector<int>> triplet = {
        {4, 4, 4},   // header: rows, cols, nonZero
        {0, 2, 3},
        {1, 0, 22},
        {2, 1, 17},
        {3, 3, 39}
    };

    cout << "Original Triplet:\n";
    display(triplet);

    vector<vector<int>> trans = transpose(triplet);

    cout << "\nTransposed Triplet:\n";
    display(trans);

    return 0;
}