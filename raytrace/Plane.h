#ifndef _INC_PLANE_H_
#define _INC_PLANE_H_

#include "Primitive.h"
#include "Vec3.h"
#include "Ray.h"

class Plane : public Primitive
{
public:
	Plane( Vec3& normal_, float D_ ) : normal( normal_ ), D( D_ ) {};
	Plane( Vec3 normal_, float D_ ) : normal( normal_ ), D( D_ ) {};
	~Plane() {};

	PrimType getType() { return PLANE; }
	Vec3 getNormal() { return normal; }
	Vec3 getNormal( Vec3& pos ) { return normal; }
	float getD() { return D; }

	int intersect( Ray& r, float& dist );

private:
	Vec3 normal;
	float D;

};

#endif // _INC_PLANE_H_
