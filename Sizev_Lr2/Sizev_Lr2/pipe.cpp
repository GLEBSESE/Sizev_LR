#include "pipe.h"

void Pipes::add() {
    mypipe pipe;
    cout << "������� �������� �����: ";
    INPUT_LINE(cin, pipe._name);
    cout << "������� ������� ����� (�����): ";
    pipe._length = GetCorrectNumber(0, 100000);
    cout << "������� ������� ����� (������): ";
    pipe._width = GetCorrectNumber(0, 100000);
    cout << "������� �������� �� �����(1 - ��������, 0 - � �������): ";
    pipe._properties = GetCorrectNumber(0, 1);
    _pipe[size_pipe++] = pipe;
}
void Pipes::View() const {
    if (_pipe.empty()) {
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        for (const auto& [i, pipe] : _pipe) {
            cout << "����� �����: " << i << " ��������: " << pipe._name << ", �����: " << pipe._length << " ������: " << pipe._width << " �������� �� ����� (1 - ��������, 0 - � �������): " << pipe._properties << endl;
        }
    }
}
void Pipes::Edit() {
    if (_pipe.empty()) {
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        cout << "������� ����� (0 - ���������������, 1 - ������� �����)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "������� ����� �����, ������� ����� ��������������� (�� 0 �� " << size_pipe << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "������� �������� �� �����(1 - ��������, 0 - � �������)" << endl;
            _pipe.at(i)._properties = GetCorrectNumber(0, 1);
        }
        else {
            cout << "������� ����� (0 - ������� ��� �����, 1 - ������� ���������� �����)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _pipe.clear();
                cout << "��� ����� �������!!!" << endl;
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "������ ������� �����? (0 - ���, 1 - �� )" << endl;
                    bool pipe_cheak = GetCorrectNumber(0, 1);
                    if (pipe_cheak && size_pipe != 0) {
                        cout << "������� ����� �����, ������� ������ ������� (������ ��������: ";
                        for (auto it = _pipe.begin(); it != _pipe.end(); ++it) {
                            std::cout << it->first << " "; 
                        }
                        cout << ")" << endl;
                        int number_del = GetCorrectNumber(0, size_pipe - 1);
                        _pipe.erase(number_del);
                        size_pipe--;
                    }
                    else {
                        cout << "����� �������!!!" << endl;
                        d = 0;
                    }
                }
            }
        }
    }
}
void Pipes::output_file() const {
    if (_pipe.empty()) {
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        ofstream out;
        out.open("data_pipes_ks.txt");
        for (const auto& [i, pipe] : _pipe) {
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
    if (_pipe.empty()) {
        cout << "����� �� �������, �������� �����" << endl;
    }
    else {
        cout << "������� ����� (���������� �� 0 - ��������, 1 - �� �������� � �������" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        vector<pair<int, mypipe>>sort_pipes(_pipe.begin(), _pipe.end());
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
