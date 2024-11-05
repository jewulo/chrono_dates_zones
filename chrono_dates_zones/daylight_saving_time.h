#pragma once

#include <chrono>
#include <print>

namespace daylight_saving_time
{
    void run()
    {

        std::print("-------------- daylight_saving_time -------------------\n");

        try
        {
            const auto now = std::chrono::floor<std::chrono::minutes>(std::chrono::system_clock::now());
            auto zt_local = std::chrono::zoned_time{ "Europe/Warsaw", now };
            std::print("now is {} UTC and Warsaw is: {}\n", now, zt_local);

            auto info = zt_local.get_info();
            std::print("local time info: \nabbrev: {},\n begin {}, end {}, \n offset {}, save {}\n",
                info.abbrev, info.begin, info.end, info.offset, info.save);
        }
        catch (std::runtime_error& ex)
        {
            std::print("Error: {}", ex.what());
        }
        std::print("---------------------------------------------------------------\n");
    }
}