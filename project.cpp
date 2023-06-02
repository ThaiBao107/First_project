#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<random>
#include<ctime>
#include<iomanip>
const int dong=10;
const int cot=9;
const int so_lan=4;
const int g=dong * cot;

const int movie1=50;
const int movie2=50;
const int movie3=50;


using namespace std;

struct Ve
{
   string name;
   string maVe;
   string number_char;
   double pricel;
};

void show_array(char a[][cot]);
void ve_movie(Ve *&a,Ve *&b, Ve *&d, char P1[][cot], char P2[][cot], char P3[][cot], bool flag, int &dem, int &dem1, int &dem2);
void nhap_1_ve(Ve &a,char movie, char P1[][cot]);
void randomID(Ve &a, char ve);
void khoi_tao(char a[][cot]);
void ticket_information(Ve *a, Ve *b, Ve *c);
void check(Ve *a, Ve *b, Ve *c, int &n, int &m, int &v);
void xuatS(Ve *a, int n);
void show_array(char a[][cot])
{
    cout<<"BANG DAT VE"<<endl;
    cout<<endl;
    for(int i=0;i<dong;i++){
        for(int j=0;j<cot;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void ve_movie(Ve *&a,Ve *&b, Ve *&d, char P1[][cot], char P2[][cot], char P3[][cot], bool flag,int &dem, int &dem1, int &dem2)
{
    if(flag == false)
    {
    int choose;
    cout<<"Nhap so luong ve can mua: ";
    while(true)
    {
        cin>> choose;
        if(choose > 0 && choose <=so_lan) break;
        else
            cout<<"Vuot qua so lan gioi han la 4, moi nhap lai: ";
    }
    system("cls");
    char movie;
    for(int i=0;i<choose;i++)
    {
        cout<<"Ve thu "<<i+1<<endl<<"---------------------------------"<<endl<<endl;
        cout<<"Ten phim: "<<endl;
        cout<<"---------------------------------------------"<<endl<<endl;
        cout<<"| 1.Conan    2. Doremon      3. Shin        |"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"Choose: "; 
        while(true)
        {
            cin >> movie;
            if(movie > '0' && movie <= '3') break;
            else
                cout<<"Khong co loai phim nay, moi nhap lai: ";
         }
          switch(movie)
        {
        case '1': // Conan
            show_array(P1);
            nhap_1_ve(a[dem++],movie,P1);
            break;
        case '2':
            show_array(P2);
            nhap_1_ve(b[dem1++],movie,P2);
            break;
        case '3':
            show_array(P3);
            nhap_1_ve(d[dem2++], movie,P3);
            break;
        }
        cout<<"-----------------------------------"<<endl;
    }
    }
}


void randomID(Ve &a, char ve, char movie)
{
    srand(time(NULL));
    const char*alpha="asdfghjklpoiuytrewqzxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789";
    const int size=3;
    int len =strlen(alpha);
    string id2;
    string id1;
    string id;
    switch(movie)
    {
        case '1':
        if(ve == '1')
        {
            id1="V";
            id1.push_back(movie);
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id2+=alpha[index];
            }
            id=id1+""+id2;
        }
        else if(ve == '2')
        {
            id1="N";
            id1.push_back(movie);
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id2+=alpha[index];
            }
            id=id1+""+id2;
        }
        a.maVe=id;
        cout<<"Ma ve: " << a.maVe<<endl;
        break;
        case '2':
        if(ve == '1')
        {
            id1="V";
            id1.push_back(movie);
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id2+=alpha[index];
            }
            id=id1+""+id2;
        }
        else if(ve == '2')
        {
            id1="N";
            id1.push_back(movie);
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id2+=alpha[index];
            }
            id=id1+""+id2;
        }
        a.maVe=id;
        cout<<"Ma ve: " << a.maVe<<endl;
        break;
        case '3':
        if(ve == '1')
        {
            id1="V";
            id1.push_back(movie);
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id2+=alpha[index];
            }
            id=id1+""+id2;
        }
        else if(ve == '2')
        {
            id1="N";
            id1.push_back(movie);
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id2+=alpha[index];
            }
            id=id1+""+id2;
        }
        a.maVe=id;
        cout<<"Ma ve: " << a.maVe<<endl;
        break;
    }
}

void nhap_1_ve(Ve &a,char movie, char P1[][cot])
{
    
    switch(movie)
    {
        case '1':
            a.name = "Conan";
            break;
        case '2':
            a.name ="Doremon";
            break;
        case '3':
            a.name ="Shin";
            break;
    }

    cout<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"|Loai ve: (Chon loai ve) ->      |"<<endl;
    cout<<"|1. VIP            2.NORMAL      |"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"| Vip: 130.000     Normal: 90.000|"<<endl;
    cout<<"----------------------------------"<<endl;
    char ve;
    cout<<"Choose: ";
    while(true)
    {
        cin >> ve;
        if(ve > '0' && ve <='2') break;
        else
            cout<<"Sai lua chon, nhap lai: ";
    }
    randomID(a,ve,movie);
    // ten phim 
    // --------------------
    datlai:
            int h,c;
            cout<<"Nhap so hang: ";
            while(true)
            {
                cin >> h;
                if(h> 0 && h<= dong) break;
                else
                    cout<<"Nhap qua so dong, nhap lai: ";
            }
            cout<<"Nhap cot: ";
            while(true)
            {
                cin >> c;
                if(c> 0 && c<= cot) break;
                else
                    cout<<"Nhap qua so cot, nhap lai: ";
            }
            cout<<endl;
            if(P1[h][c] == 'X')
            {
                
                cout<<"Da co nguoi dat, moi dat lai"<<endl;
                cout<<"-> Nhan enter de dat lai: ";
                getch();  
                system("cls");  
                goto datlai; 
            }
            else 
            {
                P1[h][c]='X';
                string k = to_string(h) +""+to_string(c);
                a.number_char = k;
                cout<<"Dat ve thanh cong"<<endl;
                getch();
            }
            system("cls");
    // --------------------
    if(ve == '1')
    {
        a.pricel=130.000;
    }
    else if(ve == '2')
    {
        a.pricel=90.000;
    }  
   
}

void menu()
{
    cout<<"                                  ====================MENU======================="<<endl;
    cout<<"                                  | 1. Dat ve xem phim                          |"<<endl;
    cout<<"                                  | 2. Xem phong ve                             |"<<endl;
    cout<<"                                  | 3. Thanh toan                               |"<<endl;
    cout<<"                                  | 4. Thong tin ve                             |"<<endl;
    cout<<"                                  | 5. Tim kiem ve                              |"<<endl;
    cout<<"                                  | 6. Huy ve                                   |"<<endl;
    cout<<"                                  | 7. EXIT                                     |"<<endl;
    cout<<"                                  ==============================================="<<endl;
}

void khoi_tao(char a[][cot])
{
    for(int i=0;i<dong;i++)
        for(int j=0;j<cot;j++)
            a[i][j]='*';

}


// thong tin ve
// --------------------------------------------------------------
void xuatS(Ve *a, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<setw(20)<<left<<a[i].name<<" ";
        cout<<setw(17)<<left<<a[i].maVe<<" ";
        cout<<setw(17)<<left<<a[i].number_char<<" ";
        cout<<setw(10)<<left<<a[i].name<<" ";
        cout<<endl;
    }
}

void check(Ve *a, Ve *b, Ve *c, int &n, int &m, int &v)
{
    for(int i=0;i<g;i++)
    {
        if(a[i].name == "") break;
        n++;
    }

    for(int i=0;i<g;i++)
    {
        if(b[i].name == "") break;
        m++;
    }
    for(int i=0;i<g;i++)
    {
        if(c[i].name == "") break;
        v++;
    }
}

void ticket_information(Ve *a, Ve *b, Ve *c)
{
    int n=0,m=0,v=0;
    check(a,b,c,n,m,v);
    // table ticket
    // name ticket       code ticket               number char       pricel
    cout<< setw(20) << left <<"Name Ticket"<<" "<<setw(17)<<left<<"Code ticket"<<" "<<setw(17)<<left<<"Number char"<<" "<<setw(10)<<left<<"Pricel"<<endl;
    xuatS(a,n);
    xuatS(b,m);
    xuatS(c,v);
}   
// --------------------------------------------------------------


int main()
{
    char choose;
    Ve *a=NULL;
    a=new Ve[g];
    Ve *b=NULL;
    b=new Ve[g];
    Ve *d=NULL;
    d=new Ve[g];
    char P1[dong][cot];
    char P2[dong][cot];
    char P3[dong][cot];
    bool flag = false;
    int dem=0;
    int dem1=0;
    int dem2=0;
    // tao phong
    khoi_tao(P1);
    khoi_tao(P2);
    khoi_tao(P3);
    manhinh:
    do
    {
        menu();
        cout<<"Choose: "; 
        while(true)
        {
            cin>> choose;
            if(choose > '0' && choose <='7') break;
            else
                cout<<"Nhap sai lua chon, nhap lai: ";
        }
        system("cls");
        switch(choose)
        {
            case '1':
            cout<<"DAT VE"<<endl;
            cout<<endl;
            ve_movie(a,b,d,P1,P2,P3,flag,dem, dem1, dem2);
            cout<<"-> Nhan enter de ve man hinh: "; 
            getch();
            system("cls");
            break;
            // ----------------------------------------------------------------------
            case '2':
            room:
            cout<<"PHONG VE"<<endl;
            cout<<"                       -------------------------------------"<<endl;
            cout<<"                       | 1. Conan                          |"<<endl;
            cout<<"                       | 2. Doremon                        |"<<endl;
            cout<<"                       | 3. Shin                           |"<<endl;
            cout<<"                       | 4. EXIT                           |"<<endl;
            cout<<"                       -------------------------------------"<<endl;
            char choose1;
            cout<<"Choose: ";
            while(true)
            {
                cin >> choose1;
                if(choose1 > '0' && choose <= '4') break;
                else
                    cout<<"Nhap sai lua chon, nhap lai: ";
            }
            system("cls");
            switch(choose1)
            {
                case '1':
                cout<<"PHONG VE PHIM CONAN"<<endl<<endl;
                show_array(P1);
                cout<<endl;
                cout<<"-> Nhan enter de ve man hinh: "; 
                getch();
                system("cls");
                break;
                case '2':
                cout<<"PHONG VE PHIM DOREMON"<<endl<<endl;
                show_array(P2);
                cout<<endl;
                cout<<"-> Nhan enter de ve man hinh: "; 
                getch();
                system("cls");
                break;
                case '3':
                cout<<"PHONG VE PHIM SHIN"<<endl<<endl;
                show_array(P3);
                cout<<endl;
                cout<<"-> Nhan enter de ve man hinh: "; 
                getch();
                system("cls");
                break;
                case '4':
                system("cls");
                goto  manhinh;
            }
            goto room;
            // -----------------------------------------------------------------
            case '3':
                cout<<"Chua lam"<<endl;
                cout<<"-> Nhan enter de ve man hinh: "; 
            
                break;
            case '4':
                cout<<"                      TICKET INFORMATION                 "<<endl;
                ticket_information(a,b,d);
                cout<<"-> Nhan enter de ve man hinh: "; 
                break;
            case '5':
                cout<<"Chua lam"<<endl;
                cout<<"-> Nhan enter de ve man hinh: "; 
                break;
            case '6':
                cout<<"Chua lam"<<endl;
                cout<<"-> Nhan enter de ve man hinh: "; 
                break;
            case '7':
                delete[]a;
                delete[]b;
                delete[]d;
                a=b=d=NULL;
                cout<<"Thoat"<<endl;
                return 0;
        }
        getch();
        system("cls");

    }while(true);
    return 0;
    }