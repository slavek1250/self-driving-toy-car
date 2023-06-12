/// @file L298n.cpp
///
/// @note Copyright (c) 2023 slavek1250

#include "Arduino.h"

#include "L298n.hpp"

namespace Device
{

namespace DualMotorControl
{

L298n::L298n(const uint8_t motorDirection1PinA,
             const uint8_t motorDirection2PinA,
             const uint8_t motorSpeedPinA,
             const uint8_t motorDirection1PinB,
             const uint8_t motorDirection2PinB,
             const uint8_t motorSpeedPinB) :
    m_MotorDirection1PinA(motorDirection1PinA),
    m_MotorDirection2PinA(motorDirection2PinA),
    m_MotorSpeedPinA(motorSpeedPinA),
    m_MotorDirection1PinB(motorDirection1PinB),
    m_MotorDirection2PinB(motorDirection2PinB),
    m_MotorSpeedPinB(motorSpeedPinB),
    m_Speed(0u),
    m_SlowTurnSpeed(0U),
    m_SlowTurnRatio(DEFAULT_SLOW_TURN_RATIO)
{
}

bool L298n::Init()
{
    pinMode(m_MotorDirection1PinA, OUTPUT);
    pinMode(m_MotorDirection2PinA, OUTPUT);
    pinMode(m_MotorSpeedPinA, OUTPUT);
    pinMode(m_MotorDirection1PinB, OUTPUT);
    pinMode(m_MotorDirection2PinB, OUTPUT);
    pinMode(m_MotorSpeedPinB, OUTPUT);
    return true;
}

void L298n::SetSpeed(const uint8_t speed)
{
    m_Speed = ScaleSpeed(speed);
    m_SlowTurnSpeed = m_Speed / m_SlowTurnRatio;
}

void L298n::SetSlowTurnRatio(const uint8_t ratio)
{
    m_SlowTurnRatio = ratio;
    m_SlowTurnSpeed = m_Speed / m_SlowTurnRatio;
}

void L298n::Forward()
{
    SetMotorA(true, m_Speed);
    SetMotorB(true, m_Speed);
}

void L298n::Back()
{
    SetMotorA(false, m_Speed);
    SetMotorB(false, m_Speed);
}

void L298n::Left()
{
    SetMotorA(false, m_Speed);
    SetMotorB(true, m_Speed);
}

void L298n::Right()
{
    SetMotorA(true, m_Speed);
    SetMotorB(false, m_Speed);
}

void L298n::Stop()
{
    SetMotorA(true, 0U);
    SetMotorB(true, 0U);
}

void L298n::ForwardRight()
{
    SetMotorA(true, m_Speed);
    SetMotorB(true, m_SlowTurnSpeed);
}

void L298n::BackRight()
{
    SetMotorA(false, m_Speed);
    SetMotorB(false, m_SlowTurnSpeed);
}

void L298n::ForwardLeft()
{
    SetMotorA(true, m_SlowTurnSpeed);
    SetMotorB(true, m_Speed);
}

void L298n::BackLeft()
{
    SetMotorA(false, m_SlowTurnSpeed);
    SetMotorB(false, m_Speed);
}

void L298n::SetMotorA(const bool forward, const uint8_t speed)
{
    analogWrite(m_MotorSpeedPinA, speed);
    digitalWrite(m_MotorDirection1PinA, static_cast<uint8_t>(!forward));
    digitalWrite(m_MotorDirection2PinA, static_cast<uint8_t>(forward));
}

void L298n::SetMotorB(const bool forward, const uint8_t speed)
{
    analogWrite(m_MotorSpeedPinB, speed);
    digitalWrite(m_MotorDirection1PinB, static_cast<uint8_t>(!forward));
    digitalWrite(m_MotorDirection2PinB, static_cast<uint8_t>(forward));
}

uint8_t L298n::ScaleSpeed(const uint8_t speed)
{
    constexpr const uint8_t MAX_SPEED = 100U;
    constexpr const uint8_t MAX_SCALED_SPEED = 255U;
    uint8_t scaledSpeed = 0U;

    if (speed >= 100U)
    {
        scaledSpeed = MAX_SCALED_SPEED;
    }
    else
    {
        const uint16_t newSpeedU16 =
            static_cast<uint16_t>(speed) * static_cast<uint16_t>(MAX_SCALED_SPEED) / static_cast<uint16_t>(MAX_SPEED);
        scaledSpeed = static_cast<uint8_t>(newSpeedU16);
    }

    return scaledSpeed;
}

}

}
