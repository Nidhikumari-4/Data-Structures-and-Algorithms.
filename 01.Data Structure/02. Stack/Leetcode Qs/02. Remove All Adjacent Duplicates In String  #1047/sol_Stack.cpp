class Solution {
public:
    string removeDuplicates(string s) {
      list<char>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()||st.back()!=s[i])
            {
                st.push_back(s[i]);
            }
            else{
                st.pop_back();
            }
        }
        return string(st.begin(),st.end());
   }
};