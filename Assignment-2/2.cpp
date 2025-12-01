#include <iostream>
using namespace std;

void bubble_sort(int arr[]){
    for (int i=0;i<6;i++){
        for (int j=0; j<6-i;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={64,34,25,12,22,11,90};
    bubble_sort(arr);
    for (int i=0;i<7;i++){
        cout<<arr[i]<<endl;
    }
}