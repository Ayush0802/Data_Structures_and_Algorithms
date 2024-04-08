#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int sieve_of_eratosthenes(int n)     //Time Complexity = nlog(log(n))
{
    int count = 0;
    vector<bool>isprime(n+1,true);

    isprime[0]=isprime[1]= false;

    for(int i=2;i<n;i++)
    {
        if(isprime[i])
        {
            count++;
            for(int j=2*i;j<n;j=j+i)
            {
                isprime[j]=false;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;

    int out = sieve_of_eratosthenes(n);
    cout<<"No. of Prime Numbers = "<<out<<endl;

    cout<<__gcd(4,8);

    return 0;
}