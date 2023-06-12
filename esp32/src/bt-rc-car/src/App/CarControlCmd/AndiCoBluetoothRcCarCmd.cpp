/// @file AndiCoBluetoothRcCarCmd.cpp
///
/// @note Copyright (c) 2023 slavek1250

#include "AndiCoBluetoothRcCarCmd.hpp"

namespace App
{

namespace CarControlCmd
{

bool AndiCoBluetoothRcCarCmd::Decode(const int data, CarControlCmd::Command::Command_& rCmd, uint8_t& rData) const
{
    bool result = false;
    rCmd = Command::STOP;
    rData = 0U;

    switch (data)
    {
    case static_cast<int>('F'):
        rCmd = Command::FORWARD;
        result = true;
        break;
    case static_cast<int>('B'):
        rCmd = Command::BACK;
        result = true;
        break;
    case static_cast<int>('L'):
        rCmd = Command::LEFT;
        result = true;
        break;
    case static_cast<int>('R'):
        rCmd = Command::RIGHT;
        result = true;
        break;
    case static_cast<int>('S'):
        rCmd = Command::STOP;
        result = true;
        break;
    case static_cast<int>('I'):
        rCmd = Command::FORWARD_RIGHT;
        result = true;
        break;
    case static_cast<int>('J'):
        rCmd = Command::BACK_RIGHT;
        result = true;
        break;
    case static_cast<int>('G'):
        rCmd = Command::FORWARD_LEFT;
        result = true;
        break;
    case static_cast<int>('H'):
        rCmd = Command::BACK_LEFT;
        result = true;
        break;
    case static_cast<int>('W'):
        rCmd = Command::FRONT_LIGHTS_ON;
        result = true;
        break;
    case static_cast<int>('w'):
        rCmd = Command::FRONT_LIGHTS_OFF;
        result = true;
        break;
    case static_cast<int>('U'):
        rCmd = Command::BACK_LIGHTS_ON;
        result = true;
        break;
    case static_cast<int>('u'):
        rCmd = Command::BACK_LIGHTS_OFF;
        result = true;
        break;
    case static_cast<int>('0'):
    case static_cast<int>('1'):
    case static_cast<int>('2'):
    case static_cast<int>('3'):
    case static_cast<int>('4'):
    case static_cast<int>('5'):
    case static_cast<int>('6'):
    case static_cast<int>('7'):
    case static_cast<int>('8'):
    case static_cast<int>('9'):
    case static_cast<int>('q'):
        rCmd = Command::SET_SPEED;
        rData = DecodeSpeed(data);
        result = true;
        break;
    default:
        break;
    }

    return result;
}

uint8_t AndiCoBluetoothRcCarCmd::DecodeSpeed(const int data) const
{
    uint8_t speed = 0U;

    if (data == static_cast<int>('q'))
    {
        speed = 100U;
    }
    else if (static_cast<int>('0') <= data && data <= static_cast<int>('9'))
    {
        speed = (static_cast<uint8_t>(data) - static_cast<uint8_t>('0')) * 10U;
    }
    else
    {
    }

    return speed;
}

}

}
