#include <iostream>
using namespace std;
class Animal{
 private:
	string name;
 public:
	Animal(){
		name = "";
		cout<<"A new Animal has been created!"<<endl;
	}
	Animal(string n){
		name = n;
		cout<<"A new Animal has been created: "<<name<<endl;
	}
	string getName(){return name;}
	void sleep(){
		cout<<"An Animal sleeps ..."<<name<<endl;
	}
	void eat(){
		cout<<"An Animal eats ..."<<name<<endl;
	}
};
class Bird: public Animal{
 public:
	Bird(){
		cout<<"A new Bird has been created!"<<endl;
	}
	Bird(string n): Animal(n){
		cout<<"A new Bird has been created!"<<endl;
	}
	void sleep(){
		cout<<"A Bird sleeps ..."<<getName()<<endl;
	}
};
class Cat: public Animal{
 public:
	Cat(){
		cout<<"A new Cat has been created!"<<endl;
	}
	Cat(string n): Animal(n){
		cout<<"A new Cat has been created!"<<endl;
	}
	void sleep(){
		Animal::sleep();
		cout<<"A Cat sleeps ..."<<getName()<<endl;
	}
	void meow(){
		cout<<"Meow!!"<<endl;
	}
};
int main(){
	cout<<"constructor calls:"<<endl;
	Cat c1;
	Cat c2("Henry the Cat");
	Animal a("Spot the Giraffe");
	Bird b;
	cout<<"method calls:"<<endl;
	a.eat();
	a.sleep();
	//a.meow();
	b.eat();
	b.sleep();
	//b.meow();
	c2.eat();
	c2.sleep();
	c2.meow();


/*
 Animal a; 
 Bird b; 
 Cat c; 
 a = b; 
 b = a;
 a = c; 
 c = a; 
 a.sleep(); 
 b.sleep(); 
 c.sleep(); 


/*




	a1=c2;//  a1= (Animal) c2; Treat a cat object like an animal?
	c1=a2;// c1 = (Cat) a2; Treat an animal object like a cat


	a1.sleep();//Calls which sleep?
	a1.eat();
	a1.meow();

	Animal* ap = &c2;
	ap->eat();
	ap->sleep();//Calls Cat's sleep
	//ap->meow();//Can only do Animal things while treating like an Animal

	  Animal a1, a2;
  Bird b1, b2;
  a1=b1; // really: a1 = (Animal) b1;
  //b2=a2; // really: b2 = (Bird) a2;

  Animal a; Bird b; Cat c;

  vector<Animal> v;
  v.push_back(a);
  v.push_back(b);
  // equivalent: v.push_back((Animal)b);
  v.push_back(c);

  for (auto a_ : v) {
    a_.sleep();
  }

*/
}