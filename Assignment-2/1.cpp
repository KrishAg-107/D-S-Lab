#include <iostream>
using namespace std;

int n;

void linear(int arr[],int element);
void binary(int arr[], int element);
void show(int arr[]);

int main(){
    int element;
    
    int arr_[100];
    cout<<"Enter number of elements: \n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr_[i];
    }
    
    show(arr_);
    cout<<"Enter element to be searched";
    cin>> element;

    binary(arr_,element);
    linear(arr_,element);

    return 0;
}

void show(int arr[]){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void linear(int arr[], int element){
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            cout<<"Element found at "<<i+1<<"th position \n";
            cout<<"Element found by linear search \n";
            break;
        }
        else{
            continue;
        }

    }
}

void binary(int arr[], int element){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==element){
            cout<<"Element found at "<<mid+1<<"th position \n";
            cout<<"element found by binary search \n";
            break;
        }
        else if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
}