
#ifndef _INC_RAY_H_
#define _INC_RAY_H_

#include "Vec3.h"

class Ray
{

public:
	Ray() : origin( Vec3( 0, 0, 0 ) ), direction( Vec3( 0, 0, 0 ) ) {};
	Ray( Vec3& origin_, Vec3& dir_ ) : origin( origin_ ), direction( dir_ ) {};

	void setOrigin( Vec3& origin_ ) { origin = origin_; }
	void setDirection( Vec3& dir_ ) { direction = dir_; }

	Vec3& getOrigin() { return origin; }
	Vec3& getDirection() { return direction; }


private:
	Vec3 origin;
	Vec3 direction;

};

#endif // _INC_RAY_H_