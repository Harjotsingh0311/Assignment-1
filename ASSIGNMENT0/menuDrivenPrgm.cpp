#include<iostream>
using namespace std;

    int arr[100];  // fixed max size
    int n = 0;     // current size of array


    void create(){
        cout<<"enter the size of array:";
        cin>>n;

        cout<<"start entering the elements";
        cout << "Enter " << n << " elements: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];

        }
                for(int i=0;i<n;i++){
            cout<<arr[i]<<"\n";
        }
        return;
    }
    
    void display(){
        cout<<"elements in the array are:\n";
        cout<<"value of n is"<<n<<"\n";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<"\n";
        }

    }
        void insert(){

            int pos, element;
            cout << "Enter position (0-based index): ";
            cin >> pos;
            cout << "Enter element to insert: ";
            cin >> element;

            if (pos < 0 || pos > n) {
                cout << "Invalid position!\n";
            } else {
                // shift elements right
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = element;
                n++;
                cout << "Element inserted successfully!\n";

                cout<<"value of n is "<<n<<endl;
            }
        
    }   
    
    void Delete(){
        int pos;
        cout << "Enter position (0-based index) of element you want to delete: ";
        cin >> pos;

            if (pos < 0 || pos > n) {
            cout << "Invalid position!\n";
            } else{

        for(int i=pos;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        n--;
        cout<<"element deleted sucessfully!!!\n";

        cout<<"value of n is"<<n<<endl;
            }

    }   
    
    void search(){
        int ele;
        cout<<"enter the element you want to search:";
        cin>>ele;
        bool found=false;
        for(int i=0;i<n;i++){
            if(arr[i]==ele){
                cout<<"element found at index "<<i<<endl;
                found=true;
                break;
            }
            
            
        }if(found==false){
            cout<<"Element not found in the array!\n";
        }

    }   
    
    void Exit(){
        cout<<"EXITING-------!!!!";
    }

int main(){
    int choice; 

    do{
    cout<<"--MENU--\n 1-> Create\n 2-> Display\n 3-> Insert\n 4->Delete\n 5-> Search\n 6-> Exit\n";
    cout<<"Enter your choice(number) : ";
    
    cin>>choice;


    
    switch(choice){
        case 1:create();
                break;
        case 2:display();
                break;
        case 3:insert();
                break;
        case 4:Delete();
                break;
        case 5:search();
                break;
        case 6:Exit();
                break;
        default:
        cout<<"Invalid choice !!!";
    }
}while(choice!=6);
    return 0;
}
