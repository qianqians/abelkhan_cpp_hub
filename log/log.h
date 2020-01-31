/*
 * log.h
 *
 *  Created on: 2020-1-27
 *      Author: qianqians
 */
#ifndef _log_h
#define _log_h

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace _log {

inline void InitLog(std::string file_path, spdlog::level::level_enum log_level) {
    spdlog::set_level(log_level);
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    auto file_logger = spdlog::basic_logger_mt("basic_logger", file_path);
    spdlog::set_default_logger(file_logger);
}

} /* namespace log */

#endif //_log_h
