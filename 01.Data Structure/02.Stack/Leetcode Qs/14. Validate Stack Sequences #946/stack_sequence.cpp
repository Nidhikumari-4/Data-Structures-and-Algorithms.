class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    
    {
        int i=0;
        int index=0;
        stack<int> st;
        
        for(int val:pushed)
        {
            st.push(val);            
            while(!st.empty() && popped[index]==st.top())
            {
                st.pop();
                index++;
            }
        }
        return st.empty();
    }
};