#include <iostream>
#include <cstring>
using namespace std;

char st[50];  
int top_stack=-1;
char out[50]; 
int outsize=0;

void push(char x){
    top_stack++;
    st[top_stack]=x;
}

char pop(){
    if(top_stack==-1){ return -1; }
    char t=st[top_stack];
    top_stack--;
    return t;
}

char stack_peek(){
    if(top_stack==-1) return -1;
    return st[top_stack];
}

int prec(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

void convert(char infix[]){
    int n=strlen(infix);
    for(int i=0;i<n;i++){
        char c=infix[i];
        if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0'&& c<='9')){
            out[outsize]=c;
            outsize++;
        } else if(c=='('){
            push(c);
        } else if(c==')'){
            while(stack_peek()!=-1 && stack_peek()!='('){
                out[outsize]=pop();
                outsize++;
            }
            pop(); 
        } else { 
            while(stack_peek()!=-1 && prec(stack_peek())>=prec(c)){
                out[outsize]=pop();
                outsize++;
            }
            push(c);
        }
    }
    while(stack_peek()!=-1){
        out[outsize]=pop();
        outsize++;
    }
    out[outsize]='\0';
}

int main(){
    char infix[50];
    cout<<"infix: ";
    cin>>infix;
    convert(infix);
    cout<<"postfix: "<<out<<"\n";
    return 0;
}
