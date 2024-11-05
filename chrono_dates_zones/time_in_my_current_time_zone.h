#pragma once

#include <chrono>
#include <print>

namespace time_in_my_current_time_zone
{
    void run()
    {
        const auto now = std::chrono::system_clock::now();
        auto zt_local = std::chrono::zoned_time{ std::chrono::current_zone(), now};

        std::print("-------------- time_in_my_current_time_zone -------------------\n");

        constexpr std::string_view Warasaw{ "Europe/Warsaw" };
        constexpr std::string_view NewYork{ "America/New_York" };
        constexpr std::string_view Tokyo{ "Asia/Tokyo" };

        try
        {
            const std::chrono::zoned_time zt_w{ Warasaw, now };
            std::print("Warsaw: {0:%F} {0:%R}\n", zt_w);

            const std::chrono::zoned_time zt_ny{ NewYork, now };
            std::print("New York: {0:%F} {0:%R}\n", zt_ny);

            const std::chrono::zoned_time zt_t{ Tokyo, now };
            std::print("Tokyo: {0:%F} {0:%R}\n", zt_t);
        }
        catch (std::runtime_error& ex)
        {
            std::print("Error: {}", ex.what());
        }
        std::print("---------------------------------------------------------------\n");
    }
}