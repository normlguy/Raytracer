#ifndef _INC_PRIMITIVEFACTORY_H_
#define _INC_PRIMITIVEFACTORY_H_

#include <cassert>
#include <limits>
#include <cstring>
#include <string>

#include "Color.h"
#include "Primitive.h"
#include "Sphere.h"
#include "Plane.h"
#include "Scene.h"

class PrimitiveFactory
{
        public:
            PrimitiveFactory();

            PrimitiveFactory* diffusion( float diff );
            PrimitiveFactory* reflectivity( float refl );
            PrimitiveFactory* color( sf::Color col );
            PrimitiveFactory* pos( Vec3 p );
            PrimitiveFactory* name( std::string s );
            PrimitiveFactory* radius( float r );
            PrimitiveFactory* dist( float d );
            PrimitiveFactory* setScene( Scene* s_ );
            PrimitiveFactory* resetScene( Scene* newScene );

            Primitive* build( Primitive::PrimType pType );

        private:

            typedef struct
            {
                float diff;
                float refl;
                float rad, dist_;
                sf::Color col;
                Material* mat;
                Vec3 pos_;
                std::string name_;
                Scene* scene;

            } ParamProxy;

            ParamProxy* params;

            static const float NaN;

};

#endif // _INC_PRIMITIVEFACTORY_H_
