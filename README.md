# DataStructures-And-Algorithms.

## Data Structures :-

#### Data Structures is a way of storing/organising data in the memory, in such a way that access, management and modification become efficient.

## Algorithms :-

#### Algorithms is any approach you use to perform operations on data (like searching, sorting, traversing, ..Etc.).


# Prerequisites :-

## 0. PROGRAMMING LANGUAGE. 
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
## 2. [CONSTRUCTOR.](https://youtu.be/DHVo9hvcQMI) - </b> Constructor has no return type not even void.
   
 
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
## 4. DESTRUCTORS
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
   
   ## 3. ACCESS MODIFIERS IN C++.
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
