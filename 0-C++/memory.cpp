#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
  public:
    User () {}
    User (string n) { name = n; }
    string getName() { return name; }
  private:
    string name;
};

class Network {
  public:
    Network () {}

    void addUser(string name) {
      //User c1(name);  //This is bad!  c1's memory is reclaimed at the end of the function call
      //users.push_back(&c1); 
      //users.push_back(u1);
      //Allocate memory for the user on the heap instead
      User* c1 = new User("name");

    }

    void print() {
      for (auto u : users) {
        cout << u->getName() << endl;
      }
    }
  private:
    vector<User*> users;
};


int main () {
  Network network;
  network.addUser("Alice");
  network.addUser("Bob");
  network.addUser("Charlie");
  network.print();
}
