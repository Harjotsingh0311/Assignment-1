#include<iostream>
using namespace std;

void Transpose(int mat[][3],int row,int column){
        for (int i = 0; i < row; i++) {
        for(int j=i;j<column;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }}

}


int main() {
    int mat[3][3] = {{4, 5,5},{ 7, 7,13},{6,9,8}};
    int row = 3;
    int column=3;
    cout<<"before transpose the matrix is--->\n";
        for (int i = 0; i < row; i++) {
        for(int j=0;j<column;j++){
             cout << mat[i][j] << " ";
        }
     cout<<endl;  
    }

    Transpose(mat,row,column);
    
    cout<<"AFTER TRANSPOSE THE MATRIX IS----->>\n";
    for (int i = 0; i < row; i++) {
        for(int j=0;j<column;j++){
             cout << mat[i][j] << " ";
        }
     cout<<endl;  
    }
    return 0;
}
