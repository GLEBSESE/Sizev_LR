#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Pipes {
public:
    void add() {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Введите название трубы: ";
        getline(cin, _name);
        cout << "Введите размеры трубы (сначала длину, потом ширину): ";
        cin >> _length >> _width;
        cout << "Введите работает ли труба(1 - работает, 0 - в ремонте): ";
        cin >> _properties;
    }
    void View() {
        if (_name.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            cout << "Название: " << _name << ", длина: " << _length << " ширина: " << _width << " работает ли труба (1 - работает, 0 - в ремонте): " << _properties << endl;
        }
    }
    void Edit() {
        if (_name.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            cout << "Введите работает ли труба(1 - работает, 2 - в ремонте)" << endl;
            cin >> _properties;
        }
    }
    void output_file() {
        if (_name.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            ofstream out;
            out.open("data_pipes_ks.txt");
            out << "Название: " << _name << ", длина: " << _length << " ширина: " << _width << " работает ли труба (1 - работает, 0 - в ремонте): " << _properties << endl;
            out.close();
        }
    }
    void input_file() {
        ifstream in;
        in.open("data_pipes_ks.txt");
        string line;
        while (getline(in, line)) {
            cout << line << " ";
        }
        cout << endl;
        in.close();
    }
private:
    string _name;
    int _length;
    int _width;
    bool _properties;
};

class KS {
public:
    void add() {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Введите название КС: ";
        getline(cin, _name);
        cout << "Введите количество цехов, потом количество цехов в работе: ";
        cin >> _quantity >> _count_work;
        cout << "Введите запуск КС(1 - запустить, 0 - остановка): ";
        cin >> _station_class;
    }
    void View() {
        if (_name.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            cout << "Название: " << _name << ", количество цехов: " << _quantity << " количество цехов в работе: " << _count_work << " класс станции: " << _station_class << endl;
        }
    }
    void Edit() {
        if (_name.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            cout << "Введите запуск КС(1 - запустить, 0 - остановка)" << endl;
            cin >> _station_class;
        }
    }
    void output_file() {
        if (_name.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            ofstream out("data_pipes_ks.txt", ios::app);
            out << "Название: " << _name << ", количество цехов: " << _quantity << " количество цехов в работе: " << _count_work << " класс станции: " << _station_class << '\n';
            out.close();
        }
    }
private:
    string _name;
    int _quantity;
    int _count_work;
    bool _station_class;
};


int main()
{
    setlocale(LC_ALL, "");
    Pipes pipe_;
    KS KS_;
    while (true) {
        cout << "1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Редактировать трубу 5. Редактировать КС 6. Сохранить 7. Загрузить 0. Выход" << endl;
        int menu_result;
        cin >> menu_result;
        switch (menu_result) {
        case 0:
            cout << "Вы закончили цикл" << endl;
            exit(0);
        case 1:
            pipe_.add();
            break;
        case 2:
            KS_.add();
            break;
        case 3:
            pipe_.View();
            KS_.View();
            break;
        case 4:
            pipe_.Edit();
            break;
        case 5:
            KS_.Edit();
            break;
        case 6:
            pipe_.output_file();
            KS_.output_file();
            break;
        case 7:
            pipe_.input_file();
            break;
        default:
            cout << "Нет подходящего номера в меню" << endl;
            break;
        }
    }
}