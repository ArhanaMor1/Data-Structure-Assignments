
#include <iostream>

void create_array();
void sort_array();
int binary_search();


int size=0;
int Array[50];

int main() {
    create_array();
    sort_array();
    binary_search();
}

void create_array(){
    std::cout<<"Enter number of elements\n";
    std::cin>>size;
    for(int i=0;i<size;i++)
    {
        std::cout<<"Enter element "<<i+1<<"\n";
        std::cin>>Array[i];
    }
    
}

void sort_array(){
    for(int i=0;i<size;i++){
         for(int j=i+1;j<size;j++){
        if(Array[i]>Array[j]) {
           int temp=Array[i] ;
           Array[i]=Array[j];
           Array[j]=temp;
           }
         }
    }
}

int binary_search(){
    int element;
    
    std::cout<<"Which element do you wish to search for? ";
    std::cin>>element;
    int l=0;
    int r=size-1; //Indexing starts from 0.
   while(l<=r)
    {int mid=(l+r)/2;
        if(Array[mid]==element){
        std::cout<<"Index is: "<<mid<<"\n";
        return 0;
        } else if (Array[mid]<element) {
         l=mid+1;  } //the +1 ensures we don't recheck mid.
           else { r=mid-1;   //the -1 ensures we don't recheck mid.
                   }
                      }
                        std::cout<<"Not found\n"; 
                        return -1;
}
