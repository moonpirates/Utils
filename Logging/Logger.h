#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <mutex>

// Filename macro
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Log colors, grabbed from https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define __ANSI_COLOR_DEFAULT__ "\033[97m"
#define __ANSI_COLOR_WARNING__ "\033[33m"
#define __ANSI_COLOR_ERROR__ "\033[31m"
#define __ANSI_COLOR_DIMMED__ "\033[90m"
#define __ANSI_COLOR_FILE__ "\033[90m"

// Column width constants
#define __FILE_COLUMN_WIDTH__ 25
#define __LINE_NUMBER_COLUMN_WIDTH__ 5
#define __LOG_LEVEL_COLUMN_WIDTH__ 4

// Log levels
#define LOG_LEVEL_DEFAULT 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2
#define LOG_LEVEL_FRIENDLY_DEFAULT ""
#define LOG_LEVEL_FRIENDLY_WARNING "WARN"
#define LOG_LEVEL_FRIENDLY_ERROR "ERR"

// Log methods
#define LOG(message) LOG_INTERNAL(LOG_LEVEL_DEFAULT, message)
#define LOG_WARN(message) LOG_INTERNAL(LOG_LEVEL_WARNING, message)
#define LOG_ERROR(message) LOG_INTERNAL(LOG_LEVEL_ERROR, message)

// Global log methods
#define LOG_INTERNAL(logLevel, message) Utils::Logger::Log(logLevel, __FILENAME__, __LINE__, [](auto &out, int level, auto datetime, std::string filename, int line) \
{ \
    out << std::left \
    << GET_DIMMED_COLOR(level) << datetime \
    << GET_DIMMED_COLOR(level) << std::right << std::setw(__FILE_COLUMN_WIDTH__) << std::string(filename) \
    << GET_DIMMED_COLOR(level) << std::left << std::setw(__LINE_NUMBER_COLUMN_WIDTH__) << ":" + std::to_string(line) << " | "\
    << GET_LOG_COLOR(level) << std::right << std::setw(__LOG_LEVEL_COLUMN_WIDTH__) << GET_FRIENDLY_LOG_LEVEL(level) \
    << GET_DIMMED_COLOR(level) << " | " \
    << GET_LOG_COLOR(level) << message \
    << __ANSI_COLOR_DEFAULT__ \
    << std::endl; \
})

// Log level specific functions
#define GET_LOG_COLOR(level) ((level) == LOG_LEVEL_ERROR ? __ANSI_COLOR_ERROR__ : (level) == LOG_LEVEL_WARNING ? __ANSI_COLOR_WARNING__ \
	: __ANSI_COLOR_DEFAULT__)
#define GET_DIMMED_COLOR(level) (level == LOG_LEVEL_DEFAULT ? __ANSI_COLOR_DIMMED__ : GET_LOG_COLOR(level))
#define GET_FRIENDLY_LOG_LEVEL(level) ((level) == LOG_LEVEL_ERROR ? LOG_LEVEL_FRIENDLY_ERROR : (level) == LOG_LEVEL_WARNING ? \
	LOG_LEVEL_FRIENDLY_WARNING : LOG_LEVEL_FRIENDLY_DEFAULT)

namespace Utils
{
    class Logger
    {
    public:
        
        static void Init(int logLevel, bool useColors)
        {
            Utils::Logger::logLevel = logLevel;
            Utils::Logger::useColors = useColors;
        }
        
        template<typename T>
        static void Log(int level, std::string filename, int line, T message)
        {
            auto now = std::chrono::system_clock::now();
            std::time_t time_now = std::chrono::system_clock::to_time_t(now);
            std::tm t;
            
            // Multi-compiler solution from: https://stackoverflow.com/a/38034148
#if defined(__unix__)
			localtime_r(&time_now, &t);
#elif defined(_MSC_VER)
			localtime_s(&t, &time_now);
#else
			static std::mutex mtx;
			std::lock_guard<std::mutex> lock(mtx);
			t = *std::localtime(&time_now);
#endif

            auto datetime = std::put_time(&t, "%Y-%m-%d %H:%M:%S");
            message(std::cout, level, datetime, filename, line);
        }
    
    private:
        inline static int logLevel = 0;
        inline static bool useColors = true;
    };

}
