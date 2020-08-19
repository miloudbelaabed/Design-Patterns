#include <iostream>
using namespace std;

class IJumpBehaivior {
public:
    virtual void jump() = 0;
};
class LongJump : public IJumpBehaivior {
private:
    void jump() override {
        cout << " Long jumping... :: " << endl;
    }
};
class ShortJump : public IJumpBehaivior{
private:
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

    void setIr(IRollBehaivior *ir) {
        this->ir = ir;
    }

    void setIj(IJumpBehaivior *ij) {
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
    RyuConcrete(IRollBehaivior *ir= nullptr, IJumpBehaivior *ij= nullptr) :  Fighter(ir,ij) {}
    void display() override {
        cout << "hi I'm RyuConcrete! " << endl;
    }
};
class  KenConcrete : public Fighter {
public:
    KenConcrete(IRollBehaivior *ir= nullptr, IJumpBehaivior *ij= nullptr) :  Fighter(ir,ij) {}
    void display() override {
        cout << "Hi there ! I'm a KenConcrete ! " << endl;
    }
};

 class ChunLiConcrete : public Fighter{
public:
    ChunLiConcrete(IRollBehaivior *ir= nullptr, IJumpBehaivior *ij= nullptr) :  Fighter(ir,ij) {}
    void display() override {
        cout << "I'm rolling in ChunLi concrete ! " << endl;
    }
};

int main() {
    LongJump *ljj = new LongJump();
    TornadoRoll *tn = new TornadoRoll();
    ChunLiConcrete *cn = new ChunLiConcrete(tn, ljj);
    cn->display();
    cn->jump();
    cn->roll();
    ShortJump *sh = new ShortJump();
    cn->setIj(sh);
    cn->jump();
    return 0;
}