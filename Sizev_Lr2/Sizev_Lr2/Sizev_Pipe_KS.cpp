#include "Sizev_Pipe_KS.h"



void Pipes::add() {
    MyPipe pipe;
    cout << "Введите название трубы: ";
    INPUT_LINE(cin, pipe._name);
    cout << "Введите размеры трубы (длину): ";
    pipe._length = GetCorrectNumber(0, 100000);
    cout << "Введите размеры трубы (ширину): ";
    pipe._width = GetCorrectNumber(0, 100000);
    cout << "Введите работает ли труба(1 - работает, 0 - в ремонте): ";
    pipe._properties = GetCorrectNumber(0, 1);
    _Pipes[_size++] = pipe;
}
void Pipes::View() const {
    if (_Pipes.empty()) {
        cout << "Трубы не найдены, добавьте трубу" << endl;
    }
    else {
        for (const auto& [i, pipe] : _Pipes) {
            cout << "Номер трубы: " << i << " Название: " << pipe._name << ", длина: " << pipe._length << " ширина: " << pipe._width << " работает ли труба (1 - работает, 0 - в ремонте): " << pipe._properties << endl;
        }
    }
}
void Pipes::Edit() {
    if (_Pipes.empty()) {
        cout << "Трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "Введите число (0 - Отредактировать, 1 - Удалить трубы)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "Введите номер трубы, которую нужно отредактировать (от 0 до "<< _size << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "Введите работает ли труба(1 - работает, 0 - в ремонте)" << endl;
            _Pipes.at(i)._properties = GetCorrectNumber(0, 1);
        }
        else {
            cout << "Введите число (0 - удалить все трубы, 1 - удалить конкретную трубу)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _Pipes.clear();
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "Хотите удалить трубу? (0 - нет, 1 - да )" << endl;
                    bool pipe_cheak = GetCorrectNumber(0, 1);
                    if (pipe_cheak && _size != 0) {
                        cout << "Введите номер трубы, которую хотите удалить ( от 0 до " << _size - 1 << " )" << endl;
                        int number_del = GetCorrectNumber(0, _size - 1);
                        _Pipes.erase(number_del);
                        _size--;
                    }
                    else {
                        cout << "Все трубы удалены!!!" << endl;
                        d = 0;
                    }
                }
            }
        }
    }
}
void Pipes::output_file() const {
    if (_Pipes.empty()) {
        cout << "Труба не найдена, добавьте трубу" << endl;
    }
    else {
        ofstream out;
        out.open("data_pipes_ks.txt");
        for (const auto& [i, pipe] : _Pipes) {
            out << "Номер трубы: " << i << " Название: " << pipe._name << " длина: " << pipe._length << " ширина: " << pipe._width << " работает ли труба (1 - работает, 0 - в ремонте): " << pipe._properties << endl;
        }
        out.close();
    }
}
void Pipes::input_file() const {
    ifstream in;
    in.open("data_pipes_ks.txt");
    string line;
    while (getline(in, line)) {
        cout << line << " ";
    }
    cout << endl;
    in.close();
}
void Pipes::View_Filter() const {
    if (_Pipes.empty()) {
        cout << "Трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "Введите число (филтровать по 0 - названию, 1 - по признаку в ремонте" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        vector<pair<int, MyPipe>>sort_pipes(_Pipes.begin(), _Pipes.end());
        if (cheak) {
            sort(sort_pipes.begin(), sort_pipes.end(),
                [](const auto& a, const auto& b) {
                    return a.second._properties > b.second._properties;
                });
        }
        else {
            sort(sort_pipes.begin(), sort_pipes.end(),
                [](const auto& a, const auto& b) {
                    return a.second._name < b.second._name;
                });
        }
        for (const auto& [i, pipe] : sort_pipes) {
                cout << "Номер трубы: " << i << " Название: " << pipe._name << " длина: " << pipe._length << " ширина: " << pipe._width << " работает ли труба (1 - работает, 0 - в ремонте): " << pipe._properties << endl;
        }
    }
}



void KS::add() {
    MyKs ks;
    cout << "Введите название КС: ";
    INPUT_LINE(cin, ks._name);
    cout << "Введите количество цехов: ";
    ks._quantity = GetCorrectNumber(0, 100000);
    cout << "Введите количество цехов в работе: ";
    ks._count_work = GetCorrectNumber(0, 100000);
    cout << "Введите запуск КС(1 - запустить, 0 - остановка): ";
    ks._station_class = GetCorrectNumber(0, 1);
    _Ks[_size++] = ks;
}
void KS::View() const {
    if (_Ks.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        for (const auto& [i, ks] : _Ks) {
            cout << "Номер КС: " << i << " Название: " << ks._name << ", количество цехов: " << ks._quantity << " количество цехов в работе: " << ks._count_work << " класс станции: " << ks._station_class << endl;
        }
    }
}
void KS::View_Filter() const {
    if (_Ks.empty()) {
        cout << "КС не найдены, добавьте КС" << endl;
    }
    else {
        cout << "Введите число (филтровать по 0 - названию, 1 - по проценту незадействованных цехов)" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        vector<pair<int, MyKs>>sort_KS(_Ks.begin(), _Ks.end());
        if (!cheak) {
            sort(sort_KS.begin(), sort_KS.end(),
                [](const auto& a, const auto& b) {
                    return a.second._name < b.second._name;
                });
        }
        else {
            sort(sort_KS.begin(), sort_KS.end(),
                [](const auto& a, const auto& b) {
                    double inactiveA = (static_cast<double>(a.second._quantity - a.second._count_work) / a.second._quantity) * 100.0;
                    double inactiveB = (static_cast<double>(b.second._quantity - b.second._count_work) / b.second._quantity) * 100.0;
                    return inactiveA > inactiveB;
                });
        }
        for (const auto& [i, ks] : sort_KS) {
            cout << "Номер КС: " << i << " Название: " << ks._name << ", количество цехов: " << ks._quantity << " количество цехов в работе: " << ks._count_work << " класс станции: " << ks._station_class << endl;
        }
    }
}
void KS::Edit() {
    if (_Ks.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        cout << "Введите число (0 - Отредактировать, 1 - Удалить КС)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "Введите номер КС, которую нужно отредактировать (от 0 до " << _size << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "Введите работает ли КС(1 - работает, 0 - в ремонте)" << endl;
            _Ks.at(i)._station_class = GetCorrectNumber(0, 1);
        }
        else {
            cout << "Введите число (0 - удалить все КС, 1 - удалить конкретную КС)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _Ks.clear();
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "Хотите удалить КС? (0 - нет, 1 - да )" << endl;
                    bool ks_cheak = GetCorrectNumber(0, 1);
                    if (ks_cheak && _size != 0) {
                        cout << "Введите номер КС, которую хотите удалить ( от 0 до " << _size - 1 << " )" << endl;
                        int number_del = GetCorrectNumber(0, _size - 1);
                        _Ks.erase(number_del);
                        _size--;
                    }
                    else {
                        d = 0;
                    }
                }
            }
        }

    }
}
void KS::output_file() const {
    if (_Ks.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        ofstream out("data_pipes_ks.txt", ios::app);
        for (const auto& [i, ks] : _Ks) {
            cout << "Номер КС: " << i << " Название: " << ks._name << ", количество цехов: " << ks._quantity << " количество цехов в работе: " << ks._count_work << " класс станции: " << ks._station_class << endl;
        }
        out.close();
    }
}