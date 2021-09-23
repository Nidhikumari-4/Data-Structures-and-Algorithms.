#include<iostream>
using namespace std;

void print(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
void reverse(int arr[], int start, int end){
     if (start >= end)
        return;
    else{
        swap(arr[start], arr[end]);
        reverse(arr,start + 1, end - 1);
    }
}
int main(){
    int arr[] = {10,20,56,89,19,22,58,2,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, 0, n-1);
    print(arr, n);
    return 0;
}