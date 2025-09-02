#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){       // in case if array is alredy sorted or array sorted before completing all the iterations
            return;
        }
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}
int main(){
    int arr[]={64,34,25,12,22,11,90};
    bubbleSort(arr,7);
    display(arr,7);
    return 0;
}

// When you pass arr to bubbleSort, you’re not passing the whole array by value.
// In C++, when you write int arr[] as a function parameter, it decays into a pointer → int* arr.

// So actually your function signature:

// void bubbleSort(int arr[], int n);


// is equivalent to

// void bubbleSort(int* arr, int n);


// That means inside bubbleSort, arr points to the same memory location as the original array in main