/// @file DualMotorControlIf.hpp
///
/// @note Copyright (c) 2023 slavek1250

#ifndef DUALMOTORCONTROL_DUALMOTORCONTROLIF_HPP
#define DUALMOTORCONTROL_DUALMOTORCONTROLIF_HPP

#include <cstdint>

namespace Device
{

namespace DualMotorControl
{

/// @brief Dual motor controller interface.
class DualMotorControlIf
{
public:
    /// @brief Default value for slow turn right/left ratio.
    static constexpr const uint8_t DEFAULT_SLOW_TURN_RATIO = 3U;

    virtual ~DualMotorControlIf()
    {
    }

    /// @brief Set speed.
    /// @param speed Speed value in range 0..100.
    virtual void SetSpeed(const uint8_t speed) = 0;

    /// @brief Set ratio of slowly turning right/left.
    /// @param ratio Ratio value, defaults to: DEFAULT_SLOW_TURN_RATIO.
    /// @see Device::DualMotorControl::DualMotorControlIf::DEFAULT_SLOW_TURN_RATIO
    virtual void SetSlowTurnRatio(const uint8_t ratio) = 0;

    /// @brief Move forward.
    virtual void Forward() = 0;

    /// @brief Move backward.
    virtual void Back() = 0;

    /// @brief Turn left.
    virtual void Left() = 0;

    /// @brief Turn right.
    virtual void Right() = 0;

    /// @brief Stop.
    virtual void Stop() = 0;

    /// @brief Move forward slowly turning right.
    virtual void ForwardRight() = 0;

    /// @brief Move backward slowly turning right.
    virtual void BackRight() = 0;

    /// @brief Move forward slowly turning left.
    virtual void ForwardLeft() = 0;

    /// @brief Move backward slowly turning left.
    virtual void BackLeft() = 0;
};

}

}

#endif
