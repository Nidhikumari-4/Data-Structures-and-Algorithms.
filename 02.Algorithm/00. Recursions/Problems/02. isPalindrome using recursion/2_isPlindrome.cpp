#include<iostream>
using namespace std;

 bool isPalindrome(string str,int s,int e){
     if(s>e)
        return true;
     else if(str[s]==str[e])
         return isPalindrome(str,s+1,e-1);
     else
        return false;
 }
int main(){
    string str="MADAM";
    int len=str.length();
    if (isPalindrome(str, 0, len - 1)) 
        cout << "Palindrome";
    else 
        cout << "Not Palindrome";
    return 0;
}