#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>


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
using std::getline;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;
using std::istringstream;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
};
// vidurkio skaiciavimo funkcija
double average(const vector<int>& v) {
    if (v.empty()) return 0.0;
    double sum = 0;
    for (int x : v) sum += x;
    return sum / v.size();
}

// medianos skaiciavimas
double median(vector<int> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0)
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    else
        return v[n/2];
}
int pasirinkimoMeniu() {
    int p;
    cout << "Pasirinkite veiksma:\n";
    cout << "1 - Ivesti duomenis ranka\n";
    cout << "2 - Sugeneruoti atsitiktinai\n";
    cout << "Jusu pasirinkimas: ";
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return p;
}
Studentas generuotiStudenta() {
    Studentas s;
    s.vardas = "Vardas" + std::to_string(std::rand() % 100);
    s.pavarde = "Pavarde" + std::to_string(std::rand() % 100);
    int nd = 1 + std::rand() % 5;
    for (int i = 0; i < nd; i++) s.pazymiai.push_back(1 + std::rand() % 10);
        s.pazymiai.push_back(1 + std::rand() % 10);

    s.egzaminas   = 1 + std::rand() % 10;
    s.galutinisVid = average(s.pazymiai) * 0.4 + s.egzaminas * 0.6;
    s.galutinisMed = median(s.pazymiai) * 0.4 + s.egzaminas * 0.6;
    return s;
}

int main() {
    std::srand(std::time(nullptr));
    cout << "Studentu informacine sistema\n"; // ties cia stop
    
    int veiksmas = pasirinkimoMeniu();
    int n;
    cout << "Kiek studentu norite ivesti? ";
    cin >> n;
    
    vector<Studentas> grupe;
    
    if (veiksmas == 1) {
        for (int i = 0; i < n; i++) {
            Studentas s;
            cout << "Iveskite varda: ";
            cin >> s.vardas;
            cout << "Iveskite pavarde: ";
            cin >> s.pavarde;
            cout << "Iveskite namu darbu pazymius (Enter uzbaigs irasyma):\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (true) {
                string eilute;
                getline(cin, eilute);
                if (eilute.empty()) break;
                s.pazymiai.push_back(std::stoi(eilute));
            }
            cout << "Egzamino rezultatas: ";
            cin >> s.egzaminas;
            
            s.galutinisVid = average(s.pazymiai) * 0.4 + s.egzaminas * 0.6;
            s.galutinisMed = median(s.pazymiai) * 0.4 + s.egzaminas * 0.6;
            grupe.push_back(s);
        }
    } else {
        for (int i = 0; i < n; i++)
            grupe.push_back(generuotiStudenta());
    }
    int pasirinkimas;
    cout << "Pasirinkite isvedimo buda:\n";
    cout << "1 - Tik pagal vidurki\n";
    cout << "2 - Tik pagal mediana\n";
    cout << "3 - Abu kartu\n";
    cout << "Jusu pasirinkimas: ";
    cin >> pasirinkimas;

    cout << "\nRezultatai:\n";
    cout << setw(15) << left << "Vardas"
         << setw(15) << left << "Pavarde";

    if (pasirinkimas == 1)
        cout << setw(20) << right << "Galutinis (Vid.)";
    else if (pasirinkimas == 2)
        cout << setw(20) << right << "Galutinis (Med.)";
    else
        cout << setw(20) << right << "Galutinis (Vid.)"
             << setw(20) << right << "Galutinis (Med.)";

    cout << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (auto &st : grupe) {
        cout << setw(15) << left << st.vardas
             << setw(15) << left << st.pavarde;

        if (pasirinkimas == 1)
            cout << setw(20) << right << fixed << setprecision(2) << st.galutinisVid;
        else if (pasirinkimas == 2)
            cout << setw(20) << right << fixed << setprecision(2) << st.galutinisMed;
        else
            cout << setw(20) << right << fixed << setprecision(2) << st.galutinisVid
                 << setw(20) << right << fixed << setprecision(2) << st.galutinisMed;

        cout << endl;
    }

    return 0;
}

