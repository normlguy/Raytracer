#ifndef _INC_SURFACE_H_
#define _INC_SURFACE_H_

#include "Color.h"
#include <SFML/Graphics.hpp>

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
	void setPixel( int x, int y, sf::Color& col );
	void clear( sf::Color color );
	const sf::Drawable& getDrawable();

private:
	sf::Image* buffer;
    sf::Sprite* sprite;
	int width, height;

};

#endif // _INC_SURFACE_H_
