#include<iostream>
using namespace std;

class tridiagonalMatrix{
    int n;
    int *arr;

public:
    tridiagonalMatrix(int size){
        n=size;
        arr=new int[3*n-2];
        for(int i=0; i<3*n-2; i++) arr[i] = 0;
    }

    void set(int i,int j,int value){
        if(i-j==1) arr[i-2]=value;
        else if(i==j) arr[n-1+i-1]=value;
        else if(i-j==-1) arr[2*n-1+i-1]=value;
        else cout<<"invalid index!!"<<endl;
    }

    int get(int i,int j){
        if(i-j==1) return arr[i-2];
        else if (i==j) return arr[n-1+i-1];
        else if(i-j==-1) return arr[2*n-1+i-1];
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
};

int main(){

    tridiagonalMatrix t(4);

    
    t.set(1,1,4);
    t.set(1,2,1);
    t.set(2,1,2); 
    t.set(2,2,5);
    t.set(2,3,3);
    t.set(3,2,6); 
    t.set(3,3,7); 
    t.set(3,4,8);
    t.set(4,3,9); 
    t.set(4,4,10);

    cout << "Tri-Diagonal Matrix:\n";
    t.display();
    return 0;
}