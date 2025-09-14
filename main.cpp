#include <iostream>
#include <iomanip>
#include <string>
#include <vector

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis;
};
int main() {
    cout <<"Studentų informacinė sistema" << endl;
}
//vidukio skaiciavimo funkcija
double average(const vector<int>& v) {
    if (v.empty()) retutn 0.0;
    double sum = 0;
    for (int x : v) sum += x;
    return sum / v.size();
}
