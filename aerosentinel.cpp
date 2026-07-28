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
    if(risk == 0) {
        std::cout << "\nRisk level: NORMAL\n";
    }
    else if(risk == 1) {
        std::cout << "\nRisk level: LOW\n";
    }
    else if(risk == 2) {
        std::cout << "\nRisk level: HIGH\n";
    }
    else {
        std::cout << "\nRisk level: CRITICAL\n";
    }
}

int analyzeReading(SensorReading reading) {
    int risk = 0;
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
    return risk;
}

SensorReading getSensorReading() {
    SensorReading reading;

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
    return reading;
}

float findMaxEngineTemperature(std::vector<SensorReading> readings) {
    float maxEngineReading = readings[0].engineTemperature;
    for(int i = 0; i < readings.size(); i++) {
        if (readings[i].engineTemperature > maxEngineReading) {
        maxEngineReading = readings[i].engineTemperature;
        }
    }
    return maxEngineReading;
}

float calculateAverageVibration(std::vector<SensorReading> readings) {
    float vibrationSum = 0;
    for(int i = 0; i < readings.size(); i++) {
        vibrationSum += readings[i].vibration;
    }
    float vibrationAverage = vibrationSum / readings.size();
    return vibrationAverage;
}

int main() {

    std::vector<SensorReading> readings;
    int readingCount;

    std::cout << "\nHow many readings do you want to enter? ";
    std::cin >> readingCount;

    if(readingCount <= 0) {
        std::cout << "\nReading count must be greater than 0. \n";
        return 1;
    }

    for(int i = 0; i < readingCount; i++) {
    readings.push_back(getSensorReading());
    }

    std::cout << "\nStored sensor reading count: " << readings.size();

    int riskyReadingCount = 0;
    
    for(int i = 0; i < readings.size(); i++) {

        std::cout << "\n\n--- Reading " << i+1 << " ---";

        int risk = analyzeReading(readings[i]);

        if(risk == 0) {
            std::cout << "\nFlight conditions are normal. ";
        }
        displayRiskLevel(risk);
        if (risk > 0) {
            riskyReadingCount++;
        }
    }
    float highestEngineTemperature = findMaxEngineTemperature(readings);
    float vibrationAverage = calculateAverageVibration(readings);

    std::cout << "\nHighest engine temperature: " << highestEngineTemperature << "\n";
    std::cout << "Average vibration level: " << vibrationAverage << "\n";
    std::cout << "Risky reading count: " << riskyReadingCount << "\n";

    return 0;
}