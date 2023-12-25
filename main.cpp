#include "frequencyTable.h"

int main(int argc, char** argv)
{
    try 
    {
        if (argc < 3) {
            std::cout << "Incorrect count of parameters";
            return 1;
        }
        setlocale(LC_ALL, "Russian");
        std::string_view inputFileName(argv[1]);
        std::string_view outputFileName(argv[2]);
        Reader reader(inputFileName);
        reader.fillTable();
        reader.sortedTable();
        Writer writer(outputFileName);
        writer.writeTable(reader);
    } catch (const std::istream::failure& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}
