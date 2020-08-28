#include <iostream>
#include <vector>
using namespace std;

class IObserver {

public:
virtual void update() = 0;
}; 

class IObservebal
  {
public:

  virtual void add(IObserver*) = 0;

 // virtual void remove() = 0;

  virtual void notify() = 0;

  };

class Station : public IObservebal
{
  vector <IObserver*> observers = vector <IObserver*>(0);
  int tempeture = 0 ;  
  public:

  void add(IObserver* observer) override {
    observers.push_back(observer);
  } 
  // void remove(IObserver* obs) {
  //   observers.push_back(obs);
  // }

  void notify() override {
    for(IObserver *o : observers) {
      o->update();
    }
  }
  void setTempeture(int tempeture) {
      this->tempeture = tempeture;
      this->notify();
  }
  int getTempture() {
    return this->tempeture;
  }
};

class Display : public IObserver {

string name;
Station* st;
public:
Display(string name,Station* st) {
  this->name = name;
  this->st = st;
}

void update() {
  cout << "I'm updated ! "<< this->name <<" the new tempeture is: " << this->st->getTempture() << endl;
}
};

class Phone : public IObserver
{
private:
  Station* st;
  string name;
public:
  Phone(string name, Station* st) {
    this->name = name;
    this->st = st;
  }
void update() override {
  cout << "I'm updated ! "<< this->name <<" the new tempeture is: " << this->st->getTempture() << endl;
}
};

int main() {
  
  Station* s = new Station();
  IObserver* o1 = new Display("LG",s); 
  IObserver* o2 = new Display("CONDOR",s); 
  IObserver* o3 = new Phone("Samsung",s); 
  s->add(o1);
  s->add(o2);
  s->add(o3);
  s->setTempeture(37);
  

  return 0;
}
