#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <iostream>

class Color {
    float _channels[3];

public:
    Color();
    Color(float r, float g, float b);

    float R() const
    {
        return _channels[0];
    }

    float G() const
    {
        return _channels[1];
    }

    float B() const
    {
        return _channels[2];
    }

    Color operator*(float c) const
    {
        return Color(_channels[0] * c,
                     _channels[1] * c,
                     _channels[2] * c);
    }
    
    const float* Channels() const {
        return _channels;
    }

    Color operator/(float denom) const
    {
        return (*this) * (1 / denom);
    }
    
    friend Color operator+(const Color& lhs, const Color& rhs)
    {
        return Color(lhs._channels[0] + rhs._channels[0],
                     lhs._channels[1] + rhs._channels[1],
                     lhs._channels[2] + rhs._channels[2]);
    }

    friend std::istream& operator>>(std::istream& stream, Color& color);
};


inline Color::Color()
{
    _channels[0] = _channels[1] = _channels[2] = 0;
}

inline Color::Color(float r, float g, float b) {
    _channels[0] = std::max(0.0f, std::min(255.0f, r));
    _channels[1] = std::max(0.0f, std::min(255.0f, g));
    _channels[2] = std::max(0.0f, std::min(255.0f, b));
}

inline std::istream &operator>>(std::istream &stream, Color &color) {
    return stream >> color._channels[0] >> color._channels[1] >> color._channels[2];
}


#endif //RAYTRACER_COLOR_H
