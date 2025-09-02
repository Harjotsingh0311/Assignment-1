#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two sparse matrices in triplet form
vector<vector<int>> multiplySparse(vector<vector<int>>& A, vector<vector<int>>& B) {
    // Check dimension compatibility
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible! Columns of A != Rows of B\n";
        return {};
    }

    int rows = A[0][0];
    int cols = B[0][1];

    // Convert B into a form easy for multiplication (transpose for matching)
    vector<vector<int>> B_T;
    B_T.push_back({B[0][1], B[0][0], B[0][2]});
    for (int i = 1; i <= B[0][2]; i++) {
        B_T.push_back({B[i][1], B[i][0], B[i][2]});
    }

    vector<vector<int>> result;
    result.push_back({rows, cols, 0});

    // Multiply A and B_T
    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B_T[0][2]; j++) {
            if (A[i][1] == B_T[j][1]) { // column of A == column of B_T (original row of B)
                int r = A[i][0];
                int c = B_T[j][0];
                int val = A[i][2] * B_T[j][2];

                // Check if already exists in result
                bool found = false;
                for (int k = 1; k <= result[0][2]; k++) {
                    if (result[k][0] == r && result[k][1] == c) {
                        result[k][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result.push_back({r, c, val});
                    result[0][2]++;
                }
            }
        }
    }

    return result;
}

// Utility function to print triplet
void printTriplet(vector<vector<int>>& T) {
    for (auto& row : T) {
        cout << row[0] << " " << row[1] << " " << row[2] << endl;
    }
}

int main() {
    // Example sparse matrices in triplet form
    vector<vector<int>> A = {
        {2, 3, 2}, // 2x3 matrix, 2 non-zeros
        {0, 0, 1},
        {1, 2, 2}
    };

    vector<vector<int>> B = {
        {3, 2, 2}, // 3x2 matrix, 2 non-zeros
        {0, 1, 3},
        {2, 0, 4}
    };

    cout << "Matrix A (triplet):\n";
    printTriplet(A);
    cout << "Matrix B (triplet):\n";
    printTriplet(B);

    vector<vector<int>> C = multiplySparse(A, B);

    cout << "Resultant Matrix (A x B) in Triplet Form:\n";
    printTriplet(C);

    return 0;
}