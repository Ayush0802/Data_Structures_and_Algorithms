#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<string>v1;
    std::vector<int>v2 (5,10);
    vector<int>v3 = {1,2,3,4,5};
    v2.reserve(100); //to define the capacity of the array
    v3.push_back(6);
    cout<<v3.back()<<endl;
    v3.pop_back();
    cout<<v3.back()<<endl;
    cout<<v3.capacity()<<endl;
    cout<<v2.capacity()<<endl;
    cout<<v3.size()<<endl;
                

    vector<pair<string,int>>ll;
    ll.push_back(make_pair("aaa",33));

    for(auto&e:ll)
    {
        cout<<e.first<<" "<<e.second;
    }

   
    return 0;
}