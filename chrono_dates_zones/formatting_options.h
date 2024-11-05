#pragma once

#include <chrono>
#include <print>

namespace formatting_options
{
	void run()
	{
        auto now = std::chrono::system_clock::now();

        std::print("-------------- formatting_options -------------------\n"); 
        std::print("now is {}\n", now);
        std::print("Full date and times: {0:%Y-%m-%d %H:%M:%S}\n", now);
        std::print("Date only: {0:%F}\n", now);
        std::print("Time only: {0:%T}\n", now);
        std::print("Day of the week: {0:%A}\n", now);
        std::print("Month name: {0:%B}\n", now);
        std::print("12-hour clock with AM/PM: {0:%I:%M:%S %p}\n", now);
        std::print("ISO 8601 format: {0:%FT%T%z}\n", now);
        std::print("-----------------------------------------------------\n");
	}
}
