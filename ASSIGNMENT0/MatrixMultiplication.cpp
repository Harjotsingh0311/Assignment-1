#include<iostream>

#include<vector>
using namespace std;

//void Multiplication(int mat1[][25],int row1,int column1,int mat2[][25],int row2,int column2,int mat3[][25]){

void Multiplication(vector<vector<int>>mat1,int row1,int column1,vector<vector<int>>mat2,int row2,int column2,vector<vector<int>>&mat3){
    for (int i = 0; i < row1; i++) {
        
        for(int j=0;j<column2;j++){
            int sum=0;
            for(int k=0;k<column1;k++){
            
            sum+=mat1[i][k]*mat2[k][j];  
            
        }
         mat3[i][j] = sum;
    }

}



}

int main() {
    //int mat1[3][3] = {{4, 5,5},{ 7, 7,13},{6,9,8}};
    int row1 ;
    cout<<"enter no. of rows in matrix 1:";
    cin>>row1;

    int column1;
    cout<<"enter no. of columns in matrix 1:";
    cin>>column1;
    vector<vector<int>> mat1(row1, vector<int>(column1));

//     creates a 2D vector (a matrix) with:

// row1 rows

// col1 columns in each row

// All elements initialized to 0 (default for int)

// Here’s how it works step-by-step:

// vector<int>(col1)
// → Creates a single row (a vector<int>) with col1 elements, all 0.
// Example: if col1 = 3 → [0, 0, 0].

// vector<vector<int>>(row1, vector<int>(col1))
// → Creates a vector containing row1 copies of that row.
// Example: if row1 = 2 and col1 = 3 →

    //int mat1[row1][column1];-------------------------------->>>>>>>>>> THIS IS BASICALLY NOW REDECLARATION !!
    cout<<"Start enter the elements in matrix 1:\n";
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            cin>>mat1[i][j];
        }
    }
    cout<<"MATRIX-1---->\n";
        for (int i = 0; i < row1; i++) {
        for(int j=0;j<column1;j++){
             cout << mat1[i][j] << " ";
        }
     cout<<endl;  
    }


    //int mat2[3][3] = {{1,2,3},{ 4,5,6},{7,8,9}};
    int row2 ;
    cout<<"enter no. of rows in matrix 2:";
    cin>>row2;

    int column2;
    cout<<"enter no. of columns in matrix 2:";
    cin>>column2;

    vector<vector<int>> mat2(row2, vector<int>(column2));
    //int mat2[row2][column2];
    cout<<"Start enter the elements in matrix 1:\n";
    for(int i=0;i<row2;i++){
        for(int j=0;j<column2;j++){
            cin>>mat2[i][j];
        }
    }

    cout<<"MATRIX-2---->\n";
    for (int i = 0; i < row1; i++) {
    for(int j=0;j<column1;j++){
    cout << mat2[i][j] << " ";
    }
     cout<<endl;  
    }

    vector<vector<int>> mat3(row1, vector<int>(column2, 0));
    //int mat3[row1][column2];
    int row3=row1;
    int column3=column2;

    if (column1 != row2) {
    throw invalid_argument("Column count of matrix 1 must match row count of matrix 2");
    }
else{

    Multiplication(mat1,row1,column1,mat2,row2,column2,mat3);
    
    cout<<"AFTER MULTIPLICATION MATRIX IS----->>\n";
    for (int i = 0; i < row3; i++) {
        for(int j=0;j<column3;j++){
             cout << mat3[i][j] << " ";
        }
     cout<<endl;  
    }

}
    return 0;
}
