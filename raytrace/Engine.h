#ifndef _INC_ENGINE_H_
#define _INC_ENGINE_H_

#include "def.h"
#include "Surface.h"
#include "Scene.h"


class Engine
{
public:
	Engine();
	Engine( Surface& surface, Scene& scene_ );
	~Engine();

	void setSurface( Surface& newSurface );
	void setScene( Scene& newScene );

	Surface* getSurface() { return result; }
	Scene* getScene() { return scene; }

	bool render( void (*msgFunc)() );
	bool isFinished() { return finished; }

protected:
	Primitive* raytrace( Ray& r, Color& col, int depth, float& dist );

private:
	void init();

	Vec3 getPixelPos( int x, int y );
	void handleMsgFunc( void (*msgFunc)(), int start );
	void checkIntersect( Ray& r, float& dist, Primitive** prim, int& result );
	void handleLighting( Primitive* prim, Ray& r, Color& col, const float dist, const int depth );
	void handleReflection( Primitive* prim, Ray& r, Vec3 intersection, Color& col, const int depth );
	void handleShade( Primitive* light, Vec3 light_pos, Vec3 intersect, float& shade );
	void setFinished( bool nFinished ) { finished = nFinished; }



	Surface* result;
	Scene* scene;
	Primitive** lastRow;

	int cur_y, cur_x;
	float delt_x, delt_y;

	typedef struct
	{
		float x, y;
	} WorldUnits;

	WorldUnits pixel_pos;
	const Vec3 view_wnd_c0, view_wnd_c1, cam_pos;
	bool finished;

};


#endif // _INC_ENGINE_H_
