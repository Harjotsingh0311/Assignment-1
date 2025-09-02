#include<iostream>
using namespace std;

//----SOME WRONG FORMULA IMPLICATIONS HERE---
// class lowertriangularMatric{
//     int n;
//     int *arr;
// public:
//     lowertriangularMatric(int n){
//         this->n=n;
//         arr=new int[4*n-6];
//         for(int i=0;i<4*n-6;i++){
//             arr[i]=0;
//         }
//     }

//     void set(int i,int j,int value){
//         if(i-j==3) arr[i-4]=value;
//         else if(i-j==2) arr[i-2]=value;
//         else if(i-j==1) arr[2*n-5+i-2]=value;    //n-3+n-2+i-2
//         else if(i==j) arr[3*n-6+i-2]=value;
//         else cout<<"invalid index position\n";
//     }

//     int get(int i,int j){
//         if(i-j==3) return arr[i-4];
//         else if(i-j==2) return arr[i-2];
//         else if(i-j==1) return arr[2*n-5+i-2];    //n-3+n-2+i-2
//         else if(i==j) return arr[3*n-6+i-2];
//          return 0;
//     }

//     void display(){
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 cout<<get(i,j)<<" ";
//             }
//             cout<<endl;
//         }
//     }

// };



class LowerTriangularMatrix {
    int n;
    int *arr;
public:
    LowerTriangularMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];   // exact number of elements
        for(int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }

    void set(int i,int j,int value) {
        if(i >= j) {
            int index = (i*(i-1))/2 + (j-1);  // formula------>Always think: flatten the 2D structure → sum of previous row sizes + position in current row.
            arr[index] = value;
        } else {
            cout<<"Invalid index position!\n";
        }
    }

    int get(int i,int j) {
        if(i >= j) {
            int index = (i*(i-1))/2 + (j-1);
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

    ~LowerTriangularMatrix() { delete[] arr; }
};

int main(){

    int n = 4;   // size of matrix
    LowerTriangularMatrix lt(n);

    lt.set(1,1,5);
    lt.set(2,1,2); lt.set(2,2,6);
    lt.set(3,1,3); lt.set(3,2,7); lt.set(3,3,9);
    lt.set(4,1,4); lt.set(4,2,8); lt.set(4,3,10); lt.set(4,4,12);

    cout << "Lower Triangular Matrix:\n";
    lt.display();
    return 0;
}