#include <iostream>
#include <vector>
#include <string>
#include "Data.h"
#include "ReportProcessor.h"
#include <windows.h>
#include "Reader.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    std::locale::global(std::locale("en_US.UTF-8"));
    vector<Data> reports;
    int choice;

    while (true) {
        cout << "Меню:\n";
        cout << "1. Добавить доклад\n";
        cout << "2. Показать все доклады\n";
        cout << "3. Сортировать доклады\n";
        cout << "4. Фильтровать доклады по времени\n";
        cout << "5. Фильтровать доклады по фамилии\n";
        cout << "6. Импорт из файла\n";
        cout << "7. Вывести самый длинный доклад\n";
        cout << "8. Выход\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            string start, end, firstName, middleName, lastName, topic;
            cout << "Введите время начала (ЧЧ:ММ): ";
            cin >> start;
            cout << "Введите время окончания (ЧЧ:ММ): ";
            cin >> end;
            cout << "Введите фамилию: ";
            cin >> lastName;
            cout << "Введите имя: ";
            cin >> firstName;
            cout << "Введите отчество: ";
            cin >> middleName;
            cout << "Введите тему: ";
            cin.ignore();
            getline(cin, topic);
            Data data(start, end, lastName, firstName, middleName, topic);
            reports.emplace_back(data);
            break;
        }
        case 2:
            printReports(reports);
            break;
        case 3: {
            int sortChoice, methodChoice;
            cout << "Сортировать по:\n1. Длительности\n2. Фамилии и теме\n";
            cin >> sortChoice;
            cout << "Выберите метод сортировки:\n1. Пирамидальная сортировка\n2. Сортировка слиянием\n";
            cin >> methodChoice;
            sortReports(reports, sortChoice == 1, methodChoice == 1);
            cout << "Сортировка выполнена.\n";
            break;
        }
        case 4: {
            int minutes;
            cout << "Введите минимальное время в минутах: ";
            cin >> minutes;
            filterReportsByTime(reports, minutes);
            break;
        }
        case 5: {
            string lastName;
            cout << "Введите фамилию: ";
            cin >> lastName;
            filterReportsByLastName(reports, lastName);
            break;
        }
        case 6: {
            string fileName;
            cout << "Введите имя файла (он должен находиться в каталоге программы): ";
            cin.ignore();
            getline(cin, fileName);
            vector<Data> newData = splitLineOnData(readFile(fileName));
            reports.insert(reports.end(), newData.begin(), newData.end());
            break;
        }
        case 7:
            if (reports.size() > 0) {
                Data data = findLongestReport(reports);
                cout << minutesToTime(getDuration(data));
            }
            else {
                cout << "Добавьте хотя бы один доклад для вызова этой функции\n";
            }
            break;
        case 8:
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }
}