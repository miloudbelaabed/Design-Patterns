#include <iostream>
using namespace std;
class Beverage {
  public:
  virtual int cost() = 0;
  void discription() {
    cout <<"this is a beverage " << endl;
  }
};
class espreso : public Beverage {
  public:
  int cost() {
    return 1;
  }
};

class milk : public Beverage {
  int cost() {
    
    return 2;
  }
};

class addOnDecorator: public Beverage {
Beverage* b;
  public:
  addOnDecorator(Beverage* b) {
    this->b = b;
  }
  int cost() {
    return this->b->cost();
  } 
};


class caramel : public addOnDecorator {
public:
caramel(Beverage *b):addOnDecorator(b) {};
int cost() {
  return addOnDecorator::cost() + 2;
}
};
class chocklet : public addOnDecorator {
  public:
  chocklet(Beverage* b):addOnDecorator(b) {};
  int cost() {
    return addOnDecorator::cost() + 3;
  }
};

int menu() {
  int n;
  cout << "chose your beverege from the list bellow : " << endl;
  cout << "1- espresso 1 da"  << endl;
  cout << "2 - milk 2 da" << endl;
  cin >> n ;
  return n;
}
int main() {
  int choix;
  Beverage* beverage;
  choix = menu();
  switch (choix) 
  {
  case 1:
    beverage = new espreso();
    break;
  case 2:
    beverage = new milk();            
    break;
  default:
  cout << "you are out of range ! " << endl;
    break;
  }

  int addon=1;
  while (addon == 1)
  {
  cout << "do you want to add something into your beverage ? "<< endl;
  cout << "1: YES ! " << endl;
  cout << "2: NO ! " << endl;
  cin >> addon;
  if (addon == 1)
  {
  int ans;
  cout << "1: caramel 2 da" << endl;
  cout << "2: chocklet 3 da" << endl;
  cin >> ans;
  switch (ans)
  {
  case 1:
    beverage = new caramel(beverage);
    break;
  case 2:
    beverage = new chocklet(beverage);
    break;
  default:
    cout<< "its not in the list "<< endl;
    break;
  }
}else{
   cout << "OK enjoy " << endl;
   break;

  }
  }
  cout <<"your cost : "<< beverage->cost();
  return 0;
}