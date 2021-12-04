class Solution {
public:
    string removeOuterParentheses(string S) 
    {
        string str = ""; //new empty string 
        stack<char> s;
    
        for(int i=0; i<S.size(); i++) 
        {
            if(s.empty())
            {
                s.push(S[i]);
            }
            else
            {                
               if(s.top()=='(' && S[i]==')')           
                {
                    s.pop();
                }
                else 
                    s.push(S[i]);
                if(!s.empty()) 
                    str =str+ S[i];
            }
        }       
        return str;
    }
};