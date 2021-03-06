//#include <windows.h>
#include <iostream>
#include <unistd.h>

#include <SFML/Graphics.hpp>

#include "def.h"
#include "Surface.h"
#include "Engine.h"
#include "Debug.h"

static sf::RenderWindow app( sf::VideoMode( SCRW, SCRH ), WINDOW_TITLE );

Engine* eng = 0;

void handleEvents();

int main( int argc, char** argv )
{
    eng = new Engine();

    eng->getSurface()->clear( sf::Color::Black );

    app.Display();

    eng->render( handleEvents );

    while( app.IsOpened() )
    {
        handleEvents();
        //usleep( WINDOW_UPDATE_DELAY * 1000 );
    }

    //std::cout << "TEST" << std::endl;

    delete eng;

    return EXIT_SUCCESS;
}

void handleEvents()
{
    //std::cout << "in handle Events" << std::endl;

    sf::Event evt;

    while( app.GetEvent( evt )  )
    {
        switch( evt.Type )
        {
            case sf::Event::Closed:
                app.Close();
                break;
        }
    }

    app.Draw( eng->getSurface()->getDrawable() );

    app.Display();
}

/*static WNDCLASS wclass;
static HWND wnd;
static char bm_buffer[ sizeof( BITMAPINFO ) + 16 ];
static BITMAPINFO* bm_info;

HDC hdc;
Engine* eng = 0;

void drawWindow();

static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	int result = 0;

	switch( message )
	{
	case WM_PAINT:
		if( !eng ) break;
		StretchDIBits( hdc, 0, 0, SCRW, SCRH, 0, 0, SCRW, SCRH, eng->getSurface()->getBuffer(), bm_info, DIB_RGB_COLORS, SRCCOPY );
		ValidateRect( wnd, NULL );
		break;
	case WM_KEYDOWN:
		if ( ( wParam & 0xFF ) != 27 ) break;
		break;
	case WM_CLOSE:
		ReleaseDC( wnd, hdc );
		DestroyWindow( wnd );
		SystemParametersInfo( SPI_SETSCREENSAVEACTIVE, 1, 0, 0 );
		ExitProcess( 0 );
		break;
	default:
		result = DefWindowProc( hWnd, message, wParam, lParam );
	}
	return result;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	RECT rect;
	int cc;

	wclass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	wclass.lpfnWndProc = WndProc;
	wclass.cbClsExtra = wclass.cbWndExtra = 0;
	wclass.hInstance = 0;
	wclass.hIcon = NULL;
	wclass.hCursor = LoadCursor(0,IDC_ARROW);
	wclass.hbrBackground = NULL;
	wclass.lpszMenuName = NULL;
	wclass.lpszClassName = WINDOW_TITLE;

	if( !RegisterClass( &wclass ) ) return FALSE;

	rect.left = rect.top = 0;
	rect.right = SCRW, rect.bottom = SCRH;

	AdjustWindowRect( &rect, WS_POPUP|WS_SYSMENU|WS_CAPTION, 0 );

	rect.right -= rect.left, rect.bottom -= rect.top;

	wnd = CreateWindowEx( 0, WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,
		CW_USEDEFAULT, CW_USEDEFAULT, rect.right, rect.bottom, 0, 0, 0, 0 );

	ShowWindow( wnd, SW_NORMAL );

	for ( cc = 0; cc < sizeof( BITMAPINFOHEADER ) + 16; cc++ ) bm_buffer[ cc ] = 0;

	bm_info = (BITMAPINFO*) &bm_buffer;
	bm_info->bmiHeader.biSize = sizeof( BITMAPINFOHEADER );
	bm_info->bmiHeader.biPlanes = 1;
	bm_info->bmiHeader.biBitCount = 32;
	bm_info->bmiHeader.biCompression = BI_BITFIELDS;
	bm_info->bmiHeader.biWidth = SCRW, bm_info->bmiHeader.biHeight = -SCRH;

	((unsigned long*)bm_info->bmiColors)[0] = 255 << 16;
	((unsigned long*)bm_info->bmiColors)[1] = 255 << 8;
	((unsigned long*)bm_info->bmiColors)[2] = 255;

	hdc = GetDC( wnd );
	SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, 0, 0, 0);

	// perform the render

	// get a new engine
	eng = new Engine();

	// and clear it with black first
	eng->getSurface()->clear( 0x00000000 );

	eng->render( drawWindow );

	while( 1 ) { Sleep( WINDOW_UPDATE_DELAY ); drawWindow(); }

	return 1;
}

void drawWindow()
{
	MSG message;
	HACCEL haccel = 0;
	InvalidateRect( wnd, NULL, TRUE );
	SendMessage( wnd, WM_PAINT, 0, 0 );
	while( PeekMessage( &message, wnd, 0, 0, PM_REMOVE ) )
	{
		if( TranslateAccelerator( wnd, haccel, &message ) == 0 )
		{
			TranslateMessage( &message );
			DispatchMessage( &message );
		}
	}
	Sleep( 0 );
}*/
