
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
    for(int i=0;i<6;i++){
         for(int j=0;j<6-i;j++){
        if(Array[j]>Array[j+1]) {
           int temp=Array[j] ;
           Array[j]=Array[j+1];
           Array[j+1]=temp;
           }
         }
    }
}

void display_array(){
    for(int i=0;i<7;i++)
    std::cout<<Array[i]<<"\t";
}
