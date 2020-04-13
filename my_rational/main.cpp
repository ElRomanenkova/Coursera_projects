#include <iostream>
#include <stdexcept>

using namespace std;

int GreatestDivider(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    return a + b;
}

int Reduction(int value, int num, int den) {
    int NOD = GreatestDivider(abs(num), abs(den));
    int res = value/NOD;
    return res;
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {

        if (new_denominator == 0)
            throw invalid_argument("Invalid argument");
        else {
            numerator = Reduction(new_numerator, new_numerator, new_denominator);
            denominator = Reduction(new_denominator, new_numerator, new_denominator);

            if (denominator < 0) {
                numerator = - numerator;
                denominator = abs(denominator);
            }
            else
            if (numerator == 0) {
                denominator = 1;
            }
        }


    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;    // числитель
    int denominator;  // знаменатель
};

bool operator== (const Rational& lhs, const Rational& rhs) {
    return lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator();
}

Rational operator+ (const Rational& lhs, const Rational& rhs) {
    int num = 0;
    int den = 0;

    den = lhs.Denominator() * rhs.Denominator(); // всегда больше нуля
    num = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();

    Rational res(num, den);

    return res;
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
    int num = 0;
    int den = 0;

    den = lhs.Denominator() * rhs.Denominator();
    num = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();

    Rational res(num, den);

    return res;
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
    int num = 0;
    int den = 0;

    den = lhs.Denominator() * rhs.Denominator();
    num = lhs.Numerator() * rhs.Numerator();

    Rational res(num, den);

    return res;
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {

    if (rhs.Numerator() == 0)
        throw domain_error("Division by zero");
    else {
        int num = 0;
        int den = 0;

        den = lhs.Denominator() * rhs.Numerator();
        num = lhs.Numerator() * rhs.Denominator();

        Rational res(num, den);

        return res;
    }

}

bool operator< (const Rational& lhs, const Rational& rhs) {
    int num = 0;
    int den = 0;

    den = lhs.Denominator() * rhs.Denominator();
    num = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();

    Rational dif (num, den);

    return dif.Numerator() < 0;

}

istream& operator>> (istream& stream, Rational& rat) {
    int num = rat.Numerator();
    int den = rat.Denominator();

    if (stream) {

        stream >> num;
        stream.ignore(1);
        stream >> den;

    }

    rat = Rational(num, den);

    return stream;
}

ostream& operator<< (ostream& stream, const Rational& rat) {
    stream << rat.Numerator() << "/" << rat.Denominator();
    return stream;
}




int main() {

    Rational r1, r2;
    string operation;

    try {
        cin >> r1 >> operation >> r2;

        if (operation == "+")
            cout << r1 + r2;
        else if (operation == "-")
            cout << r1 - r2;
        else if (operation == "*")
            cout << r1 * r2;
        else
            try {
                cout << r1 / r2;
            } catch (domain_error& ex) {
                cout << ex.what();
            }

    } catch (invalid_argument& ex) {
        cout << ex.what();
    }



    return 0;
}