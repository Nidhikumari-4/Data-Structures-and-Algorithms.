class Solution {
public:
     bool isValid(string s) {
        stack<char> s1;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                s1.push(s[i]);
            
            else if(s[i]==')')
            {
                if(s1.empty() || s1.top()!='(')
                    return false;
                else
                    s1.pop();
            }
            
            else if(s[i]=='}')
            {
                if(s1.empty() || s1.top()!='{')
                    return false;
                else
                    s1.pop();
            }

            else if(s[i]==']')
            {
                if(s1.empty() || s1.top()!='[')
                    return false;
                else
                    s1.pop();
            }
        }
        
        if(s1.empty())
            return true;
        return false;
    }
};