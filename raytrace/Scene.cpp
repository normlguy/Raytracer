#include "Scene.h"
#include "def.h"
#include "PrimitiveFactory.h"
#include "Plane.h"
#include "Sphere.h"

Scene::~Scene()
{
    for( int i = 0; i < this->primCount(); i++ )
    {
        Primitive* p = this->getPrim( i );

        delete p;
    }

	delete[] prims;
}

void Scene::build()
{
	delete[] prims;

	prims = new Primitive*[ PRIM_ARRAY_SIZE ];

	Primitive *p = 0;
	Material *m = 0;
    PrimitiveFactory* pf = new PrimitiveFactory();

    pf->setScene( this );

	// floor plane
	pf->pos( Vec3( 0, 1, 0 ) );
	pf->dist( 4.4f );
	pf->color( sf::Color( 102, 77, 77 ) );
	pf->diffusion( 1.0f );
	pf->reflectivity( 0.0f );
	pf->name( "bottom plane" );
	p = pf->build( Primitive::PLANE );
	//addPrim( p );
	//p = new Plane( Vec3( 0, 1, 0 ), 4.4f );
	//m = new Material( sf::Color( 0.4f * 255, 0.3f * 255, 0.3f * 255 ), 1.0f, 0.0f );
	//p->setName( "plane" );
	//p->setMaterial( m );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );//->setMaterial( Material( Color( 0.1f, 0.1f, 0.1f ), 1.0f, 0.0f ) );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );
	//addPrim( p );

	// big sphere
	pf->pos( Vec3( 5, 3.8f, -10 ) );
	pf->radius( 2.5f );
	pf->color( sf::Color( 0.0f * 255, 1.0f * 255, 0.0f * 255 ) );
	//pf->diffusion( 0.4f );
	//pf->reflectivity( 0.5f );
	pf->name( "big sphere" );
	p = pf->build( Primitive::SPHERE );
	addPrim( p );

	//p = new Sphere( Vec3( 5, 3.8f, 10 ), 2.5f );
	//m = new Material( sf::Color( 0.9f * 255, 0.7f * 255, 0.9f * 255 ), 0.4f, 0.5f );
	//p->setName( "big sphere" );
	//p->setMaterial( m );//->setReflectivity( 0.6f )->setDiffusion( 0.5f )->setColor( Color( 0.7f, 0.7f, 0.7f ) );
	//addPrim( p );

	// small sphere
	p = new Sphere( Vec3( -4.5f, -0.5, 7 ), 2 );
	m = new Material( sf::Color( 1.0f * 255, 1.0f * 255, 1.0f * 255 ), 0.4f, 0.5f );
	p->setName( "small sphere" );
	p->setMaterial( m );
	addPrim( p );

	//add a bunch of small spheres

	// light source 1
	p = new Sphere( Vec3( 8, 10, 5 ), 0.1f ); // y, up down, x left right, z forward back
	m = new Material( sf::Color( 255, 255, 255 ) );
	p->setLight( true );
	p->setName( "light 1" );
	p->setMaterial( m );
	addPrim( p );

//     additional lights
	//light source 2
	p = new Sphere( Vec3( -5, 5, 5 ), 0.1f );
	m = new Material( sf::Color( 255, 255, 255 ) );
	p->setLight( true );
	p->setName( "light 2" );
	p->setMaterial( m );
	addPrim( p );

	//light source 3
	p = new Sphere( Vec3( -15, 7, 3 ), 0.1f );
	m = new Material( sf::Color( 255, 255, 255 ) );
	p->setLight( true );
	p->setName( "light 2" );
	p->setMaterial( m );
	addPrim( p );


	// back plane
	p = new Plane( Vec3( 0.0f, 0, -1 ), 24 );
	m = new Material( sf::Color( 0, 0.6f * 255, 0.3f * 255 ), 1.0f, 0.0f );
	p->setName( "plane" );
	p->setMaterial( m );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );//->setMaterial( Material( Color( 0.1f, 0.1f, 0.1f ), 1.0f, 0.0f ) );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );
	addPrim( p );

	delete pf;
}
