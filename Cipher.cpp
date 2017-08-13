// Ceaser Cipher
// Enter agnfcp and it will decode to CIPHER

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#define n 26

int search(int [n] , int );
void decode();
void code();

void main()
{
  char ch;

  while(1)
  {
    clrscr();
    cout<<"\t\t\t\t Ceaser Cipher ";

    cout<<"\n\n 1.Code"
        <<"\n 2.Decode"
        <<"\n 0.Exit"
        <<"\n\n Enter your choice : ";
     cin>>ch;

    clrscr();

    switch(ch)
    {
      case '1': code(); break;
      case '2': decode(); break;
      case '0': exit(0);
      default : cout<<"\n\n Invalid choice.";
    }
  }
}

void code()
{
  cout<<"\t\t\t\t Code ";

  int B[n] , i , r , d ;
  char *q; char C[n];

  cout<<"\n\n Enter no. of chars to code : ";
  cin>>d;

  q=new char[d];

  cout<<"\n\n Enter Key : ";
  cin >> r ;

  for(i=0 ; i<n ; i++)
    B[i]=i;

 int tp[n];
 for(i=0 ; i<n ; i++)
  {
     if(i+r>=n)
       tp[i+r-n]=B[i];
     else
       tp[i+r]=B[i];
  }
 for(i=0 ; i<n ; i++)
  {
    B[i]=tp[i];
    C[i]=(char)(B[i]+65);
  }

 char src , g;

 clrscr();
 for(i=0 ; i<d ; i++)
  {
    cout<<"\n\n Enter char(one at a time) : ";
    cin>>src ;
    g=toupper(src);
    int p=int(g)-65;
    *(q+i)=(char)(C[p]);

  }

  cout<<"\n\n Coded :\n ";
  for( i=0 ; i<d ; i++)
   cout<<*(q+i);

  cout<<"\n\n Press any key to continue.....";
  getch();
}

void decode()
{
  cout<<"\t\t\t\t Decode ";

  int B[n] , i, r, d;
  char *q;

  cout<<"\n\n Enter no. of chars to decode : ";
  cin>>d;

  q=new char[d];

  cout<<"\n\n Enter Key : ";
  cin >> r ;

  for(i=0 ; i<n ; i++)
    B[i]=i;
  int tp[n];

 for(i=0 ; i<n ; i++)    // This is to rotate array as per given key
  {
     if(i+r>=n)
       tp[i+r-n]=B[i];
     else
       tp[i+r]=B[i];
  }
 for(i=0 ; i<n ; i++)
     B[i]=tp[i];


 char src , g;
 int p;

 clrscr();
 for(i=0 ; i<d ; i++)         //for taking each char of code and decode them
  {

    cout<<"\n\n Enter char (one at a time) : ";
    cin>>src ;
    g=toupper(src);
    p=(int)g - 65 ; // will convert char to int
    int c ;
    c=search(B,p);  // Find the position of the required no. in array
    *(q+i)=(char)(c+65);

  }

  cout<<"\n\n Decoded :\n ";
  for( i=0 ; i<d ; i++)
   cout<<*(q+i);

  cout<<"\n\n Press any key to continue.....";
  getch();
}

int search(int P[n] , int src)
{
   int f;
  for(int i=0 ; i<n ; i++)
   {
      if(P[i]==src)
        f=i ;
   }
  return f;
}


