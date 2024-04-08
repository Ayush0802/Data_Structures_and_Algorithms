#include <iostream>
#include <map>
#include <unordered_map> // here the key-value pair is not sorted
#include <vector>
#include <functional>
using namespace std;

int main()
{
    map<string,int,std::greater<>>M;
    M["Ayush"]=2;
    M["DUMMY"]=1;
    M.insert(std::make_pair("A",3));

    for(const auto & e:M)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }
    cout<<M["A"]<<endl;
    cout<<M.count("Ayush")<<endl;
    cout<<M.count("ayush")<<endl;
    cout<<M.size()<<endl;
    M.erase("A");
    cout<<M.size()<<endl;


    multimap<char,int>MM;
    MM.insert(make_pair('a',1));
    MM.insert(make_pair('a',2));
    MM.insert(make_pair('a',3));
    MM.insert(make_pair('b',2));
    MM.insert(make_pair('b',1));

    for(const auto & e:MM)
    {
        cout<<e.first<<" "<<e.second<<endl;
    }
    
    cout<<MM.count('a')<<endl;
    auto pair = MM.find('a');
    cout<<pair->first<<" "<<pair->second<<endl;
    auto range = MM.lower_bound('a');
    cout<<range->first<<" "<<range->second<<endl;


    return 0;
}


// multimap can be used so that we can have similar keys for different values