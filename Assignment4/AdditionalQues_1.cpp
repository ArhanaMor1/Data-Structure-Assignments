#include <iostream>
int n;
void binary();
int main() {
    std::cout<<"Enter n: ";
    std::cin>>n;
    binary();
    return 0;
}
void binary() {
    for(int i=1;i<= n;i++) {
        int num=i;
        int array[50];
        int k=0;
        while (num>0) {
            array[k]=num%2;
            num=num/2;
            k++;
        }
        for (int j=k-1; j>=0; j--) {
            cout<<array[j];
        }
        cout<<"\n";
    }
}
