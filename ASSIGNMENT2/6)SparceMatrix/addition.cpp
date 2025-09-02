#include <iostream>
using namespace std;


void addSparseMatrices(int A[][3], int B[][3]) {
    int m = A[0][0], n = A[0][1]; // rows and cols
    int t1 = A[0][2]; // non-zero count in A
    int t2 = B[0][2]; // non-zero count in B

    int result[100][3];
    result[0][0] = m;
    result[0][1] = n;

    int i = 1, j = 1, k = 1;

    // Traverse both matrices
    while (i <= t1 && j <= t2) {
        // Compare row and col
        if (A[i][0] < B[j][0] || 
           (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || 
                (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++; k++;
        }
        else { // same row & col
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                result[k][0] = A[i][0];
                result[k][1] = A[i][1];
                result[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    // Remaining elements of A
    while (i <= t1) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++; k++;
    }

    // Remaining elements of B
    while (j <= t2) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++; k++;
    }

    // Update count
    result[0][2] = k - 1;

    
    cout << "\nResultant Sparse Matrix (Triplet Form):\n";
    for (int x = 0; x < k; x++) {
        cout << result[x][0] << " " << result[x][1] << " " << result[x][2] << endl;
    }
}

int main() {
    

    int A[5][3] = {
        {3, 3, 4},  // 3x3 matrix with 4 non-zero
        {0, 0, 5},
        {0, 2, 8},
        {1, 1, 7},
        {2, 2, 6}
    };

    int B[4][3] = {
        {3, 3, 3},  // 3x3 matrix with 3 non-zero
        {0, 0, 3},
        {1, 1, 9},
        {2, 0, 4}
    };

    addSparseMatrices(A, B);

    return 0;
}