#include <iostream>
const float MAX_ENGINE_TEMPERATURE = 900;
const float MIN_OIL_PRESSURE = 25;
const float MAX_VIBRATION_LEVEL = 7;
const float MIN_FUEL_PRESSURE = 30;
const float MIN_ENGINE_RPM = 1000;
const float MAX_ENGINE_RPM = 5000;

struct SensorReading {
    float engineTemperature;
    float oilPressure;
    float vibration;
    float fuelPressure;
    float engineRpm;    
};

bool isEngineTemperatureDangerous(float temperature) {
    return temperature > MAX_ENGINE_TEMPERATURE;
}
bool isOilPressureDangerous(float pressure) {
    return pressure < MIN_OIL_PRESSURE;
}
bool isVibrationDangerous(float vibration) {
    return vibration > MAX_VIBRATION_LEVEL;
}
bool isFuelPressureDangerous(float pressure) {
    return pressure < MIN_FUEL_PRESSURE;
}
bool isEngineRpmDangerous(float rpm) {
    return rpm < MIN_ENGINE_RPM || rpm > MAX_ENGINE_RPM;
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

    SensorReading reading;
    int risk=0;
    std::cout << "Enter engine temperature: ";
    std::cin >> reading.engineTemperature;
    std::cout << "\nEnter oil pressure: ";
    std::cin >> reading.oilPressure;
    std::cout << "\nEnter vibration level: ";
    std::cin >> reading.vibration;
    std::cout << "\nEnter fuel pressure: ";
    std::cin >> reading.fuelPressure;
    std::cout << "\nEnter engine RPM: ";
    std::cin >> reading.engineRpm;

    if(isEngineTemperatureDangerous(reading.engineTemperature)) {
        std::cout << "\nEngine temperature is at critical level!";
        risk += 1;
    }
    if(isOilPressureDangerous(reading.oilPressure)) {
        std::cout << "\nOil pressure is at critical level!";
        risk += 1;
    }
    if(isVibrationDangerous(reading.vibration)) {
        std::cout << "\nVibration level is at critical level!";
        risk += 1;
    }
    if(isFuelPressureDangerous(reading.fuelPressure)) {
        std::cout << "\nFuel pressure is at critical level!";
        risk += 1;
    }
    if(isEngineRpmDangerous(reading.engineRpm)) {
        std::cout << "\nEngine RPM is outside the safe range!";
        risk += 1;
    }   

    if(risk==0) {
        std::cout << "\nFlight conditions are normal. ";
    }
    displayRiskLevel(risk);

    return 0;
}