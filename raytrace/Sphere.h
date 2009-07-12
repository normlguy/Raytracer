#ifndef _INC_SPHERE_H_
#define _INC_SPHERE_H_

#include "Primitive.h"
#include "Vec3.h"
#include "Ray.h"

class Sphere : public Primitive
{
public:
	Sphere( Vec3& center_, float radius_ ) :
		center( center_ ), radius( radius_ ),
		sq_radius( radius_ * radius_ ), recip_radius( 1.0f / radius_ ) {};
    Sphere( Vec3 center_, float radius_ ) :
		center( center_ ), radius( radius_ ),
		sq_radius( radius_ * radius_ ), recip_radius( 1.0f / radius_ ) {};
	~Sphere() {};

	PrimType getType() { return SPHERE; }
	Vec3& getCenter() { return center; }
	float getSqRadius() { return sq_radius; }
	float getRadius() { return radius; }
	Vec3 getNormal( Vec3& pos ) { return (pos - center) * recip_radius; }

	int intersect( Ray& r, float& dist );

private:
	Vec3 center;
	float radius, sq_radius, recip_radius;

};

#endif // _INC_SPHERE_H_
