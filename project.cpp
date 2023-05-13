#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<random>
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
void ve_movie(Ve *&a,Ve *&b, Ve *&d, char P1[][cot], char P2[][cot], char P3[][cot], bool flag);
void nhap_1_ve(Ve &a,char movie);
void randomID(Ve &a, char ve);
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

void ve_movie(Ve *&a,Ve *&b, Ve *&d, char P1[][cot], char P2[][cot], char P3[][cot], bool flag)
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
        int dem=0;
        int dem1=0;
        int dem2=0;
        char movie;
    for(int i=0;i<choose;i++)
    {
        cout<<"Ve thu "<<i+1<<endl<<"---------------------------------"<<endl;
        cout<<"Ten phim: "<<endl;
        cout<<"---------------------------------------------"<<endl;
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
            nhap_1_ve(a[dem++],movie);
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
                cout<<"Dat ve thanh cong"<<endl;
            }
            system("cls");
            break;
        case '2':
            show_array(P2);
            nhap_1_ve(b[dem1++],movie);
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
            if(P2[h][c] == 'X')
            {
                
                cout<<"Da co nguoi dat, moi dat lai"<<endl;
                cout<<"-> Nhan enter de dat lai: ";
                getch();  
                system("cls");  
                goto datlai; 
            }
            else 
            {
                P2[h][c]='X';
                cout<<"Dat ve thanh cong"<<endl;
            }
            system("cls");
            break;
        case '3':
            show_array(P3);
            nhap_1_ve(d[dem2++], movie);
            datlai:
            int h,C;
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
                cin >> C;
                if(C> 0 && C<= cot) break;
                else
                    cout<<"Nhap qua so cot, nhap lai: ";
            }
            cout<<endl;
            if(P3[h][C] == 'X')
            {
                
                cout<<"Da co nguoi dat, moi dat lai"<<endl;
                cout<<"-> Nhan enter de dat lai: ";
                getch();  
                system("cls");  
                goto datlai; 
            }
            else 
            {
                P3[h][C]='X';
                cout<<"Dat ve thanh cong"<<endl;
            }
            system("cls");
            break;
        }
        cout<<"-----------------------------------"<<endl;
    }
    }
    else
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
    
    // ---------------------------------------
    int dem=0;
    int dem1=0;
    int dem2=0;
    char movie;
    for(int i=0;i<dong;i++)
    {
        for(int j=0;j<cot;j++)
        {
            if(P1[i][j] == 'X') dem++;
        }
    }

    for(int i=0;i<dong;i++)
    {
        for(int j=0;j<cot;j++)
        {
            if(P2[i][j] == 'X') dem1++;
        }
    }

    for(int i=0;i<dong;i++)
    {
        for(int j=0;j<cot;j++)
        {
            if(P3[i][j] == 'X') dem2++;
        }
    }
    // ------------------------------------------------------

    for(int i=0;i<choose;i++)
    {
        cout<<"Ve thu "<<i+1<<endl<<"---------------------------------"<<endl;
        cout<<"Ten phim: "<<endl;
        cout<<"---------------------------------------------"<<endl;
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
            // so bang ghe phim conan
            show_array(P1);
            nhap_1_ve(a[dem++],movie);
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
                cout<<"Dat ve thanh cong"<<endl;
            }
            system("cls");
            break;
        case '2':
            show_array(P2);
            nhap_1_ve(b[dem1++],movie);
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
            if(P2[h][c] == 'X')
            {
                
                cout<<"Da co nguoi dat, moi dat lai"<<endl;
                cout<<"-> Nhan enter de dat lai: ";
                getch();  
                system("cls");  
                goto datlai; 
            }
            else 
            {
                P2[h][c]='X';
                cout<<"Dat ve thanh cong"<<endl;
            }
            system("cls");
            break;
        case '3':
            show_array(P3);
            nhap_1_ve(d[dem2++], movie);
            datlai:
            int h,C;
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
                cin >> C;
                if(C> 0 && C<= cot) break;
                else
                    cout<<"Nhap qua so cot, nhap lai: ";
            }
            cout<<endl;
            if(P3[h][C] == 'X')
            {
                
                cout<<"Da co nguoi dat, moi dat lai"<<endl;
                cout<<"-> Nhan enter de dat lai: ";
                getch();  
                system("cls");  
                goto datlai; 
            }
            else 
            {
                P3[h][C]='X';
                cout<<"Dat ve thanh cong"<<endl;
            }
            system("cls");
            break;
        }
        cout<<"-----------------------------------"<<endl;
    }
    }
}


void randomID(Ve &a, char ve)
{
    srand(time(NULL));
    const char*alpha="asdfghjklpoiuytrewqzxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789";
    const int size=5;
    int len =strlen(alpha);
    string id;
        if(ve == '1')
        {
            id[0]='V';
            id[1]='I';
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id+=alpha[index];
            }
        }
        else if(ve == '2')
        {
            id[0]='N';
            id[1]='0';
            for(int i=0;i<size;i++)
            {
                int index= rand() %len;
                id+=alpha[index];
            }
        }
    a.maVe=id;
    cout<<a.maVe<<endl;
}

void nhap_1_ve(Ve &a,char movie)
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
    while(true)
    {
        cin >> ve;
        if(ve > '0' && ve <='2') break;
        else
            cout<<"Sai lua chon, nhap lai: ";
    }
    randomID(a,ve);
    // ten phim 
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
    cout<<"                                  | 4. Tim kiem ve                              |"<<endl;
    cout<<"                                  | 5. Huy ve                                   |"<<endl;
    cout<<"                                  | 6. EXIT                                     |"<<endl;
    cout<<"                                  ==============================================="<<endl;
}


int main()
{
    Ve *a=NULL;
    a=new Ve[g];
    Ve *b=NULL;
    b=new Ve[g];
    Ve *c=NULL;
    c=new Ve[g];
    char P1[dong][cot];
    char P2[dong][cot];
    char P3[dong][cot];

}