#include "Surface.h"

Surface::Surface( int width_, int height_ ) : width( width_ ),
                                              height( height_ )
{
    buffer = new sf::Image( width_, height_ );
}

Surface::~Surface()
{
    delete[] buffer;
}

void Surface::setPixel( int x, int y, Color& col )
{
	int r = int( col.getRed() * 255 );
	int g = int( col.getGreen() * 255 );
	int b = int( col.getBlue() * 255 );

	if( r < 0 ) r = 0;
	if( g < 0 ) g = 0;
	if( b < 0 ) b = 0;

	if( r > 255 ) r = 255;
	if( g > 255 ) g = 255;
	if( b > 255 ) b = 255;

	buffer->SetPixel( x, y, sf::Color::Color( r, g, b ) );
}

void Surface::clear( sf::Color color )
{
    buffer->Create( width, height, color );
}

const sf::Color Surface::getPixel( int x, int y )
{
    // hack it back into an Uint8* and then cast to Pixel
    // it's really hacky, but it will have to do until
    // the whole shebang is rewritten to use sf::Colors

    // function is not yet used anywhere else in the implementation
    // we can safely return sf::Color's now
    //return static_cast< Pixel >( buffer->GetPixelsPtr()[ x + ( y * width ) ] );

    return buffer->GetPixel( x, y );
}

int Surface::getHeight()
{
    return height;
}

int Surface::getWidth()
{
    return width;
}

const Pixel* Surface::getBuffer()
{
    return buffer->GetPixelsPtr();
}
