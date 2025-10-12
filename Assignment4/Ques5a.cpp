
#include <iostream>
#include <queue>
using namespace std;
class Stack{
queue <int> queue1;
queue <int> queue2;
public:
 
 void push(int x){ if(queue1.empty()){
      queue1.push(x); 
      while(!queue2.empty())
      {
           int z=queue2.front();
              queue1.push(z);
              queue2.pop();
      }
 } else { 
      
              queue2.push(x);
              while(!queue1.empty())
              {int z=queue1.front();
              queue2.push(z);
              queue1.pop();}
        
       
    } 
 }
    
 int pop(){ if(!queue1.empty())
 {int x=queue1.front();
 queue1.pop();
     return x;
  } else if(queue1.empty()&&queue2.empty()){
      return -1;
  } else
  {int a=queue2.front();
 queue2.pop();
  return a;
  }
 }
  int top(){
      if(queue1.empty()){ if(queue2.empty()){
          return -1;
      } else {
          return queue2.front();}
          } else {
      return queue1.front(); }
  }
   
   int empty(){ 
    if(queue1.empty()&&queue2.empty()){
       return 1;
   } else return 0;
    }
 
};


int main()
{ Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    while (!s1.empty()){
    int a=s1.top();
    s1.pop();
    cout<<a<<"\n"; }
}
