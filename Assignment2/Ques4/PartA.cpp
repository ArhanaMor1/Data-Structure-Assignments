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

    void concat(const String &s2) {
        int i = 0;
        while (string[i] != '\0') i++;  

        int j = 0;
        while (s2.string[j] != '\0' && i < 99) {
            string[i] = s2.string[j];
            i++;
            j++;
        }
        string[i] = '\0';
    }
};

int main() {
    String obj1, obj2;

    char str1[] = "Arhana";
    char str2[] = "Mor";

    obj1.input_string(str1);  
    obj2.input_string(str2);  

    obj1.concat(obj2);         

    obj1.display();            

    return 0;
}
