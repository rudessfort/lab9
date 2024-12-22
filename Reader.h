#pragma once

#include "Data.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::endl;
using std::ifstream;
using std::vector;

vector<string> split(const string& str, char separator);
vector<string> readFile(const string& fileName);
vector<Data> splitLineOnData(const vector<string>& lines);