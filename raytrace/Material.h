#ifndef _INC_MATERIAL_H_
#define _INC_MATERIAL_H_

#include "Color.h"

class Material
{
public:
	Material() : refl( 0.0f ), diff( 0.2f ), col( Color( 0.9f, 0.2f, 0.2f ) ) {}; //pink if color not specified :)
	Material( Color& col_ ) : col( Color( col_.getRed(), col_.getGreen(), col_.getBlue() ) ) {};
	Material( Color& col_, float diff_ ) : col( Color( col_.getRed(), col_.getGreen(), col_.getBlue() ) ), diff( diff_ ) {};
	Material( Color& col_, float diff_, float refl_ ) : col( Color( col_.getRed(), col_.getGreen(), col_.getBlue() ) ), diff( diff_ ), refl( refl_ ) {};
	Material( Color col_ ) : col( Color( col_.getRed(), col_.getGreen(), col_.getBlue() ) ) {};
	Material( Color col_, float diff_ ) : col( Color( col_.getRed(), col_.getGreen(), col_.getBlue() ) ), diff( diff_ ) {};
	Material( Color col_, float diff_, float refl_ ) : col( Color( col_.getRed(), col_.getGreen(), col_.getBlue() ) ), diff( diff_ ), refl( refl_ ) {};


	void setColor( Color col_ ) { col = col_; }
	void setDiffusion( float diff_ ) { diff = diff_; }
	void setReflectivity( float refl_ ) { refl = refl_; }

	Color& getColor() { return col; }
	float getDiffusion() { return diff; }
	float getReflectivity() { return refl; }
	float getSpecular() { return 1.0f - diff; }

	void operator = ( const Material& rhs ) {}

private:
	Color col;
	float refl;
	float diff;
};


#endif // _INC_MATERIAL_H_
