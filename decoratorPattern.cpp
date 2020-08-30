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
class mikl : public Beverage {
  public :
  int cost(){
    return 3;
  }
};
class milk : public Beverage {
  int cost() {
    
    return 1;
  }
};

class addOnDecorator: public Beverage {
  public:
  virtual int cost() = 0;
};

class caramel : public addOnDecorator {
Beverage* b;
public:
caramel(Beverage* b) {
  this->b = b;
}
int cost() {
  return this->b->cost() + 2;
}
};
class chocklet : public addOnDecorator {
  Beverage* b;
  public:
  chocklet(Beverage* b) {
    this->b = b;
  }
  int cost() {
    return this->cost() + 3;
  }
};
int menu() {
  int n;
  cout << "chose your beverege from the list bellow : " << endl;
  cout << "1- espresso "  << endl;
  cout << "2 - milk " << endl;
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
  cout << "1: caramel " << endl;
  cout << "2: chocklet " << endl;
  cin >> ans;
  switch (ans)
  {
  case 1:
    Beverage* c = new caramel(beverage);
    break;
  case 2:
    Beverage* d = new chocklet(beverage);
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