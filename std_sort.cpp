#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v1 = {3,1,9,5,6,2};
    vector<int> v2 = {3,1,9,5,6,2};
    sort( v1.begin(),v1.end(),greater<int>());
    for(auto elm:v1)
    {
        cout<<elm<<" ";
    }
    cout<<endl << is_sorted(v1.begin(),v1.end());
    cout<<endl;
    partial_sort( v2.begin()+1,v2.begin()+3,v2.end()-1);
    for(auto elm:v2)
    {
        cout<<elm<<" ";
    }

    return 0;
}