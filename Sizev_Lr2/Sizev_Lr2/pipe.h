#pragma once
#include "utils.h"

using namespace std;


class Pipes {
public:
    void add();
    void View() const;
    void Edit();
    bool CheakByProperities(const bool properties);
    bool CheakByName(const string name);
    void SavePipe(ofstream& fout);
    void LoadPipe(ifstream& fin);
private:
    string _name;
    int _length;
    int _width;
    bool _properties;
};