#include <iostream>
using namespace std;
class A{
public:
  A(){ cout << "new A" << endl; }
  void virtual foo(){  cout << "A foo" << endl; }
  void virtual fun(){ cout << "A fun" << endl; }
};
class B: public A{
public:
  B() {  cout << "new B" << endl; }
  void foo(){ cout << "B foo" << endl; }
  void bar(){ cout << "B bar" << endl; }
};
int main(){
  A a1;//new A
  A a2;//new A
  B b1;//new A new B
  B b2;//new A new B

  a1=b1;
  //b2=a2;
  a1.foo();//A foo  We don't get the polymorphism behavior because we aren't working with pointers
  b2.foo();//B foo
  //a1.bar();
  b2.bar();//B bar
  a1.fun();//A fun
  b2.fun();//A fun

  A* a3=new A();//new A
  A* a4=new B();//new A new B
  //B* b3=new A();
  B* b4=new B();//new A new B
  
  a3->foo();//A foo
  a4->foo();//B foo  This is the polymorphism one!!!
  //b3->foo();
  b4->foo();//B foo
  
  //a3->bar(); 
  //a4->bar();//even though the actual object is a B we're accessing it through an A* and so we can't call the methods only defined for B
  //b3->bar();
  b4->bar();//B bar
  
  a3->fun();//A fun
  a4->fun();//A fun
  //b3->fun();
  b4->fun();//A fun
}

