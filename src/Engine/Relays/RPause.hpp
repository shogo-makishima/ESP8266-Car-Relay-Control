#ifndef _RELAY_PAUSE_H_
#define _RELAY_PAUSE_H_

#include "Engine/Relays/Relay.hpp"
#include "Engine/Utils/Timer.hpp"
#include "Engine/Relays/Types.hpp"

class RPause : public Relay {
    private:
    /// Таймер отвечающий за время удержания
    Timer beforeComplete;
    
    public:
    /// Базовый конструктор
    RPause(float holdTime = 2.0) {
        m_type = RelayType::PAUSE;

        beforeComplete = Timer(holdTime, [&] {
            b_isRunning = false;
            b_isComplete = true;

            Serial.println("End: " + String(holdTime));
            Serial.println();
        });
    }

    void Trigger() override {
        beforeComplete.Reset();
        b_isComplete = false;
        b_isRunning = true;

        Serial.println("Pause!");
    }

    void Update() override {
        if (b_isRunning) {
            beforeComplete.Update();
        }
    }
};

#endif