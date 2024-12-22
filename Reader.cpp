#include "Reader.h"
#include <fstream>
#include <iostream>
#include <sstream>

using std::cerr;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;
using std::stringstream;

vector<string> split(const string& str, char separator) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, separator)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> readFile(const string& fileName) {
    vector<string> result;
    ifstream ifs(fileName);
    if (!ifs) {
        cerr << "Не удалось открыть файл: " << fileName << endl;
        return result;
    }

    string line;
    while (getline(ifs, line)) {
        result.push_back(line);
    }
    return result;

}

vector<Data> splitLineOnData(const vector<string>& lines) {
    vector<Data> result;
    for (const auto& line : lines) {
        auto data = split(line, ',');
        if (data.size() >= 6) {
            result.emplace_back(Data(data[0], data[1], data[2], data[3], data[4], data[5]));
        }
    }
    return result;
}