#include"FileManager.h"

int main()
{
    auto now = system_clock::now();
    time_t now_c = system_clock::to_time_t(now);
    tm tm;
    localtime_s(&tm, &now_c);
    redirect_output_wrapper cerr_out(cerr);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d_%m_%Y_%H_%M_%S");
    std::string time = oss.str();

    ofstream logfile("log_" + time + ".txt");
    if (logfile)
        cerr_out.redirect(logfile);
    setlocale(LC_ALL, "");
    FileManager Manager;
    unordered_map<int, KC> kc;
    unordered_map<int, Pipes> pipes;
    while (true) {
        cout << "1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Просмотр труб по фильтру 5. Просмотр КС по фильтру 6. Редактировать трубу 7. Редактировать КС 8. Сохранить 9. Загрузить 0. Выход" << endl;
        switch (GetCorrectNumber(0, 9)) {
        case 0: {
            cout << "Вы закончили цикл" << endl;
            exit(0);
        }
        case 1: {
            Pipes p;
            p.add();
            pipes.emplace(p.GetId(), p);
            break;
        }
        case 2: {
            KC s;
            s.add();
            kc.emplace(s.GetId(), s);
            break;
        }
        case 3: {
            Manager.PrintKcPipe(pipes, kc);
            break;
        }
        case 4: {
            Manager.FilterPipe(pipes);
            break;
        }
        case 5: {
            Manager.FilterKC(kc);
            break;
        }
        case 6: {
            Manager.EditPipe(pipes);
            break;
        }
        case 7: {
            Manager.EditKC(kc);
            break;
        }
        case 8: {
            string filename;
            cout << "Введите имя файла для сохранения (без расширения): ";
            INPUT_LINE(cin, filename);
            if (filename.empty()) {
                std::cout << "Имя файла не может быть пустым.\n";
                break;
            }
            Manager.SaveAll(pipes, kc, filename + ".txt");

            break;
        }
        case 9: {
            string filename;
            cout << "Введите имя файла для сохранения (без расширения): ";
            INPUT_LINE(cin, filename);
            if (filename.empty()) {
                cout << "Имя файла не может быть пустым.\n";
                break;
            }
            Manager.LoadAll(pipes, kc, filename + ".txt");
            break;
        }
        }
    }
}