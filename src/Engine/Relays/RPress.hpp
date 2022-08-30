#ifndef _RELAY_PRESS_H_
#define _RELAY_PRESS_H_

#include "Engine/Relays/Relay.hpp"
#include "Engine/Utils/Timer.hpp"
#include "Engine/Relays/Types.hpp"

class RPress : public Relay {
    private:
    public:
    /// Базовый конструктор
    RPress(short int pinNumber = 13) {
        m_type = RelayType::PRESS;

        this->pinNumber = pinNumber;
    }

    void Trigger() override {
        b_isComplete = false;
        b_isRunning = true;

        Serial.println("Press: " + String(pinNumber) + ";");
    }

    void Update() override {
        if (b_isRunning) {
            b_isComplete = true;
            b_isRunning = false;

            
        }
    }
};

#endif