#include <iostream>
#include <string>
using namespace std;

std::string mode = "STABILIZE";
bool armed = false;
double x = 0, y = 0, z = 0;

void setMode(std::string modeBaru) {
    mode = modeBaru;
}

bool arm() {
    if (mode == "GUIDED") armed = true;
    return armed;
}

void takeOff(double alt) {
    if (armed) {
        z = alt;
        std::cout << "[TAKEOFF] Alt: " << z << "m\n";
    }
}

void moveDrone(double targetX, double targetY, std::string dir) {
    x = targetX;
    y = targetY;
    std::cout << "[MOVE " << dir << "] Pos: (" << x << ", " << y << ")\n";
}

void land() {
    setMode("LAND");
    z = 0;
    armed = false;
    std::cout << "[LANDED]\n";
}

int main() {
    setMode("GUIDED");

    if (arm()) {
        takeOff(5.0);
        moveDrone(0.0, 5.0, "MAJU 5M");
        moveDrone(6.0, 5.0, "KIRI 6M");
        moveDrone(6.0, -2.0, "MUNDUR 7M");
        land();
    }

    return 0;
}