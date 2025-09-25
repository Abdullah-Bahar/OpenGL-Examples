/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#define PI 3.1456


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);


/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;
    
//  buyuk dairenin degiskenleri
    float sayac;
    float xyonu=0.0;
    float yyonu=0.0;
    float rx=0.0;
    float ry=0.0;
    float teta=0.0;
    
//	kucuk dairenin degiskenleri
	float sayac1;
	float xyonu1=0.0;
	float yyonu1=0.0;
	float rx1=0.0;
	float ry1=0.0;
	float teta1=0.0;
	
// yildiz dairesinin degiskenleri
	float sayac2;
	float xyonu2=0.0;
	float yyonu2=0.0;
	float rx2=0.0;
	float ry2=0.0;
	float teta2=0.0;

	
	
    

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GLSample";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "GLSample", "OpenGL Sample", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 920, 600,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor (1.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);
            
//          Buyuk daire  
			rx=0.3260869565;
			ry=0.4891304348;
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin (GL_POLYGON);
            for (sayac=0.1;sayac<=180;sayac+=0.1){
            	xyonu=rx*cos((sayac*2*PI)/180)-0.2608695652;
            	yyonu=ry*sin((sayac*2*PI)/180);
            	glVertex2f(xyonu,yyonu);
			}
			glEnd ();
			
//			Kucuk daire
 			rx1=0.2608695652;
			ry1=0.3913043478;
            glColor3f(1.0f, 0.0f, 0.0f);
            glBegin (GL_POLYGON);
            for (sayac1=0.1;sayac1<=180;sayac1+=0.1){
            	xyonu1=rx1*cos((sayac1*2*PI)/180)-0.1739130435;
            	yyonu1=ry1*sin((sayac1*2*PI)/180);
            	glVertex2f(xyonu1,yyonu1);
			}
			glEnd ();
			
//			yildiz kismi
/*			rx2=0.1630434783;
			ry2=0.2445652174;
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin (GL_POLYGON);
            for (sayac2=0.1;sayac2<=180;sayac2+=1){
            	xyonu2=rx2*cos((sayac2*2*PI)/180)+0.1630434783;
            	yyonu2=ry2*sin((sayac2*2*PI)/180);
            	glVertex2f(xyonu2,yyonu2);
			}
			glEnd ();  */
        	
//       	Direk kısmı
			glBegin (GL_QUAD_STRIP);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-1.0f, 1.0f);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-0.9565217391f, 1.0f);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-1.0f, -1.0f);
        	glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (-0.9565217391f, -1.0f);
			glEnd ();         	
			
//			yildiz icin ic bukey dikdörtgen			
			glBegin (GL_QUAD_STRIP);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.0f, 0.0f);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.27f, 0.14f);
        	glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.27f, -0.14f);
        	glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.21f, 0.0f);
			glEnd ();			
			
//			yildiz icin ucgen			
			glBegin (GL_TRIANGLE_STRIP);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.1f, 0.22f);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.1f, -0.22f);
            glColor3f (1.0f, 1.0f, 1.0f);   glVertex2f (0.21f, 0.0f);
			glEnd ();			

            glPopMatrix (); 
            

            SwapBuffers (hDC);
			
			
            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
