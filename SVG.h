#ifndef SVG_H
#define SVG_H

#include "polygon.h"
#include <string>

void PolyToSVG(const polygon& a, const polygon& b, const polygon& abInter, const string& file);

#endif
