#ifndef _INC_SURFACE_H_
#define _INC_SURFACE_H_

#include "Color.h"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Color.hpp>

typedef sf::Uint8 Pixel;

class Surface
{
public:
	Surface( int width_, int height_ );
	~Surface();

	const Pixel* getBuffer();
	int getWidth();
	int getHeight();
	const sf::Color getPixel( int x, int y );
	void setPixel( int x, int y, Color& col );
	void clear( sf::Color color );

private:
	sf::Image* buffer;
	int width, height;

};

#endif // _INC_SURFACE_H_
