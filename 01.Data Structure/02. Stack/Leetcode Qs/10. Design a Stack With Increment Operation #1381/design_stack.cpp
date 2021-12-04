class CustomStack
{
    int top;
    int arr[1000];
   int n;// size of stack
    
public: 
     CustomStack(int maxSize)
     {
         top=-1;
         n=maxSize;
         
    for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
     }
    
   void push(int x) 
   {
      if (top != n-1)
      {
          top++; 
		  arr[top] = x;
      }  
    }
    
     int pop()
     {
        if (top == -1) return -1;
        else
        {
            int popValue = arr[top];
	      arr[top] = 0;
	      top--;
	      return popValue;
        }
    }
    
    void increment(int k, int val) 
    {
         if(top>=k)
        {
            for(int i=0;i<k;i++)
            {
                arr[i] += val;
            }
        }
        else
        {
            for(int i=0;i<=top;i++)
            {
                arr[i] +=val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */