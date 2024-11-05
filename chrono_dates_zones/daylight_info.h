#pragma once

#include <chrono>
#include <print>

namespace daylight_info
{
	void printInfo(std::chrono::sys_days sd, std::string_view zone)
	{
        auto zt_local = std::chrono::zoned_time{ "Europe/Warsaw", std::chrono::sys_days{sd} };
        auto info = zt_local.get_info();
        std::print("time info for {:%F} in {}: \nabbrev: {},\nbegin {}, end {}, \noffset {}, save {}\n",
            sd, zone, info.abbrev, info.begin, info.end, info.offset, info.save);
	}

    void run()
    {
        std::print("------------------- daylight_info ---------------------------\n");

        try
        {
            printInfo(std::chrono::year{ 2024 } / 9 / 14, "Europe/Warsaw");
            printInfo(std::chrono::year{ 2024 } / 11 / 14, "Europe/Warsaw");
        }
        catch (std::runtime_error& ex)
        {
            std::print("Error: {}", ex.what());
        }
        std::print("---------------------------------------------------------------\n");
    }

}

