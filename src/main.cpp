#include <Arduino.h>
#include "Engine/Engine.hpp"

void setup() {
	Serial.begin(115200);

	Serial.println("[DEBUG] Loading: ");

	pinMode(RY1, OUTPUT);
	pinMode(RY2, OUTPUT);
	pinMode(RY3, OUTPUT);
	pinMode(RY4, OUTPUT);

	Serial.println("[DEBUG] Setup has complete!");
}

void loop() {
	RelaysController::UpdateRelaysState();
}