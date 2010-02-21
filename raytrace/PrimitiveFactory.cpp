#include "PrimitiveFactory.h"

const float PrimitiveFactory::NaN = std::numeric_limits<float>::quiet_NaN();

PrimitiveFactory::PrimitiveFactory()
{
    //params.reset();
    params->diff = 1.0f;
    params->refl = 0.0f;
}


PrimitiveFactory* PrimitiveFactory::diffusion( float d )    { params->diff  = d; }
PrimitiveFactory* PrimitiveFactory::reflectivity( float r ) { params->refl  = r; }
PrimitiveFactory* PrimitiveFactory::color( sf::Color c )    { params->col   = c; }
PrimitiveFactory* PrimitiveFactory::pos( Vec3 p )           { params->pos_  = p; }
PrimitiveFactory* PrimitiveFactory::name( std::string s )   { params->name_ = std::string( s ); }
PrimitiveFactory* PrimitiveFactory::radius( float r )       { params->rad   = r; }
PrimitiveFactory* PrimitiveFactory::dist( float d )         { params->dist_ = d; }
PrimitiveFactory* PrimitiveFactory::setScene( Scene* s )    { params->scene = s; }

PrimitiveFactory* PrimitiveFactory::resetScene( Scene* newScene )
{
    params->scene = ( newScene != NULL ) ? newScene : NULL;
}


Primitive* PrimitiveFactory::build( Primitive::PrimType pType )
{
    //clear anything we have in the passed pointer


    Primitive* ret;

    // depending on the type we were passed, create the primitive
    // and associated material
    switch ( pType )
    {
    case Primitive::SPHERE:
        //assert( memcmp( static_cast<const void*>( &rad ), static_cast<const void*>( &NaN ), sizeof( float ) ) != 0 );
        ret = new Sphere( params->pos_, params->rad );
        params->mat = new Material( params->col, params->diff, params->refl );

        if (  params->name_ != "" ) ret->setName( params->name_ );

        ret->setMaterial( params->mat );
        break;

    case Primitive::PLANE:
        //assert( memcmp( static_cast<const void*>( &dist_ ), static_cast<const void*>( &NaN ), sizeof( float ) ) != 0 );
        ret = new Plane( params->pos_, params->dist_ );
        params->mat = new Material( params->col, params->diff, params->refl );

        if ( params->name_ != "" ) ret->setName( params->name_ );

        ret->setMaterial( params->mat );
        break;

    }

    // add the primitive to the scene if we have one
    if( params->scene != NULL ) params->scene->addPrim( ret );

    // reset the variables so they are not re-used next time
    //diff = refl = rad = dist_ = NaN;

    // is ret falling out of scope after it is returned, leaving the objects pointerless?
    return ret;
}
