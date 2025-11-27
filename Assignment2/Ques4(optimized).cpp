#include <iostream>
class String
{
char string[100];

 public:
void input_string(const char str[]){ int i=0;
   
    while(str[i]!='\0'){ string[i]= str[i];
        i++;   } string[i]= '\0';
}

int is_vowel(char ch){
    if (ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return 1;
     else return 0;   
    }

 void display(){ int i=0;
     while(this->string[i]!='\0'){ std::cout<<string[i]<<"\t";
        i++;   }   std::cout<<"\n";
}
 
 
 void vowel_delete(){
     int write = 0;
     for(int i=0; this->string[i]!='\0'; i++)
     if(!is_vowel(string[i])){
         this->string[write++]=this->string[i];
     }
        this->string[write]='\0'; }
   };
 
 
 int main(){
     String obj;
  
     obj.input_string("Arhana");
      obj.display();
     obj.vowel_delete();
   
     obj.display();
     
 }
