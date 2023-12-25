#ifndef HEADER
#define HEADER
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <fstream>

using Table = std::list<std::pair<std::string, int>>;

class Reader;

class Writer {
public:
    Writer(const std::string_view& name) : fileName(name) {}
    std::ofstream openFile();
    void writeTable(const Reader& reader);
private:
    std::string fileName;
};

class Reader {
public:
    Reader(const std::string_view& name) : fileName(name) {}
    std::ifstream openFile();
    void fillTable();
    void sortedTable();
    friend void Writer::writeTable(const Reader& reader);
private:
    std::string fileName;
    std::map<std::string, int> table;
    Table sortedByFreqTable;
};
#endif

