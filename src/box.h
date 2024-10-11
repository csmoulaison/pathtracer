#pragma once
#include "vector.h"

// Axis aligned bounding box
struct Box {
   struct Vec3 min;
   struct Vec3 max;
};
