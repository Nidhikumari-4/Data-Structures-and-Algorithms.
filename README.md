# DataStructures-And-Algorithms.

## Data Structures :-

### Data Structures is a way of storing/organising data in the memory, in such a way that access, management and modification become efficient.

## Algorithms :-

### Algorithms is any approach you use to perform operations on data (like searching, sorting, traversing, ..Etc.).


# Prerequisites :-

0. PROGRAMMING LANGUAGE. 
1. [CLASS AND OBJECTS.](https://youtu.be/DHVo9hvcQMI) 
   - <b>CLASS</B> - Classes are type of gropus in which two things come variables and functions.
   - <b>OBJECT</b> - These are individual instant/entity of the class that has some characheristics and behaviours.
2. [CONSTRUCTOR.](https://youtu.be/DHVo9hvcQMI)
3. ACCESS MODIFIERS IN C++.
   - <b>ACCESS MODIFIERS </b> -  Access modifiers are used to set boundaries for availability of members of class it can be  it's data members or member functions.You can use either one, two or all 3 modifiers in the same class to set different boundaries for different class members. 
   #### There are 3  ACCESS MODIFIERS in c++.


    - <b>The public Members</b> - "Public" means visible to all. So all the class members declared under public will be available to everyone. The data members and member functions declared under public member can be accessed by other classes too.

 ```cpp
    class PublicAccess
{
    // public access modifier
    public:   
    int x;            // Data Member Declaration 
    void display();   // Member Function decaration
}
```
<b>The private Members</b> - "Private" means personal that belongs to no one. So  no one can access the class members declared private, outside that class. If someone tries to access the private members of a class, they will get a compile time error. By default class variables and member functions are private.
```cpp
class PrivateAccess
{
    // private access modifier
    private:   
    int x;            // Data Member Declaration 
    void display();   // Member Function decaration
}
```
<b>The Protected Member</b> - "Protected" means to protect,preserve someone or something. Protected is similar to private, it makes class member inaccessible outside the class. But they can be accessed by any subclass of that class. (If class A is inherited by class B, then class B is subclass of class A.)We will learn it more in INHERITANCE .
```cpp
class ProtectedAccess
{
    // protected access modifier
    protected: 
    int x;            // Data Member Declaration 
    void display();   // Member Function decaration
}
```

