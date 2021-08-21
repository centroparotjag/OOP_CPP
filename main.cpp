#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

#define false  0
#define true   1
#define empty -1

// 1. ------------------------------------------------------------
class Power{
private:
    int number;
    int power;
public:
    Power(){
        number  = 0;
        power = 0;
    }

    ~Power()
    {
    }

    void set(int num, int pow){
        number = num;
        power  = pow;
    }

    void calculate (){
        int result = pow(number, power);
        cout << number << "^" << power << "=" << result << std::endl;
    }
};

// 2. ---------------------------------------------------------------
class RGBA{
private:
    std::uint8_t m_red   = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue  = 0;
    std::uint8_t m_alpha = 255;
public:
    RGBA()
    {
    }

    RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }

    ~RGBA()
    {
    }

    void print(){
        printf("\r\n");
        printf("m_red   = %d\r\n", m_red);
        printf("m_green = %d\r\n", m_green);
        printf("m_blue  = %d\r\n", m_blue);
        printf("m_alpha = %d\r\n", m_alpha);
    }
};

// 3. ------------------------------------------------------------
class Stack{
private:
    int arr_stack [10] = {0};
    int len = 0;
public:
    Stack()
    {
    }

    ~Stack()
    {
    }

    void reset (){
        for (int i = 0; i < 10; ++i) {
            arr_stack [i] = 0;
        }
        len = 0;
    }

    int push(int data){
        if (len >= 10)
            return false;

        arr_stack [len++] = data;
        return true;
    }

    int pop(){
        if (len == 0)
            return empty;

        return arr_stack [len--];
    }

    void print(){
        printf("(");
        for (int i = 0; i < len; ++i) {
            printf(" %d", arr_stack [i]);
        }
        printf(" )\r\n");
    }
};



int main(int argc, char *argv[]){
/*1. Создать класс Power, который содержит два вещественных числа.
     Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
     Еще создать два метода: один с именем set, который позволит присваивать значения переменным,
     второй — calculate, который будет выводить результат возведения первого числа в степень второго числа.
     Задать значения этих двух чисел по умолчанию. */
    Power calc;
    calc.set(12, 7);
    calc.calculate ();



/*2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
     Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
     Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
     Написать функцию print(), которая будет выводить значения переменных-членов. */
    RGBA colour;
    //RGBA colour(1,2,3,4);
    colour.print();



/*3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
    -   private-массив целых чисел длиной 10;
    -   private целочисленное значение для отслеживания длины стека;
    -   public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
    -   public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
    -   public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
    -   public-метод с именем print(), который будет выводить все значения стека. */
    printf("\r\n");

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

//    ( )
//    ( 3 7 5 )
//    ( 3 7 )
//    ( )

    return 0;
}
