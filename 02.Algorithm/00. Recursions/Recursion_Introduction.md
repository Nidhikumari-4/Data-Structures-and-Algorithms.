# **Recursion**
### **How Function call works in a launguage?**
- while the function is not finished executing it will remain in stack.
- when a function finishes executing it is removed from stack and the flow of program is over.

 ### **What is recursion?**
 - #### In simple words a function that calls itself.

 ### **Why do we need recursion?**
 - #### It helps us in solving bigger/complex problems in simple way.
 - #### You can convert recursion solutions into iteration(loops) and vice versa.
- #### Space complexity is not constant because of recursion calls. 
- #### Helps us in breaking down bigger problems into smaller problems.

### **How to understand & approach a problem ?**
1.  Identify if you can break down problem into smaller problems .
2. Write the recurance relation if needed.
3. Draw the recursive tree.
4. About the tree:
   - see the flow of functions,how they are getting in stack.
   - Identify & focus on left tree calls and right tree calls.
   - Draw the tree and pointers again and again using pen & paper.
   - Use a debugger to see the flow. 
5. See how the values & what type of values(int,string,etc.) are returned  at each step.
6. See where the function call will come out.
7. In the end,you will come out of the main function.
8. Make sure to return   the result of a function and of the value type.

```cpp
/* Calculate the factorial of a nimber.
 factorial of 5: 5*4*3*2*1=120 
 
 1. Divide the problem into smaller sub problem.

 Calulate fact(4)
 Fact(1)=1
 Fact(2) = 2*1 = 2*fact(1)
 Fact(3) = 3*2*1 = 3*fact(2)
 Fact(4) = 4*3*2*1 = 4*fact(3)

 Fact(n) = n * Fact(n-1)

 2. Specify the base codition to stop recursion.
 */

#include<iostream>
using namespace std;

int fact(int n){
    if(n==1)
    return 1;
    else
    return n*fact(n-1);
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Factorial of a number "<< n <<" is "<< fact(n);
    return 0;
}

/*
fact(5) // 120 
   |
   5*fact(4) // 5*24=120
        |
      4*fact(3) // 4*6=24
           |
          3*fact(2) // 3*2=6
               |
             2*fact(1) // 2*1=2
                  |
                 return 1  // 1
```