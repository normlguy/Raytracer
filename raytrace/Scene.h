#ifndef _INC_SCENE_H_
#define _INC_SCENE_H_

#include "Primitive.h"
#include "def.h"
#include "PrimitiveFactory.h"

class Scene
{
public:
	Scene() : primNum( 0 ), prims( 0 ) {};
	~Scene();

	void build();
	int primCount() { return primNum; }
	Primitive* getPrim( int id ) { return prims[ id ]; }
	void addPrim( Primitive* p ) { prims[ primNum++ ] = p; }

private:
	int primNum;
	Primitive** prims;

};

#endif // _INC_SCENE_H_
