#include <iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l1 ={2,5,6,7,8};
    list<int> l2 = {3,4,5,6,1};
    // l1 = l2;
    for(auto & e:l1)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<l1.front()<<" ";
    cout<<l2.back()<<" "<<endl;
    l1.sort();
    l2.sort();
    l1.merge(l2);
    for(auto & e:l1)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    
    return 0;
}