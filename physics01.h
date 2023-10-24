
#ifndef PHYSICS01_H_
#define PHYSICS01_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef NDEBUG
#define _debugd(x) printf(#x ": %d\n", x)
#define _debugf(x) printf(#x ": %f\n", x)
#else // NDEBUG
#define _debugd(x)
#define _debugf(x)
#endif

#endif // PHYSICS01_H_
