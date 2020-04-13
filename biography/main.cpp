#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string GetHistory(const map<int, string>& all_names, int year) {

    vector<string> temp_names;

    for (const auto& x : all_names)
        if (x.first < (--all_names.upper_bound(year))->first)
            temp_names.push_back(x.second);
        else
            break;

    string res;
    if (!temp_names.empty() && all_names.size() > 1) {
        res = " (";
        for (unsigned int i = temp_names.size() - 1; i >= 0; i--) {

            if (i == temp_names.size() - 1) {
                if ((--all_names.upper_bound(year))->second != temp_names[i]) {
                    if (i > 0) {
                        res += temp_names[i] + ", ";
                    }
                    else {
                        res += temp_names[i];
                    }
                }
                else
                    if (i == 0) {
                        res.clear();
                        return res;
                    }
            }
            else
                if (temp_names[i + 1] != temp_names[i]) {
                    if (i > 0) {
                        res += temp_names[i] + ", ";
                    } else {
                        res += temp_names[i];
                    }
                }
                else
                    if (i == 0) {
                        res.clear();
                        return res;
                    }
                }
        res +=")";

    }

        return res;
}


class Person {
public:

    Person(const string& add_name, const string& add_surname, int year) {
        name[year] = add_name;
        surname[year] = add_surname;
        birthday_year = year;
    }

    void ChangeFirstName(int year, const string& first_name) { // добавить факт изменения имени на first_name в год year
        name[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {   // добавить факт изменения фамилии на last_name в год year
        surname[year] = last_name;
    }

    string GetFullName(int year) const {     // получить имя и фамилию по состоянию на конец года year

        if (year < birthday_year)
            return "No person";

        else if ((year < (*name.begin()).first || name.empty()) && (surname.empty() || year < (*surname.begin()).first))
            return "Incognito";

        else if (year >= (*name.begin()).first && (surname.empty() || year < (*surname.begin()).first))
            return (--name.upper_bound(year))->second + " with unknown last name";

        else if ((name.empty() || year < (*name.begin()).first) && year >= (*surname.begin()).first)
            return (--surname.upper_bound(year))->second + " with unknown first name";

        else
            return (--name.upper_bound(year))->second + " " + (--surname.upper_bound(year))->second;
    }

    string GetFullNameWithHistory(int year) const {      // получить все имена и фамилии по состоянию на конец года year

        if (year < birthday_year)
            return "No person";

        if ((year < (*name.begin()).first || name.empty()) && (surname.empty() || year < (*surname.begin()).first))
            return "Incognito";

        else if (year >= (*name.begin()).first && (surname.empty() || year < (*surname.begin()).first))
            return (--name.upper_bound(year))->second + GetHistory(name, year) + " " + "with unknown last name";

        else if ((name.empty() || year < (*name.begin()).first) && year >= (*surname.begin()).first)
            return (--surname.upper_bound(year))->second + GetHistory(surname, year) + " " + "with unknown first name";

        else
            return (--name.upper_bound(year))->second + GetHistory(name, year) + " " + (--surname.upper_bound(year))->second + GetHistory(surname, year);


    }

private:
    map<int, string> name;
    map<int, string> surname;
    int birthday_year;

};


int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

//    No person
//    Polina Sergeeva
//    Appolinaria (Polina) Sergeeva
//    Appolinaria (Polina) Ivanova (Sergeeva)

    return 0;
}