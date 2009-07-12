#ifndef _INC_PRIMITIVE_H_
#define _INC_PRIMITIVE_H_

#include <string>

#include "Vec3.h"
#include "Ray.h"
#include "Material.h"

typedef const unsigned int PrimType;

class Primitive
{
public:
	static PrimType SPHERE = 0;
	static PrimType PLANE = 1;

	//ctor
	Primitive() : light( false ) {}

	//dtor
	virtual ~Primitive()
	{
		delete mat;
	}

	// concrete methods
	void setMaterial( Material* mat_ ) { mat = mat_; }

	virtual Primitive* setColor( Color& col ) { if( !mat ) return NULL; mat->setColor( col ); return this; }
	virtual Primitive* setReflectivity( float ref ) { if( !mat ) return NULL; mat->setReflectivity( ref ); return this; }
	virtual Primitive* setDiffusion( float diff ) { if( !mat ) return NULL; mat->setDiffusion( diff ); return this; }

	virtual Color& getColor() { return mat->getColor(); }
	virtual float getDiffusion() { return mat->getDiffusion(); }
	virtual float getReflectivity() { return mat->getReflectivity(); }
	virtual float getSpecular() { return mat->getSpecular(); }

	bool isLight() { return light; }
	void setLight( bool light_ ) { light = light_; }
	void setName( std::string newName ) { name = newName; }
	const std::string& getName() { return name; }

	// virtual methods
	virtual PrimType getType() = 0;
	virtual int intersect( Ray& r, float& dist ) = 0;
	virtual Vec3 getNormal( Vec3& pos ) = 0;


protected:
	Material* mat;
	std::string name;
	bool light;

};



#endif //_INC_PRIMITIVE_H_
