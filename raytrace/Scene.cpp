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
	m = new Material( sf::Color( 0.4f * 255, 0.3f * 255, 0.3f * 255 ), 1.0f, 0.0f );
	p->setName( "plane" );
	p->setMaterial( m );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );//->setMaterial( Material( Color( 0.1f, 0.1f, 0.1f ), 1.0f, 0.0f ) );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );
	addPrim( p );


//m_Primitive[6] = new PlanePrim( vector3( 0.4f, 0, -1 ), 12 );
	//m_Primitive[6]->SetName( "back plane" );
	//m_Primitive[6]->GetMaterial()->SetReflection( 0.0f );
	//m_Primitive[6]->GetMaterial()->SetRefraction( 0.0f );
	//m_Primitive[6]->GetMaterial()->SetSpecular( 0 );
	//m_Primitive[6]->GetMaterial()->SetDiffuse( 0.6f );
	//m_Primitive[6]->GetMaterial()->SetColor( Color( 0.5f, 0.3f, 0.5f ) );

	// big sphere
	p = new Sphere( Vec3( 5, 3.8f, 10 ), 2.5f );
	m = new Material( sf::Color( 0.9f * 255, 0.7f * 255, 0.9f * 255 ), 0.4f, 0.5f );
	p->setName( "big sphere" );
	p->setMaterial( m );//->setReflectivity( 0.6f )->setDiffusion( 0.5f )->setColor( Color( 0.7f, 0.7f, 0.7f ) );
	addPrim( p );

	// small sphere
	p = new Sphere( Vec3( -4.5f, -0.5, 7 ), 2 );
	m = new Material( sf::Color( 1.0f * 255, 1.0f * 255, 1.0f * 255 ), 0.4f, 0.5f );
	p->setName( "small sphere" );
	p->setMaterial( m );
	addPrim( p );

	// light source 1
	p = new Sphere( Vec3( 30, 5, 10 ), 0.1f ); // y, up down, x left right, z forward back
	m = new Material( sf::Color( 1.0f * 255, 1.0f * 255, 1.0f * 255 ) );
	p->setLight( true );
	p->setName( "light 1" );
	p->setMaterial( m );
	addPrim( p );

    /* additional lights
	//light source 2
	p = new Sphere( Vec3( 10, 5, 25 ), 0.1f );
	m = new Material( Color( 1.0f, 0.5f, 1.0f ) );
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
	*/

	// back plane
	p = new Plane( Vec3( 0.6f, 0, -1 ), 24 );
	m = new Material( sf::Color( 0, 0.6f * 255, 0.3f * 255 ), 0.8f, 0.0f );
	p->setName( "plane" );
	p->setMaterial( m );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );//->setMaterial( Material( Color( 0.1f, 0.1f, 0.1f ), 1.0f, 0.0f ) );//setReflectivity( 0 )->setDiffusion( 1.0f )->setColor( Color( 0.1f, 0.1f, 0.1f ) );
	addPrim( p );
}
