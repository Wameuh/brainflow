#pragma once

#include <string>
#include <tuple>

#include "brainflow_constants.h"

// we pass this structure from user API as a json string
struct BrainFlowInputParams
{
    std::string serial_port;
    std::string mac_address;
    std::string ip_address;
    int ip_port;
    int ip_protocol;
    std::string other_info;
    int timeout;
    std::string serial_number;
    std::string file;
    int preset;
    int master_board;

    BrainFlowInputParams ()
    {
        serial_port = "";
        mac_address = "";
        ip_address = "";
        ip_port = 0;
        ip_protocol = 0;
        other_info = "";
        timeout = 0;
        serial_number = "";
        file = "";
        preset = (int)BrainFlowPresets::DEFAULT_PRESET;
        master_board = (int)BoardIds::NO_BOARD;
    }

    // default copy constructor and assignment operator are ok, need less operator to use in map
    bool operator< (const struct BrainFlowInputParams &other) const
    {
        return std::tie (serial_port, mac_address, ip_address, ip_port, ip_protocol, other_info,
                   timeout, serial_number, file, preset,
                   master_board) < std::tie (other.serial_port, other.mac_address, other.ip_address,
                                       other.ip_port, other.ip_protocol, other.other_info, timeout,
                                       serial_number, file, preset, master_board);
    }

    bool operator> (const struct BrainFlowInputParams &other) const
    {
        return (!(*this < other)) && ((*this != other));
    }

    bool operator== (const struct BrainFlowInputParams &other) const
    {
        return (!(*this < other)) && (!(other < *this));
    }

    bool operator!= (const struct BrainFlowInputParams &other) const
    {
        return !(*this == other);
    }
};
