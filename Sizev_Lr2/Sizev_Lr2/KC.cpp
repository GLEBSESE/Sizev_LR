#include "KC.h"


void KC::add() {
    cout << "Введите название КС: ";
    INPUT_LINE(cin, _name);
    cout << "Введите количество цехов: ";
    _quantity = GetCorrectNumber(0, 100000);
    cout << "Введите количество цехов в работе: ";
    _count_work = GetCorrectNumber(0, 100000);
    cout << "Введите запуск КС(1 - запустить, 0 - остановка): ";
    _station_class = GetCorrectNumber(0, 1);
}
void KC::View() const {
    cout << " Название: " <<_name << ", количество цехов: " << _quantity << " количество цехов в работе: " << _count_work << " класс станции: " << _station_class << endl;
}

bool KC::CheakByName(string name) {
    return _name == name;
}

void KC::SaveKC(ofstream& fout) {
    fout << _name << " " << _quantity <<" " << _count_work<< " " << _station_class << endl;
}
void KC::LoadKC(ifstream& fin) {
    fin >> _name;
    fin >> _quantity;
    fin >> _count_work;
    fin >> _station_class;
}
void KC::Edit() {
    _station_class = GetCorrectNumber(0, 1);

}

double KC::CheackIdleWorkshops() {
    return (static_cast<double>(_quantity - _count_work) / _quantity) * 100.0;
}