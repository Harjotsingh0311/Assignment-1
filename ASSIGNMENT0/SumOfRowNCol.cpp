#include <iostream>
using namespace std;

int mat[3][4] = {
    {1, 2, 3, 4},
    {4, 5, 6, 1},
    {7, 8, 9, 1}
};

int row=3,column=4;
int main() {
    // Sum of each row
    for (int i = 0; i < row; i++) {
        int sumR = 0;
        for (int j = 0; j < column; j++) {
            sumR += mat[i][j];
        }
        cout << "Sum of row with index " << i << " is " << sumR << endl;
    }

    // Sum of each column
    for (int i = 0; i < column; i++) {
        int sumC = 0;
        for (int j = 0; j < row; j++) {
            sumC += mat[j][i];
        }
        cout << "Sum of column with index " << i << " is " << sumC << endl;
    }

    return 0;
}