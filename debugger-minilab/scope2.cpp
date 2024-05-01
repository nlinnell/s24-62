#include <iostream>
using namespace std;


int foo(int q){return q+1;}
int bar(int a, int b);//forward declaration
int main()
{   int a=5, b=7;
    int c = bar(b,a);
    cout << "in main c is:"<<c << endl;
    cout<<"in main a is:"<< a<<" b is:"<<b/*<<" r is:"<<r*/
        <<" result of function:"<<bar(4, a)<<endl;
    if(a==5){
        string a = "hello";
        int c = bar(99, 8);
        char d='u';
        b=199;

        cout<<"in main a is:"<< a<<" b is:"<<b<<"c is "<<c
          <<"d is "<<d/*<<"  r is:"<<r*/<<endl;
    }

    cout<<"in main a is:"<< a<<" b is:"<<b<<"c is "<<c
      /*<<"d is "<<d<<" r is:"<<r*/<<endl;

    for(int i=0; i<10; i++){
      cout<<"hello";
    }
    /*cout<<i<<endl;*/

    return 0;
}


int bar(int a, int b){
    int r= a+b;
    a=100;
    b=1;
    cout<<"in bar a is:"<<a<<" b is:"<<b<<" r is:"<<r<<endl;
    return r+foo(b);
}





/*
    a=100;
    b=1;
    cout<<"in addition"<<a<<" "<<b<<" "<<endl;



    int a=12;
    int b=17;
    int c = addition(a,b);
    cout << "in main"<< a<<" "<<b<<" "<<c << endl;
    */
