#include <stdio.h>
#include<time.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<windows.h>
#include <fstream>
using namespace std;
int i,j,k,c=0,m=0,v=0;
char stores[6][35],o;
char mainword[5][6];
std::string s;
int a[10][10],p,b[10][10];
class words
 {
 private:
     char word[6][20];
     int w=0;
 public:
    void intro()
    {
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout<<"WELCOME TO WORD-IT"<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        cout<<"Here are the RULES of the Game:"<<endl<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout<<"RED: Letter exists but Wrong Position"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            cout<<"BLUE:Letter doesn't Exist in the Word"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
            cout<<"GREEN:Letter exists and in Right Position"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        
   }
    void input()
    {
        cout<<endl;
        cout<<(6-m)<<" "<<"tries remaining."<<endl<<endl;
        cout<<"Type 5 Letter Word Guess:";
        cin>>word[m];
        m=m+1;
        cout<<endl;
    }
    void term();
    void clear(int);
    void check();
    void store()
    {
      strcpy(stores[c],word[c]);
      c=c+1;
    }
    void indout(int);
    void allout(int);
    void display(int z)
    {
    for(i=z; i<6; i++)
   {
       v=v+1;
    for(j=0; j<5; j++)
    {
       for(k=0; k<5; k++)
       {
           if(strcmp(stores[i],mainword[0])==0)
           {
               term();
           }
           if(mainword[0][j]==stores[i][k])
          {
              if(j==k)
              {
                  a[i][k]=k+1;
              }
              else if(j!=k)
              {
                  b[i][k]=k+1;
              }
          }
       }
    }
 }
}
};
void words::clear(int z)
{
    if(z==1)
    {
     cout<<endl;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    cout<<endl<<"!!OUT OF TRIES!!"<<endl<<endl;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    cout<<"!!BETTER LUCK NEXT TIME!!"<<endl;
    cout<<endl<<"THE WORD WAS:"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    for(i=0; i<5; i++)
    {
        cout<<" "<<mainword[0][i];
    }
    }
    if(z==2)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    getch();
    system("cls");
    }
    cout<<endl;
    cout<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
    getch();
}
void words::term()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    if(v==1)
    {
    cout<<"!!GENIUS!!"<<endl<<endl;
    for(i=0; i<5; i++)
    {
        cout<<" "<<mainword[0][i];
    }
    }
    else
    {
    allout(v);
    for(i=0; i<5; i++)
    {
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout<<" "<<mainword[0][i];
    }
    cout<<endl;
    cout<<endl<<"PERFECTO!!YOU GOT IT!"<<endl<<endl;
    }
    cout<<endl;
    cout<<"!!WINNER!!"<<endl;
    cout<<endl;
    getch();
    exit(3);
}
void words::allout(int f)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    for(i=0; i<f; i++)
    {
        for(j=0; j<5; j++)
        {
           if(a[i][j]!=0)
           {
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
               cout<<" "<<stores[i][j];
           }
           else if(b[i][j]!=0)
           {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout<<" "<<stores[i][j];
           }
           else
           {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
          cout<<" "<<stores[i][j];
           }
        }
        cout<<endl;
        cout<<endl;
    }
}


void words::indout(int y)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    for(i=y; i<y+1; i++)
    {
        for(j=0; j<5; j++)
        {
           if(a[i][j]!=0)
           {
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
               cout<<" "<<stores[i][j];
           }
           else if(b[i][j]!=0)
           {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            cout<<" "<<stores[i][j];
           }
           else
           {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
          cout<<" "<<stores[i][j];
           }
        }
    }
}

int main()
{
    int randy;
    int LINE;
    srand(time(0));
    randy=rand()%200;
    LINE=randy;
    std::ifstream f("word.txt");
    for (int i = 1; i <= LINE; i++){
    getline(f, s);
    }
    for(i=0; i<5; i++)
    {

        if(i==0)
        {
         s[i]=s[i]+32;
         mainword[0][i]=s[i];
        }
        else
        {
            mainword[0][i]=s[i];
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    words w1,w2,w3,w4,w5,w6;
    w1.intro();
    w1.input();
    w1.store();
    w1.display(0);
    w1.allout(0);
    w1.indout(0);
    w1.clear(0);

    w2.input();
    w2.store();
    w2.display(1);
    w2.allout(1);
    w2.indout(1);
    w2.clear(0);

    w3.input();
    w3.store();
    w3.display(2);
    w3.allout(2);
    w3.indout(2);
    w3.clear(0);

    w4.input();
    w4.store();
    w4.display(3);
    w4.allout(3);
    w4.indout(3);
    w4.clear(0);

    w5.input();
    w5.store();
    w5.display(4);
    w5.allout(4);
    w5.indout(4);
    w5.clear(0);

    w6.input();
    w6.store();
    w6.display(5);
    w6.allout(5);
    w6.indout(5);
    w6.clear(1);

 return 0;
}
