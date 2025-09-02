#include<iostream>
using namespace std;

class UpperTriangularMatrix {
    int n;
    int *arr;
public:
    UpperTriangularMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];   // exact number of elements
        for(int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }

    void set(int i,int j,int value) {
        if(i <= j) {
            int index = ((i-1)*(2*n-i+2))/2 + (j-i);  // formula------>Always think: flatten the 2D structure → sum of previous row sizes + position in current row.
            arr[index] = value;
        } else {
            cout<<"Invalid index position!\n";
        }
    }

    int get(int i,int j) {
        if(i <= j) {
            int index = ((i-1)*(2*n-i+2))/2 + (j-i);
            return arr[index];
        }
        return 0;
    }

    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }

    ~UpperTriangularMatrix() { delete[] arr; }
};


int main(){

    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    UpperTriangularMatrix m(n);

    // set some values in upper triangular part
    m.set(1, 1, 5);
    m.set(1, 3, 8);
    m.set(2, 2, 7);
    m.set(2, 4, 9);
    m.set(3, 3, 6);
    m.set(4, 4, 4);

    cout << "\nMatrix is:\n";
    m.display();

    return 0;
}