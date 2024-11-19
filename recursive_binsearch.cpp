#include<iostream>
using namespace std;

void binarySearch(int arr[],int search,int low,int high){
    if(low>high){
        cout<<"Element not found in the array"<<endl;
        return;
    }
    else{
        int mid=(low+high)/2;
        if(arr[mid]==search){
            cout<<"Element found at index "<<mid<<endl;
            return;        
        }
        else if(arr[mid>search]){
            binarySearch(arr,search,low,mid-1);
        }
        else{
            binarySearch(arr,search,mid+1,high);
        }
    }
}

int main(){
    int arr[100];
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Eneter element"<<i+1<<":";
        cin>>arr[i];
    }
    int search;
    cout<<"Enter the element to search:",
    cin>>search;
    int low=0;
    int high=n-1;
    binarySearch(arr,search,low,high);
}