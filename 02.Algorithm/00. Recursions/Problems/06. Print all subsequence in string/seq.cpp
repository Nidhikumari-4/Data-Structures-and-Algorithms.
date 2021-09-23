//Print all subsequences of a string

#include<iostream>
using namespace std;

void Subsequence(string s, string ans)
{
    if (s.length()==0) {
        cout << ans << endl;
        return;
    }
    //pick
    char ch=s[0];
    //not pick
    string ros=s.substr(1); //ros=rest of string
    
    Subsequence(ros,ans);
    Subsequence(ros,ans+ch);
}
int main()
{
  // two strings non empty and empty
   Subsequence("123","");
    return 0;
}
