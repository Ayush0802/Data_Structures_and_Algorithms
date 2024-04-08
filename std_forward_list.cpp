#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> l1 = {3,2,5,6,7};
    forward_list<int> l2 = {2,7,9,8,4};
    l1.insert_after(l1.begin(),10);
    l1.reverse();
    for(auto & e :l1)
    {
        cout<<e<<endl;
    }
    cout<<endl;
    // l1.sort(); 
    // l2.sort();
    // l1.merge(l2);
    // for(auto & e :l1)
    // {
    //     cout<<e<<endl;
    // }
    cout<<distance(l2.begin(),l2.end())<<endl;
    cout<<endl;
    l1.splice_after(l1.begin(),l2);
    for(auto & e :l1)
    {
        cout<<e<<endl;
    }
    cout<<endl;
    l1.remove(2);
    for(auto & e :l1)
    {
        cout<<e<<endl;
    }
    cout<<endl;
    l1.remove_if([] (int n){
        return n>7;
    });
    for(auto & e :l1)
    {
        cout<<e<<endl;
    }
    cout<<endl;
    l1.resize(4);
    for(auto & e :l1)
    {
        cout<<e<<endl;
    }
    cout<<endl;
    l1.resize(8);
    for(auto & e :l1)
    {
        cout<<e<<endl;
    }
    cout<<endl;


}