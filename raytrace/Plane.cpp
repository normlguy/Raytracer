#include "def.h"
#include "Plane.h"

int Plane::intersect( Ray &r, float &dist)
{
	float d = r.getDirection().dot( normal );

	if( d == 0 ) return MISS;

	float dist_ = -( normal.dot( r.getOrigin() ) + D ) / d;

	if( dist_ > 0 && dist_ < dist )
	{
		dist = dist_;
		return HIT;
	}

	return MISS;

}