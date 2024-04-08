#include <iostream>
#include <queue>
using namespace std;

//front, back,size, empty, pop, push
int main()
{
    queue<int>qq;

    qq.push(10);
    qq.push(22);
    qq.push(33);

    cout<<qq.size()<<endl;
    qq.pop();
    cout<<qq.front()<<endl;
    cout<<qq.back()<<endl;
    cout<<qq.empty()<<endl;
    return 0;
}