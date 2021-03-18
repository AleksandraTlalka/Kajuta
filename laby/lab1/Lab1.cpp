#include<string>
#include<iostream>
#include<typeinfo>

//---------------------------------------------------------------------
//Klasa Program
//---------------------------------------------------------------------
class Program {
protected:
    std::string name;
public:
    Program(std::string n)
        :name(n)
    {
    }
    virtual void print() = 0;
    virtual ~Program() {}
};
//---------------------------------------------------------------------
//Klasa Freeware
//---------------------------------------------------------------------
class Freeware: public Program {
public:
    Freeware(std::string name)
        :Program(name) {}
    void print() {}
};
//---------------------------------------------------------------------
//Klasa Shareware
//---------------------------------------------------------------------
class Shareware: public Program {
private:
    float price;
public:
    float getPrice() { return price;}
    Shareware(std::string name, float cash)
        :Program(name), price(cash) {}
    void print() {}
};
//---------------------------------------------------------------------
//Funkcje
//---------------------------------------------------------------------
float total(Program* prg[], int size) {
    Shareware* share;
    float total = 0;
    for (int i = 0; i < size; i++) {
        if (share = dynamic_cast<Shareware*>(prg[i]))
            total = total + share->getPrice();
    }
    return total;
}
void print(Program* prg[], int size) {
    Shareware* share;
    for (int i = 0; i < size; i++) {
        if (typeid(Shareware) == typeid(*prg[i]))
            std::cout << typeid(*prg[i]).name()<< std::endl;
    }
}


int main()
{
    Freeware free1("Freeware1");
    Freeware free2("Freeware2");
    Shareware sha1("Shareware1", 15.92);
    Shareware sha2("Shareware2", 13.24);
    Shareware sha3("Shareware3", 11.44);
    Program* prgram[5] = { &free1, &free2, &sha1, &sha2, &sha3};
    std::cout << total(prgram, 5);
    std::cout << std::endl;
    print(prgram, 5);
    return 0;
}

