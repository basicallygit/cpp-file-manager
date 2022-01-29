#ifdef _WIN32
#include <direct.h>
#define CD _chdir
#define WIND 1
#else
#include <unistd.h>
#define CD chdir
#define WIND 0
#endif