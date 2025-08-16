
#include <iostream>

int size;
int Array[50];

void create();
void find_missing_linear_search();
int  find_missing_binary_search();

int main(){
    
   create();
   find_missing_linear_search();
    find_missing_binary_search();
}


void create(){
    std::cout << "Enter number of elements\n";
    std::cin >> size;
     std::cout << "Enter elements in ascending order only \n" ;
    for(int i = 0; i < size; i++) {
        std::cout << "Enter element " << i+1<<"\n";
        std::cin >> Array[i];
    }
}

void find_missing_linear_search(){
    
    for(int i=0;i<size;i++)
    {
        int expected=1+i;
        if(expected!=Array[i])
        { std::cout<<"Missing (linear search):"<<expected<<"\n";
        break;
    }
}
}


int  find_missing_binary_search(){
    int l=0;
    int r=size-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(Array[mid]!=mid+1){
            if(mid==0||Array[mid-1]==mid){
                std::cout<<"Missing (binary search): "<<mid+1 << "\n";
                return 0;
            }
            else if(Array[mid]>mid+1){
                r=mid-1;
            }
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
