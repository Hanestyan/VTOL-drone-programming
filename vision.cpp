#include <iostream>
#include <string>
using namespace std;

std::string objectColor = "RED";
bool cameraActive = false;
int objectCount = 0;

void startCamera() {
    cameraActive = true;
    std::cout << "[CAMERA] Camera started\n";
}

void detectObject(std::string color) {
    if (cameraActive == true) {
        objectColor = color;

        if (color == "RED") {
            objectCount++;
            std::cout << "[DETECT] Red object detected!\n";
        }
        else if (color == "BLUE") {
            objectCount++;
            std::cout << "[DETECT] Blue object detected!\n";
        }
        else {
            std::cout << "[WARNING] Unknown object color\n";
        }
    }
}

void stopCamera() {
    cameraActive = false;
    std::cout << "[CAMERA] Camera stopped\n";
}

int main() {
    startCamera();

    detectObject("RED");
    detectObject("BLUE");
    detectObject("GREEN");

    cout << "Total object detected: " << objectCount << endl;

    stopCamera();

    return 0;
}
