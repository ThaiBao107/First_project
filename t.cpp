#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct ve
{
    string ma="hello";

};

int main()
{
    ve v;
    cout<<int(v.ma[0]) -32 -1<<endl;
    return 0;   
}