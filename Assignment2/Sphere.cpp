//
// Created by goksu on 30.10.2015.
//

#include "Sphere.h"
#include "Scene.h"
#include <cmath>

Sphere::Sphere(VertexId center, float radius, MaterialId material, TextureId texture)
{
    _center = center;
    _radius = radius;
    _material = material;
    _texture = texture;
}

Vector3 Sphere::Normal(const Vector3 &at) const
{
    return (at - _scene->GetVertex(_center).Position()) / _radius;
}

void Sphere::SetScene(const Scene *scene)
{
    _scene = scene;
}

bool Sphere::RayHit(const Ray& ray, RayHitInfo& hitInfo) const
{
    Vector3 line = ray.Origin() - _scene->GetVertex(_center).Position();        // (o - c)

    float B = 2 * (Vector3::Dot(ray.Direction(), line));                        // Dot(d, (o - c))
    float C = line.SquaredMagnitude() - (_radius * _radius);                   // Dot((o - c), (o - c)) - r^2

    float Delta = B * B - 4 * C;

    if (Delta < -0.00001f) {
        return false;
    }

	float root = (-B - std::sqrt(Delta)) / 2;

	hitInfo.Position = ray.Origin() + (root * ray.Direction());
    
    if (_texture != 0) {
        hitInfo.Color = _scene->GetTexture(_texture).Interpolate(hitInfo.Position, _scene->GetVertex(_center), _radius);
    }
    else {
        hitInfo.Color = Color(-1, -1, -1);
    }
    
    hitInfo.Material = _material;
    hitInfo.Parameter = root;
    
    return true;
}
