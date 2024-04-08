#include  <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dd ={1,2,3};
    dd.push_back(5);
    dd.pop_front();
    for(const auto & e : dd)
    {
        cout<<e<<endl;
    }
    cout<<dd.front();
    return 0;
}