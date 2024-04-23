#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Shape{
private:
	std::size_t sides_;
public:
	Shape(){}
	Shape(std::size_t s){sides_=s;}
	std::size_t sides(){return sides_;}
	virtual double area()=0;
	virtual double perimeter()=0;
};

class Rectangle: public Shape{
private:
	double w_, h_;
public:
	Rectangle():Shape(4){w_=h_=0;}
	Rectangle(double width, double height):Shape(4){w_=width; h_=height;}
	double w(){return w_;}
	double h(){return h_;}
	//Different restrictions or rules about what Rectangle can do wrt to 
	//sides() vs area() from Shape?
	//We HAVE to give versions of area and perimeter bc pure virtual
	double area(){
		return w_*h_;
	}
	double perimeter(){
		return 2*(w_+h_);
	}
};

class Square: public Rectangle{
public:
	Square():Rectangle(){}
	Square(double side):Rectangle(side, side){}
	//What should we do for area and perimeter for Square?
/*	double area(){
		return h()*h();
	}
	*/
	double area(){
		cout<<"Square"<<endl;//Can always call parent's method + do more stuff
		return Rectangle::area();
	}//Could skip implementing area and just use Rectangle's
	//Skip implementing perimeter and use Rectangle's
};

class Triangle: public Shape{
private:
	double base_, height_, side1_, side2_;
public:
	Triangle():Shape(3){base_=height_=side1_=side2_=0;}
	Triangle(double b, double h, double s1, double s2):Shape(3){
		base_=b; height_=h;
		side1_=s1; side2_=s2;
	}
	double base(){return base_;}
	double height(){return height_;}
	double side1(){return side1_;}
	double side2(){return side2_;}
	double area(){return .5*base_*height_;}
	double perimeter(){return base_+side1_+side2_;}

};

class RightTriangle: public Triangle{
public:
	RightTriangle():Triangle(){}
	RightTriangle(double a, double b): Triangle(a, b, b, sqrt(a*a+b*b)){}
	double hypotenuse(){return Triangle::side2();}
	double a(){return Triangle::base();}
	double b(){return Triangle::side1();}
	//Can use Triangle's area and perimeter

};
int main(){
	vector<Shape*> v;
  Square* s = new Square(10);//How many constructors are called?  3
  v.push_back(s);
  v.push_back(new Rectangle(3, 9));
  v.push_back(new RightTriangle(3, 4)); // which line of code figures out the third side length?

	for(auto e:v){
		cout<<e->perimeter()<<endl;;
	}

  Rectangle* r = new Square (10);
  cout << r->perimeter() << endl;
}
