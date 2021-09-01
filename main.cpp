#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/*1.Добавить в контейнерный класс, который был написан в этом уроке, методы:
 * - для удаления последнего элемента массива (аналог функции pop_back() в векторах)
 * - для удаления первого элемента массива (аналог pop_front() в векторах)
 * - для сортировки массива
 * - для вывода на экран элементов. */


class ArrayInt{
private:
    int *m_data;
    int m_length;
public:
    ArrayInt() : m_length(0), m_data(nullptr){

    }
    ArrayInt(int length) : m_length(length){
        assert(length >= 0);            //#include <cassert>
        if(length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    ~ArrayInt(){
        delete []  m_data;
    }
    void clear(){
        delete [] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int size () const{
        return m_length;
    }
    int& operator[](int index){
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newLength){
        if (newLength == m_length)
            return;
        if (newLength <= 0){
            clear();
            return;
        }
        int *data = new int[newLength];
        int elementsToCopy = newLength > m_length ? m_length : newLength;
        for (int i = 0; i < elementsToCopy; ++i) {
            data[i] = m_data[i];
        }
        delete []  m_data;
        m_data = data;
        m_length = newLength;
    }
    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int *data = new int[m_length+1];

        // Копируем все элементы до index-а
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем новый элемент в новый массив
        data [index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value){
        insertBefore(value, m_length);
    }

    // **************************    1. added func. here  *****************************************************

    void analog_pop_back(){                 // для удаления последнего элемента массива (аналог функции pop_back() в векторах)
        // Создаем новый массив на один элемент меньше старого массива
        int *data = new int[m_length-1];

        // Копируем все элементы до index-а
        for (int before=0; before < m_length-1; ++before)
            data[before] = m_data[before];

        // Удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void analog_pop_front(){       // для удаления первого элемента массива (аналог pop_front() в векторах)
        // Создаем новый массив на один элемент меньше старого массива
        int *data = new int[m_length-1];

        // Копируем все элементы после 0
        for (int before=1; before < m_length; ++before)
            data[before-1] = m_data[before];

        // Удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    //------ рекурсивная быстрая сортировка, признаюсь - украл в сети (http://mindhalls.ru/quick-sort-c-cpp/) ---------
    void qsortRecursive(int *mas, int size) {
        //Указатели в начало и в конец массива
        int i = 0;
        int j = size - 1;

        //Центральный элемент массива
        int mid = mas[size / 2];
        //Делим массив
        do {
            //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
            //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
            while(mas[i] < mid) {
                i++;
            }
            //В правой части пропускаем элементы, которые больше центрального
            while(mas[j] > mid) {
                j--;
            }
            //Меняем элементы местами
            if (i <= j) {
                int tmp = mas[i];
                mas[i] = mas[j];
                mas[j] = tmp;
                i++;
                j--;
            }
        } while (i <= j);
        //Рекурсивные вызовы, если осталось, что сортировать
        if(j > 0) {
            //"Левый кусок"
            qsortRecursive(mas, j + 1);
        }
        if (i < size) {
            //"Првый кусок"
            qsortRecursive(&mas[i], size - i);
        }
    }
    void sort_array (){
        qsortRecursive(m_data, m_length);
    }

    void print_array (){                    // для вывода на экран элементов
        for (int i = 0; i < size (); ++i) {
            cout <<  m_data [i] << " ";
        }
        cout << endl;
    }
};


/* 2. Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм. */

int number_of_different (vector<int>& vec){
    // Удаляю из вектора (массива) все что повторяется (в задании не запрещено "портить вектор")
    int j = 0;
    while (j < (int)vec.size()-1){
        int tmp = vec[j];

        int flag = 0;
        int cnt_erase_cycle = 0;
        int i = (int)vec.size()+1;

        for ( ; i > j; i--)
        {
            if(cnt_erase_cycle==0 && i==1+j)        // не удалять самого себя если небыло раньше
                continue;
            if (tmp == vec[i-1]){
                  vec.erase(vec.begin() + i-1);
                  flag = 1;
                  cnt_erase_cycle++;
            }
        }

        if (!flag)
            j++;
    }

    // из остатка вектора возвращаю его размер
    return vec.size();
}

void print_vector (vector<int>& vec){
    for (int i = 0; i < (int)vec.size(); ++i) {
        cout <<  vec [i] << " ";
    }
    cout << endl;
}

/* 3. Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле: вектор указателей карт
 * (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).
 * Также в классе Hand должно быть 3 метода:
 * - метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
 * - метод Clear, который очищает руку от карт
 * - метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11). */


// не понял как реализовать (суть задачи) (:

typedef int Card;

class Hand {
private:
    vector<Card*> m_Cards;
public:
    void Add (Card* pCard){

    }
    void Clear(){

    }

    int GetValue(){

    }

};







int main(int argc, char *argv[]){

// 1. -----------------------------------------
    ArrayInt arr1(16);
    arr1.print_array();
    for (int i = 0; i < 16; ++i) {
        arr1.insertBefore(i, i);
    }
    arr1.print_array();
    for (int i = 32; i > 15; i--) {
        arr1.push_back(i);
    }
    arr1.print_array();
    arr1.analog_pop_back();
    arr1.print_array();
    arr1.analog_pop_front();
    arr1.print_array();
    arr1.sort_array ();
    arr1.print_array();

// 2. -----------------------------------------
    vector<int> arr2 {3, 3, 3, 10, 255, 1, 32, 3, 0, 7, 8, 44, 55, 1, 73, 18, 3, 0, 7, 7, 4};
    print_vector(arr2);
    cout << "Different = " << number_of_different (arr2) << endl;
    print_vector(arr2);

// 3. -----------------------------------------





    return 0;
}
