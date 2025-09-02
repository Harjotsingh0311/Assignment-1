#include<iostream>
#include<vector>
using namespace std;
//LINEAR TIME
void missingElement(int arr[],int n){
    for(int i=0;i<n;i++){
        if((i+1)!=arr[i]){
            cout<<"the missing element in the sorted array is "<<arr[i]-1<<endl;
        }
    }
}


//USING BINARY SEARCH

int missingEleBinarySearch(int arr[],int n){
    int st=0,end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==mid+1){
            st=mid+1;
        }else{
            end=mid-1;
            if(arr[mid-1]==mid){
                return mid+1;
            }
        }
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7,9};
    missingElement(arr,8);

    cout<<"missing ele is "<<missingEleBinarySearch(arr,8)<<endl;
    return 0;
}