#include<iostream>
#include<vector>
using namespace std;

    int n = 4; // example size
    int arr[4][4] = {
        {0, 0, 3, 0},
        {22, 0, 0, 0},
        {0, 17, 0, 0},
        {0, 0, 0, 39}
    };

    vector<int> values;
    vector<int> rows;
    vector<int> columns;


//SORTING

int main(){
	int count=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                count++;
                values.push_back(arr[i][j]);
                rows.push_back(i);
                columns.push_back(j);
            }
        }
    }
	cout<<" total non zero entries are:"<<count;
 // Just to show the collected values and indices
    for (int i = 0; i < count; i++) {
        cout << "Value: " << values[i] << ", Row: " << rows[i] << ", Column: " << columns[i] << "\n";
    }
	int arrN[count+1][3]={};
	
		int indR=0;
		int indC=0;
		int indV=0;
	for(int i=0;i<count+1;i++){
		for(int j=0;j<3;j++){
			if(i==0 ){
				if(j==2){
					arrN[i][j]=count;
				}
				else arrN[i][j]=n;
				
			}else{
				if(j==0){
				
					arrN[i][j]=rows[indR];
					indR++;
				}else if(j==1){
					arrN[i][j]=columns[indC];
					indC++;
				}else{
					arrN[i][j]=values[indV];
					indV++;
				}
				
				
			}
			
		}
	}
	
	for(int i=0;i<count+1;i++){
		for(int j=0;j<3;j++){
		cout<<arrN[i][j]<<" ";
	}
	cout<<endl;
	}
	
	return 0;
}





//CLEANER VERSION OF THE ABOVE CODE
// Why this is better:

// No overwrite bug in header row.

// No need for messy indR, indC, indV.

// Uses vector instead of fixed array size (safer in modern C++).

//Clear separation of Step 1 (collect), Step 2 (triplet), Step 3 (display).



// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n = 4; // example size
//     int arr[4][4] = {
//         {0, 0, 3, 0},
//         {22, 0, 0, 0},
//         {0, 17, 0, 0},
//         {0, 0, 0, 39}
//     };

//     vector<int> values, rows, cols;

//     // Step 1: Collect non-zero values
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (arr[i][j] != 0) {
//                 values.push_back(arr[i][j]);
//                 rows.push_back(i);
//                 cols.push_back(j);
//             }
//         }
//     }

//     int count = values.size();
//     cout << "Total non-zero entries: " << count << "\n";

//     // Step 2: Create triplet form (using vector for safety)
//     vector<vector<int>> triplet(count + 1, vector<int>(3, 0));

//     // First row: matrix info
//     triplet[0][0] = n;
//     triplet[0][1] = n;
//     triplet[0][2] = count;

//     // Remaining rows: row, col, value
//     for (int i = 0; i < count; i++) {
//         triplet[i + 1][0] = rows[i];
//         triplet[i + 1][1] = cols[i];
//         triplet[i + 1][2] = values[i];
//     }

//     // Step 3: Display triplet
//     cout << "\nTriplet form:\n";
//     for (int i = 0; i <= count; i++) {
//         cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << "\n";
//     }

//     return 0;
// }