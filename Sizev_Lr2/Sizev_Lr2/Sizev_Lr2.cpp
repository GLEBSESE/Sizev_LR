#include "KC.h"
#include <chrono>
#include <format>
#include <string>

using namespace std;
using namespace chrono;

int size_kc = 0;
int size_pipe = 0;

void FilterPipe(map<int,Pipes> pipes) {
    if (pipes.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "введите число (филтровать по 0 - названию, 1 - по признаку в ремонте)" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        if (cheak) {
            cout << "введите число (0 - в ремонте, 1 - работает)" << endl;
            bool properities = GetCorrectNumber(0, 1);
            for (int i = 0; i < size_pipe; i++) {
                if (pipes.at(i).CheakByProperities(properities)) {
                    cout << "Номер трубы: " << i;
                    pipes.at(i).View();
                }
            }
        }
        else {
            cout << "введите имя трубы: " << endl;
            string name;
            INPUT_LINE(cin, name);
            for (int i = 0; i < size_pipe; i++){
                if (pipes.at(i).CheakByName(name)) {
                    cout << "Номер трубы: " << i;
                    pipes.at(i).View();
                }
            }

        }
    }

}
void FilterKC(map<int, KC>& kc) {
    if (kc.empty()) {
        cout << "кс не найдены, добавьте кс" << endl;
    }
    else {
        cout << "введите число (филтровать по 0 - названию, 1 - по  проценту незадействованных цехов)" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        if (cheak) {
            cout << "Введите процент незадействованных цехов: " << endl;
            int Idle = GetCorrectNumber(0, 100);
            for (int i = 0; i < size_kc; i++) {
                if (kc.at(i).IdleWorkshops() < Idle) {
                    cout << "Номер кс: " << i;
                    kc.at(i).View();
                }
            }

        }
        else {
            cout << "Введите имя трубы: " << endl;
            string name;
            INPUT_LINE(cin, name);
            for (int i = 0; i < size_pipe; i++) {
                if (kc.at(i).CheakByName(name)) {
                    cout << "Номер трубы: " << i;
                    kc.at(i).View();
                }
            }

        }
    }

}
void EditPipe(map<int, Pipes>& pipe) {
    if (pipe.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "введите число (0 - отредактировать, 1 - удалить трубы)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "введите номер трубы, которую нужно отредактировать (от 0 до " << size_pipe << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "введите работает ли труба(1 - работает, 0 - в ремонте)" << endl;
            pipe.at(i).Edit();
        }
        else {
            cout << "введите число (0 - удалить все трубы, 1 - удалить конкретную трубу)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                pipe.clear();
                cout << "все трубы удалены!!!" << endl;
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "хотите удалить трубу? (0 - нет, 1 - да )" << endl;
                    bool pipe_cheak = GetCorrectNumber(0, 1);
                    if (pipe_cheak && size_pipe != 0) {
                        cout << "введите номер трубы, которую хотите удалить (номера доступны: ";
                        for (auto it = pipe.begin(); it != pipe.end(); ++it) {
                            std::cout << it->first << " ";
                        }
                        cout << ")" << endl;
                        int number_del = GetCorrectNumber(0, size_pipe - 1);
                        pipe.erase(number_del);
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

void EditKC(map<int, KC>& kc) {
    if (kc.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        cout << "Введите число (0 - Отредактировать, 1 - Удалить КС)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "Введите номер КС, которую нужно отредактировать (от 0 до " << size_kc - 1 << " )" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "Введите работает ли КС(1 - работает, 0 - в ремонте)" << endl;
            kc.at(i).Edit();
        }
        else {
            cout << "Введите число (0 - удалить все КС, 1 - удалить конкретную КС)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                kc.clear();
                cout << "Все КС удалены" << endl;
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "Хотите удалить КС? (0 - нет, 1 - да )" << endl;
                    bool ks_cheak = GetCorrectNumber(0, 1);
                    if (ks_cheak && size_kc != 0) {
                        cout << "введите номер КС, которую хотите удалить (Номера доступны: ";
                        for (auto it = kc.begin(); it != kc.end(); ++it) {
                            std::cout << it->first << " ";
                        }
                        cout << ")" << endl;
                        int number_del = GetCorrectNumber(0, size_kc - 1);
                        kc.erase(number_del);
                        size_kc--;
                    }
                    else {
                        d = 0;
                    }
                }
            }
        }

    }
}

void SaveAll(map<int, Pipes>& pipe, map<int, KC>& kc) {
    ofstream fout_pipe;
    fout_pipe.open("Pipe_data.txt", ios::out);
    if (fout_pipe.is_open()) {
        fout_pipe << pipe.size() << endl;
        for (int i = 0; i < pipe.size(); i++) {
            pipe.at(i).SavePipe(fout_pipe);
        }
        fout_pipe.close();
    }
    ofstream fout_kc;
    fout_kc.open("KC_data.txt", ios::out);
    if (fout_kc.is_open()) {
        fout_kc << kc.size() << endl;
        for (int i = 0; i < kc.size(); i++) {
            kc.at(i).SaveKC(fout_kc);
        }
        fout_kc.close();
    }
}

void LoadAll(map<int, Pipes>& pipe, map<int, KC>& kc) {
    ifstream fin_pipe;
    fin_pipe.open("Pipe_data.txt", ios::in);
    if (fin_pipe.is_open()) {
        int count;
        fin_pipe >> count;
        while (count--) {
            pipe[size_pipe++].LoadPipe(fin_pipe);
        }
        cout << "Все трубы были успешно загружены!!!" << endl;
    }
    ifstream fin_kc;
    fin_kc.open("KC_data.txt", ios::in);
    if (fin_kc.is_open()) {
        int count;
        fin_kc >> count;
        while (count--) {
            kc[size_kc++].LoadKC(fin_kc);

        }
        cout << "Все КС были успешно загружены!!!" << endl;
    }
}
void PrintKcPipe(map<int, Pipes>& pipe, map<int, KC>& kc) {
    if (kc.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        for (int i = 0; i < size_kc; i++) {
            cout << "Номер кс: " << i;
            kc.at(i).View();
        }
    }
    if (pipe.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        for (int i = 0; i < size_pipe; i++) {
            cout << "Номер трубы: " << i;
            pipe.at(i).View();
        }
    }
}


int main()
{
    redirect_output_wrapper cerr_out(cerr);
    string time = format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
    ofstream logfile("log_" + time);
    if (logfile)
        cerr_out.redirect(logfile);
    setlocale(LC_ALL, "");
    map<int, KC> kc;
    map<int, Pipes> pipe;
    while (true) {
        cout << "1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Просмотр труб по фильтру 5. Просмотр КС по фильтру 6. Редактировать трубу 7. Редактировать КС 8. Сохранить 9. Загрузить 0. Выход" << endl;
        switch (GetCorrectNumber(0, 9)) {
        case 0:
            cout << "Вы закончили цикл" << endl;
            exit(0);
        case 1:
            pipe[size_pipe++].add();
            break;
        case 2:
            kc[size_kc++].add();
            break;
        case 3:
            PrintKcPipe(pipe, kc);
            break;
        case 4:
            FilterPipe(pipe);
            break;
        case 5:
            FilterKC(kc);
            break;
        case 6:
            EditPipe(pipe);
            break;
        case 7:
            EditKC(kc);
            break;
        case 8:
            SaveAll(pipe, kc);
            break;
        case 9:
            LoadAll(pipe, kc);
            break;
        }
    }
}