

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
void Subset(int ind,vector<int> ns,int sum,int arr[],int n)
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