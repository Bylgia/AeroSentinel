#include <iostream>
#include <vector>

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
    std::vector<SensorReading> readings;
    int readingCount;

    std::cout << "\nHow many readings do you want to enter? ";
    std::cin >> readingCount;

    if(readingCount <= 0) {
        std::cout << "\nReading count must be greater than 0. \n";
        return 1;
    }

    for(int i = 0; i < readingCount; i++) {
    std::cout << "\nEnter engine temperature: ";
    std::cin >> reading.engineTemperature;
    std::cout << "\nEnter oil pressure: ";
    std::cin >> reading.oilPressure;
    std::cout << "\nEnter vibration level: ";
    std::cin >> reading.vibration;
    std::cout << "\nEnter fuel pressure: ";
    std::cin >> reading.fuelPressure;
    std::cout << "\nEnter engine RPM: ";
    std::cin >> reading.engineRpm;

    readings.push_back(reading);
    }

    std::cout << "\nStored sensor reading count: " << readings.size();

    float maxEngineReading = readings[0].engineTemperature;
    
    for(int i = 0; i < readings.size(); i++) {

        if (readings[i].engineTemperature > maxEngineReading) {
        maxEngineReading = readings[i].engineTemperature;
        }

        int risk = 0;

        std::cout << "\n\n--- Reading " << i+1 << " ---";
        if(isEngineTemperatureDangerous(readings[i].engineTemperature)) {
            std::cout << "\nEngine temperature is at critical level!";
            risk += 1;
        }
        if(isOilPressureDangerous(readings[i].oilPressure)) {
            std::cout << "\nOil pressure is at critical level!";
            risk += 1;
        }
        if(isVibrationDangerous(readings[i].vibration)) {
            std::cout << "\nVibration level is at critical level!";
            risk += 1;
        }
        if(isFuelPressureDangerous(readings[i].fuelPressure)) {
            std::cout << "\nFuel pressure is at critical level!";
            risk += 1;
        }
        if(isEngineRpmDangerous(readings[i].engineRpm)) {
            std::cout << "\nEngine RPM is outside the safe range!";
            risk += 1;
        }
        if(risk==0) {
        std::cout << "\nFlight conditions are normal. ";
        }
        displayRiskLevel(risk);
    }

    std::cout << "\nHighest engine temperature: " << maxEngineReading << "\n";
    return 0;
}