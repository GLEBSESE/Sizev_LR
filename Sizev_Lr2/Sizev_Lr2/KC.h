#pragma once
#include "pipe.h"

class KC {
private:
    struct MyKC
    {
        string _name;
        int _quantity;
        int _count_work;
        bool _station_class;
    };
    map<int, MyKC> _KC;
    int size_KC = 0;
public:
    void add();
    void View() const;
    void View_Filter() const;
    void Edit();
    void output_file() const;
};