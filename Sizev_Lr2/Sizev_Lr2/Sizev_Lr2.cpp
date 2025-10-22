#include "KC.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    KC kc;
    Pipes pipe;
    while (true) {
        cout << "1. �������� ����� 2. �������� �� 3. �������� ���� �������� 4. �������� ���� �� ������� 5. �������� �� �� ������� 6. ������������� ����� 7. ������������� �� 8. ��������� 9. ��������� 0. �����" << endl;
        switch (GetCorrectNumber(0, 9)) {
        case 0:
            cout << "�� ��������� ����" << endl;
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