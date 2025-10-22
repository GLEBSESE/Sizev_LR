#include "KC.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    KC kc;
    Pipes pipe;
    while (true) {
        cout << "1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Просмотр труб по фильтру 5. Просмотр КС по фильтру 6. Редактировать трубу 7. Редактировать КС 8. Сохранить 9. Загрузить 0. Выход" << endl;
        switch (GetCorrectNumber(0, 9)) {
        case 0:
            cout << "Вы закончили цикл" << endl;
            exit(0);
        case 1:
            pipe.add();
            break;
        case 2:
            kc.add();
            break;
        case 3:
            pipe.View();
            kc.View();
            break;
        case 4:
            pipe.View_Filter();
            break;
        case 5:
            kc.View_Filter();
            break;
        case 6:
            pipe.Edit();
            break;
        case 7:
            kc.Edit();
            break;
        case 8:
            pipe.output_file();
            kc.output_file();
            break;
        case 9:
            pipe.input_file();
            break;
        }
    }
}