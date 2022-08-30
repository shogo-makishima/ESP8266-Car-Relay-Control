#ifndef _RELAYS_CONTROLLER_H_
#define _RELAYS_CONTROLLER_H_

#include "Engine/Relays/Relay.hpp"

#define RY1 16
#define RY2 14
#define RY3 12
#define RY4 13

namespace RelaysController {
    /// Список действий над реле
    Relay* RELAYS_LIST[32] = {
        new RPause(4000),
        new RHold(100, RY1),
        new RPause(500),
        new RHold(100, RY2),
        new RPause(500),
        new RHold(100, RY3),
        new RPause(500),
        NULL
    };
    /// Текущее действие над реле
    short int currentRelayIndex = 0;

    void UpdateRelaysState() {
        Relay* currentRelay = RELAYS_LIST[currentRelayIndex];
        if (currentRelay == NULL) return;

        if (!currentRelay->b_isRunning)
            currentRelay->Trigger();
        if (!currentRelay->b_isComplete)
            currentRelay->Update();

        if (currentRelay->b_isComplete)
            currentRelayIndex++;
    }
};



#endif

