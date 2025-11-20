#pragma once
#include "pipe.h"

class KC {
private:
    string _name;
    int _quantity;
    int _count_work;
    bool _station_class;
public:
    void add();
    void View() const;
    void Edit();
    bool CheakByName(string name);
    void SaveKC(ofstream& fin);
    void LoadKC(ifstream& fout);
    double CheackIdleWorkshops();
};