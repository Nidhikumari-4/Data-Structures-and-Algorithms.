class Solution {
public:
    string makeGood(string s) 
    {
        stack<char> St;
        for(int i=0;i<s.length();i++)
        {
            if(St.empty())
                St.push(s[i]);
            else
            {
                if(abs(St.top()-s[i])==32) // a(97) - A(65) = 32
                    St.pop();
                else
                    St.push(s[i]);
            }
        }
        string ans="";
        while(!St.empty()){
            ans=St.top()+ans;
            St.pop();
        }
        return ans;
        
    }
};