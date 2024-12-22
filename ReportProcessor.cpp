#include <iostream>
#include <vector>
#include <string>
#include "ReportProcessor.h"
#include "Data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::swap;
using std::to_string;

int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int getDuration(const Data& report) {
    return timeToMinutes(report.end) - timeToMinutes(report.start);
}

void printReports(const vector<Data>& reports) {
    for (const auto& report : reports) {
        cout << report.start << " - " << report.end << " | "
            << report.lastName << " " << report.firstName << " " << report.middleName << " | "
            << report.topic << endl;
    }
}

void heapSort(vector<Data>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int largest = j;

            if (left < n && arr[left].lastName > arr[largest].lastName) {
                largest = left;
            }

            if (right < n && arr[right].lastName > arr[largest].lastName) {
                largest = right;
            }

            if (largest != j) {
                swap(arr[j], arr[largest]);
            }
        }
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        for (int j = 0; j < i; j++) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int largest = j;

            if (left < i && arr[left].lastName > arr[largest].lastName) {
                largest = left;
            }

            if (right < i && arr[right].lastName > arr[largest].lastName) {
                largest = right;
            }

            if (largest != j) {
                swap(arr[j], arr[largest]);
            }
        }
    }
}


void mergeSort(vector<Data>& arr) {
    if (arr.size() <= 1) return;

    int mid = arr.size() / 2;
    vector<Data> left;
    vector<Data> right;

    for (int i = 0; i < mid; i++) {
        left.push_back(arr[i]);
    }
    for (int i = mid; i < arr.size(); i++) {
        right.push_back(arr[i]);
    }

    mergeSort(left);
    mergeSort(right);

    arr.clear();

    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].lastName <= right[j].lastName) {
            arr.push_back(left[i]);
            i++;
        }
        else {
            arr.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        arr.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        arr.push_back(right[j]);
        j++;
    }
}

void sortReports(vector<Data>& reports, bool byDuration, bool useHeapSort) {
    if (useHeapSort) {
        heapSort(reports);
    }
    else {
        mergeSort(reports);
    }
}

void filterReportsByTime(const vector<Data>& reports, int minutes) {
    for (const auto& report : reports) {
        if (getDuration(report) >= minutes) {
            cout << report.start << " - " << report.end << " | "
                << report.lastName << " " << report.firstName << " " << report.middleName << " | "
                << report.topic << endl;
        }
    }
}

void filterReportsByLastName(const vector<Data>& reports, const string& lastName) {
    for (const auto& report : reports) {
        if (report.lastName == lastName) {
            cout << report.start << " - " << report.end << " | "
                << report.lastName << " " << report.firstName << " " << report.middleName << " | "
                << report.topic << endl;
        }
    }
}

Data findLongestReport(vector<Data>& arr)
{
    Data result("00:00", "00:00", "lastName", "firstName", "middleName", "topic");
    for (const auto& data : arr) {
        if (getDuration(data) >= getDuration(result)) {
            result = data;
        }
    }
    return result;
}

string minutesToTime(int minutes)
{
    int hours = minutes / 60;
    int mins = minutes % 60;

    string time = (hours < 10 ? "0" : "") + to_string(hours) + ":" +
        (mins < 10 ? "0" : "") + to_string(mins);

    return time;
}
