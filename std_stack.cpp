#include <iostream>
#include <stack>
using namespace std;

//top,size, empty, pop, push
int main()
{
    stack<int>ss;

    ss.push(10);
    ss.push(22);
    ss.push(33);

    cout<<ss.size()<<endl;
    ss.pop();
    cout<<ss.top()<<endl;
    cout<<ss.empty()<<endl;
    return 0;
}