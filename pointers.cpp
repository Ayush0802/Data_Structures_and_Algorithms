#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int num = 5;
    cout<<"content of num "<<num<<endl;     //content of num
    cout<<"address of num "<<&num<<endl;    //address of num          

    int *ptr =&num;     // Pointers stores the address of num
    (*ptr)++;    
    cout<<"value is "<<*ptr<<endl;
    cout<<"Address is "<<ptr<<endl;

    int *p = ptr;       //copy of pointers
    cout<<"value is "<<*ptr<<endl;
    cout<<"Address is "<<ptr<<endl;

    cout<<endl;

    int arr[100] ={2,5,8,1,6};
    cout<< "Address "<<arr<<endl<<"Address "<<&arr[0]<<endl;
    cout<<*arr<<endl;        //first element of the array
    cout<<*(arr+1)<<endl;    //second element of the array

    cout<<endl;

    char abc[6] = "abcde";     
    cout<<abc<<endl;
    char *a = &abc[0];              //USELESS
    cout<<a<<endl;

    cout<<endl;

    int temp[10] = {1,2};
    cout << sizeof(temp) << endl;
    cout << "1st " <<  sizeof(*temp) << endl;
    cout << "2nd " <<  sizeof(&temp) << endl;

    int *pt = &temp[0];
    cout << sizeof(pt) << endl ;
    cout << sizeof(*pt) << endl ;
    cout << sizeof(&pt) << endl ;

    return 0;
}