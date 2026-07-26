#include <iostream>

bool isEngineTemperatureDangerous(float temperature) {
    return temperature > 900;
}
bool isOilPressureDangerous(float pressure) {
    return pressure < 25;
}
bool isVibrationDangerous(float vibration) {
    return vibration > 7;
}
bool isFuelPressureDangerous(float pressure) {
    return pressure < 30;
}
bool isEngineRpmDangerous(float rpm) {
    return rpm < 1000 || rpm > 5000;
}

void displayRiskLevel(int risk) {

    std::cout << "\nDetected risk count: " << risk;
    if(risk==0) {
        std::cout << "\nRisk level: NORMAL\n";
    }
    else if(risk==1) {
        std::cout << "\nRisk level: LOW\n";
    }
    else if(risk==2) {
        std::cout << "\nRisk level: HIGH\n";
    }
    else {
        std::cout << "\nRisk level: CRITICAL\n";
    }
}

int main() {
    float engineRpm;
    float engTemp;
    float oil;
    float vib;
    float fuelPressure;
    int risk=0;
    std::cout << "Enter engine temperature: ";
    std::cin >> engTemp;
    std::cout << "\nEnter oil pressure: ";
    std::cin >> oil;
    std::cout << "\nEnter vibration level: ";
    std::cin >> vib;
    std::cout << "\nEnter fuel pressure: ";
    std::cin >> fuelPressure;
    std::cout << "\nEnter engine RPM: ";
    std::cin >> engineRpm;

    if(isEngineTemperatureDangerous(engTemp)) {
        std::cout << "\nEngine temperature is at critical level!";
        risk += 1;
    }
    if(isOilPressureDangerous(oil)) {
        std::cout << "\nOil pressure is at critical level!";
        risk += 1;
    }
    if(isVibrationDangerous(vib)) {
        std::cout << "\nVibration level is at critical level!";
        risk += 1;
    }
    if(isFuelPressureDangerous(fuelPressure)) {
        std::cout << "\nFuel pressure is at critical level!";
        risk += 1;
    }
    if(isEngineRpmDangerous(engineRpm)) {
        std::cout << "\nEngine RPM is outside the safe range!";
        risk += 1;
    }   

    if(risk==0) {
        std::cout << "\nFlight conditions are normal. ";
    }
    displayRiskLevel(risk);

    return 0;
}