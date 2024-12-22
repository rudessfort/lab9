#pragma once

#include <string>

using std::string;

struct Data {
    string start;
    string end;
    string lastName;
    string firstName;
    string middleName;
    string topic;

    Data(const string& start, const string& end,
        const string& lastName, const string& firstName,
        const string& middleName, const string& topic)
        : start(start), end(end), lastName(lastName), firstName(firstName), middleName(middleName), topic(topic) {}
};