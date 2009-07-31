#include "Surface.h"

Surface::Surface( int width_, int height_ ) : width( width_ ),
                                              height( height_ )
{
    buffer = new sf::Image( width_, height_ );
    sprite = new sf::Sprite( *buffer );
}

Surface::~Surface()
{
    delete buffer;
    delete sprite;
}

void Surface::setPixel( int x, int y, sf::Color& col )
{
	buffer->SetPixel( x, y, col );
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

const sf::Drawable& Surface::getDrawable()
{
    return *sprite;
}

