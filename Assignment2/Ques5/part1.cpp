
#include <iostream>
const int size=4;
int i,j,Array[size];
int main() {
    
    std::cout << "Enter diagonal elements(row major)\n";
for(i=0;i<size;i++)
{ std::cin>>Array[i];
   }
    std::cout<<"The matrix is:\n";
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(i==j)
           { std::cout<<Array[i];}
            else
            { std::cout<<"0"; }
          
        }  std::cout<<"\n";
    }
}
