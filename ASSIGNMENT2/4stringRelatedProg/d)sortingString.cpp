#include<iostream>
#include<string>
#include<algorithm>             // for sort func
using namespace std;

int main(){
    
    int n;
    cout<<"enter number of strings:";
    cin>>n;
    cin.ignore();

//     When you use cin >> to take input (like numbers or words), it leaves a newline \n in the input buffer after you press Enter.
// If you then immediately call getline(cin, str1);, it will read that leftover newline as an "empty string" — skipping the actual user input.
// To fix this, we put cin.ignore(); before getline() so that the unwanted \n is removed, and getline() can properly wait for the next input line.
    string arr[100];
    cout<<"enter strings :"<<endl;
    for(int i=0;i<n;i++){
    getline(cin,arr[i]);
    }

     sort(arr, arr + n);        //n is number of elements in the array

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "->";
    }

     return 0;
}