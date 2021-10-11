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
**
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
# [**LECTURE-3**](https://youtu.be/uisK9EJQcaY)

## Print the subsequence whose sum=k repetation allowed.
#### **Note** - when you pick we don't go to next Index.
- For Examples: arr={1,2,3} 
- sum=4
- {1,1,1,1}, {1,3}, {1,1,2}, {2,2}.


```cpp
**
#include<iostream>
using namespace std;

int countF(int ind,int sum,int arr[],int n){
    if(sum==0)
      return 1;
    if(ind==n){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    int left=0;
    int right=0;

    //pick
    //when can you pick a particular element
    if(arr[ind]<=sum){
        //sum will decrease
        sum-=arr[ind];
        left=countF(ind,sum,arr,n);
        // restore sum
        sum+=arr[ind];
    }
    //not pick means move to next INDEX
    right=countF(ind+1,sum,arr,n);
    return left+right;
}

int main()
{
    int ind,sum=4,n;
    int arr[3]={1,2,3};
    n = sizeof(arr) / sizeof(arr[0]);
    countF(ind,sum,arr,n);
    return 0;
}
```
## Print all the paths in Matrix 
- 2 directions LEFT , RIGHT 
```cpp
#include<iostream>
using namespace std;

int m,n;
void findPath(int i,int j,string s){
    if(i>=n||j>=m) 
       return;
    if(i==n-1&&j==m-1){
        cout<<s<<endl;
        return;
    }
    //down
    s+='D';
    findPath(i+1,j,s);
    s.pop_back();
    //right
    s+='R';
    findPath(i,j+1,s);
    s.pop_back();
}
int main()
{
    cin>>m>>n;
    findPath(0,0," ");
    return 0;
}
```
## Print all the paths in Matrx
#### **NOTE** - In a path, no cell can be visited more than one time
- Same as above ques only the difference is here we have taken 4 directions
- LEFT , RIGHT , UP , DOWN


```cpp
#include <bits/stdc++.h>
using namespace std;

int m,n;
void findPath(int i,int j,string s,vector<vector<int>> &vis){
    if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1) 
       return;
    if(i==n-1 && j==m-1){
        cout<<s<<endl;
        return;
    }
    vis[i][j]=1;

    //down
    s+='D';
    findPath(i+1,j,s,vis);
    s.pop_back();
    //right
    s+='R';
    findPath(i,j+1,s,vis);
    s.pop_back();
    //up
    s+='U';
    findPath(i-1,j,s,vis);
    s.pop_back();
    //left
    s+='L';
    findPath(i,j-1,s,vis);
    s.pop_back();

    vis[i][j]=0;
}
int main(){
    cin>>m>>n;
    vector<vector<int>>vis(n, vector<int>(m,0));
    findPath(0,0," ",vis);
    return 0;
}
```
## Little optimized Sol of above Ques
```cpp
#include <bits/stdc++.h>
using namespace std;

string dir="DRUL";
int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};
int m,n;
void findPath(int i,int j,string s,vector<vector<int>> &vis){
    if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1) 
       return;
    if(i==n-1 && j==m-1){
        cout<<s<<endl;
        return;
    }
    vis[i][j]=1;

    for(int x=0;x<4;x++){
        s+=dir[x];
        findPath(i+di[x],j+dj[x],s,vis);
        s.pop_back();
    }
    vis[i][j]=0;
}
int main(){
    cin>>m>>n;
    vector<vector<int>>vis(n, vector<int>(m,0));
    findPath(0,0," ",vis);
    return 0;
}
```
## Count paths
```cpp
#include <bits/stdc++.h>
using namespace std;

string dir="DRUL";
int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};
int m,n;
int findPath(int i,int j,string s,vector<vector<int>> &vis){
    if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1 ) 
       return 0;
    if(i==n-1 && j==m-1){
        return 1;
    }
    vis[i][j]=1;
    int count=0;
    for(int x=0;x<4;x++)
    {
        count+=findPath(i+di[x],j+dj[x],s,vis);
    }
    vis[i][j]=0;
    return count;
}
int main(){
    cin>>m>>n;
    vector<vector<int>>vis(n, vector<int>(m,0));
    cout<<findPath(0,0," ",vis);
    return 0;
}
```
# [**LECTURE-4**](https://youtu.be/r9af_mSpBLo)
## Print only one subsequences whose sum is divisible by K.
``` cpp
#include <bits/stdc++.h>
using namespace std;

int k=3;
bool Subset(int ind,vector<int> &ns,int sum,int arr[],int n)
{
    if (ind==n ) {
        if (sum %k == 0 && ns.size()!=0){
            for (auto x : ns){
                cout << x << " ";
                cout << endl;
       }
        return true;
    }
    return false;
    }
   ns.push_back(arr[ind]);
   sum+=arr[ind];
   // pick
   if(Subset(ind+1,ns,sum,arr,n)==true)
   {
       return true;
   }
   ns.pop_back();
    sum-=arr[ind];
    // not pick
    if(Subset(ind+1,ns,sum,arr,n)==true){
        return true;
    }
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
## N Queens This will print only one valid Nqueen - Approach 1
```cpp
int n;
bool isSafe(int row, int col, vector<vector<int>>&mat){

    //up digonal i--,j--
     for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(mat[i][j]==1) return false;
    }
    // left i,j--
    for(int i=row,j=col; i>=0 && j>=0; j--){
         if(mat[i][j]==1) return false;
    }
    // down digonal i++, j-- 
    for(int i=row,j=col; i<n && j>=0; i++,j--){
        if(mat[i][j]==1) return false;
    }
    return true;
}
bool nQueens(int col, vector<vector<int>>&mat){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int row=0; row<n; row++){
        if(isSafe(row,col,mat)){
            mat[row][col]=1;
            if(nQueens(col+1,mat)==true) return true;
            mat[row][col]=0;
        }
    }
    return false;
}
```
## N Queens This will print only one valid Nqueen - Approach 2
###  Here we have optimised isSafe() method instead of ittirating.We made 3 arrays to hash left, upLeftDigonal, downLeftDigonal so TC of isSafe() turns to O(1).
```cpp
int n;
bool isSafe(int row, int col, vector<vector<int>>&mat, vector<vector<int>>&rowHash, vector<vector<int>>&thirdHash, vector<vector<int>>&firstHash){

      if(rowHash[row]==1 || thirdHash[row+col]==1 || firstHash[n-1+row-col]==1 )  return false;
      return true;            
}
bool nQueens(int col, vector<vector<int>>&mat, vector<vector<int>>&rowHash, vector<vector<int>>&thirdHash, vector<vector<int>>&firstHash){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int row=0; row<n; row++){
        if(isSafe(row,col,mat,rowHash,thirdHash,firstHash)){
            mat[row][col]=1;
            rowHash[row]=1; // left 
            thirdHash[row+col]=1; //down left Diagonal 
            firstHash[n-1+row-col]=1; // upper left diagonal
        if(nQueens(col+1,mat,rowHash,thirdHash,firstHash)==true) return true;
            mat[row][col]=0; 
            rowHash[row]=0;//not taken
            thirdHash[row+col]=0;
            firstHash[n-1+row-col]=0;
        }
    }
    return false;
}
int main(){
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    vector<vector<int>> rowHash(n,0);    
    vector<vector<int>> thirdHash(2*n-1,0);
    vector<vector<int>> firstHash(2*n-1,0);
    nQueens(0,mat, rowHash,thirdHash,firstHash);
    return 0;
}
```