#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;

struct Car {
public:
	int year;
	string name;
	double bhp;

	Car(int year, string name, double bhp) {
		this->year = year;
		this->name = name;
		this->bhp = bhp;
	}
};


int main() {
	vector<Car> vect = {
						Car(1981, "Jalpa", 255),
						Car(1968, "Islero", 350),
						Car(1971, "Miura SV", 430),
						Car(2015, "Huracan", 610),
						Car(2012, "Aventador", 700),
						Car(1972, "Countach", 375),
						Car(2008, "Reventon", 650),
						Car(2013, "Veneno", 740),
						Car(2006, "Murcielago", 640),
						Car(2009, "Gallardo", 560),
						Car(2010, "Sesto Elemento", 570),
						Car(1972, "Urraco", 220),
					};

	cout << "Printing pre-sorting\n";
	cout << "--------------------\n";
	for (int i = 0; i < vect.size(); ++i)
		cout << "Car(" << vect[i].year << ", \"" << vect[i].name << ", " << vect[i].bhp << ")\n";
	cout << "\n";

	// sort(vect.begin(), vect.end());
	exit(EXIT_SUCCESS);
}