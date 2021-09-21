#include <iostream>
using namespace std;

int binarySearch(int arr[], int S, int beg, int end){
    int mid;
    if (beg > end){
        cout << "Number is not found";
        return 0;
    }
    else{
        mid = (beg + end) / 2;
        if (arr[mid] == S){
            cout << "Number is found at " << mid<<endl;
            return 0;
        }
        else if (arr[mid] < S){
            binarySearch(arr, S, mid + 1, end);
        }
        else if (arr[mid] > S){
            binarySearch(arr, S, beg, mid - 1);
        }
    }
}
int main()
{
    int i, n, beg = 0, mid, end, S;
    int arr[100];
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    cout << "Enter the sorted values: ";
    for (i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter a value to be search \n";
    cin >> S;
    end = n - 1;
    binarySearch(arr, S, beg, end);
    return 0;
}