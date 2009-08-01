#ifndef _INC_MATERIAL_H_
#define _INC_MATERIAL_H_

#include "Color.h"

class Material
{
public:
	Material() : refl( 0.0f ), diff( 0.2f ), col( sf::Color( 0.9f * 255, 0.2f * 255, 0.2f * 255, 255 ) ) {}; //pink if color not specified :)

	//Material( Color& col_ ) : col( sf::Color( col_.getRed() * 255, col_.getGreen() * 255, col_.getBlue() * 255, 255 ) ) {};
	//Material( Color& col_, float diff_ ) : col( sf::Color( col_.getRed() * 255, col_.getGreen() * 255, col_.getBlue() * 255, 255 ) ), diff( diff_ ) {};
	//Material( Color& col_, float diff_, float refl_ ) : col( sf::Color( col_.getRed() * 255, col_.getGreen() * 255, col_.getBlue() * 255, 255 ) ), diff( diff_ ), refl( refl_ ) {};

	//Material( Color col_ ) : col( sf::Color( col_.getRed() * 255, col_.getGreen() * 255, col_.getBlue() * 255, 255 ) ) {};
	//Material( Color col_, float diff_ ) : col( sf::Color( col_.getRed() * 255, col_.getGreen() * 255, col_.getBlue() * 255, 255 ) ), diff( diff_ ) {};
	//Material( Color col_, float diff_, float refl_ ) : col( sf::Color( col_.getRed() * 255, col_.getGreen() * 255, col_.getBlue() * 255, 255 ) ), diff( diff_ ), refl( refl_ ) {};

    //Material( sf::Color& col_ ) : col( sf::Color( col_.r, col_.g, col_.b, 255 ) ) {};
	//Material( sf::Color& col_, float diff_ ) : col( sf::Color( col_.r, col_.g, col_.b, 255 ) ), diff( diff_ ) {};
	//Material( sf::Color& col_, float diff_, float refl_ ) : col( sf::Color( col_.r, col_.g, col_.b, 255 ) ), diff( diff_ ), refl( refl_ ) {};

	Material( sf::Color col_ ) : col( sf::Color( col_.r, col_.g, col_.b, 255 ) ) {};
	Material( sf::Color col_, float diff_ ) : col( sf::Color( col_.r, col_.g, col_.b, 255 ) ), diff( diff_ ) {};
	Material( sf::Color col_, float diff_, float refl_ ) : col( sf::Color( col_.r, col_.g, col_.b, 255 ) ), diff( diff_ ), refl( refl_ ) {};

	void setColor( sf::Color col_ ) { col = col_; }
	void setColor( Color col_ ) { col = sf::Color( col_.getRed(), col_.getGreen(), col_.getBlue(), 255 ); }
	void setDiffusion( float diff_ ) { diff = diff_; }
	void setReflectivity( float refl_ ) { refl = refl_; }

	//Color& getColor() { return Color( col ); }
	sf::Color& getColor() { return col; }
	float getDiffusion() { return diff; }
	float getReflectivity() { return refl; }
	float getSpecular() { return 1.0f - diff; }

	void operator = ( const Material& rhs ) {}

private:
	sf::Color col;
	float refl;
	float diff;
};


#endif // _INC_MATERIAL_H_
