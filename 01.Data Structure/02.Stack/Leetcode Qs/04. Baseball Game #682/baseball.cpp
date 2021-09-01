class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int> s;
        int sum=0;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                s.pop();
            }
            else if(ops[i]=="+")
            {
                int sum1=s.top();
                s.pop();
                int sum2=s.top();
                s.push(sum1);
                s.push(sum1+sum2);
            }
            else if(ops[i]=="D")
            {
                s.push((s.top())*2);
            }
            else
            {
                s.push(stoi(ops[i]));
            }
        }
        while(!s.empty())
        {
            sum=sum+s.top();
            s.pop();
        }
        return sum;
        
    }
};