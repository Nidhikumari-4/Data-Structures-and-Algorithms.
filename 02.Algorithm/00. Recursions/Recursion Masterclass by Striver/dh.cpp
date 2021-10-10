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
    cout<<count;
}
int main(){
    cin>>m>>n;
    vector<vector<int>>vis(n, vector<int>(m,0));
    cout<<findPath(0,0," ",vis);
    return 0;
}