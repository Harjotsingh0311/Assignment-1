#include<iostream>
using namespace std;

void Reverse_elements(int arr[],int size){

for(int i=0;i<size/2;i++){
    int temp=arr[size-1-i];
    arr[size-1-i]=arr[i];
    arr[i]=temp;
}


}

int main() {
    int arr[25] = {4, 5,5, 7, 7,13, 8};
    int size = 7;
    
    bool duplicate=false;
    Reverse_elements(arr, size);
    
  
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
