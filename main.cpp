#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

struct Person {
    string name;
    int day;
    int month;
};

class BirthdayList {
private:
    map<string, Person> birthdays;

public:
    void add_birthday(Person p) {
        birthdays[p.name] = p;
    }

    void edit_birthday(string name, Person p) {
        if (birthdays.count(name)) {
            birthdays[name] = p;
        }
    }

    void display_birthday(string name) {
        if (birthdays.count(name)) {
            Person p = birthdays[name];
            cout << p.name << "'s birthday is on " << p.month << "/" << p.day << endl;
        }
    }

    void display_birthdays() {
        cout << "List of Birthdays:" << endl;
        for (auto const& [key, value] : birthdays) {
            cout << value.name << ": " << value.month << "/" << value.day << endl;
        }
    }

    void search_birthday(string name) {
        if (birthdays.count(name)) {
            Person p = birthdays[name];
            cout << p.name << "'s birthday is on " << p.month << "/" << p.day << endl;
        } else {
            cout << "No birthday found for " << name << endl;
        }
    }

    void display_monthly_birthdays() {
        cout << "List of Monthly Birthdays:" << endl;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int current_month = ltm->tm_mon + 1;
        vector<Person> monthly_birthdays;
        for (auto const& [key, value] : birthdays) {
            if (value.month == current_month) {
                monthly_birthdays.push_back(value);
            }
        }
        for (int i = 0; i < monthly_birthdays.size() && i < 5; i++) {
            Person p = monthly_birthdays[i];
            cout << p.name << ": " << p.month << "/" << p.day << endl;
        }
    }
};

int main() {
    BirthdayList b;
    b.add_birthday({"John", 5, 2});
    b.add_birthday({"Jane", 8, 4});
    b.add_birthday({"Tom", 15, 3});
    b.add_birthday({"Amy", 22, 5});
    b.add_birthday({"Brad", 17, 2});
    b.display_birthdays();
    b.search_birthday("Jane");
    b.display_monthly_birthdays();
    b.edit_birthday("Tom", {"Tom", 16, 3});
    b.display_birthday("Tom");
    return 0;
}
