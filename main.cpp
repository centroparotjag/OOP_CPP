#include <iostream>
#include <cstdint>
#include <math.h>

#define closed 0
#define open   1

using namespace std;

// 1.------------------------------------------------
class Figure{
protected:
    double S=0;
public:
    Figure (double S) {
        S = 0;
    }
    ~Figure(){}
    virtual void area () = 0;
    void print (string text) const {
        cout << text << " area = " << S << endl;
    }
};

class Parallelogram : public Figure {
protected:
    double a;
    double b;
    double angle;
public:
    Parallelogram () : Figure(0){
        S = 0;
        a = 0;
        b = 0;
        angle = 0;
    }
    ~Parallelogram (){}
    void area() override{
        S = a * b * sin(angle * M_PI / 180);
    }
    void set_Parallelogram (double a_P, double b_P, double angle_P){
        a = a_P;
        b = b_P;
        angle = angle_P;
    }
};

class Circle : public Figure {
protected:
    double radius;
public:
    Circle () : Figure(0){
        radius = 0;
    }
    ~Circle (){}
    void area() override{
        S = M_PI * pow (radius, 2);
    }
    void set_Circle (double R){
        radius = R;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle () {}
    ~Rectangle () {}
    void area() override{
        S = a * b;
    }
    void set_Rectangle (double a_P, double b_P){
        a = a_P;
        b = b_P;
    }
};

class Square : public Parallelogram {       // квадрат
public:
    Square () {}
    ~Square () {}
    void area() override{
        S = pow (a, 2);
    }
    void set_Square(double a_P){
        a = a_P;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus () {}
    ~Rhombus () {}
    void area() override{
        S = pow (a, 2) * sin(angle * M_PI / 180);
    }
    void set_Rhombus(double a_P, double angle_P){
        a = a_P;
        angle = angle_P;
    }
};


// 2.------------------------------------------------
class Car
{
protected:
    string company;
    string model;
public:
    Car () {
        cout << "Car" << endl;
    }
    ~Car () {
        cout << "~Car" << endl;
    }
};

class PassengerCar: virtual public Car
{
public:
    PassengerCar (string company, string model) {
        cout << "PassengerCar" << endl;
    }
    ~PassengerCar () {
        cout << "~PassengerCar" << endl;
    }
};

class Bus: virtual public Car
{
public:
    Bus (string company, string model) {
        cout << "Bus" << endl;
    }
    ~Bus () {
        cout << "~Bus" << endl;
    }
};

class Minivan: public PassengerCar, public Bus
{
public:
    Minivan (string company, string model) :  PassengerCar(company, model), Bus(company, model) {
        cout << "Minivan" << endl;
    }
    ~Minivan () {
        cout << "~Minivan" << endl;
    }
};



// 4.------------------------------------------------



class Card {
private:
    enum card_suit{Hearts, Tiles, Clovers, Pikes} enum_suit;
    enum card_value{two, three, four, five, six, seven, eight, nine, ten, jack, lady, king, ace} enum_value;
    bool card_position;
public:
 //   Card ( card_suit suit, card_value value, bool position) : enum_suit(suit),  enum_value(value), card_position(position){}
    Card (){}
    void Flip(){
        card_position = !card_position;
    }

    int GetValue(){

    }
    void print (){
        cout << "enum_value -" << enum_value << ", enum_suit - " << enum_suit << ", card_position - " << card_position << endl;

    }
};


int main(int argc, char *argv[]){


/*  1.Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
 *  Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
 *  Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
 *  Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.    */

    Parallelogram P_area;
    P_area.set_Parallelogram (3.45 , 8.9, 45);
    P_area.area();
    P_area.print("Parallelogram");

    Circle C_area;
    C_area.set_Circle (5.25);
    C_area.area();
    C_area.print("Circle");

    Rectangle R_area;
    R_area.set_Rectangle(2.1 , 4.5);
    R_area.area();
    R_area.print("Rectangle");

    Square S_area;
    S_area.set_Square(2.1);
    S_area.area();
    S_area.print("Square");

    Rhombus RO_area;
    RO_area.set_Rhombus(8.4, 90);
    RO_area.area();
    RO_area.print("Rhombus");


/* 2.Создать класс Car (автомобиль) с полями company (компания) и model (модель).
 * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
 * От этих классов наследует класс Minivan (минивэн).
 * Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
 * Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
 * Обратить внимание на проблему «алмаз смерти». */

    Minivan diamond ("DeLorean", "DMC-12");


/* 4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля:
 * масть, значение карты и положение карты (вверх лицом или рубашкой).
 * Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool.
 * Также в этом классе должно быть два метода:
 * - метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
 * - метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1. */

//    Card game;
//    game.Flip();

//    game.print();
    // Не доделал.












    return 0;
}
