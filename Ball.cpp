#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Box;

class Ball {
public:
    string color;
    double radius;
    Box* box; // указатель - адрес коробки

    Ball(string c, double r) {
        color = c;
        radius = r;
        box = nullptr; //изначально нигде
    }

    double getVolume() {
        return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
    }

    bool isInBox() {
        return box != nullptr;
    }

    string whereAmI();
};

class Box {
public:
    string name;
    double length, width, height;
    vector<Ball*> balls; // храним адреса шариков

    Box(string n, double l, double w, double h) {
        name = n;
        length = l;
        width = w;
        height = h;
    }

    double getVolume() {
        return length * width * height;
    }

    double getBallsVolume() {
        double sum = 0;
        for (int i = 0; i < balls.size(); i++) {
            sum += balls[i]->getVolume();
        }
        return sum;
    }

    void putBall(Ball* ball) {
        double afterAdd = getBallsVolume() + ball->getVolume();
        if (afterAdd > getVolume()) {
            cout << "Шарик \"" << ball->color
                 << "\" не влезает в коробку \"" << name << "\"!" << endl;
            return;
        }
        balls.push_back(ball); // кладем указатель в вектор
        ball->box = this; // this = адрес этой коробки
    }

    void removeBall(Ball* ball) {
        for (int i = 0; i < balls.size(); i++) {
            if (balls[i] == ball) {
                balls.erase(balls.begin() + i);
                ball->box = nullptr;
                cout << "Шарик \"" << ball->color
                     << "\" убран из коробки \"" << name << "\"" << endl;
                return;
            }
        }
        cout << "Шарик \"" << ball->color
             << "\" не лежит в коробке \"" << name << "\"" << endl;
    }

    void showBalls() {
        cout << name << " содержит: ";
        if (balls.empty()) {
            cout << "пусто";
        } else {
            for (int i = 0; i < balls.size(); i++) {
                cout << balls[i]->color << " ";
            }
        }
        cout << "(занято " << getBallsVolume()
             << " из " << getVolume() << ")" << endl;
    }
};

string Ball::whereAmI() {
    if (!isInBox()) {
        return "ни в какой коробке";
    }
    return "в коробке \"" + box->name + "\"";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Ball red("красный", 3);
    Ball green("зеленый", 3);
    Ball blue("синий", 2);
    Ball yellow("желтый", 2);

    Box box1("Коробка №1", 10, 10, 10);
    box1.showBalls();

    box1.putBall(&red);
    box1.putBall(&green);
    box1.putBall(&blue);
    box1.putBall(&yellow);
    box1.showBalls();

    cout << "\nУбираем зелёный шарик" << endl;
    box1.removeBall(&green);
    box1.showBalls();
    cout << "Зеленый шарик теперь: " << green.whereAmI() << endl;

    cout << "\nПробуем убрать шарик, которого там нет" << endl;
    Ball black("черный", 2);
    box1.removeBall(&black);
    box1.showBalls();

    return 0;
}