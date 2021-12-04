class Solution {
public:
    string removeDuplicates(string s) {
          string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(ans.size()>0 && ans.back() ==s[i]) //if last character equals s[i] we have to delete
               ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
        
      }
};