#include "Sizev_Pipe_KS.h"



void Pipes::add() {
    MyPipe pipe;
    cout << "������� �������� �����: ";
    INPUT_LINE(cin, pipe._name);
    cout << "������� ������� ����� (�����): ";
    pipe._length = GetCorrectNumber(0, 100000);
    cout << "������� ������� ����� (������): ";
    pipe._width = GetCorrectNumber(0, 100000);
    cout << "������� �������� �� �����(1 - ��������, 0 - � �������): ";
    pipe._properties = GetCorrectNumber(0, 1);
    _Pipes[_size++] = pipe;
}
void Pipes::View() const {
    if (_Pipes.empty()) {
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        for (const auto& [i, pipe] : _Pipes) {
            cout << "����� �����: " << i << " ��������: " << pipe._name << ", �����: " << pipe._length << " ������: " << pipe._width << " �������� �� ����� (1 - ��������, 0 - � �������): " << pipe._properties << endl;
        }
    }
}
void Pipes::Edit() {
    if (_Pipes.empty()) {
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        cout << "������� ����� (0 - ���������������, 1 - ������� �����)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "������� ����� �����, ������� ����� ��������������� (�� 0 �� "<< _size << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "������� �������� �� �����(1 - ��������, 0 - � �������)" << endl;
            _Pipes.at(i)._properties = GetCorrectNumber(0, 1);
        }
        else {
            cout << "������� ����� (0 - ������� ��� �����, 1 - ������� ���������� �����)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _Pipes.clear();
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "������ ������� �����? (0 - ���, 1 - �� )" << endl;
                    bool pipe_cheak = GetCorrectNumber(0, 1);
                    if (pipe_cheak && _size != 0) {
                        cout << "������� ����� �����, ������� ������ ������� ( �� 0 �� " << _size - 1 << " )" << endl;
                        int number_del = GetCorrectNumber(0, _size - 1);
                        _Pipes.erase(number_del);
                        _size--;
                    }
                    else {
                        cout << "��� ����� �������!!!" << endl;
                        d = 0;
                    }
                }
            }
        }
    }
}
void Pipes::output_file() const {
    if (_Pipes.empty()) {
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        ofstream out;
        out.open("data_pipes_ks.txt");
        for (const auto& [i, pipe] : _Pipes) {
            out << "����� �����: " << i << " ��������: " << pipe._name << " �����: " << pipe._length << " ������: " << pipe._width << " �������� �� ����� (1 - ��������, 0 - � �������): " << pipe._properties << endl;
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
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        cout << "������� ����� (���������� �� 0 - ��������, 1 - �� �������� � �������" << endl;
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
                cout << "����� �����: " << i << " ��������: " << pipe._name << " �����: " << pipe._length << " ������: " << pipe._width << " �������� �� ����� (1 - ��������, 0 - � �������): " << pipe._properties << endl;
        }
    }
}



void KS::add() {
    MyKs ks;
    cout << "������� �������� ��: ";
    INPUT_LINE(cin, ks._name);
    cout << "������� ���������� �����: ";
    ks._quantity = GetCorrectNumber(0, 100000);
    cout << "������� ���������� ����� � ������: ";
    ks._count_work = GetCorrectNumber(0, 100000);
    cout << "������� ������ ��(1 - ���������, 0 - ���������): ";
    ks._station_class = GetCorrectNumber(0, 1);
    _Ks[_size++] = ks;
}
void KS::View() const {
    if (_Ks.empty()) {
        cout << "�� �� ������, �������� ��" << endl;
    }
    else {
        for (const auto& [i, ks] : _Ks) {
            cout << "����� ��: " << i << " ��������: " << ks._name << ", ���������� �����: " << ks._quantity << " ���������� ����� � ������: " << ks._count_work << " ����� �������: " << ks._station_class << endl;
        }
    }
}
void KS::View_Filter() const {
    if (_Ks.empty()) {
        cout << "�� �� �������, �������� ��" << endl;
    }
    else {
        cout << "������� ����� (���������� �� 0 - ��������, 1 - �� �������� ����������������� �����)" << endl;
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
            cout << "����� ��: " << i << " ��������: " << ks._name << ", ���������� �����: " << ks._quantity << " ���������� ����� � ������: " << ks._count_work << " ����� �������: " << ks._station_class << endl;
        }
    }
}
void KS::Edit() {
    if (_Ks.empty()) {
        cout << "�� �� ������, �������� ��" << endl;
    }
    else {
        cout << "������� ����� (0 - ���������������, 1 - ������� ��)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "������� ����� ��, ������� ����� ��������������� (�� 0 �� " << _size << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "������� �������� �� ��(1 - ��������, 0 - � �������)" << endl;
            _Ks.at(i)._station_class = GetCorrectNumber(0, 1);
        }
        else {
            cout << "������� ����� (0 - ������� ��� ��, 1 - ������� ���������� ��)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _Ks.clear();
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "������ ������� ��? (0 - ���, 1 - �� )" << endl;
                    bool ks_cheak = GetCorrectNumber(0, 1);
                    if (ks_cheak && _size != 0) {
                        cout << "������� ����� ��, ������� ������ ������� ( �� 0 �� " << _size - 1 << " )" << endl;
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
        cout << "�� �� ������, �������� ��" << endl;
    }
    else {
        ofstream out("data_pipes_ks.txt", ios::app);
        for (const auto& [i, ks] : _Ks) {
            cout << "����� ��: " << i << " ��������: " << ks._name << ", ���������� �����: " << ks._quantity << " ���������� ����� � ������: " << ks._count_work << " ����� �������: " << ks._station_class << endl;
        }
        out.close();
    }
}