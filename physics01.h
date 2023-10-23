
#ifndef PHYSICS01_H_
#define PHYSICS01_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef NDEBUG
#define _debugd(x) printf(#x ": %d\n", x)
#else // NDEBUG
#define _debugd(x)
#endif

#endif // PHYSICS01_H_
