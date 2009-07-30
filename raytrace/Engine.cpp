//#include <windows.h>
#include <cmath>
#include <cassert>
#include <iostream>

#include "Time.h"
#include "Engine.h"
#include "Sphere.h"
#include "Debug.h"

Engine::Engine() : view_wnd_c0( Vec3( VIEW_WINDOW_X1, VIEW_WINDOW_Y1, 0 ) ),
        view_wnd_c1( Vec3( VIEW_WINDOW_X2, VIEW_WINDOW_Y2, 0 ) ),
        cam_pos( Vec3( CAM_X, CAM_Y, CAM_Z ) )
{
    result = new Surface( SCRW, SCRH );
    scene = new Scene();

    init();
}

Engine::Engine( Surface& surface, Scene& scene_ ) : result( &surface ),	scene( &scene_ ),
        view_wnd_c0( Vec3( VIEW_WINDOW_X1, VIEW_WINDOW_Y1, 0 ) ),
        view_wnd_c1( Vec3( VIEW_WINDOW_X2, VIEW_WINDOW_Y2, 0 ) ),
        cam_pos( Vec3( CAM_X, CAM_Y, CAM_Z ) )
{
    init();
};

void Engine::init()
{
    cur_y = 0;
    finished = false;
    scene->build();
}

Engine::~Engine()
{
    delete scene;
    delete[] lastRow;

}

void Engine::setSurface( Surface &newSurface )
{
    result = &newSurface;
}

void Engine::setScene( Scene& newScene )
{
    scene = &newScene;
}

Vec3 Engine::getPixelPos( int x, int y )
{
    return Vec3( Vec3( view_wnd_c0["x"] + ( delt_x * x ), view_wnd_c0["y"] + ( delt_y * y ), 0 ) - cam_pos ).normalize();
}

void Engine::handleMsgFunc( void ( *msgFunc )(), int start )
{
    int finish = GetTickCount();

    if ( ( finish - start ) > WINDOW_UPDATE_DELAY )
    {
        msgFunc();
    }
}

void Engine::checkIntersect( Ray& r, float& dist, Primitive** prim, int& result )
{
    // loop to find any intersections
    for ( int i = 0; i < scene->primCount(); i++ )
    {
        Primitive* p = scene->getPrim( i );

        int hit;
        if ( hit = p->intersect( r, dist ) )
        {
            *prim = p;
            result = hit;
        }
    }
}

void Engine::handleLighting( Primitive* prim, Ray& r, Color& col, const float dist, const int depth )
{
    if ( prim->isLight() )
    {
        // hit a light.
        col = prim->getColor();
        return;
    }

    // find intersection vector
    Vec3 orig = r.getOrigin();
    Vec3 dir = r.getDirection();
    Vec3 intrsect = orig + dir * dist;

    // trace to the lights to determine lighting
    for ( int i = 0; i < scene->primCount(); i++ )
    {
        Primitive* p = scene->getPrim( i );
        if ( p->isLight() )
        {
            Primitive* light = p;

            // get a vector from the intersection point to the center of the light
            Vec3 light_pos = ( ( Sphere* ) light )->getCenter() - intrsect;
            float light_dist = light_pos.length() - ( ( Sphere* ) light )->getRadius();

            // normalize
            Vec3 light_pos_norm = light_pos.normalize();

            // handle point lights
            float shade = 1.0f;

            handleShade( light, light_pos, intrsect, shade );

            // get the normal at the intersection point
            Vec3 norm = prim->getNormal( intrsect );

            // calculate diffuse shading
            if ( ENABLE_DIFFUSE_LIGHTING && prim->getDiffusion() > 0 )
            {
                // get a number of how "similar" the vector that is the normal at the intersection point
                // is to the vector that is from the intersection point to the center of the light
                // in a nutshell, how much is the normal of the intersection point facing the light?
                float dot = norm.dot( light_pos_norm );

                if ( dot > 0 )
                {
                    // the light is visible looking away from the sphere towards
                    // the normal of the intersection point, so it is going to be lit
                    float diff = dot * prim->getDiffusion() * shade;

                    // add the light color to the color of the ray
                    col += diff * prim->getColor() * light->getColor();
                }
            }

            // now specular shading
            if ( ENABLE_SPEC_LIGHTING && prim->getSpecular() > 0 && prim->getType() != Primitive::PLANE )
            {
                Vec3 refl_vec = light_pos_norm - ( norm * light_pos_norm.dot( norm ) * 2.0f );

                float dot = dir.dot( refl_vec );

                if ( dot > 0 )
                {
                    float spec = powf( dot, 20 ) * prim->getSpecular() * shade;

                    col += spec * light->getColor();
                }
            }
        }
    }

    // now calculate reflection rays
    handleReflection( prim, r, intrsect, col, depth );
}

void Engine::handleReflection( Primitive* prim, Ray& r, Vec3 intersection, Color& col, const int depth )
{
    if( !ENABLE_REFLECTIONS ) return;

    // now calculate reflection rays
    float refl = prim->getReflectivity();
    if ( refl > 0.0f )
    {
        Vec3 norm = prim->getNormal( intersection );
        Vec3 refl_vec = r.getDirection() - ( norm * 2.0f * r.getDirection().dot( norm ) );

        if ( depth < MAX_RAY_DEPTH )
        {
            Color nCol( 0, 0, 0 );
            float ndist;
            Vec3 newVec = intersection + refl_vec * EPSILON;
            Ray newRay = Ray( newVec, refl_vec );
            raytrace( newRay, nCol, depth + 1, ndist );
            col += refl * nCol * prim->getColor();
        }
    }
}

void Engine::handleShade( Primitive* light, Vec3 light_pos, Vec3 intersect, float& shade )
{
    if( !ENABLE_HARD_SHADOWS ) return;

    //if ( light->getType() == Primitive::SPHERE )
    {
        Vec3 light_pos_norm = light_pos.normalize();
        float tdist = light_pos.length();

        Vec3 newVec = intersect + light_pos_norm * EPSILON;

        Ray rr( newVec, light_pos_norm );

        for ( int s = 0; s < scene->primCount(); s++ )
        {
            Primitive* pr = scene->getPrim( s );
            if ( ( pr != light ) && ( !pr->isLight() ) && ( pr->intersect( rr, tdist ) ) )
            {
                shade = 0;
                break;
            }
        }
    }
}

bool Engine::render( void ( *msgFunc )() )
{
    // set the first line
    cur_y = 32;
    cur_x = 0;

    // for interpolation, calc world units per pixel
    delt_x = ( view_wnd_c1["x"] - view_wnd_c0["x"] ) / result->getWidth();
    delt_y = ( view_wnd_c1["y"] - view_wnd_c0["y"] ) / result->getHeight();

    const int SCRH_LIM = SCRH - cur_y;

    // start the clock
    int start = GetTickCount();

    // make sure all the vars are set correctly so everything will line up right
    // if this assertion fails, check your SCRW, SCRH, and RENDER_TILE_SIZE variables
    float test1 = floor( float( ( SCRW + SCRH ) / RENDER_TILE_SIZE ) );
    float test2 = ( ( SCRW + SCRH ) / RENDER_TILE_SIZE );
    assert( test1 == test2 );


    // do the render
    const int nrows = SCRH / RENDER_TILE_SIZE;
    const int ncols = SCRW / RENDER_TILE_SIZE;
    for ( int rows = 0; rows < nrows; rows++ )
    {
        for ( int cols = 0; cols < ncols; cols++ )
        {

            for ( int y = cur_y; y < RENDER_TILE_SIZE + cur_y; y++ )
            {

                // render all the pixels for this line
                for ( int x = cur_x; x < RENDER_TILE_SIZE + cur_x; x++ )
                {
                    //x = 0;
                    //y = SCRH_LIM - 10;
                    Color col = Color( 0, 0, 0 );

                    // direction from camera to pixel
                    Vec3 dir = getPixelPos( x, y );

                    // shoot the primary ray for this pixel
                    Vec3 newVec = cam_pos;
                    Ray r( newVec, dir );
                    float dist;

                    Primitive* prim = raytrace( r, col, 1, dist );


                    // set the correct pixel to the color we got back from raytrace
                    result->setPixel( x, y, col );

                }
            }

            handleMsgFunc( msgFunc, start );
            cur_x = RENDER_TILE_SIZE * cols;

        }

        cur_y = RENDER_TILE_SIZE * rows;

    }

    // done!
    this->setFinished( true );
    return true;
}

Primitive* Engine::raytrace( Ray& r, Color& col, int depth, float& dist )
{
    //TRACE( "x: %i, y:%i\n", x, y );
    // bouncing too much? bail
    if ( depth > MAX_RAY_DEPTH ) return NULL;

    dist = 10000000.0f;
    Primitive* ret = 0;
    int result;

    checkIntersect( r, dist, &ret, result );

    // was there a hit? if not, bail
    if ( !ret ) return NULL;

    // hit the lights
    handleLighting( ret, r, col, dist, depth );

    return ret;
}
