/// @file L298n.hpp
///
/// @note Copyright (c) 2023 slavek1250

#ifndef DUALMOTORCONTROL_L298N_HPP
#define DUALMOTORCONTROL_L298N_HPP

#include "DualMotorControlIf.hpp"

namespace Device
{

namespace DualMotorControl
{

/// @brief Driver class for L298N dual H-bridge motor driver.
class L298n :
    public DualMotorControlIf
{
public:
    L298n(const uint8_t motorDirection1PinA,
          const uint8_t motorDirection2PinA,
          const uint8_t motorSpeedPinA,
          const uint8_t motorDirection1PinB,
          const uint8_t motorDirection2PinB,
          const uint8_t motorSpeedPinB);

    bool Init();

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::SetSpeed()
    void SetSpeed(const uint8_t speed) override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::SetSlowTurnRatio()
    void SetSlowTurnRatio(const uint8_t ratio) override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::Forward()
    void Forward() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::Back()
    void Back() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::Left()
    void Left() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::Right()
    void Right() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::Stop()
    void Stop() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::ForwardRight()
    void ForwardRight() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::BackRight()
    void BackRight() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::ForwardLeft()
    void ForwardLeft() override;

    /// @copydoc Device::DualMotorControl::DualMotorControlIf::BackLeft()
    void BackLeft() override;

private:
    void SetMotorA(const bool forward, const uint8_t speed);
    void SetMotorB(const bool forward, const uint8_t speed);
    uint8_t ScaleSpeed(const uint8_t speed);

    const uint8_t m_MotorDirection1PinA;
    const uint8_t m_MotorDirection2PinA;
    const uint8_t m_MotorSpeedPinA;
    const uint8_t m_MotorDirection1PinB;
    const uint8_t m_MotorDirection2PinB;
    const uint8_t m_MotorSpeedPinB;
    uint8_t m_Speed;
    uint8_t m_SlowTurnSpeed;
    uint8_t m_SlowTurnRatio;
};

}

}

#endif
