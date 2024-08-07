#include "min.h"

float float_min(float a, float b) {
	if (b < a) {
		return b;
	}
	return a;
}
