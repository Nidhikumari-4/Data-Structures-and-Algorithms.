## [39.Combination](https://leetcode.com/problems/combination-sum/)
#### [Video Reference](https://youtu.be/OyZFFqQtu98)

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans;  
     }
     void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans,            vector<int>&ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(ds); 
            }
            return; 
        }
        // pick up the element 
        if(arr[ind] <= target) {
            target-=arr[ind];
            ds.push_back(arr[ind]);
            findCombination(ind,target,arr,ans,ds);
        // not pick
            target+=arr[ind];
            ds.pop_back();
        }
        findCombination(ind+1, target, arr, ans, ds);    
    }
};
```