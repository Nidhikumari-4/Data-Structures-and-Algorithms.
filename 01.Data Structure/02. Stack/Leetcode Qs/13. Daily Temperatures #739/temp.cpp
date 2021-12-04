class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        int n=T.size();
        vector<int> ans(n,0);  //Create a vector of size n with all values as 0.
        if(n<=1)
            return ans;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&T[i]>=T[st.top()])
               st.pop();
            if(!st.empty())
                ans[i]=st.top()-i;
           st.push(i);
        }
        return ans;
        
        
    }
};