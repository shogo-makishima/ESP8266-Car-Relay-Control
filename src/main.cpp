#include <Arduino.h>
#include "Engine/Engine.hpp"

bool b_isComplete = false;
Timer relayTimer = Timer(10000, []{
	digitalWrite(RY4, LOW);
	b_isComplete = true;
});

void setup() {
	Serial.begin(115200);

	Serial.println("[DEBUG] Loading: ");

	pinMode(RY1, OUTPUT);
	pinMode(RY2, OUTPUT);
	pinMode(RY3, OUTPUT);
	pinMode(RY4, OUTPUT);

	digitalWrite(RY4, HIGH);

	Serial.println("[DEBUG] Setup has complete!");
}

void loop() {
	RelaysController::UpdateRelaysState();
	if (!b_isComplete) relayTimer.Update();
}