/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>
#include <math.h>

// HIPERBOL DENEMESI 


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
    
    // HIPERBOL DEGISKENLERI
	float oncekix, oncekiy, yenix, yeniy;
	float t = 0.0;
	float a = 0.0; 
	float b = 0.0; 

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
      0, 0, 500, 500,
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

            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

/*            glPushMatrix ();
            glRotatef (theta, 0.0f, 0.0f, 1.0f);
            glBegin (GL_TRIANGLES);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (0.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.87f, -0.5f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (-0.87f, -0.5f);
            glEnd ();
            glPopMatrix ();   */
            
            
            t = (-3.1);
            a = 0.3;
            b = 0.3;
            oncekix = a / cos(t);
			oncekiy = b * tan(t);
			glColor3f(1.0f, 0.0f, 0.0f);
			glBegin(GL_LINES);
			for(t=(-3.0); t<-1.5; t+=0.01)
			{
				yenix = a / cos(t);
				yeniy = b * tan(t);
				glVertex2f (oncekix, oncekiy);
				glVertex2f (yenix, yeniy);
				oncekix = yenix;
				oncekiy = yeniy;
				glEnd();
			}                              
			for(t=-1.4; t<1.5; t+=0.01)
			{
				yenix = a / cos(t);
				yeniy = b * tan(t);
				glColor3f(1.0f, 0.0f, 0.0f);
				glBegin(GL_LINES);
				glVertex2f (oncekix, oncekiy);
				glVertex2f (yenix, yeniy);				
				oncekix = yenix;
				oncekiy = yeniy;
				glEnd();
			}
		for(t=1.5; t<3.2; t+=0.01)
			{
				yenix = a / cos(t);
				yeniy = b * tan(t);
				glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex2f (oncekix, oncekiy);
				glVertex2f (yenix, yeniy);				
				oncekix = yenix;
				oncekiy = yeniy;
				glEnd();	
			}
				for(t=3.2; t<-3.2; t-=0.01)
			{
				yenix = a / cos(t);
				yeniy = b * tan(t);
				glBegin(GL_LINES);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex2f (oncekix, oncekiy);
				glVertex2f (yenix, yeniy);				
				oncekix = yenix;
				oncekiy = yeniy;
				glEnd();	
			}                                  
			
						
			

            SwapBuffers (hDC);

//          theta += 1.0f;
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
