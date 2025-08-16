
#include <iostream>

void bubble_sort();
int Array[7]={64,34,25,12,22,11,90};
void display_array();
int main() {
   
   std::cout<<"Before sorting: " ;
   display_array();
    bubble_sort();
    std::cout<<"\nAfter sorting: ";
    display_array();
}


void bubble_sort(){
    for(int i=0;i<7;i++){
         for(int j=i+1;j<7;j++){
        if(Array[i]>Array[j]) {
           int temp=Array[i] ;
           Array[i]=Array[j];
           Array[j]=temp;
           }
         }
    }
}

void display_array(){
    for(int i=0;i<7;i++)
    std::cout<<Array[i]<<"\t";
}
