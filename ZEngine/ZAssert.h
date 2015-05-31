//-----------------------------------------------------------
// ZAssert.h
//---------------------------------------------------------

#include <cassert>

namespace ZEngine
{
#define ZASSERT(cond) assert(cond)

#define ZMEMORYASSERT(cond) assert(cond && "Could not allocate more MEMORY")

#define ZVALIDPOINTER(pointer) assert(pointer && "invalid POINTER")
}