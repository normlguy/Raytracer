#ifndef _INC_DEF_H_
#define _INC_DEF_H_

#define SCRW 928
#define SCRH 672

#define PRIM_ARRAY_SIZE 20

#define HIT		1
#define MISS	0
#define INPRIM	-1

#define VIEW_WINDOW_X1 -4
#define VIEW_WINDOW_Y1 3

#define VIEW_WINDOW_X2 4
#define VIEW_WINDOW_Y2 -3

#define CAM_X 0
#define CAM_Y 0
#define CAM_Z -1

#define WINDOW_TITLE "raytracer"
#define WINDOW_UPDATE_DELAY 0

#define MAX_RAY_DEPTH 6
#define EPSILON 0.0001f

#define RENDER_TILE_SIZE 16

#define ENABLE_SPEC_LIGHTING 1
#define ENABLE_REFLECTIONS 1
#define ENABLE_DIFFUSE_LIGHTING 1
#define ENABLE_HARD_SHADOWS 1

#define CLAMP( x, min, max )	(x < min) ? x = min : ( (x > max) ? x = max :  );
#define __RGB( r, g, b )			int( r * 255 ), int( g * 255 ), int( b * 255 )
#define DOT(A,B)		( A["x"] * B["x"]+ A["y"] * B["y"] + A["z"] * B["z"] )
#define NORMALIZE(A)	{ float l = 1 / sqrtf( A["x"] * A["x"] + A["y"] * A["y"] + A["z"] * A["z"] ); A["x"] *= l; A["y"] *= l; A["z"] *= l; }
#define LENGTH(A)		( sqrtf( A["x"] * A["x"] + A["y"] * A["y"] + A["z"] * A["z"] ) )
#define SQRLENGTH(A)	( A["x"] * A["x"] + A["y"] * A["y"] + A["z"] * A["z"] )
#define SQRDISTANCE(A,B) ( ( A["x"] - B["x"] ) * ( A["x"] - ["x"] ) + ( A["y"] - B["y"] ) * ( A["y"] - B["y"] ) + ( A["z"] - B["z"] ) * ( A["z"] - B["z"] ) )

#define DEBUG 1
#define _OUT( x ) if( DEBUG ){ std::cout << x << "\n"; }

#endif // _INC_DEF_H_
