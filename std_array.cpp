#include <iostream>
#include <array>
using namespace std;

int main()
{
    std::array<int,10>arr1 = {1,2,3,4,5,6,7,8,9,10};
    std::array<int,10>arr2;
    arr2 = {10,9,8,7,6,5,4,3,2,1};

    cout<<arr1.at(5)<<endl;
    cout<<arr2.at(8)<<endl;
    cout<<arr1.front()<<endl;
    cout<<arr2.back()<<endl;
    return 0;
}