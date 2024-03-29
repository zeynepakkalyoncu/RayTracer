//
// Created by Fatih on 10/27/15.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Color.h"
#include "Vector3.h"

class Scene;

class Material {
    Color _ambient;
    Color _diffuse;
    Color _specular;
    size_t _phong;
    Color _reflectance;

public:

	static Material Diffuse(const Color& color);

    Color Calculate(const Vector3& normal, const Vector3 &pointOfIntersection, const Vector3& viewDirection, const Scene* scene, int hitCount, const Color* textureColor) const;
    void CalculateReflectance(Color &reflectedColor, const Vector3& normal, const Vector3 &rayDirection, const Vector3 &pointOfIntersection, const Scene* scene, int hitCount) const;

    friend std::istream& operator>>(std::istream& stream, Material& mat);
};

typedef size_t MaterialId;

#endif //RAYTRACER_MATERIAL_H
