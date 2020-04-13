#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <set>

using namespace std;

struct Day {
    int value;
    Day() = default;
    explicit Day(int new_value) {
        if (new_value < 1 || new_value > 31)
            throw logic_error("Day value is invalid: " + to_string(new_value) + "\n");
        else
            value = new_value;
    }
};

struct Month {
    int value;
    Month() = default;
    explicit Month(int new_value) {
        if (new_value < 1 || new_value > 12)
            throw logic_error("Month value is invalid: " + to_string(new_value) + "\n");
        else
            value = new_value;
    }
};

struct Year {
    int value;
    Year() = default;
    explicit Year(int new_value) {
        value = new_value;
    }
};

class Date {
public:
    Date() = default;

    explicit Date(string& value) {
        int y;
        int m;
        int d;
        char c1, c2;
        stringstream stream(value);
        stream >> y >> c1 >> m >> c2 >> d;
        if (stream && c1 == '-' && c2 == '-' && stream.peek() == EOF) {
            Year new_year = Year(y);
            year = new_year.value;
            Month new_month = Month(m);
            month = new_month.value;
            Day new_day = Day(d);
            day = new_day.value;
        }

        else
            throw logic_error("Wrong date format: " + value + "\n");


    }

    int GetYear() const {
        return year;
    }

    int GetMonth() const {
        return month;
    }

    int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator< (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();
    else if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();
    else
        return lhs.GetDay() < rhs.GetDay();
}

class Database {
public:
    Database() = default;

    void AddEvent(const Date& date, const string& event) {
        database[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (database.count(date) > 0) {
            set<string> &events = database.at(date);
            if (events.size() == 1 && events.count(event)) {
                database.erase(date);
                return true;
            }
            else {
                if (events.count(event)) {
                    events.erase(event);
                    return true;
                }
            }

            return false;
        }
        else
            return false;

    }

    int  DeleteDate(const Date& date) {
        if (database.count(date) > 0) {
            int amount = database.at(date).size();
            database.erase(date);
            return amount;
        }
        else
            return 0;

    }

    void Find(const Date& date) const {
        try {
            for (const auto &ev : database.at(date))
                cout << ev << endl;
        } catch (out_of_range& ex) {
        }

    }

    void Print() const {
        for (const auto& d : database)
            for (const auto& ev : d.second)
                cout << setw(4) << setfill('0') << d.first.GetYear() << '-'
                     << setw(2) << setfill('0') << d.first.GetMonth() << '-'
                     << setw(2) << setfill('0') << d.first.GetDay() << ' '
                     << ev << endl;

    }

private:
    map<Date, set<string>> database;
};

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        try {
            string request;
            stringstream input(command);
            getline(input, request, ' ');

            if (request == "Add") {
                string event, date;
                getline(input, date, ' ');
                getline(input, event);
                db.AddEvent(Date(date), event);         // исключение
            }

            else if (request == "Del") {
                string date, event;
                getline(input, date, ' ');
                if (getline(input, event)) {
                    if (db.DeleteEvent(Date(date), event)) {  // исключение
                        cout << "Deleted successfully" << endl;
                    }
                    else {
                        cout << "Event not found" << endl;
                    }
                }
                else {
                    int amount = db.DeleteDate(Date(date)); // исключение
                    cout << "Deleted " << amount << " events" << endl;
                }
            }

            else if (request == "Find") {
                string date;
                getline(input, date, ' ');
                db.Find(Date(date));              // исключение
            }

            else if (request == "Print") {
                db.Print();
            }

            else if (command.empty()) {
                continue;
            }

            else {
                cout << "Unknown command: " << command << endl;
                break;
            }

        } catch (exception& ex1) {
            cout << ex1.what();       // исключение по Дате (месяцу и дню)
            break;
        }

    }

    return 0;
}