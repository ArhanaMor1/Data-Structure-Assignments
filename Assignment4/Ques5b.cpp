#include <iostream>
#include <queue>
using namespace std;
class Stack{
queue <int> queue1;
public:
 
 void push(int x){ 
  queue1.push(x);
    if(!queue1.empty()){ 
        while(queue1.front()!=x)
        {queue1.push(queue1.front());
            queue1.pop();}
               }
    }
    
 int pop(){ int x=queue1.front();
 queue1.pop();
     return x;
  } 
  
  int top(){
      if(queue1.empty()){return -1;
          } else {
      return queue1.front(); }
  }
   int empty(){ 
    if(queue1.empty()){
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
