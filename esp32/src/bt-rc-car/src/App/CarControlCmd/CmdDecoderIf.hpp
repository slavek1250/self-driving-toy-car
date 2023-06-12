/// @file CmdDecoderIf.hpp
///
/// @note Copyright (c) 2023 slavek1250

#ifndef CARCONTROLCMD_CMDDECODERIF_HPP
#define CARCONTROLCMD_CMDDECODERIF_HPP

#include <cstdint>

#include "CarControlCmd.hpp"

namespace App
{

namespace CarControlCmd
{

/// @brief Commands decoder interface.
class CmdDecoderIf
{
public:
    /// @brief Decode raw data to car control command.
    /// @param data Data to decode.
    /// @param rCmd Decoded command code.
    /// @param rData Additional data the command caries, currently valid only for SET_SPEED.
    ///
    /// @retval true  Command decoded successfully.
    /// @retval false Command can not be decoded.
    virtual bool Decode(const int data, CarControlCmd::Command::Command_& rCmd, uint8_t& rData) const = 0;
};

}

}

#endif
