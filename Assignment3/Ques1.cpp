#include <iostream>
int size=50;
int stack[50];
int top = -1; 
void push();
int isFull();
int isEmpty();
void pop();
void display();
void peek();

int main() {
    int input;  
    while (1) { 
        std::cout << "Press:\n 1:Push \n 2:Pop \n 3:check if empty \n 4:check if full \n 5: display elements\n 6: use peek function \n 7 to exit\n";
        std::cin >> input;
        std::cout << "\n";
             switch(input) {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: isEmpty();
            break;
            case 4: isFull();
            break;
            case 5: display();
            break;
             case 6: peek();
            break;
        }
        if(input == 7) break;
    }
    return 0;

} 

int isFull(){
    if(top==size-1){ std::cout<<"Overflow\n" ; return 1;}else return 0;
}
int isEmpty(){
    if(top==-1){ std::cout<<"Underflow\n" ; return 1;}else return 0;
}
void push(){ int data;
    if(isFull()==0){top=top+1;
       std::cout<<"Enter:"; std::cin>>data;
         stack[top]=data;
    }
}

void pop(){if(isEmpty()==0){int data=stack[top];
    top=top-1; 
    std::cout<<"Popped:"<<data<< "\n";
}
}

void display() {
    if (isEmpty() == 1) {
        std::cout << "Stack is empty\n";
    } else {
        std::cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            std::cout << stack[i] << " ";
        }
        std::cout << "\n";
    }
}

    void peek() {
    if (isEmpty() == 1) {
        std::cout << "Stack is empty\n";
    } else {
        std::cout << "Top element: " << stack[top] << "\n";
    }
}


