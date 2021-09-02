class Solution {
public:
    int scoreOfParentheses(string S) 
    {
        int score = 0;
    stack<int> st;
    
    for(int i = 0; i < S.size(); i++)
    {
      if( S[i] == '(' )
      {
        st.push(score);
        score = 0;
      }
      else
      {
          //calculate score
        if(score == 0) 
            score = st.top() + 1;
        else 
            score = score*2 + st.top();
        st.pop();
      }
    }
    
    return score;
        
    }
};