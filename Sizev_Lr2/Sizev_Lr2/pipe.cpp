#include "pipe.h"

void Pipes::add() {
    mypipe pipe;
    cout << "введите название трубы: ";
    INPUT_LINE(cin, pipe._name);
    cout << "введите размеры трубы (длину): ";
    pipe._length = GetCorrectNumber(0, 100000);
    cout << "введите размеры трубы (ширину): ";
    pipe._width = GetCorrectNumber(0, 100000);
    cout << "введите работает ли труба(1 - работает, 0 - в ремонте): ";
    pipe._properties = GetCorrectNumber(0, 1);
    _pipe[size_pipe++] = pipe;
}
void Pipes::View() const {
    if (_pipe.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        for (const auto& [i, pipe] : _pipe) {
            cout << "номер трубы: " << i << " название: " << pipe._name << ", длина: " << pipe._length << " ширина: " << pipe._width << " работает ли труба (1 - работает, 0 - в ремонте): " << pipe._properties << endl;
        }
    }
}
void Pipes::Edit() {
    if (_pipe.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "введите число (0 - отредактировать, 1 - удалить трубы)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "введите номер трубы, которую нужно отредактировать (от 0 до " << size_pipe << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "введите работает ли труба(1 - работает, 0 - в ремонте)" << endl;
            _pipe.at(i)._properties = GetCorrectNumber(0, 1);
        }
        else {
            cout << "введите число (0 - удалить все трубы, 1 - удалить конкретную трубу)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                _pipe.clear();
                cout << "Все трубы удалены!!!" << endl;
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "хотите удалить трубу? (0 - нет, 1 - да )" << endl;
                    bool pipe_cheak = GetCorrectNumber(0, 1);
                    if (pipe_cheak && size_pipe != 0) {
                        cout << "введите номер трубы, которую хотите удалить (Номера доступны: ";
                        for (auto it = _pipe.begin(); it != _pipe.end(); ++it) {
                            std::cout << it->first << " "; 
                        }
                        cout << ")" << endl;
                        int number_del = GetCorrectNumber(0, size_pipe - 1);
                        _pipe.erase(number_del);
                        size_pipe--;
                    }
                    else {
                        cout << "трубы удалены!!!" << endl;
                        d = 0;
                    }
                }
            }
        }
    }
}
void Pipes::output_file() const {
    if (_pipe.empty()) {
        cout << "труба не найдена, добавьте трубу" << endl;
    }
    else {
        ofstream out;
        out.open("data_pipes_ks.txt");
        for (const auto& [i, pipe] : _pipe) {
            out << "номер трубы: " << i << " название: " << pipe._name << " длина: " << pipe._length << " ширина: " << pipe._width << " работает ли труба (1 - работает, 0 - в ремонте): " << pipe._properties << endl;
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
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "введите число (филтровать по 0 - названию, 1 - по признаку в ремонте" << endl;
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
            cout << "номер трубы: " << i << " название: " << pipe._name << " длина: " << pipe._length << " ширина: " << pipe._width << " работает ли труба (1 - работает, 0 - в ремонте): " << pipe._properties << endl;
        }
    }
}
