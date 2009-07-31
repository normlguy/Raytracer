#ifndef _INC_VEC3_H_
#define _INC_VEC3_H_

#include <cmath>
#include <cstdlib>
#include <cassert>

class Vec3
{
public:
	// constructors
	Vec3() : x( 0.0f ), y( 0.0f ), z( 0.0f ) {};
	Vec3( float x, float y, float z ) : x( x ), y( y ), z( z ) {};
	Vec3( const Vec3& t ) : x( t.x ), y( t.y ), z( t.z ) {};

	float length() { return (float) sqrtf( x * x + y * y + z * z ); }
	float dot( Vec3& that ) { return x * that.x + y * that.y + z * that.z; }
	Vec3 cross( Vec3& that ) { return Vec3( y * that.z - z * that.y, z * that.x - x * that.z, x * that.y - y * that.x ); }
	Vec3 normalize() { float l = 1 / length(); return Vec3( x * l, y * l, z * l ); }

	void			operator =( const Vec3& rhs ) {}
	Vec3			operator -() const { return Vec3( -x, -y, -z ); }
	float		operator []( const int idx ) const { switch( idx ) { case 0: return x; case 1: return y; case 2: return z; default: return NULL; } }
	float		operator []( const char* idx ) const { if( idx == "x" ){ return x; } if( idx == "y" ){ return y; } if( idx == "z" ){ return z; } return NULL; }

	friend Vec3 operator + ( const Vec3& first, const Vec3& second ) { return Vec3( first.x + second.x, first.y + second.y, first.z + second.z ); }
	friend Vec3 operator - ( const Vec3& first, const Vec3& second ) { return Vec3( first.x - second.x, first.y - second.y, first.z - second.z ); }
	friend Vec3 operator + ( const Vec3& first, Vec3* second ) { return Vec3( first.x + second->x, first.y + second->y, first.z + second->z ); }
	friend Vec3 operator - ( const Vec3& first, Vec3* second ) { return Vec3( first.x - second->x, first.y - second->y, first.z - second->z ); }
	friend Vec3 operator * ( const Vec3& vec, float f ) { return Vec3( vec.x * f, vec.y * f, vec.z * f ); }
	friend Vec3 operator * ( const Vec3& first, Vec3& second ) { return Vec3( first.x * second.x, first.y * second.y, first.z * second.z ); }


private:
	const float x, y, z;
};

#endif // _INC_VEC3_H_
