# DataStructures-And-Algorithms.

## Data Structures :-

### Data Structures is a way of storing/organising data in the memory, in such a way that access, management and modification become efficient.

## Algorithms :-

### Algorithms is any approach you use to perform operations on data (like searching, sorting, traversing, ..Etc.).


# Prerequisites :-

## 0. PROGRAMMING LANGUAGE.

****************************************************************************  
## 1. [CLASS AND OBJECTS.](https://youtu.be/DHVo9hvcQMI) 
   ### <b>CLASS</B> - Classes are type of gropus in which two things come variables and functions.
   ### <b>OBJECT</b> - These are individual instant/entity of the class that has some characheristics and behaviours.

   ```cpp
   #include<iostream>

using namespace std; // this is namespace

class car
{
    char color[10];
    public:
    int speed;

    public:
    void getdata(int distance, int fuel)
    {
        cout<<"The car has covered "<< distance << " km and has consumed " << fuel <<"L fule\n";
    }

    void mileage(float distance, float fuel);

    void carspeed()
    {
        cout<<"The car speed is" << speed <<"\n";
    }

} audi;

void car :: mileage(float d, float f)
{
    float carmileage = d/f;
    cout<<"The car mileage is " << carmileage <<"\n";
}

int main ()
{
    car swift;

    // swift.getdata(130, 7);
    // audi.getdata(150,25);
    // swift.mileage(130,7);

    swift.speed = 50;
    swift.carspeed();

    return 0;
}
```

****************************************************************************


## 2. ACCESS MODIFIERS IN C++.
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
   - <b>The private Members</b> - "Private" means personal that belongs to no one. So  no one can access the class members declared private, outside that class. If someone tries to access the private members of a class, they will get a compile time error. By default class variables and member functions are private.

```cpp
class PrivateAccess
{
    // private access modifier
    private:   
    int x;            // Data Member Declaration 
    void display();   // Member Function decaration
}
```

  - <b>The Protected Member</b> - "Protected" means to protect,preserve someone or something. Protected is similar to private, it makes class member inaccessible outside the class. But they can be accessed by any subclass of that class. (If class A is inherited by class B, then class B is subclass of class A.)We will learn it more in INHERITANCE .
   ```cpp
   class ProtectedAccess
{
    // protected access modifier
    protected: 
    int x;            // Data Member Declaration 
    void display();   // Member Function decaration
}
```



****************************************************************************

## 3. [CONSTRUCTOR.](https://youtu.be/DHVo9hvcQMI) - </b> Constructor has no return type not even void.
   
 
 ###  <b>There are 3 Types of Constructors in C++</b>
   ###    <b>DEFAULT CONSTRUCTOR</b> - Default constructor is the constructor which doesn't take any argument. It has no parameter.

```cpp
class_name(parameter1, parameter2, ...)
{ 
    // constructor Definition 
}
```
```cpp
#include <iostream>
using namespace std;

// declare a class
class  Wall {
  private:
    double length;

  public:
    // default constructor to initialize variable
    Wall() {
      length = 5.5;
      cout << "Creating a wall." << endl;
      cout << "Length = " << length << endl;
    }
};

int main() {
  Wall wall1;
  return 0;
}

/*  when the wall1 object is created, the Wall() constructor is called. This sets the length variable of the object to 5.5
*/

/* /*  /* Note-- If no constructor is defined in our class, then the C++ compiler will automatically create a default constructor with an empty code and no parameters.

*/ 
```
   ### <b>PARAMETERIZED CONSTRUCTOR</b> -  Parameterized Constructors are  constructor with parameters .

```cpp
#include <iostream>
using namespace std;

// declare a class
class Wall {
  private:
    double length;
    double height;

  public:
    // parameterized constructor to initialize variables
    Wall(double len, double hgt) {
      length = len;
      height = hgt;
    }

    double calculateArea() {
      return length * height;
    }
};

int main() {
  // create object and initialize data members
  Wall wall1(10.5, 8.6);
  Wall wall2(8.5, 6.3);

  cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
  cout << "Area of Wall 2: " << wall2.calculateArea();

  return 0;
}
```
  ###   <b>COPY CONSTRUCTOR</b> - Copy constructor  is used to copy data of one object to another.They are also used to run a default code when an object is created.

```cpp
#include <iostream>
using namespace std;

// declare a class
class Wall {
  private:
    double length;
    double height;

  public:

    // initialize variables with parameterized constructor
    Wall(double len, double hgt) {
      length = len;
      height = hgt;
    }

    // copy constructor with a Wall object as parameter
    // copies data of the obj parameter
    Wall(Wall &obj) {
      length = obj.length;
      height = obj.height;
    }

    double calculateArea() {
      return length * height;
    }
};

int main() {
  // create an object of Wall class
  Wall wall1(10.5, 8.6);

  // copy contents of wall1 to wall2
  Wall wall2 = wall1;

  // print areas of wall1 and wall2
  cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
  cout << "Area of Wall 2: " << wall2.calculateArea();

  return 0;
}

```

*************************************************************************



## 4. [DESTRUCTORS](https://youtu.be/DHVo9hvcQMI)
   - When are Destructor called ?
      - It is automatically called when program finish execution and when a scope(the {} parenthesis) containing local variables end.
   - It is a function similar to other ordinary function used to destroy or de allocate the memory block that has already been allocated by constructor.
      - It can have return type even void.
      - It cannot be overloaded.
      - It is automatically invoked or called when the life of object gets over or get out of scope.
      - Must have same value as the class
      - Symbol(~)
```cpp
~class_name()    
{   
   //Some code   
}
```
```cpp
#include <iostream>
using namespace std;
class HelloWorld{
public:
  //Constructor
  HelloWorld(){
    cout<<"Constructor is called"<<endl;
  }
  //Destructor
  ~HelloWorld(){
    cout<<"Destructor is called"<<endl;
   }
   //Member function
   void display(){
     cout<<"Hello World!"<<endl;
   }
};
int main(){
   //Object created
   HelloWorld obj;
   //Member function called
   obj.display();
   return 0;
}
```
   
   ************************************************************************
   
## 5. [INHERITANCE](https://youtu.be/DHVo9hvcQMI) 

   - Inheritance is the process where a class is derieved from its parent class and having the properties,characteristics of parent class.

   - What is child class?
      - A class that inherits another class is known as child class, it is also known as derived class or subclass.

   -  What is parent class?
      - The class that is being inherited by other class is known as parent class, super class or base class.

```CPP
      class parent_class
{
    //Body of parent class
};
class child_class : access_modifier parent_class
{
   //Body of child class
};
```
```cpp
// C++ program to demonstrate inheritance

#include <iostream>
using namespace std;

// base class
class Animal {

   public:
    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// derived class
class Dog : public Animal {
 
   public:
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

int main() {
    // Create object of the Dog class
    Dog dog1;

    // Calling members of the base class
    dog1.eat();
    dog1.sleep();

    // Calling member of the derived class
    dog1.bark();

    return 0;
}
```
   

 ###  <b> Types of Inheritance</b>
1) Single inheritance
2) Multilevel inheritance
3) Multiple inheritance
4) Hierarchical inheritance
5) Hybrid inheritance

 ###   <b>SINGLE INHERITANCE</b> - In Single inheritance one class inherits one class exactly.

   - B inherits A

```cpp
#include <iostream>
using namespace std;
class A {
public:
  A(){
     cout<<"Constructor of A class"<<endl;
  }
};
class B: public A {
public:
  B(){
     cout<<"Constructor of B class";
  }
};
int main() {
   //Creating object of class B
   B obj;
   return 0;
}
```

###   <b>MULTILEVEL INHERITANCE</b> - In this type of inheritance one class inherits another child class
   - C inherits B and B inherits A

   ```cpp
   #include <iostream>
using namespace std;
class A {
public:
  A(){
     cout<<"Constructor of A class"<<endl;
  }
};
class B: public A {
public:
  B(){
     cout<<"Constructor of B class"<<endl;
  }
};
class C: public B {
public:
  C(){
     cout<<"Constructor of C class"<<endl;
  }
};
int main() {
  //Creating object of class C
  C obj;
  return 0;
}
```


###   <b>MULTIPLE INHERITANCE</b> - In multiple inheritance, a class can inherit more than one class. 

   - C inherits A and B both
```cpp
#include <iostream>
using namespace std;
class A {
public:
  A(){
     cout<<"Constructor of A class"<<endl;
  }
};
class B {
public:
  B(){
     cout<<"Constructor of B class"<<endl;
  }
};
class C: public A, public B {
public:
  C(){
     cout<<"Constructor of C class"<<endl;
  }
};
int main() {
   //Creating object of class C
   C obj;
   return 0;
}
```

###   <b>HIERARCHIAL INHERITANCE</b> - In this type of inheritance, one parent class has more than one child class.

   - Class B and C inherits class A

```cpp
#include <iostream>
using namespace std;
class A {
public:
  A(){
     cout<<"Constructor of A class"<<endl;
  }
};
class B: public A {
public:
  B(){ 
     cout<<"Constructor of B class"<<endl;
  }
};
class C: public A{
public:
  C(){
     cout<<"Constructor of C class"<<endl;
  }
};
int main() {
   //Creating object of class C
   C obj;
   return 0;
}
```

###   <b>HYBRID INHERITANCE</b> - Hybrid inheritance is a combination of more than one type of inheritance. For example, A child and parent class relationship that follows multiple and hierarchical inheritance both can be called hybrid inheritance.


