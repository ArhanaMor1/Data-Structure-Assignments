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

    void vowel_delete() { int num=0; 
       while(string[num]!='\0') {num++;}
 for(int i=0;i<num;i++){ 
     if (string[i]=='a'||string[i]=='e'||string[i]=='i'||string[i]=='o'||string[i]=='u'||string[i]=='A'||string[i]=='E'||string[i]=='I'||string[i]=='O'||string[i]=='U')
   { for(int j=i;j<num;j++)
   {string[j]=string[j+1]; }
   num--; i--;
           }
             } 
              }
                };

int main() {
    
    String obj1; 
    char str1[] = "Arhana";
    obj1.input_string(str1);  
    obj1.display();
    obj1.vowel_delete();         
    obj1.display();

    return 0;
}
