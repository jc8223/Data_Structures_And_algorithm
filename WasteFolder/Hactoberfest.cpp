//Fraction to Decimal Conversion and vice versa

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    string res;
    if (numerator < 0 ^ denominator < 0) res += '-';
    long n = labs(numerator), d = labs(denominator), r = n % d;
    res += to_string(n / d);
    if (r == 0) return res;
    res += '.';
    unordered_map<long, int> rs;
    while (r) {
        if (rs.find(r) != rs.end()) {
            res.insert(rs[r], 1, '(');
            res += ')';
            break;
        }
        rs[r] = res.size();
        r *= 10;
        res += to_string(r / d);
        r %= d;
    }
    return res;
}


int main() {
    //Fraction to Decimal Conversion and vice versa
    int numerator, denominator;
    cin >> numerator >> denominator;
    cout << fractionToDecimal(numerator, denominator) << endl;
    return 0;
}