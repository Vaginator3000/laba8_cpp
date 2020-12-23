#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    int power;
    int weight;
    string color;
    int cost;

public:
    void init() {
        brand = " ";
        model = " ";
        year = 0;
        power = 0;
        weight = 0;
        color = " ";
        cost = 0;
    }

    void init(string brand, string model, int _year, int _power, int _weight, string _color, int _cost) {
        this->brand = " ";
        this->brand = brand;
        this->model = " ";
        this->model = model;
        year = _year;
        power = _power;
        weight = _weight;
        color = " ";
        color = _color;
        cost = _cost;
    }

    void read() { //Ввод данных
        cout << "Enter a brand: ";   cin >> brand;
        cout << "Enter a model: ";   cin >> model;
        cout << "Enter a year: ";    cin >> year;
        cout << "Enter a power: ";   cin >> power;
        cout << "Enter a weight: ";  cin >> weight;
        cout << "Enter a color: ";   cin >> color;
        cout << "Enter a cost: ";    cin >> cost;
    }

    void display() {
        cout << endl;
        cout << brand << " " << model << " " << year << "года" << endl;
        cout << power << "л.с. " << weight << "кг" << endl;
        cout << color << endl;
        cout << cost << endl;
    }

    void changeColor() {
        cout << "Enter a new color: ";   cin >> color;
    }

    int getCost() {
        return cost;
    }

};

class Autoshow {
private:
    Car car;
    int count;
    static int allCarsCount;  

public:
    void init() {
        car.init();
        count = 1;
        allCarsCount++;
    }

    void init(Car _car, int _count) {
        car = _car;
        count = _count;
        allCarsCount++;
    }

    void read() {
        car.read();
        cout << "Enter a count: ";    cin >> count;
    }

    void display() {
        car.display();
        cout << "Количество: " << count << endl;
        cout << endl;
    }

    void changeCount(int n) {
        count = n;
    }

    void changeCar(Car _car) {
        car = _car;
    }

    static int getCarsCount() {
        return allCarsCount;
    }
};

int Autoshow::allCarsCount = 0;

int main() {
    setlocale(LC_ALL, "rus");

    Autoshow ashow[2];
    Car car;
    car.init("Ford", "F-150", 2013, 400, 3000, "black", 3000000);
    ashow[0].init(); //1 экземпляр
    ashow[1].init(); //2 экземпляр
    ashow[0].changeCar(car);
    ashow[0].display();
    
    cout << Autoshow::getCarsCount() << endl; //вывод 2


    return 0;
}
