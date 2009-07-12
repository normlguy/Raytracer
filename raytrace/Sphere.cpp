#include <cmath>

#include "def.h"
#include "Sphere.h"
#include "Debug.h"

int Sphere::intersect( Ray& r, float& dist )
{
	Vec3 v = r.getOrigin() - center;

	float b = -v.dot( r.getDirection() );
	float det = ( b * b ) - v.dot( v ) + sq_radius;

	int ret = MISS;

	if( det > 0 )
	{
		det = sqrtf( det );

		float sol1 = b - det;
		float sol2 = b + det;

		if( sol2 > 0 )
		{
			if( sol1 < 0 )
			{
				if( sol2 < dist )
				{
					dist = sol2;
					ret = INPRIM;
				}
			}
			else
			{
				if( sol1 < dist )
				{
					dist = sol1;
					ret = HIT;
				}
			}
		}
	}
	return ret;
}