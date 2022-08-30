#ifndef _RELAY_HOLD_H_
#define _RELAY_HOLD_H_

#include "Engine/Relays/Relay.hpp"
#include "Engine/Utils/Timer.hpp"
#include "Engine/Relays/Types.hpp"

class RHold : public Relay {
    private:
    /// Таймер отвечающий за время удержания
    Timer beforeComplete;
    
    public:
    /// Базовый конструктор
    RHold(float holdTime = 2.0, short int pinNumber = 13) {
        m_type = RelayType::HOLD;

        this->pinNumber = pinNumber;

        beforeComplete = Timer(holdTime, [&] {
            b_isRunning = false;
            b_isComplete = true;

            ChangeRelayState(LOW);

            Serial.println("End: " + String(holdTime));
            Serial.println();
        });
    }

    void ChangeRelayState(bool state) {
        digitalWrite(pinNumber, state);        
    }

    void Trigger() override {
        beforeComplete.Reset();
        b_isComplete = false;
        b_isRunning = true;

        ChangeRelayState(HIGH);

        Serial.println("Hold!");
    }

    void Update() override {
        if (b_isRunning) {
            beforeComplete.Update();
        }
    }
};

#endif