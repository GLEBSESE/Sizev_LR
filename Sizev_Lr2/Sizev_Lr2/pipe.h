#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define INPUT_LINE(in, str) getline(in>>std::ws, str); \
						std::cerr << str << std::endl

#define PRINT_PARAM(out, x) out<< #x << "=" << x << std::endl


class redirect_output_wrapper
{
    std::ostream& stream;
    std::streambuf* const old_buf;
public:
    redirect_output_wrapper(std::ostream& src)
        :old_buf(src.rdbuf()), stream(src)
    {
    }

    ~redirect_output_wrapper() {
        stream.rdbuf(old_buf);
    }
    void redirect(std::ostream& dest)
    {
        stream.rdbuf(dest.rdbuf());
    }
};



template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail()	// check type
        || std::cin.peek() != '\n'	// is buffer empty (int/float check)
        || x < min || x > max)		// check range
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Type number (" << min << "-" << max << "):";
    }
    return x;
}

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