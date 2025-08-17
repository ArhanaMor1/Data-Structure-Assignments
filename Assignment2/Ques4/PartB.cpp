#include <iostream>

class String {
    char string[100];  

public:
    void input_string(const char str[]) { 
        int i = 0;
        while (str[i] != '\0' && i < 99) {
            string[i] = str[i];
            i++;
        }
        string[i] = '\0';  
    }

    void display() {
        std::cout << string << std::endl;
    }

    void reverse() { int num=0; 
       while(string[num]!='\0') {num++;}
 for(int i=0,j=num-1;i<j;i++,j--){
    int temp=string[i];
    string[i]=string[j];
    string[j]=temp;
}
}
};

int main() {
    
    String obj1; 
    char str1[] = "Arhana";
    obj1.input_string(str1);  
    obj1.display();
    obj1.reverse();         
    obj1.display();

    return 0;
}
