#include<iostream>
using namespace std;

int Remove_duplicate(int arr[],int size,bool duplicate){
int times=0;
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]==arr[j]){
            times++;
            for(int k=j;k<size;k++){
                arr[k]=arr[k+1];
            }
            cout<<"DUPLICATE!!!!----\n";
            size--;
            duplicate=true;
        }
    }
}

if(duplicate==false){
            cout<<"no duplicate element!!\n";
        }
        return times;
}

int main() {
    int arr[25] = {4, 5,5, 7, 7, 8};
    int size = 6;
    
    bool duplicate=false;
    int times=Remove_duplicate(arr, size,duplicate);
    
    for(int i=0;i<times;i++){
        size--;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
