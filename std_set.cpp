#include <iostream>
#include <set> // by default set means ordered_set
#include <unordered_set>
#include <string>
#include <functional>
using namespace std;

class person
{
    public:
        float age;
        string name;

    bool operator < (const person& rhs) const {return age<rhs.age;}
    bool operator > (const person& rhs) const {return age>rhs.age;}
    
};     

int main()
{

    set <person, std::less<>> set3 = {{30,"Ayush"}, {25,"AAAyush"}};
    for(const auto& e:set3)
    {
        cout<<e.age <<" " << e.name << endl;
    }
    std::set<int> set1 = {4,5,1,3,4,6,8};
    unordered_set<int> uset1 = {4,5,1,3,4,6,8};
    set<int,greater<int>>set2 = {4,5,1,3,4,6,8};
    set2.insert(18);
    set1.erase(5);
    uset1.erase(5);
    for(const auto& i:set1)
    {
        cout<<i <<" ";
    }
    cout<<endl;
    for(const auto& i:set2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(const auto& i:uset1)
    {
        cout<<i<<" ";
    }

    auto search = uset1.find(2);
    if(search!=uset1.end())
    {
        cout<< endl<< "Found";
    }
    else
    {
        cout<<endl <<"Not Found ";
    }
    return 0;
}