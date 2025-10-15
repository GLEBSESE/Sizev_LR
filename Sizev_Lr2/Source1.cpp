#include "Sizev_Lr2.h"



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
        cout << _Pipes.size() << endl;
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
        cout << "������� ����� �����, ������� ����� ���������������" << endl;
        int i = GetCorrectNumber(0, 1000);
        cout << "������� �������� �� �����(1 - ��������, 0 - � �������)" << endl;
        _Pipes.at(i)._properties = GetCorrectNumber(0, 1);
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
    _Ks[_size] = ks;
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
void KS::Edit() {
    if (_Ks.empty()) {
        cout << "�� �� ������, �������� ��" << endl;
    }
    else {
        cout << "������� ����� ��, ������� ����� ���������������" << endl;
        int i = GetCorrectNumber(0, 1000);
        cout << "������� ������ ��(1 - ���������, 0 - ���������)" << endl;
        _Ks.at(i)._station_class = GetCorrectNumber(1, 0);
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