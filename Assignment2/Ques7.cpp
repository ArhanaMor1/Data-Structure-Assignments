
#include <iostream>
int size=0;
int Array[50];

void count_inversions();
void create();

int main() {
    create();
    count_inversions();
    
    return 0;
}

void create(){
    std::cout << "Enter number of elements\n";
    std::cin >> size;
        for(int i = 0; i < size; i++) {
        std::cout << "Enter element " << i+1<<"\n";
        std::cin >> Array[i];
    }
}

void count_inversions(){ int count=0;
     for(int j=size-1;j>=0;j--){
       {for (int i=0;i<j;i++)
            if(Array[i]>Array[j]){
                count++;
                
            }
        }
    } std::cout<<"Number of inversions:"<<count;
}
