#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Pipes {
public:
    void add() {
        string name, properties;
        double length, width;
        cin >> name >> length >> width >> properties;
        name_ = name;
        properties_ = properties;
        length_ = length;
        width_ = width;
    }
    void View() {
        if (name_.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            cout << "Название: " << name_ << ", длина: " << length_ << " ширина: " << width_ << " признак: " << properties_ << endl;
        }
    }
    void Edit() {
        if (name_.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            string properties;
            cin >> properties;
            properties_ = properties;
        }
    }
    void input_file() {
        if (name_.empty()) {
            cout << "Труба не найдена, добавьте трубу" << endl;
        }
        else {
            ofstream in;
            in.open("data_pipes_ks.txt");
            in << name_ << length_ << width_ << properties_ << '\n';
            in.close();
        }
    }
    void output_file() {
        ifstream out;
        out.open("data_pipes_ks.txt");
        string line;
        while (getline(out, line)) {
            cout << line << " ";
        }
        out.close();
    }
private:
    string name_;
    double length_;
    double width_;
    string properties_;
};

class KS {
public:
    void add() {
        string name, station_class;
        int quantity, count_work;
        cin >> name >> quantity >> count_work >> station_class;
        name_ = name;
        quantity_ = quantity;
        count_work_ = count_work;
        station_class_ = station_class;
    }
    void View() {
        if (name_.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            cout << "Название: " << name_ << ", количество цехов: " << quantity_ << " количество цехов в работе: " << count_work_ << " класс станции: " << station_class_ << endl;
        }
    }
    void Edit() {
        if (name_.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            string station_class;
            cin >> station_class;
            station_class_ = station_class;
        }
    }
    void input_file() {
        if (name_.empty()) {
            cout << "КС не найден, добавьте КС" << endl;
        }
        else {
            ofstream in;
            in.open("data_pipes_ks.txt");
            in << "Название: " << name_ << ", количество цехов: " << quantity_ << " количество цехов в работе: " << count_work_ << " класс станции: " << station_class_ << '\n';
            in.close();
        }
    }
    void output_file() {
        ifstream out;
        out.open("data_pipes_ks.txt");
        string line;
        while (getline(out, line)) {
            cout << line << " ";
        }
        out.close();
    }
private:
    string name_;
    int quantity_;
    int count_work_;
    string station_class_;
};

int main()
{
    setlocale(LC_ALL, "");
    int count_menu = 1;
    Pipes pipe_;
    KS KS_;
    while (count_menu == 1) {
        cout << "1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Редактировать трубу 5. Редактировать КС 6. Сохранить 7. Загрузить 0. Выход" << endl;
        int menu_result;
        cin >> menu_result;
        switch (menu_result) {
        case 0:
            cout << "Вы закончили цикл" << endl;
            count_menu = 0;
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
            pipe_.input_file();
            KS_.input_file();
            break;
        case 7:
            pipe_.output_file();
            KS_.output_file();
            break;
        default:
            cout << "Нет подходящего номера в меню" << endl;
            break;
        }
    }
}