#include <iostream>
#include <string>

class  Person
{
public:
    Person( );
    Person(std::string theName);
    std::string getName( ) const{return name;}

private:
    std::string name;

};

Person::Person( )
{
     name = "Default";
     std::cout<<"Default Person Constructor Called"<<std::endl;
}

Person::Person(std::string theName)
{
     name = theName;
     std::cout<<"Person Constructor Called for "<<name<<std::endl;

   }

class Student : virtual public Person
{
public:
    Student( );
    Student(std::string theName, double theGpa);
    double getGpa()const{return gpa;}

private:
    double gpa;
};



Student::Student( ): Person()
{
     gpa = 0;

     std::cout<<"Default Student Constructor Called"<<std::endl;
}


Student::Student(std::string theName, double theGpa ):Person(theName)
{

     gpa = theGpa;

     std::cout<<"Student Constructor Called for "<<gpa<<std::endl;

}

class Employee: virtual public Person
{
public:
    Employee( );
    Employee(std::string theName, double theSalary);
    double getSalary()const{return salary;}

private:
    double salary;
};

Employee::Employee( ): Person()
{
     salary = 0;
     std::cout<<"Default Employee Constructor Called"<<std::endl;
}


Employee::Employee(std::string theName, double theSalary )
: Person(theName)
{
     salary = theSalary;
     std::cout<<"Employee Constructor Called for "<<salary<<std::endl;

}

class Grader: public Student, public Employee
{
public:
    Grader( );
    Grader(std::string theName, double theSalary, std::string theCourse, double theGpa);
    std::string getCourse( ) const{return course;}
    std::string getName() const {return Student::getName();}

private:
    std::string course;
};

Grader::Grader( ): Employee(), Student()
{
     course = "None";

     std::cout<<"Default Grader Constructor Called"<<std::endl;

}

Grader::Grader(std::string theName, double theSalary, std::string theCourse, double theGpa):
Employee(theName, theSalary), Student(theName, theGpa), Person(theName)
{
     course=theCourse;
     std::cout<<"Grader Constructor Called for "<<course<<std::endl;

}


using namespace std;
int main(){
  Grader g = Grader("Jill", 2000, "Math 12", 3.2);
  cout<<g.getGpa()<<" "<<g.getName()<<" "<<g.getSalary()<<" "<<g.getCourse()<<endl;

  return 0;
}
