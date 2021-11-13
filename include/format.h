#ifndef FORMAT_H
#define FORMAT_H

#include <string>

namespace Format {
std::string ElapsedTime(long times);
std::string FormatString(std::string s, int targetSize);
};                                    // namespace Format

#endif