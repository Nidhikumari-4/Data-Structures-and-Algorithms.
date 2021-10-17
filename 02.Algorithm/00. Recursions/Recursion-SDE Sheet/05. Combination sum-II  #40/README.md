## [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)
#### [Video Reference](https://youtu.be/G1fRTGRxXU8)

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans,             vector<int>&ds) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }        
    for(int i=ind; i<arr.size(); i++){
            if(i!=ind && arr[i]==arr[i-1]) continue;
            
            if(arr[i]<=target)
            {   
                target-=arr[i];
                ds.push_back(arr[i]);
                findCombination(i+1,target,arr,ans,ds);
                target+=arr[i];
                ds.pop_back();
            }
        }
    }
};
```