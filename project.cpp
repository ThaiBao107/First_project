#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<random>
const int dong=40;
const int cot=10;


using namespace std;

struct Ve
{
   string maVe;
   int soluong;
   double pricel;
};

void ve_XP(Ve *&a, int n)
{

}


void randomID(Ve &a, char ve)
{
    srand(time(NULL));
    const char*alpha="asdfghjklpoiuytrewqzxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789";
    const int size=5;
    int len =strlen(alpha);
    string id;
    for(int i=2;i<size;i++)
    {
        if(ve == '1')
        {
            id[0]='V';
            id[1]='I';
            int index= rand() %len;
            id+=alpha[index];
        }
        else if(ve == '2')
        {
            id[0]='N';
            id[1]='0';
            int index= rand() %len;
            id+=alpha[index];
        }
    }
    a.maVe=id;
    cout<<a.maVe<<endl;
}

void nhap_1_ve(Ve &a,char ve)
{

    cout<<"Ten phim: "<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"| 1.Conan    2. Doremon      3. Shin        |"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"Choose: "; 
    
    cout <<"Loai ve: (Chon loai ve) -> "<<endl;
    cout<<"1. VIP            2.NORMAL  "<<endl;
    while(true)
    {
        cin >> ve;
        if(ve > '0' && ve <='2') break;
        else
            cout<<"Sai lua chon, nhap lai: ";
    }
    randomID(a,ve);
    // ten phim 
}