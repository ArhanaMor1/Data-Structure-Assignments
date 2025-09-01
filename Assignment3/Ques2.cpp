#include <iostream>
#include <string>
using namespace std;

char stack[100];
int top = -1;
int size = 100;

int isFull() {
    if (top == size - 1) { cout << "Overflow\n"; return 1; }
    else return 0;
}

int isEmpty() {
    if (top == -1) { cout << "Underflow\n"; return 1; }
    else return 0;
}

void push(char c) {
    if (isFull() == 0) {
        top = top + 1;
        stack[top] = c;
    }
}

char pop() {
    char c = ' ';
    if (isEmpty() == 0) {
        c = stack[top];
        top = top - 1;
    }
    return c;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    // Push all characters
    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
    // Pop and store in a variable before printing
    for (int i = 0; i < str.length(); i++) {
        char a = pop();
        cout << a;
    }
    cout << "\n";

    return 0;
}
