//
// Created by Fatih on 10/30/15.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <iostream>

class Color {
    float _channels[3];

public:
    Color();
    Color(float r, float g, float b);
    
    Color(const Color& rhs);

    inline float R() const
    {
        return _channels[0];
    }

    inline float G() const
    {
        return _channels[1];
    }

    inline float B() const
    {
        return _channels[2];
    }

    inline Color operator*(float c) const
    {
        Color col = *this;

        col._channels[0] *= c;
        col._channels[1] *= c;
        col._channels[2] *= c;

        return col;
    }

    inline Color operator/(float denom) const
    {
        return (*this) * (1 / denom);
    }

    friend std::istream& operator>>(std::istream& stream, Color& color);

    void Clamp();
    
};

#endif //RAYTRACER_COLOR_H
