
#include <iostream>
class Queue1{
    public: char Queue[50]; 
    int front=-1; 
    int rear=-1;
    int size=50;
   int isEmpty(){ if((front==-1&&rear==-1)||front>rear){
      return 1;  
     } else return 0;
    }
  int  isFull(){if(rear==size-1){return 1;}
    else return 0; }
    char peek(){ if(!isEmpty())
        {return Queue[front];}
        else return '\0';
    }
    
   void enqueue(char x){ if(isFull()){std::cout<<"Queue full!";}        else{ if(front==-1&&rear==-1)
        { front=0; 
        rear=0; } else {rear=rear+1;}
        Queue[rear]=x; 
   }
    }
    char dequeue(){ if(isEmpty()){std::cout<<"Empty queue!";
    return '\0';} 
    else
   { char z= Queue[front];
        front=front+1;
       return z;}
      }
};
void NonRepeating(char Array[],int array_size){
    Queue1 q1;
   int freq[256]={0};
   
   for(int i=0;i<array_size;i++)
   {     q1.enqueue(Array[i]);
        freq[Array[i]]++;
    
     while(!q1.isEmpty() && freq[q1.peek()] >1)
    {      q1.dequeue();
        }  if(q1.isEmpty()){ std::cout<<"-1\n";}
       else std::cout<<q1.peek()<<std::endl;
        
     } 
    
}

int main() { char Array[5]={'a','a','b','b','d'};
    
NonRepeating(Array,5);
}
