#include <iostream>
#include <math.h>

long double calculateFactor(int multiplicity, long double length, long double distance, long double x) {
    return multiplicity * length * sqrt(distance*distance + x*x) / x;
}

int main() {
    int n = 0;
    std::cout << "Podaj ilosc odleglosci: ";
    std::cin >> n;
    long double D[n];
    long double x1[n];
    long double x2[n];
    long double factor[n*2];
    long double length;
    std::cout << "Podaj dlugosc swiatla [nm]: ";
    std::cin >> length;

    for (int i=0; i<n; i++) {
        std::cout << "Podaj odleglosc nr "+ std::to_string(i+1)+" [m]: ";
        std::cin >> D[i];
        std::cout << "Podaj x1 nr "+ std::to_string(i+1)+" [m]: ";
        std::cin >> x1[i];
        std::cout << "Podaj x2 nr "+ std::to_string(i+1)+" [m]: ";
        std::cin >> x2[i];
    }

    for (int i=0; i<n; i++) {
        long double distance = D[i];
        factor[i] = calculateFactor(1, length, distance, x1[i]);
        factor[n+i] = calculateFactor(2, length, distance, x2[i]);
    }

    std::cout << std::endl << "Wyniki:"<< std::endl;

    for (int i=0; i<n; i++) {
        std::cout << "Odleglosc nr " << std::to_string(i+1)<< std::endl;
        std::cout << "d x1 = 1 * "<<length<<" * (" << std::to_string(D[i]) << "^2 + " << std::to_string(x1[i]) << "^2) / " << std::to_string(x1[i])<< " * 10^-7 [m] = " << std::to_string(factor[i]) << " * 10^-7 [m]"<< std::endl;
        std::cout << "d x2 = 1 * "<<length<<" * (" << std::to_string(D[i]) << "^2 + " << std::to_string(x2[i]) << "^2) / " << std::to_string(x2[i])<< " * 10^-7 [m] = " << std::to_string(factor[n+i])<<" * 10^-7 [m]" << std::endl;
    }

    long double mean=0;
    long double sum=0;

    for (int i=0; i < 2*n; i++) {
        sum = sum + factor[i];
        mean = sum/2*n;
    }

    std::cout << "Srednia: " << std::to_string(mean);

    return 0;
}

