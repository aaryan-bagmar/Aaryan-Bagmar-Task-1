#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class BirthdayList {
private:
    map<string, Date> birthdays;

public:
    void addBirthday(string name, int day, int month, int year) {
        birthdays[name] = { day, month, year };
    }

    void editBirthday(string name, int day, int month, int year) {
        birthdays[name] = { day, month, year };
    }

    void displayBirthday(string name) {
        auto birthday = birthdays.find(name);
        if (birthday == birthdays.end()) {
            cout << "No birthday found for " << name << endl;
        }
        else {
            cout << name << "'s birthday is on " << birthday->second.day << "/" << birthday->second.month << "/" << birthday->second.year << endl;
        }
    }

    void displayMonthlyBirthdays(int month) {
        cout << "Birthdays in month " << month << ":" << endl;
        vector<string> names;
        for (auto birthday : birthdays) {
            if (birthday.second.month == month) {
                names.push_back(birthday.first);
            }
        }
        sort(names.begin(), names.end());
        for (auto name : names) {
            cout << name << endl;
        }
    }

    void searchBirthday(string name) {
        auto birthday = birthdays.find(name);
        if (birthday == birthdays.end()) {
            cout << "No birthday found for " << name << endl;
        }
        else {
            cout << name << "'s birthday is on " << birthday->second.day << "/" << birthday->second.month << "/" << birthday->second.year << endl;
        }
    }
};

int main() {
    BirthdayList list;
    list.addBirthday("John", 20, 5, 2000);
    list.addBirthday("Jane", 25, 10, 2002);
    list.addBirthday("Bob", 10, 3, 2001);
    list.addBirthday("Alice", 15, 7, 2003);
    list.addBirthday("Eve", 30, 9, 2004);

    list.displayBirthday("John");
    list.displayMonthlyBirthdays(5);
    list.searchBirthday("Jane");

    return 0;
}

