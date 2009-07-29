#include "Scene.h"
#include "def.h"
#include "Plane.h"
#include "Sphere.h"

Scene::~Scene()
{
	delete[] prims;
}

void Scene::build()
{
	delete[] prims;

	prims = new Primitive*[ PRIM_ARRAY_SIZE ];

	Primitive *p = 0;
	Material *m = 0;

	// floor plane
	p = new Plane( Vec3( 0, 1, 0 ), 4.4f );
	m = new Material( Color( 0.4f, 0.3f, 0.3f ), 1.0f, 0.0f );
	p->setName( "plane" );
	p->setMaterial( m );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );//->setMaterial( Material( Color( 0.1f, 0.1f, 0.1f ), 1.0f, 0.0f ) );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );
	addPrim( p );

	// back plane
	//p = new Plane( Vec3( 0, 0, 1 ), 4.4f );
	//m = new Material( Color( 0.4f, 0.3f, 0.3f ), 1.0f, 0.0f );
	//p->setName( "plane" );
	//p->setMaterial( m );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );//->setMaterial( Material( Color( 0.1f, 0.1f, 0.1f ), 1.0f, 0.0f ) );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );
	//addPrim( p );

	// big sphere
	p = new Sphere( Vec3( 5, 3.8f, 10 ), 2.5f );
	m = new Material( Color( 0.9f, 0.7f, 0.9f ), 0.4f, 0.5f );
	p->setName( "big sphere" );
	p->setMaterial( m );//->setReflectivity( 0.6f )->setDiffusion( 0.5f )->setColor( Color( 0.7f, 0.7f, 0.7f ) );
	addPrim( p );

	// small sphere
	p = new Sphere( Vec3( -4.5f, -0.5, 7 ), 2 );
	m = new Material( Color( 0.0f, 0.0f, 1.0f ), 0.5f, 0.2f );
	p->setName( "small sphere" );
	p->setMaterial( m );
	addPrim( p );

	// light source 1
	p = new Sphere( Vec3( -7, 5, 7 ), 0.1f );
	m = new Material( Color( 1.0f, 1.0f, 1.0f ) );
	p->setLight( true );
	p->setName( "light 1" );
	p->setMaterial( m );
	addPrim( p );

	//light source 2
	p = new Sphere( Vec3( 0, 5, 8 ), 0.1f );
	m = new Material( Color( 0.0f, 0.0f, 1.0f ) );
	p->setLight( true );
	p->setName( "light 2" );
	p->setMaterial( m );
	addPrim( p );

	//light source 3
	p = new Sphere( Vec3( -2, 7, 3 ), 0.1f );
	m = new Material( Color( 1.0f, 1.0f, 1.0f ) );
	p->setLight( true );
	p->setName( "light 2" );
	p->setMaterial( m );
	addPrim( p );
}
