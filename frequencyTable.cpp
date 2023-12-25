#include "frequencyTable.h"

int countWords = 0;

std::ifstream Reader::openFile() {
    std::ifstream ifs(fileName);
    if (!ifs) {
        ifs.exceptions(std::ifstream::failbit);
    }
    return ifs;
}

std::ofstream Writer::openFile() {
    std::ofstream ofs(fileName);
    if (!ofs) {
        ofs.exceptions(std::ofstream::failbit);
    }
    return ofs;
}

void Reader::fillTable() {
    std::string str;
    std::ifstream ifs = openFile();
    while(std::getline(ifs, str)) {
        std::string word{""};
        for(size_t i = 0; i < str.size(); ++i) {
            unsigned char ch = str[i];
            if (std::isdigit(ch) || std::isalpha(ch)) {
                word += str[i];
                continue;
            }
            if (word.size() > 0) {
                ++table[word];
                ++countWords;
                word.clear();
            }
        }
        if (word.size() > 0) {
            ++table[word];
            ++countWords;
        }
    }
}

void Writer::writeTable(const Reader& reader) {
    std::ofstream ofs = openFile();
    for (const auto& [word, count] : reader.sortedByFreqTable) {
        ofs << word << ";" << count << ";" << (((double)count/countWords) * 100) << '%' << "\n";
    }
}

void Reader::sortedTable() {
    Table sortedByFreq(table.begin(), table.end());
    sortedByFreq.sort(
        [](const auto& lhs, const auto& rhs) {
            return rhs.second < lhs.second;
        }
    );
    sortedByFreqTable = sortedByFreq;
}