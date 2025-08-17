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

    void uppercase_to_lowercase() { int num=0; 
       while(string[num]!='\0') {num++;}
       for(int i=0;i<num;i++){
           if(string[i]>=65 && string[i]<=90)
        string[i]+=32;}
              }
                };

int main() {
    
    String obj1; 
    char str1[] = "ARHANA";
    obj1.input_string(str1);  
    obj1.display();
    obj1.uppercase_to_lowercase();         
    obj1.display();

    return 0;
}
