# **Trie Data Structure**

![](https://i.ibb.co/GJfR5kt/1-rkan-FIU4-G-tmu-C939-txh-A.jpg)

### A trie is a tree-like data structure whose nodes **(it can have N no. of nodes)** store the letters of an alphabet. By structuring the nodes in a particular way, words and strings can be retrieved from the structure by traversing down a branch path of the tree.

<hr>

# **General overview on TRIE DS formation**

## **Remember :** Every Node has 26pointers (for each alphabets) although they are not shown here.

![](https://i.ibb.co/Z8j17Rs/1-K7-LHR1-JFGIP-4-Auz-Jel4-A.png)

<hr>

# **What's in a Single Node of Trie ?**

![](https://i.ibb.co/g3Zb6bj/Trie-DS.png)

<hr>

## **Insertion of Words in a Trie**

```cpp
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
```

<hr>

## **[Video Reference 1](https://youtube.com/playlist?list=PL6Zs6LgrJj3uwRyATdtSua12k9EFQIW50)**

## **[Video Reference 2](https://youtu.be/Kqfckuz0pcw)**

## **[Implementation of Trie using Array.](./Trie_using_array.cpp)**

- ## **[Video Reference ](https://youtu.be/dOXfffhl4uI)**

## **[Implementation of Trie using HashMap.](./Trie_using_hashmap.cpp)**

- ## **[Video Reference ]()**

**Trie using HashMap give you the edge in inserting any string containing any character over Trie using Array + Trie using HashMap has less space complexity.**

<hr>
<h1 align="center"><b>THANK YOU</b></h1>