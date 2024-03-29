//
// Created by Fatih on 10/27/15.
//

#ifndef RAYTRACER_VERTEX_H
#define RAYTRACER_VERTEX_H

#include "Vector3.h"

class Vertex {
    Vector3 _position;

public:
    Vertex() = default;
    explicit Vertex(Vector3 position);

    inline const Vector3& Position() const
    {
        return _position;
    }

    friend std::istream& operator>>(std::istream& stream, Vertex& vertex);
    
    bool operator==(const Vertex &vertex) const;
    
    bool operator!=(const Vertex &vertex) const;
};

typedef size_t VertexId;

#endif //RAYTRACER_VERTEX_H
