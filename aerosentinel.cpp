#include <iostream>

int main() {
    float engTemp;
    float oil;
    float vib;
    int risk=0;
    std::cout << "Enter engine temperature: ";
    std::cin >> engTemp;
    std::cout << "\nEnter oil pressure: ";
    std::cin >> oil;
    std::cout << "\nEnter vibration level: ";
    std::cin >> vib;

    if(engTemp>900) {
        std::cout << "\nEngine temperature is at critical level!";
        risk += 1;
    }
    if(oil<25) {
        std::cout << "\nOil pressure is at critical level!";
        risk += 1;
    }
    if(vib>7) {
        std::cout << "\nVibration level is at critical level!";
        risk += 1;
    }
    if(risk==0) {
        std::cout << "\nFlight conditions are normal. ";
    }
    std::cout << "\n Detected risk count: " << risk;
    return 0;
}