#include "pipe.h"

void Pipes::add() {
    cout << "введите название трубы: ";
    INPUT_LINE(cin, _name);
    cout << "введите размеры трубы (длину): ";
    _length = GetCorrectNumber(0, 100000);
    cout << "введите размеры трубы (ширину): ";
    _width = GetCorrectNumber(0, 100000);
    cout << "введите работает ли труба(0 - в ремонте, 1 - работает): ";
    _properties = GetCorrectNumber(0, 1);
}
void Pipes::View() const {
    cout  << " название: " << _name << ", длина: " << _length << " ширина: " << _width << " работает ли труба (1 - работает, 0 - в ремонте): " << _properties << endl;
}

bool Pipes::CheakByProperities(bool properties) {
    return _properties == properties;
}
bool Pipes::CheakByName(string name) {
    return _name == name;
}

void Pipes::Edit() {
    _properties = GetCorrectNumber(0, 1);


}
void Pipes::SavePipe(ofstream& fout) {
    fout << _name << " " << _length << " " << _width << " " << _properties << endl;
}
void Pipes::LoadPipe(ifstream& fin) {
    fin >> _name;
    fin >> _length;
    fin >> _width;
    fin >> _properties;
}
