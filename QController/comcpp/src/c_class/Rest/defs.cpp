#include "defs.h"

void sleep(int ms)
{
#ifdef __linux__
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, nullptr);
#else
    std::ignore = ms;
#endif
}
