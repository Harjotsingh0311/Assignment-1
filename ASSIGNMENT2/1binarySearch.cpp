#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr,int tar){
    int st=0,end=arr.size()-1;
    int mid;
    while(st<=end){
        mid=st+(end-st)/2;
        if(tar>arr[mid]){
            st=mid+1;
        }else if(tar<arr[mid]){
            end=mid-1;
        }else{
            return mid;
        }

    }
    return -1;
}

int main(){
    vector<int>arr1={1,3,4,5,6,8,9};       //odd len arr
    int tar1=8;
    cout<<binarySearch(arr1,tar1)<<endl;
     vector<int>arr2={1,3,4,5,6,8,9,11};       //even len arr
     int tar2=11;
     cout<<binarySearch(arr2,tar2)<<endl;
    return 0;
}