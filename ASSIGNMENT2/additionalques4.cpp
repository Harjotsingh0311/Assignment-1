#include<iostream>
#include<vector>
using namespace std;

//Dutch National Flag Algorithm

void sort012(vector<int>&arr){        //passing by reference
    int n=arr.size();
    int lo=0,mid=0;
    int hi=n-1;
    while(mid<=hi){
        if(arr[mid]==0){
            swap(arr[mid++],arr[lo++]);
        }else if(arr[mid]==1){
            mid++;
        }else if(arr[mid]==2){
            swap(arr[mid],arr[hi--]);
        }



    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(){
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();
    
    // sort the array in-place
    sort012(arr); 
    cout<<endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}