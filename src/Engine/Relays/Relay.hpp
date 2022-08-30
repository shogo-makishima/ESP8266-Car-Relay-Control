#ifndef _RELAY_H_
#define _RELAY_H_

#include "Engine/Relays/Types.hpp"

/// Базовый класс реле
struct Relay {
    private:
    public:
    /// Тип реле
    RelayType m_type = RelayType::NONE;
    /// Завершено ли замыкание реле
    bool b_isComplete = false;
    /// Запущен ли скрипт реле
    bool b_isRunning = false;
    /// Текущий пин
    short int pinNumber = 0;

    /// Триггер замыкания реле
    virtual void Trigger() {
        Serial.println("BASE TRIGGER!");
    }

    /// Функция обновления
    virtual void Update() { }
};

#endif