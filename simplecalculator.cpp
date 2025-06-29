#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2;
    cout<<"enter two numbers :";
    cin>>n1>>n2;
    char op;
    cout<<"enter the operation you want to perform :";
    cin>>op;
    switch(op)
    {
        case '+':cout<<"addition of two number is :"<<(n1+n2)<<endl;
        break;
        case '-':cout<<"substraction of two number is :"<<(n1-n2)<<endl;
        break;
        case '/':cout<<"division of two number is :"<<(n1/n2)<<endl;
        break;
        case '%':cout<<"modulus of two number is"<<(n1%n2)<<endl;
        break;
        default:cout<<"invalid choice of operation"<<endl;
        break;

    }
    return 0;

}