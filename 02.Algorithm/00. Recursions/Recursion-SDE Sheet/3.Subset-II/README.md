## [90. Subsets II](https://leetcode.com/problems/subsets-ii/)
#### [Video Reference](https://youtu.be/RIn3gOkbhQE)

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subSet(0,nums,ans,temp);
        return ans;
    }
    void subSet(int ind,vector<int> &nums,vector<vector<int>>&ans,vector<int> &temp){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
                temp.push_back(nums[i]);
            subSet(i+1,nums,ans,temp);
            temp.pop_back();
        }
    } 
};
```