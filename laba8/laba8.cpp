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
    int VIN;
    const static int number = 222;
    static int allCarsCount;  

public:
    void init() {
        brand = " ";
        model = " ";
        year = 0;
        power = 0;
        weight = 0;
        color = " ";
        cost = 0;
        VIN = 0;
        allCarsCount++;
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
        VIN = 0;
        cost = _cost;
        allCarsCount++;
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
        cout << "VIN: " << VIN << endl;
        cout << color << endl;
        cout << cost << endl;
    }

    void changeColor() {
        cout << "Enter a new color: ";   cin >> color;
    }

    int getCost() {
        return cost;
    }

    static int get_VIN_number() {
        return number;
    }

     static int getCarsCount() {
         return allCarsCount;
     }

    void set_VIN() {
        string num = to_string(number);
        num.append(to_string(allCarsCount));
        VIN = stoi(num);
    }

};

class Autoshow {
private:
    Car car;
    int count;

public:
    void init() {
        car.init();
        count = 1;
    }

    void init(Car _car, int _count) {
        car = _car;
        count = _count;
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
};

int Car::allCarsCount = 0;

int main() {
    setlocale(LC_ALL, "rus");

    cout << Car::getCarsCount() << endl; 
    Car car1, car2;
    car1.init("Ford", "F-150", 2013, 400, 3000, "black", 3000000);
    car1.set_VIN();
    car2.init("Mazda", "3", 2005, 120, 1300, "red", 300000);
    car2.set_VIN();
    car1.display();
    car2.display();

    return 0;
}
