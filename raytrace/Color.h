#ifndef _INC_COLOR_H_
#define _INC_COLOR_H_

#include "def.h"
#include <cassert> // assert
#include <algorithm> // min, max

#include <SFML/Graphics/Color.hpp>

using std::min;
using std::max;

class Color
{
public:
	//Color() : r( 0 ), g( 0 ), b( 0 ) {};
	//Color() { col = sf::Color( 0, 0, 0, 255 ); }
	//Color( const Color& col ) : r( col.getRed() ), g( col.getGreen() ), b( col.getBlue() ) {}
	//Color( int r_, int b_, int g_ ) : r( r_ ), g( g_ ), b( b_ ) {}
    //Color( float r, float g, float b ) { col = sf::Color( r * 255, g * 255, b * 255, 255 ); }
    //Color( float r, float g, float b, float a ) { col = sf::Color( r * 255, g * 255, b * 255, a * 255 ); }

	float getRed() const { return col.r; }
	float getGreen() const { return col.g; }
	float getBlue() const { return col.b; }

	//friend Color operator + ( const Color& col1, const Color& col2 ) { return Color( col1.r + col2.r, col1.g + col2.g, col1.b + col2.b ); }
	//friend Color operator - ( const Color& col1, const Color& col2 ) { return Color( col1.r - col2.r, col1.g - col2.g, col1.b - col2.b ); }
	//friend Color operator * ( const Color& col1, float f ) { return Color( col1.r * f, col1.g * f, col1.b *f ); }
	//friend Color operator * ( const Color& col1, const Color& col2 ) { return Color( col1.r * col2.r, col1.g * col2.g, col1.b * col2.b ); }
	//friend Color operator * ( float f, const Color& col1 ) { return Color( col1.r * f, col1.g * f, col1.b *f ); }

	//friend Color operator + ( const Color& col1, const Color& col2 ) { return Color( col1.r + col2.r, col1.g + col2.g, col1.b + col2.b ); }
	//friend Color operator - ( const Color& col1, const Color& col2 ) { return Color( col1.r - col2.r, col1.g - col2.g, col1.b - col2.b ); }
	friend sf::Color operator * ( const sf::Color& col1, float f ) { return sf::Color( col1.r * f, col1.g * f, col1.b * f, 255 ); }

	friend sf::Color operator * ( const sf::Color& col1, const sf::Color& col2 )
	{
        sf::Color col = col1;
        col *= col2;

        return col;
    }

	friend sf::Color operator * ( float f, const sf::Color& col1 ) { return sf::Color( col1.r * f, col1.g * f, col1.b * f, 255 ); }

	//Color operator + ( const Color& col1 ) { return Color( col1.r + r, col1.g + g, col1.b + b ); }
	//Color operator - ( const Color& col1 ) { return Color( col1.r - r, col1.g - g, col1.b - b ); }
	//Color operator * ( float f ) { return Color( r * f, g * f, b *f ); }
	//Color operator * ( const Color& col1 ) { return Color( col1.r * r, col1.g * g, col1.b * b ); }


	Color& operator += ( const Color& col1 ) { r += col1.r, g += col1.g, b += col1.b; return *this; }
	Color& operator -= ( const Color& col1 ) { r -= col1.r, g -= col1.g, b -= col1.b; return *this; }
	Color& operator *= ( float f ) { r *= f , g *= f , b *= f; return *this; }
	Color& operator *= ( const Color& col1 ) { r *= col1.r, b *= col1.b, g *= col1.g; return *this; }

	const float& operator[]( const int idx ) { assert( idx >= 0 && idx <= 2 ); switch( idx ) { case 0: return r; case 1: return g; case 2: return b; } }

	void operator = ( const Color& rhs ) { }//r = rhs.getRed(), g = rhs.getGreen(), b = rhs.getBlue(); }
    void operator = ( const sf::Color& rhs ) { r = float( rhs.r / 255.0f ), g = float( rhs.g / 255.0f ), b = float( rhs.b / 255.0f ); }
private:
	float r, g, b;
	sf::Color col;
};

#endif // _INC_COLOR_H_
