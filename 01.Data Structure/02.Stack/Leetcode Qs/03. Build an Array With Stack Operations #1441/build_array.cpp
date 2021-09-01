class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
         vector<string>ans;
        int j=0;
        for(int i=1;i<=n;i++){
            if(j>=target.size())
                break;
            if(target[j]==i){
                ans.push_back("Push");
                j++;
            }
            else{
                ans.push_back("Push");
                    ans.push_back("Pop");
            }
        }
        return ans;
        
    }
};