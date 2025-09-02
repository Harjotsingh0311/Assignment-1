#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


int countPair(vector<int>arr,int n){
	int k=3;
    int i=0,j=0;
    int cnt=0;
	while(j<n){
        if(arr[j]-arr[i]<k){
			j++;
		}else if(arr[j]-arr[i]>k){
			i++;
		}
		else{
			int ele1 = arr[i], ele2 = arr[j];
            int cnt1 = 0, cnt2 = 0;
          
            // Count frequency of first element of the pair
            while(j < n && arr[j] == ele2) {
                j++;
                cnt2++;
            }
          
            // Count frequency of second element of the pair
            while(i < n && arr[i] == ele1) {
                i++;
                cnt1++;
            }
          
            // If both the elements are same, then count of
            // pairs = the number of ways to choose 2 
            // elements among cnt1 elements
            if(ele1 == ele2)                                                //They might be the same value (only possible when k = 0). → use nC2 formula.
            	cnt += (cnt1 * (cnt1 - 1))/2;
          
            // If the elements are different, then count of
            // pairs = product of the count of both elements
            else                                                            //They might be different values. → use product of counts.
            	cnt += (cnt1 * cnt2);
		}
	}
    return cnt;
	
}




//void sortArray(vector<int> arr,int n){
//	for(int i=0;i<n-1;i++){
//		for(int j=0;j<n-1-i;j++){
//			if(arr[j]>arr[j+1]){
//				swap(arr[j],arr[j+1]);
//			}
//		
//		}
//	}
//}
int main(){
	vector<int> arr={1,4,1,4,5};
	//sortArray(arr,5);
	
	// DIRECT SORTING
	sort(arr.begin(),arr.end());
	cout<<countPair(arr,5);	
	
return 0;
}





//Yes, in C++, std::sort from the <algorithm> header is the standard and most common way to sort vectors and arrays. You generally write it like this:
//
//std::sort(container.begin(), container.end());
//
//
//(for vectors or other STL containers)
//
//or
//
//std::sort(array, array + size);
//
//
//(for raw arrays)