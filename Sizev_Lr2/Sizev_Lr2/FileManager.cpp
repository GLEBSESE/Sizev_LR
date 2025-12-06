#include "FileManager.h"



void FileManager::RepairPipeForEdit(unordered_map<int, Pipes>& pipe) {
    cout << "введите номер трубы, которую нужно отредактировать  (номера доступны: ";
    for (auto it = pipe.begin(); it != pipe.end(); ++it) {
        std::cout << it->first << " ";
    }
    cout << ")" << endl;
    int i = GetCorrectNumber(0, 1000);
    cout << "введите работает ли труба(1 - работает, 0 - в ремонте)" << endl;
    pipe.at(i).Edit();
}

void FileManager::ErasePipeForEdit(unordered_map<int, Pipes>& pipe) {
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
            if (pipe_cheak && pipe.size() != 0) {
                cout << "введите номер трубы, которую хотите удалить (номера доступны: ";
                for (auto it = pipe.begin(); it != pipe.end(); ++it) {
                    std::cout << it->first << " ";
                }
                cout << ")" << endl;
                int number_del = GetCorrectNumber(1, int(pipe.size() + 1));
                pipe.erase(number_del);
            }
            else {
                cout << "трубы удалены!!!" << endl;
                d = 0;
            }
        }
    }
}

void FileManager::EditPipe(unordered_map<int, Pipes>& pipe) {
    if (pipe.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "введите число (0 - отредактировать, 1 - удалить трубы)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            RepairPipeForEdit(pipe);
        }
        else {
            cout << "введите число (0 - удалить все трубы, 1 - удалить конкретную трубу)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                pipe.clear();
                cout << "все трубы удалены!!!" << endl;
            }
            else {
                ErasePipeForEdit(pipe);
            }
        }
    }
}

void FileManager::RepairKC(unordered_map<int, KC>& kc) {
    cout << "Введите номер КС, которую нужно отредактировать (Номера доступны: ";
    for (auto it = kc.begin(); it != kc.end(); ++it) {
        std::cout << it->first << " ";
    }
    cout << ")" << endl;
    int i = GetCorrectNumber(0, 1000);
    cout << "Введите работает ли КС(1 - работает, 0 - в ремонте)" << endl;
    kc.at(i).Edit();
}

void FileManager::EraseKC(unordered_map<int, KC>& kc) {
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
            if (ks_cheak && kc.size() != 0) {
                cout << "введите номер КС, которую хотите удалить (Номера доступны: ";
                for (auto it = kc.begin(); it != kc.end(); ++it) {
                    std::cout << it->first << " ";
                }
                cout << ")" << endl;
                int number_del = GetCorrectNumber(1, int(kc.size() + 1));
                kc.erase(number_del);
            }
            else {
                d = 0;
            }
        }
    }
}

void FileManager::EditKC(unordered_map<int, KC>& kc) {
    if (kc.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        cout << "Введите число (0 - Отредактировать, 1 - Удалить КС)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            RepairKC(kc);
        }
        else {
            EraseKC(kc);
        }
    }
}

void FileManager::ErasePipes(unordered_map<int, Pipes>& pipes, vector<int>& id_p) {
    cout << "введите число (0 - удалить все трубы, 1 - удалить конкретную трубу)" << endl;
    bool del = GetCorrectNumber(0, 1);
    if (!del) {
        for (int id : id_p) {
            pipes.erase(id);
        }
        cout << "все трубы удалены!!!" << endl;
    }
    else {
        bool d = 1;
        while (d) {
            cout << "хотите удалить трубу? (0 - нет, 1 - да )" << endl;
            bool pipe_cheak = GetCorrectNumber(0, 1);
            if (pipe_cheak && pipes.size() != 0) {
                cout << "введите номер трубы, которую хотите удалить (номера доступны: ";
                for (int id : id_p) {
                    cout << id << " ";
                }
                cout << ")" << endl;
                int number_del = GetCorrectNumber(1, int(id_p.size()));
                pipes.erase(number_del);
            }
            else {
                cout << "трубы удалены!!!" << endl;
                d = 0;
            }
        }
    }
}

void FileManager::RepairPipes(unordered_map<int, Pipes>& pipes, vector<int>& id_p) {
    cout << "введите номер трубы, которую нужно отредактировать  (номера доступны: ";
    for (int id : id_p) {
        cout << id << " ";
    }
    cout << ")" << endl;
    int i = GetCorrectNumber(0, 1000);
    cout << "введите работает ли труба(1 - работает, 0 - в ремонте)" << endl;
    pipes.at(i).Edit();
}

void FileManager::FilterEditIdPipes(unordered_map<int, Pipes>& pipes, vector<int>& id_p) {
    cout << "Хотите отредактировать отфилтрованные трубы? (0 - нет , 1 - да)" << endl;
    bool cheak = GetCorrectNumber(0, 1);
    if (cheak) {
        cout << "введите число (0 - отредактировать, 1 - удалить трубы)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (cnt) {
            ErasePipes(pipes, id_p);
        }
        else {
            RepairPipes(pipes, id_p);
        }
    }
}
namespace filters {
    template<typename T>
    bool by_name(const T& obj, const std::string& name) {
        return obj.CheakByName(name);
    }
    inline bool pipe_by_repair(const Pipes& pipe, bool in_repairs) {
        return pipe.CheakByProperities(in_repairs);
    }
    inline bool station_by_unused(const KC& station, double min_percent) {
        double unused = station.IdleWorkshops();
        return unused >= min_percent;
    }
}

template <typename T, typename Filter, typename Param>
auto FileManager::find_by_filter(const unordered_map<int, T>& objects, Filter filter, Param param) {
    vector<int> id_map;
    for (const auto& [id, obj] : objects) {
        if (filter(obj, param)) {
            id_map.push_back(id);
            obj.View();
        }
    }
    return id_map;
}


void FileManager::NameFilterPipe(unordered_map<int, Pipes>& pipes) {
    cout << "введите имя трубы: " << endl;
    string name;
    INPUT_LINE(cin, name);
    vector<int> id_p = find_by_filter(pipes, filters::by_name<Pipes>, name);
    if (id_p.empty()) {
        cout << "Фильтр с именем не нашел подходящей трубы" << endl;
    }
    else {
        FilterEditIdPipes(pipes, id_p);
    }
}

void FileManager::RepairPipe(unordered_map<int, Pipes>& pipes) {
    cout << "введите число (0 - в ремонте, 1 - работает)" << endl;
    bool properities = GetCorrectNumber(0, 1);
    auto filter = filters::pipe_by_repair;
    vector<int> id_p = find_by_filter(pipes, filter, properities);
    if (id_p.empty()) {
        cout << "Фильтр по признаку в ремонте не нашел подходящей трубы" << endl;
    }
    else {
        FilterEditIdPipes(pipes, id_p);
    }
}

void FileManager::FilterPipe(unordered_map<int, Pipes>& pipes) {
    if (pipes.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        cout << "введите число (филтровать по 0 - названию, 1 - по признаку в ремонте)" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        if (cheak) {
            RepairPipe(pipes);
        }
        else {
            NameFilterPipe(pipes);
        }
    }
}

void FileManager::FilterEditIdKC(unordered_map<int, KC>& kc, vector<int>& id_kc) {
    cout << "Хотите отредактировать отфилтрованные КС? (0 - нет , 1 - да)" << endl;
    bool cheak = GetCorrectNumber(0, 1);
    if (cheak) {
        cout << "Введите число (0 - Отредактировать, 1 - Удалить КС)" << endl;
        bool cnt = GetCorrectNumber(0, 1);
        if (!cnt) {
            cout << "Введите номер КС, которую нужно отредактировать (Номера доступны: ";
            for (int id : id_kc) {
                cout << id << " ";
            }
            cout << ")" << endl;
            int i = GetCorrectNumber(0, 1000);
            cout << "Введите работает ли КС(1 - работает, 0 - в ремонте)" << endl;
            kc.at(i).Edit();
        }
        else {
            cout << "Введите число (0 - удалить все КС, 1 - удалить конкретную КС)" << endl;
            bool del = GetCorrectNumber(0, 1);
            if (!del) {
                for (int id : id_kc) {
                    kc.erase(id);
                }
                cout << "Все КС удалены" << endl;
            }
            else {
                bool d = 1;
                while (d) {
                    cout << "Хотите удалить КС? (0 - нет, 1 - да )" << endl;
                    bool ks_cheak = GetCorrectNumber(0, 1);
                    if (ks_cheak && kc.size() != 0) {
                        cout << "введите номер КС, которую хотите удалить (Номера доступны: ";
                        for (int id : id_kc) {
                            cout << id << " ";
                        }
                        cout << ")" << endl;
                        int number_del = GetCorrectNumber(1, int(id_kc.size() + 1));
                        kc.erase(number_del);
                    }
                    else {
                        d = 0;
                    }
                }
            }
        }
    }
}

void FileManager::FilterIdleWorkshopsKC(unordered_map<int, KC>& kc) {
    cout << "Введите процент незадействованных цехов: " << endl;
    int Idle = GetCorrectNumber(0, 100);
    vector<int> id_kc = find_by_filter(kc, filters::station_by_unused, Idle);
    FilterEditIdKC(kc, id_kc);
}

void FileManager::FilterNameKC(unordered_map<int, KC>& kc) {
    cout << "Введите имя трубы: " << endl;
    string name;
    INPUT_LINE(cin, name);
    vector<int> id_kc = find_by_filter(kc, filters::by_name<KC>, name);
    FilterEditIdKC(kc, id_kc);
}

void FileManager::FilterKC(unordered_map<int, KC>& kc) {
    if (kc.empty()) {
        cout << "кс не найдены, добавьте кс" << endl;
    }
    else {
        cout << "введите число (филтровать по 0 - названию, 1 - по  проценту незадействованных цехов)" << endl;
        bool cheak = GetCorrectNumber(0, 1);
        if (cheak) {
            FilterIdleWorkshopsKC(kc);
        }
        else {
            FilterNameKC(kc);
        }
    }

}

void FileManager::SaveAll(const unordered_map<int, Pipes>& pipes,
    const unordered_map<int, KC>& stations,
    const string& filename)
{
    std::ofstream f(filename);
    if (!f.is_open()) {
        cout << "Ошибка: невозможно открыть файл для записи.\n";
        return;
    }

    f << "PIPES " << pipes.size() << "\n";
    for (const auto& [id, pipe] : pipes)
        pipe.SavePipe(f);

    f << "STATIONS " << stations.size() << "\n";
    for (auto& [id, station] : stations)
        station.SaveKC(f);

    std::cout << "Data saved to " << filename << "\n";
}

void FileManager::LoadAll(unordered_map<int, Pipes>& pipes,
    unordered_map<int, KC>& stations,
    const std::string& filename) {
    std::ifstream f(filename);
    if (!f.is_open()) {
        cout << "Ошибка: невозможно открыть файл для чтения.\n";
        return;
    }

    pipes.clear();
    stations.clear();

    std::string section;
    while (f >> section) {
        if (section == "PIPES") {
            size_t count;
            f >> count;
            f.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (size_t i = 0; i < count; ++i) {
                Pipes p;
                p.LoadPipe(f);
                pipes.emplace(p.GetId(), p);
            }
        }
        else if (section == "STATIONS") {
            size_t count;
            f >> count;
            f.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (size_t i = 0; i < count; ++i) {
                KC s;
                s.LoadKC(f);
                stations.emplace(s.GetId(), s);
            }
        }
    }

    std::cout << "Данные успешно загружены из " << filename << "\n";
}
void FileManager::PrintKcPipe(unordered_map<int, Pipes>& pipe, unordered_map<int, KC>& kc) {
    if (kc.empty()) {
        cout << "КС не найден, добавьте КС" << endl;
    }
    else {
        for (auto s : kc) {
            s.second.View();
        }
    }
    if (pipe.empty()) {
        cout << "трубы не найдены, добавьте трубу" << endl;
    }
    else {
        for (auto p : pipe) {
            p.second.View();
        }
    }
}
