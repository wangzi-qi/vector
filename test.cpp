#include"vector.h"
#include<iostream>
using namespace std;

int main()
{
    int e[3] = {1,2,3};
    vector <int> a(e,3);
    cout<<"a="<<a<<endl;

    vector b(a);
    cout<<"b="<<b<<endl;

    vector <int>c;
    cin>>c;
    cout<<"c="<<c<<endl;
    c.push(6);
    cout<<"c="<<c<<endl;
    c.pop( );
    cout<<"c="<<c<<endl;
    c.insert(2,5,6);
    c.insert(2,88);
    cout<<"c="<<c<<endl;
    cout <<c.at(3)<<endl<<c[3]<<endl;
    a=c+b;
    cout<<++a<<endl;
    cout<< a++<<endl;
    cout<<a<<endl;
    cout<<a.capacity()<<endl;
    cout<<a.size()<<endl;
    a.reserve(15);
    cout<<a.capacity()<<endl;
    cout<<a.size()<<endl;
    cout<<a.empty()<<endl;
    a.shrink_to_fit();
    cout<<a.capacity()<<endl;
    cout<<a.size()<<endl;
    a.swap(c);
    cout<<"c="<<c<<endl;
    cout<<"a="<<a<<endl;
    vector <int>d;
    cout<<d.empty()<<endl;
    vector <char> dd;
    cin>>dd;
    cout<<dd<<endl;
    dd.push('A');
    vector <char> as=dd;
    cout<<as<<endl;
    as.insert(1,'d',10);
    cout<<as<<endl;
    dd.swap(as);
    cout<<as<<endl;
    cout<<dd<<endl;
    cout<<++dd<<endl;
    return 0;
}