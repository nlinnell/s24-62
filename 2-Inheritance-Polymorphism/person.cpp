#include <iostream>
#include <string>

using namespace std;

class Person{
  private: 
    string name;
  public:
    Person() {
      name = "";
      cout << "New Person" << endl;
    }
    Person(string n) {
      name = n;
      cout << "New Person: " << n<< endl;
    }
    void foo () {
      cout << "Person foo" << endl;
    }
    void bar () {
      cout << "Person bar" << endl;
    }
    string toString(){
      return name;
    }
};
class Employee: public Person{
  private:
    int id;
  public:
    Employee(){ 
      cout << "New Employee" << endl;
    }
    Employee(string n, int i) : Person(n){
      //name = n;//Child can't directly access private fields of parent
      id = i;
      cout << "New Employee" << endl;
    }
    void foo () {
      cout << "Employee foo" << endl;
    }
    void pay () {
      cout << "Employee pay" << endl;
    }
    string toString() {
      //return "Employee " + name + ", ID: " + std::to_string(id);
      return "Employee " + Person::toString() + ", ID: " + std::to_string(id);
    }
};


int main(){
  Person p0;
  Employee e0; 
  Person p1("Alice in Wonderland");
  Employee e1("Spongebob Squarepants",1);


  p0.foo();
  e0.foo();

  p0.bar();
  e0.bar(); // can we still call this?

  //p0.pay();//Doesn't work
  e0.pay();

  cout << p1.toString() << endl;
  cout << e1.toString() << endl;



  /*
  // which one compiles?
  p0 = e0;
  e0 = p0;
  */
}
