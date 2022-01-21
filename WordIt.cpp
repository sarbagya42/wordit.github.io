#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int i,j,k,c=0,m=0;
char stores[6][35];
class words
 {
 private:
     char word[6][20],mainword[5][6]={"store"};
     int w=0;
 public:
    void input()
    {
        cout<<endl;
        cout<<"Type your Guess:";
        cin>>word[m];
        m=m+1;
        cout<<endl;
    }
    void store()
    {
      strcpy(stores[c],word[c]);
      c=c+1;
    }
    void allout(int);
    void display(int z)
    {
    for(i=z; i<6; i++)
   {
    for(j=0; j<5; j++)
    {
       for(k=0; k<5; k++)
       {
           if(mainword[0][j]==stores[i][k])
          {
              if(j==k)
              {
                  cout<<stores[i][k]<<" "<<"Present and in Correct Position"<<endl;
                   w=w+1;
                  if(w==5)
                  {
                      cout<<endl;
                      cout<<"GENIUS!!"<<endl;
                  }
              }
              else if(j!=k)
              {
                  w=w+1;
                  cout<<stores[i][k]<<" "<<"Present but in Incorrect Position"<<endl;
              }
          }
       }
    }
 }
 if(w==0)
 {
     cout<<"Nothing is Present."<<endl;
 }
}
};

void words::allout(int f)
{
cout<<endl;
for(i=0; i<f; i++)
{
 cout<<stores[i]<<endl;
}
}

int main()
{
    words w1,w2,w3,w4,w5,w6;
    w1.input();
    w1.store();
    w1.display(0);
    w1.allout(1);

    w2.input();
    w2.store();
    w2.display(1);
    w2.allout(2);

    w3.input();
    w3.store();
    w3.display(2);
    w3.allout(3);

    w4.input();
    w4.store();
    w4.display(3);
    w4.allout(4);

    w5.input();
    w5.store();
    w5.display(4);
    w5.allout(5);

    w6.input();
    w6.store();
    w6.display(5);
    w6.allout(6);

 return 0;
}
