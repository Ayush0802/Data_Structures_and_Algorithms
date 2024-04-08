#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    priority_queue<int,vector<int>>pq1 ;
    priority_queue<int,vector<int>,greater<int>>pq2 ;
    for(int elm : {3,2,4,6,5,9})
    {
        pq1.push(elm);
        pq2.push(elm);
    }
    cout<<pq1.top();
    pq1.pop();
    cout<<endl<<pq1.top();
    cout<<endl;
    cout<<pq2.top();
    pq2.pop();
    cout<<endl<<pq2.top();
    return 0;
}