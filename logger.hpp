#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

namespace logger
{
    class Logger
    {
    public:
        Logger() : Logger(".log") {}
        Logger(std::string file_path) : file_path(file_path), log_file(file_path) {}

        void set_log_file_name(std::string name) { file_path = name; }
        void reopen() { log_file.open(file_path); }
        void reopen(std::string name)
        {
            file_path = name;
            reopen();
        }

        template <typename T>
        Logger &operator<<(T log)
        {
#ifdef LOGGING
            log_file << log;
#endif
            return *this;
        }

    private:
        std::string file_path = ".log";
        std::ofstream log_file = std::ofstream(file_path);
    };
}
#endif