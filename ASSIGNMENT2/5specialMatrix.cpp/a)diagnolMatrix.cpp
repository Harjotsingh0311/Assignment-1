#include<iostream>
using namespace std;

void getDiagonalmatrix(int arr[],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) cout<<arr[i-1]<<" ";
            else cout<<"0"<<" ";
        }
        cout<<"\n";
    }
}



// int main(){
//     int n;
    
//     cout<<"enter the size diagnol matrix(enter value of n for nxn matrix) :";
//     cin>>n;
//     int arr[n];
//     cout<<"enter the diagonal values in the matrix:";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     getDiagonalmatrix(arr,n);
//     return 0;
// }








//USING CLASS(for abstract data type(ADT)) AND DYNAMIC MEMORY ALLOCATION

class diagonalMatrix{
    int n;
    int *arr;

public:
    diagonalMatrix(int size){
        n=size;
        arr=new int[n];      //creating dynamic array of size n to just store the diagonal elements
        for(int i=0;i<n;i++){
            arr[i]=0;
        }

    }
    void set(int i,int j,int value){
        if(i==j) arr[i-1]=value;
    }

    int get(int i,int j){
        if(i==j) return arr[i-1];
        return 0;
    }

    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }

    ~diagonalMatrix(){delete[]  arr;}
};

int main(){
    diagonalMatrix D(4);
    D.set(1,1,9);
    D.set(2,2,8);
    D.set(3,3,7);
    D.set(4,4,6);
    cout<<"DIAGONAL MATRIX----\n";
    D.display();
    return 0;
}