#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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

// vidurkio skaiciavimo funkcija
double average(const vector<int>& v) {
    if (v.empty()) return 0.0;
    double sum = 0;
    for (int x : v) sum += x;
    return sum / v.size();
}

int main() {
    cout << "Studentų informacinė sistema" << endl;

    int n;
    cout << "Kiek studentu norite ivesti? ";
    cin >> n;

    vector<Studentas> grupe;

    for (int i = 0; i < n; i++) {
        Studentas s;
        cout << "Iveskite varda: ";
        cin >> s.vardas;
        cout << "Iveskite pavarde: ";
        cin >> s.pavarde;

        int nd_kiek;
        cout << "Kiek namu darbu pazymiu? ";
        cin >> nd_kiek;

        cout << "Iveskite " << nd_kiek << " pazymius: ";
        for (int j = 0; j < nd_kiek; j++) {
            int x;
            cin >> x;
            s.pazymiai.push_back(x);
        }

        cout << "Egzamino rezultatas: ";
        cin >> s.egzaminas;

        s.galutinis = average(s.pazymiai) * 0.4 + s.egzaminas * 0.6;

        grupe.push_back(s);
    }

    cout << "\nRezultatai:\n";
    cout << setw(15) << left << "Vardas"
         << setw(15) << left << "Pavarde"
         << setw(20) << right << "Galutinis (Vid.)" << endl;
    cout << "----------------------------------------------------------" << endl;

    for (int i = 0; i < grupe.size(); i++) {
        cout << setw(15) << left << grupe[i].vardas
             << setw(15) << left << grupe[i].pavarde
             << setw(20) << right << fixed << setprecision(2) << grupe[i].galutinis
             << endl;
    }

    return 0;
}

