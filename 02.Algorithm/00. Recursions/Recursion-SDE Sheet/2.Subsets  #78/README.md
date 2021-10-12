## [78. Subsets](https://leetcode.com/problems/subsets/)
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> temp;
        subsets(0,nums, ans, temp);
        return ans; 
    }
    void subsets(int start,vector<int>& nums, vector<vector<int>>& ans, vector<int> &temp) {
        
        if(start == nums.size()) {
            ans.push_back(temp);
            return;
        }
        //pick
        temp.push_back(nums[start]);
        subsets(start + 1,nums, ans, temp );
        // not pick
        temp.pop_back();
        subsets( start + 1,nums, ans, temp);
    }
}; 
```