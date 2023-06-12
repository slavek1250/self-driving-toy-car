/// @file AndiCoBluetoothRcCarCmd.hpp
///
/// @note Copyright (c) 2023 slavek1250

#ifndef CARCONTROLCMD_ANDICOBLUETOOTHRCCARCMD_HPP
#define CARCONTROLCMD_ANDICOBLUETOOTHRCCARCMD_HPP

#include "CmdDecoderIf.hpp"

namespace App
{

namespace CarControlCmd
{

/// @brief Decoder of commands defined by https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller
class AndiCoBluetoothRcCarCmd :
    public CmdDecoderIf
{
public:
    /// @copydoc App::CarControlCmd::CmdDecoderIf::Decode()
    bool Decode(const int data, CarControlCmd::Command::Command_& rCmd, uint8_t& rData) const override;

private:
    uint8_t DecodeSpeed(const int data) const;
};

}

}

#endif
