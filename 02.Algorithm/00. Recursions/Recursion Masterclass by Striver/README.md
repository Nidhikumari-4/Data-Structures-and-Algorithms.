# [**LECTURE-1**](https://youtu.be/cHMr5-0SDAA)

## [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
```cpp
//Print Fibonacci Number Series upto N
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
        return n;
    int a = fib(n - 1);
    int b = fib(n - 2);
    return a + b;
    }
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacii series upto " << n << " is " << fib(n);
    return 0;
}
};
```

## [344. Reverse String](https://leetcode.com/problems/reverse-string)
```cpp
class Solution {
public:
    void reverseString(vector<char>& s,int start, int end) {
        if(start>=end)
            return ;
        swap(s[start], s[end]);
        reverseString(s, start+1, end-1);
    }
    void reverseString(vector<char>& s) {
       reverseString(s,0,s.size()-1);
        return ;
    }
};
```
## BS using recurrsion
```cpp
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
```
## isPalindrome String using recurssion
```cpp
#include<iostream>
using namespace std;

 bool isPalindrome(string str,int s,int e){
     if(s>e)
        return true;
     else if(str[s]==str[e])
         return isPalindrome(str,s+1,e-1);
     else
        return false;
 }
int main(){
    string str="MADAM";
    int len=str.length();
    if (isPalindrome(str, 0, len - 1)) 
        cout << "Palindrome";
    else 
        cout << "Not Palindrome";
    return 0;
}
```
# [**LECTURE-2**](https://youtu.be/QbDAWmuOn5Y)
## [Print all subsequences of a string - GFG](https://www.geeksforgeeks.org/print-subsequences-string/)

```cpp
//Print all subsequences of a string

#include<iostream>
using namespace std;

void Subsequence(string s, string ans)
{
    // if input is empty print the output string
    if (s.length()==0) {
        cout << ans << endl;
        return;
    }
    //pick
    char ch=s[0];
    //non pick
    string ros=s.substr(1); //ros=rest of string
    
    Subsequence(ros,ans);
    Subsequence(ros,ans+ch);
}
int main()
{
  // two strings non empty and empty
   Subsequence("123","");
    return 0;
}
```
## Print  all the subsequences whose sum is divisible by k
```cpp
#include <bits/stdc++.h>
using namespace std;

int k=3;
void Subset(int ind,vector<int> &ns,int sum,int arr[],int n)
{
    if (ind==n ) {
        if (sum %k == 0 && ns.size()!=0){
        for (auto x : ns)
            cout << x << " ";
        cout << endl;
       }
        return;
    }
   ns.push_back(arr[ind]);
   sum+=arr[ind];
   // pick
   Subset(ind+1,ns,sum,arr,n);
   ns.pop_back();
    sum-=arr[ind];
    // not pick
    Subset(ind+1,ns,sum,arr,n);
}
int main(){
    int ind,sum=0;
    vector<int> ns;
    int arr[]={4,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
   Subset(ind,ns,sum,arr,n);
    return 0;
}

```

## WAF which returns Count of all the subsequences whose sum are divisible by K.
#### Note: You can't declare globally nor internally a count variable and use it as a counter.
- Example : arr[]={3,6} k=3 
```cpp
#include <bits/stdc++.h>
using namespace std;

int k;

int Subset(int ind,int arr[],int sum,int n)
{
    if (ind==n ){
        if (sum %k == 0 )
            return 1;
        else
        return 0;
    }  
    // pick
   sum+=arr[ind];
   int l=Subset(ind+1,arr,sum,n);
   // not pick 
   sum-=arr[ind]; 
   int r= Subset(ind+1,arr,sum,n);
    return l+r;

int ans=Subset(0,arr,0,0)-1; //  to avoid empty set
}
int main(){
    int ind,sum=0;
    int arr[]={3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
   Subset(ind,arr,sum,n);
    return 0;
}
```
## [Subset Sums - GFG](https://practice.geeksforgeeks.org/problems/subset-sums2234/1#)
```cpp
class Solution{
    public:
    void fun(int ind,int sum,vector<int>&arr,int N,vector<int> &sumSubset){
        if(ind==N)
        {
           sumSubset.push_back(sum);
           return;
        }
        // pick
        fun(ind+1,sum+arr[ind],arr,N,sumSubset);
        // not pick
        fun(ind+1,sum,arr,N,sumSubset);
    }
    public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int>sumSubset;
        fun(0,0,arr,N,sumSubset);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    };
};  
```
## [Subset Sum Problem-GFG ](https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#)
```cpp
class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        if(N==0 || sum<0)
            return false;
        if(sum==0)
            return true;
        if(arr[N-1]==0 && sum!=0)
            return false;
        
        int L,R;
        if(arr[N-1]>sum){
            L=isSubsetSum(N-1,arr,sum);
            return L;
            R=isSubsetSum(N-1,arr,sum-arr[N-1]);
        }
        return L || R;
    }
};
```
# [**LECTURE-3**]()
