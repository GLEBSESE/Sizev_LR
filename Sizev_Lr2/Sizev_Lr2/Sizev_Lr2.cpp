#include "Sizev_Pipe_KS.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Pipes pipe_;
    KS KS_;
    while (true) {
        cout << "1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Просмотр труб по фильтру 5. Просмотр КС по фильтру 6. Редактировать трубу 7. Редактировать КС 8. Сохранить 9. Загрузить 0. Выход" << endl;
        switch (GetCorrectNumber(0, 7)) {
        case 0:
            cout << "Вы закончили цикл" << endl;
            exit(0);
        case 1:
            pipe_.add();
            break;
        case 2:
            KS_.add();
            break;
        case 3:
            pipe_.View();
            KS_.View();
            break;
        case 4:
            pipe_.View_Filter();
            break;
        case 5:
            KS_.View_Filter();
            break;
        case 6:
            pipe_.Edit();
            break;
        case 7:
            KS_.Edit();
            break;
        case 8:
            pipe_.output_file();
            KS_.output_file();
            break;
        case 9:
            pipe_.input_file();
            break;
        }
    }
}