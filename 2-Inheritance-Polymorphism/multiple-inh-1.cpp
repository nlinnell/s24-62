#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee( )
    {
         name = "Default";
         salary = 0;
    }

    Employee(std::string theName, double theSalary )
    {
         name = theName;
         salary = theSalary;
    }

    std::string getName( ) const{return name;}
    double getSalary()const{return salary;}

private:
    std::string name;
    double salary;
};

class Student
{
public:
    Student( )
    {
         name = "Default";
         gpa = 0;
    }

    Student(std::string theName, double theGpa )
    {
         name = theName;
         gpa = theGpa;
    }
    std::string getName( ) const{return name;}
    double getGpa()const{return gpa;}

private:
    std::string name;
    double gpa;
};

class Grader: public Student, public Employee
{
public:
    Grader( ): Employee(), Student()
    {
         course = "None";
    }

    Grader(std::string theName, double theSalary, std::string theCourse, double theGpa):
    Employee(theName, theSalary), Student(theName, theGpa)
    {
         course=theCourse;
    }
    std::string getCourse( ) const{return course;}
    std::string getName() const{return Employee::getName();}

private:
    std::string course;
};

int main(){
Grader g = Grader("Jill", 2000, "Math 12", 3.2);
cout<<g.getGpa()<<" "<<g.getName()/*g.Student::getName()*/<<" "<<g.getSalary()<<" "<<g.getCourse()<<endl;

}