#include <iostream>
#include <cstdint>

using namespace std;


// 1. --------------------------------------------------------------------
class Person {
protected:
    string name;
    int age;
    string floor;
    int weight;
public:
    Person (string n, int a, string f, int w) : name(n), age(a), floor(f), weight(w){}
    ~Person(){}
};


class Student : public Person
{
private:
    int year;
    static int count;
public:
    Student(string n, int a, string f, int w, int y) : Person (n, a, f, w), year(y) { count++; }
    ~Student(){}

    void print() const{
        std::cout << "name-" << name << " age-" << age << " floor-" << floor << " weight-" << weight << " year-" << year << std::endl;
    }

    static int getCount(){
        return count;
    }
};

int Student::count = 0;


// 2. --------------------------------------------------------------------
class Fruit
{
protected:
    string name;
    string color;
public:
    Fruit(string n, string c) : name(n), color(c){}
    ~Fruit(){}

};

class Banana : public Fruit
{
protected:
    double weight;
public:
    Banana(string n, string c, double w) : Fruit(n, c), weight(w) { }
    ~Banana() {}
};


class Apple : public Fruit
{
protected:
    double weight;
public:
    Apple(string n, string c, double w) : Fruit(n, c), weight(w) { }
    ~Apple() {}

};

class GrannySmith : public Apple
{
protected:
    double size;
public:
    GrannySmith(string n, string c, double w, double s) : Apple(n, c, w), size(s){}
    ~GrannySmith() {}
    void print() const{
        std::cout << "name-" << name << " color-" << color << " weight-" << weight << " size-" << size << std::endl;
    }
};




int main(int argc, char *argv[]){

/*   1. Создать класс Person (человек) с полями: имя, возраст, пол и вес.
    Определить методы переназначения имени, изменения возраста и веса.
    Создать производный класс Student (студент), имеющий поле года обучения.
    Определить методы переназначения и увеличения этого значения.
    Создать счетчик количества созданных студентов.
    В функции main() создать несколько студентов. По запросу вывести определенного человека. */


    Student Vasia("Vasia", 18, "m", 61, 2021);
    Student Petia("Petia", 17, "m", 60, 2020);
    Student Anna("Anna", 16, "f", 59, 2019);

    std::cout << "Student - " << Student::getCount() << std::endl;

    Vasia.print();
    Petia.print();
    Anna.print();


/*   2.  Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
    У Fruit есть две переменные-члена: name (имя) и color (цвет).
    Добавить новый класс GrannySmith, который наследует класс Apple. */

    GrannySmith variety("GrannySmith", "Red", 0.558, 1.01);
    variety.print();



    return 0;
}
