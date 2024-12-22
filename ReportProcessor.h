#pragma once

#include "Data.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int timeToMinutes(const string& time);
int getDuration(const Data& report);
void printReports(const vector<Data>& reports);
void heapSort(vector<Data>& arr);
void mergeSort(vector<Data>& arr);
void sortReports(vector<Data>& reports, bool byDuration, bool useHeapSort);
void filterReportsByTime(const vector<Data>& reports, int minutes);
void filterReportsByLastName(const vector<Data>& reports, const string& lastName);
Data findLongestReport(vector<Data>& arr);
string minutesToTime(int minutes);