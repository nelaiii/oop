// #include <iostream>
// #include <string>
// #include <vector>
// #include <windows.h>
// //Задача: создать класс Student с хранением информации об оценках в объекте, предусмотреть методы для объявления оценок и их просмотра
//
// using namespace std;
// class Student {
//     string name;
//     int age;
//     string group;
//     int course;
//     vector<int> grades;
//     // name обязателен, остальные поля - со значениями по умолчанию, чтобы можно было создать студента, зная только имя
//     // выбран список инициализации (: name(name), ...) как правильный способ заполнить поля сразу при создании объекта
//     public:
//         Student(string name, int age = 0, string group = "", int course = 1)
//             : name(name), age(age), group(group), course(course) {}
//         void addGrade(int grade) {
//             grades.push_back(grade);
//         }
//         void showGrades() {
//             cout << "Оценки студента: " << name << ": ";
//             for (int i = 0; i < grades.size(); i++) {
//                 cout << grades[i] << " ";
//             }
//             cout << endl;
//         }
//         void showInfo() {
//                 cout << "Имя: " << name << endl;
//                 cout << "Возраст: " << age << endl;
//                 cout << "Группа: " << group << endl;
//                 cout << "Курс: " << course << endl;
//             }
// };
//
//
// int main() {
//     SetConsoleOutputCP(CP_UTF8);
//     Student student("Наталья", 21, "ИВТ02", 4);
//     student.addGrade(5);
//     student.addGrade(4);
//     student.addGrade(5);
//
//     student.showInfo();
//     student.showGrades();
//
//     Student student2("Лизик");
//     student2.addGrade(4);
//     student2.addGrade(5);
//     student2.showGrades();
// }
