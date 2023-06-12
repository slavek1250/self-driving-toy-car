/// @file CarControlCmd.hpp
///
/// @note Copyright (c) 2023 slavek1250

#ifndef CARCONTROLCMD_CARCONTROLCMD_HPP
#define CARCONTROLCMD_CARCONTROLCMD_HPP

namespace App
{

namespace CarControlCmd
{

/// @brief Car control commands.
struct Command
{
    enum Command_
    {
        FORWARD,
        BACK,
        LEFT,
        RIGHT,
        FORWARD_LEFT,
        FORWARD_RIGHT,
        BACK_LEFT,
        BACK_RIGHT,
        STOP,
        FRONT_LIGHTS_ON,
        FRONT_LIGHTS_OFF,
        BACK_LIGHTS_ON,
        BACK_LIGHTS_OFF,
        SET_SPEED
    };
};

}

}

#endif
