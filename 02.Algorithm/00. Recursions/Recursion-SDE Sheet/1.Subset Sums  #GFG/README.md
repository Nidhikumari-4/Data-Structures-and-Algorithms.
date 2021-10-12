## [Subset Sums](https://practice.geeksforgeeks.org/problems/subset-sums2234/1)
```cpp
class Solution
{
    public:
    void fun(int ind,int sum,vector<int>&arr,int N,vector<int> &sumSubset)
    {
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
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>sumSubset;
        fun(0,0,arr,N,sumSubset);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    };
};
```