#include "polygon.h"
#include <fstream>

void PolyToSVG(const polygon& a, const polygon& b, const polygon& abInter, const string &file)
    {
        ofstream out(file);
        out << "<svg xmlns='http://www.w3.org/2000/svg' width='500' height='500' "
            << "viewBox='0 0 500 500'>\n";
        auto draw = [&](const polygon &c, const string &color)
        {
            out << "<polygon points='";
            for (int i = 0; i < c.size(); i++)
                out << (c[i].x * 100) << "," << (500 - c[i].y * 100) << " ";
            out << "' fill='" << color << "' fill-opacity='0.5' "
            << "stroke='" << color << "' stroke-width='2'/>\n";
        };
        draw(a,"blue");
        draw(b, "green");
            for (int i = 0; i < abInter.size(); i++)
        out << "<circle cx='" << (abInter[i].x * 100)
            << "' cy='" << (500 - abInter[i].y * 100)
            << "' r='4' fill='red'/>\n";
        out << "</svg>\n";
    }
