#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>

class Logger
{
public:
    static void log(const std::string &msg)
    {
        std::ofstream out("debug.log", std::ios::app);
        out << msg << std::endl;
    }
};

#endif
