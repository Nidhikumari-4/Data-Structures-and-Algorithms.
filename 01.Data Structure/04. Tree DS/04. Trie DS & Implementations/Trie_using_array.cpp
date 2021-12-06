#include<iostream>
using namespace std;


class Trie_Arr{
    public:
    class Node{
        public:
        int count;
        Node* next[26];
        bool isEnd;

    Node(){
        isEnd=false;
        count=0;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
  };
  Node* root; 
  int count; // this will keep the count for the no. of words formed using particular character

  Trie_Arr(){
      root=new Node();
      count=0;
  }


  void insert(string word){
      Node* curr=root;
      for(int i=0;i<word.size();i++){
          if(curr->next[word[i]-'a']==NULL){
              curr->next[word[i]-'a']=new Node();
          }
          curr=curr->next[word[i]-'a'];
          count++;
      }
      curr->isEnd=true;
      
  }
  bool search(string word){
     Node* curr=root; 
      for(int i=0;i<word.size();i++){
        if(curr->next[word[i]-'a']==NULL){
            return false;
        }
        curr=curr->next[word[i]-'a'];
     }  
     return curr->isEnd;
	}
    // return true if any word with "prefix" is present in trie
  bool startWith(string prefix){
      Node* curr=root;
      for(int i=0;i<prefix.size();i++){
          if(curr->next[prefix[i]-'a']==NULL){
              return false;
          }
          curr=curr->next[prefix[i]-'a'];
      }
      cout<<"NO. OF STRINGS FORMED USING PREFIX- "<<prefix<<" is = "<<endl<<curr->count<<endl;
      return true;

  }
  void Delete(string word){
      if(search(word)){
          Node* curr=root;
          for(int i=0;i<word.size();i++){
              curr=curr->next[word[i]-'a'];
          }
          curr->isEnd=false;
          cout<<"Deleted"<<endl;
        }
      else{
          cout<<"Word not found"<<endl;
          return;
      }
  }
};

int main(){
    Trie_Arr trA;
Trie_Arr* tr=new Trie_Arr();
        tr->insert("antman");
	tr->insert("ant");
	tr->insert("batman");
	tr->insert("bat");
	tr->insert("batball");
	tr->insert("nidhi");
	tr->insert("anu");
        tr->insert("test");
        tr->insert("testing");
        cout<<tr->search("batb")<<endl;
        cout<<tr->search("hello")<<endl;
        cout<<tr->search("ant")<<endl;
        cout<<tr->search("bat")<<endl;
        cout<<tr->search("antman")<<endl;
        cout<<tr->search("nidhi")<<endl;
        cout<<tr->startWith("an")<<endl;
        cout<<tr->startWith("nidh")<<endl;
        cout<<tr->startWith("bat")<<endl;
        //checking delete function
        cout<<tr->search("ant")<<endl;
        tr->Delete("ant");
        cout<<tr->search("ant")<<endl;
    return 0;
}
