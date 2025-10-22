#include "KC.h"


void KC::add() {
    MyKC ks;
    cout << "������� �������� ��: ";
    INPUT_LINE(cin, ks._name);
    cout << "������� ���������� �����: ";
    ks._quantity = GetCorrectNumber(0, 100000);
    cout << "������� ���������� ����� � ������: ";
    ks._count_work = GetCorrectNumber(0, 100000);
    cout << "������� ������ ��(1 - ���������, 0 - ���������): ";
    ks._station_class = GetCorrectNumber(0, 1);
    _KC[size_KC++] = ks;
}
void KC::View() const {
    if (_KC.empty()) {
        cout << "�� �� ������, �������� ��" << endl;
    }
    else {
        for (const auto& [i, kc] : _KC) {
            cout << "����� ��: " << i << " ��������: " << kc._name << ", ���������� �����: " << kc._quantity << " ���������� ����� � ������: " << kc._count_work << " ����� �������: " << kc._station_class << endl;
        }
    }
}
void KC::View_Filter() const {
    if (_KC.empty()) {
        cout << "�� �� �������, �������� ��" << endl;
    }
    else {
        cout << "������� ����� (���������� �� 0 - ��������, 1 - �� �������� ����������������� �����)" << endl;
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
            cout << "����� ��: " << i << " ��������: " << kc._name << ", ���������� �����: " << kc._quantity << " ���������� ����� � ������: " << kc._count_work << " ����� �������: " << kc._station_class << endl;
        }
    }
}
void KC::Edit() {
    if (_KC.empty()) {
        cout << "�� �� ������, �������� ��" << endl;
    }
    else {
        cout << "������� ����� (0 - ���������������, 1 - ������� ��)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "������� ����� ��, ������� ����� ��������������� (�� 0 �� " << size_KC-1 << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "������� �������� �� ��(1 - ��������, 0 - � �������)" << endl;
            _KC.at(i)._station_class = GetCorrectNumber(0, 1);
        }
        else {
            cout << "������� ����� (0 - ������� ��� ��, 1 - ������� ���������� ��)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _KC.clear();
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "������ ������� ��? (0 - ���, 1 - �� )" << endl;
                    bool ks_cheak = GetCorrectNumber(0, 1);
                    if (ks_cheak && size_KC != 0) {
                        cout << "������� ����� ��, ������� ������ ������� (������ ��������: ";
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
        cout << "�� �� ������, �������� ��" << endl;
    }
    else {
        ofstream out("data_pipes_ks.txt", ios::app);
        for (const auto& [i, kc] : _KC) {
            cout << "����� ��: " << i << " ��������: " << kc._name << ", ���������� �����: " << kc._quantity << " ���������� ����� � ������: " << kc._count_work << " ����� �������: " << kc._station_class << endl;
        }
        out.close();
    }
}