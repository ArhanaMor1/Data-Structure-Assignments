#include<iostream>
#include<queue>
int main(){

std::queue<int> queue1;
std::queue<int> queue2;
for(int i=0;i<6;i++)
{
 int x=i+1;
 queue1.push(x);
}

int i=0;
while(i<3)
{
 int x=queue1.front();
 queue1.pop();
 queue2.push(x);
 i++;
}

while(!queue2.empty())
{
 int z=queue1.front();
 queue1.pop();
 queue1.push(z);
 int q=queue2.front();
 queue2.pop();
 queue1.push(q);
}

while(!queue1.empty())
{
 std::cout<<queue1.front()<<"\t";
 queue1.pop();
}
}
