#include <iostream>
using namespace std;

/*class IFlyBehaivior {
public:
    virtual void fly() = 0;
};

class IFlyBehaiviourConcrete:IFlyBehaivior {

    void fly() {
        cout << " i Flay concrete here ! " << endl;
    }
};
class NoIFlyBehaiviourConcrete:IFlyBehaivior {
    void fly() {
        cout << "i cant fly " << endl;
    }
};
class IQuackBehaibvior {
public:
    virtual void quack() = 0;
};
class IQuackBehaiviorConcrete:IQuackBehaibvior {
    void quack() {
        cout << " i quack concrete:: "<<endl;
    }
};
class NoIQuackBehaiviorConcrete:IQuackBehaibvior {
    void quack() {
        cout << " No concrete behaivior:: " << endl;
    }
};

class Duck {
private:
    IQuackBehaibvior *iq;
    IFlyBehaivior *ifl;
public:
    Duck(IFlyBehaiviourConcrete *iq = nullptr, IFlyBehaivior *ifl = nullptr) {
        this->iq = reinterpret_cast<IQuackBehaibvior *>(iq);
        this->ifl = ifl;
    }

    void fly() {
        this->ifl->fly();
    }
    void quack() {
        this->iq->quack();
    }
};*/
// SECOND EXAMPLE
 /*class strategy {
public:
    virtual int doOperation(int x, int y) = 0;
};
class Operationadd : public strategy {
public:
    int doOperation(int x, int y) {
        return x+y;
    }
};
class Operationsub : public strategy {
public:
    int doOperation(int x, int y) {
        return x-y;
    }
};
class Operationmul : public strategy {
public:
    int doOperation(int x, int y) {
        return x*y;
    }
};
class Context {
public:
    strategy *sr;
public:
    Context(strategy *st = nullptr) {
        this->sr = st;
    }
    int Operation(int x,int y) {
        return this->sr->doOperation(x,y);
    }
};*/
// ***********************************************************
class IJumpBehaivior {
public:
    virtual void jump() = 0;
};
class LongJump : IJumpBehaivior {
    void jump() override {
        cout << " Long jumping... :: " << endl;
    }
};
class ShortJump : IJumpBehaivior{
    void jump() override {
        cout << "Short Jump ... " << endl;
    }
};

class IRollBehaivior{
public:
    virtual void roll() = 0;
};
class TornadoRoll : public IRollBehaivior {
    void roll() override {
        cout << "Hi, there ! I'm tornado roll " << endl;
    }
};
class LighningRoll : public IRollBehaivior {
    void roll() override {
        cout << "Hi there !, I'm Lighning roll " << endl;
    }
};



class Fighter {
private:
IRollBehaivior *ir;
IJumpBehaivior *ij;

public:
    Fighter(IRollBehaivior *ir= nullptr, IJumpBehaivior *ij= nullptr) {
        this->ir = ir;
        this->ij = ij;
    }

    virtual void display() = 0;
    void kick() {
        cout << "I'm kicking right now ! " << endl;
    }
    void punch() {
        cout << "I'm punshing right now ! " << endl;
    }
    void roll() {
        this->ir->roll();
    }
    void jump(){
        this->ij->jump();
    }
};

class RyuConcrete : public Fighter {
public:
    void display() override {
        cout << "hi I'm RyuConcrete! " << endl;
    }
};
class  KenConcrete : public Fighter {
public:
    void display() override {
        cout << "Hi there ! I'm a KenConcrete ! " << endl;
    }
};

class ChunLiConcrete : public Fighter{
public:
    void display() override {
        cout << "I'm rolling in ChunLi concrete ! " << endl;
    }
};

int main() {

    ChunLiConcrete *cn = new ChunLiConcrete();
    cn->display();
    cn->jump();
    cn->roll();

    /*Duck GoodDuck = *new Duck(new IFlyBehaiviourConcrete, reinterpret_cast<IFlyBehaivior *>(new IQuackBehaiviorConcrete));
    GoodDuck.quack();
    GoodDuck.fly();*/

//    Context *cn = new Context(new Operationmul);
//
//    cn->Operation(10,20);
//Fighter *f = new Fighter(new KenConcrete)


    return 0;
}