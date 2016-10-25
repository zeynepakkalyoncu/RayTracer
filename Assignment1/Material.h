#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Color.h"
#include "Vector3.h"

class Scene;

class Material {
    //////////////////
    /// PUT YOUR VARIABLES, HELPER FUNCTIONS HERE !
    //////////////////
    int _materialID;
    Vector3 _ambient;
    Vector3 _diffuse;
    // specular - not vector3
    // TODO: fix
    Vector3 _specular;
    Vector3 _reflectance;
public:

    /*
     * Implement a Calculate function that does Diffuse, Specular and Ambient, Reflective shading
     */

    friend std::istream& operator>>(std::istream& stream, Material& mat);
    
    Material(int mid, Vector3 ambient,Vector3 diffuse, Vector3 specular, Vector3 reflectance) {
        _materialID = mid;
        _ambient = ambient;
        _diffuse = diffuse;
        _specular = specular;
        _reflectance = reflectance;
    }
};

using MaterialId = int;

#endif //RAYTRACER_MATERIAL_H