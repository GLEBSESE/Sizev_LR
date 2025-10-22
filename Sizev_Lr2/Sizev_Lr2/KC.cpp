#include "KC.h"


void KC::add() {
    MyKC ks;
    cout << "Введите название КС: ";
    INPUT_LINE(cin, ks._name);
    cout << "Введите количество цехов: ";
    ks._quantity = GetCorrectNumber(0, 100000);
    cout << "Введите количество цехов в работе: ";
    ks._count_work = GetCorrectNumber(0, 100000);
    cout << "Введите запуск КС(1 - запустить, 0 - остановка): ";
    ks._station_class = GetCorrectNumber(0, 1);
    _KC[size_KC++] = ks;
}
void KC::View() const {
    if (_KC.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        for (const auto& [i, kc] : _KC) {
            cout << "Номер КС: " << i << " Название: " << kc._name << ", количество цехов: " << kc._quantity << " количество цехов в работе: " << kc._count_work << " класс станции: " << kc._station_class << endl;
        }
    }
}
void KC::View_Filter() const {
    if (_KC.empty()) {
        cout << "КС не найдены, добавьте КС" << endl;
    }
    else {
        cout << "Введите число (филтровать по 0 - названию, 1 - по проценту незадействованных цехов)" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        vector<pair<int, MyKC>>sort_KC(_KC.begin(), _KC.end());
        if (!cheak) {
            sort(sort_KC.begin(), sort_KC.end(),
                [](const auto& a, const auto& b) {
                    return a.second._name < b.second._name;
                });
        }
        else {
            sort(sort_KC.begin(), sort_KC.end(),
                [](const auto& a, const auto& b) {
                    double inactiveA = (static_cast<double>(a.second._quantity - a.second._count_work) / a.second._quantity) * 100.0;
                    double inactiveB = (static_cast<double>(b.second._quantity - b.second._count_work) / b.second._quantity) * 100.0;
                    return inactiveA > inactiveB;
                });
        }
        for (const auto& [i, kc] : sort_KC) {
            cout << "Номер КС: " << i << " Название: " << kc._name << ", количество цехов: " << kc._quantity << " количество цехов в работе: " << kc._count_work << " класс станции: " << kc._station_class << endl;
        }
    }
}
void KC::Edit() {
    if (_KC.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        cout << "Введите число (0 - Отредактировать, 1 - Удалить КС)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "Введите номер КС, которую нужно отредактировать (от 0 до " << size_KC-1 << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "Введите работает ли КС(1 - работает, 0 - в ремонте)" << endl;
            _KC.at(i)._station_class = GetCorrectNumber(0, 1);
        }
        else {
            cout << "Введите число (0 - удалить все КС, 1 - удалить конкретную КС)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _KC.clear();
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "Хотите удалить КС? (0 - нет, 1 - да )" << endl;
                    bool ks_cheak = GetCorrectNumber(0, 1);
                    if (ks_cheak && size_KC != 0) {
                        cout << "введите номер КС, которую хотите удалить (Номера доступны: ";
                        for (auto it = _KC.begin(); it != _KC.end(); ++it) {
                            std::cout << it->first << " ";
                        }
                        cout << ")" << endl;
                        int number_del = GetCorrectNumber(0, size_KC - 1);
                        _KC.erase(number_del);
                        size_KC--;
                    }
                    else {
                        d = 0;
                    }
                }
            }
        }

    }
}
void KC::output_file() const {
    if (_KC.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        ofstream out("data_pipes_ks.txt", ios::app);
        for (const auto& [i, kc] : _KC) {
            cout << "Номер КС: " << i << " Название: " << kc._name << ", количество цехов: " << kc._quantity << " количество цехов в работе: " << kc._count_work << " класс станции: " << kc._station_class << endl;
        }
        out.close();
    }
}