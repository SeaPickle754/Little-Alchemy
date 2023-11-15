// this file only should exist in debug mode
#pragma once
// in release you have to delete this:
#define MODE_DEBUG

#ifdef MODE_DEBUG
#include <stdio.h>
#define msg(m) printf("ENGINE: %s", m)
#define value(m) printf("ENGINE: %d", m)






#endif // MODE_DEBUG
