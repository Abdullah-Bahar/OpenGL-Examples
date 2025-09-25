/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>
#include <math.h>

/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

 // FONKSIYONLARIM
long faktoriyel(int sayi){
	
	int donus=1;
	int sayac;
	if(sayi>=2){
		for(sayac=sayi;sayac>1;sayac--){
			donus = donus*sayac;
		}
	}
	return donus;
}

float kombinasyon(int n, int i){
	
	float kombi=0.0;
	kombi = faktoriyel(n)/(faktoriyel(i)*faktoriyel(n-i));
 	
	return kombi;
}

double JJ(int n,int i,float t){
	
	float sonuc=0.0;
	sonuc = kombinasyon(n,i) * pow(t,i) * pow((1-t),(n-i));
	
	return sonuc;
}


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
    
    //DEGISKENLERIM
    int P[4][2];   // 0->x  1->y
    float J[4];
    float t=0.0;
    int n=3;
    int i;
	float noktax = 0.0;
	float noktay = 0.0;
	
	//Daire degiskenleri
/*	float xr=0.0;
	float yr=0.0;
	float xyonu=0.0;
	float yyonu=0.0;   */
	
	float xr1=0.0;
	float yr1=0.0;
	float xyonu1=0.0;
	float yyonu1=0.0;
	
	float xr2=0.0;
	float yr2=0.0;
	float xyonu2=0.0;
	float yyonu2=0.0;	
	
/*	float konumx1;
	float konumy1;
	float konumx2;
	float konumy2;
	float konumx3;
	float konumy3;
	float konumx4;
	float konumy4;    */
	
	
	P[1][0]=0.1;
	P[1][1]=0.1;
	P[2][0]=0.2;
	P[2][1]=0.3;
	P[3][0]=0.4;
	P[3][1]=0.3;
	P[4][0]=0.3;
	P[4][1]=0.1;     
	
	
	  

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
      0, 0, 600, 600,
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

            glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
            glClear (GL_COLOR_BUFFER_BIT);

 //           glPushMatrix ();
 //           glRotatef (theta, 0.0f, 0.0f, 1.0f);
  /*          glBegin (GL_TRIANGLES);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (0.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.87f, -0.5f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (-0.87f, -0.5f);
            glEnd ();  */
 //           glPopMatrix ();
            
 /*            glPushMatrix ();
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_POLYGON);
	            for(t=0.0;t<=1.0;t+=0.1){
		
				J[0] = JJ(n,0,t);
				J[1] = JJ(n,1,t);
				J[2] = JJ(n,2,t);
				J[3] = JJ(n,3,t);
		
				noktax = P[0][0] * J[0] + P[1][0] * J[1] + P[2][0] * J[2] + P[3][0] * J[3];
				noktay = P[0][1] * J[0] + P[1][1] * J[1] + P[2][1] * J[2] + P[3][1] * J[3];
				
				glVertex2f(noktax, noktay);
				}
			glEnd();
			glPopMatrix();   */
			
/*			xr=0.5;
			yr=0.0;
			glBegin (GL_LINE_LOOP);
			glColor3f (1.0f, 0.0f, 0.0f);
			for(int i=0;i<=360;i++){
				
				if(i<45 && i>=0){
					xr-=0.0055555555555556;
					yr+=0.0055555555555556;
					xyonu=xr * cos((i * 2 * 3.1456)/360);
					yyonu=yr * sin((i * 2 * 3.1456)/360);
					glVertex2f(xyonu,yyonu);			
				}else if(i>=45 && i<90){
					xr-=0.0055555555555556;
					yr-=0.0055555555555556;
					xyonu=xr * cos((i * 2 * 3.1456)/360);
					yyonu=yr * sin((i * 2 * 3.1456)/360);
					glVertex2f(xyonu,yyonu);					
				}else if(i>=90 && i<135){
					xr-=0.0055555555555556;
					yr+=0.0055555555555556;
					xyonu=xr * cos((i * 2 * 3.1456)/360);
					yyonu=yr * sin((i * 2 * 3.1456)/360);
					glVertex2f(xyonu,yyonu);					
				}else if(i>=135 && i<180){
					xr-=0.0055555555555556;
					yr-=0.0055555555555556;
					xyonu=xr * cos((i * 2 * 3.1456)/360);
					yyonu=yr * sin((i * 2 * 3.1456)/360);
					glVertex2f(xyonu,yyonu);					
				}else if(i>=180 && i>270){
					xr+=0.0055555555555556;
					yr-=0.01;
					xyonu=xr * cos((i * 2 * 3.1456)/360);
					yyonu=yr * sin((i * 2 * 3.1456)/360);
					glVertex2f(xyonu,yyonu);					
				}else if(i>=270 && i<360){
					xr+=0.0055555555555556;
					yr+=0.01;
					xyonu=xr * cos((i * 2 * 3.1456)/360);
					yyonu=yr * sin((i * 2 * 3.1456)/360);
					glVertex2f(xyonu,yyonu);					
				}
			}			
			glEnd();   */
			
			//Kalbin sag tarafi
	    	yr1=0.4;
			xr1=0.4;
			glBegin (GL_POLYGON);
			glColor3f (1.0f, 0.0f, 0.0f);
			for(int i=314;i<=495;i+=1){
				xyonu1=xr1 * cos((i * 2 * 3.1456)/360)+0.284;
				yyonu1=yr1 * sin((i * 2 * 3.1456)/360)+0.28;
				glVertex2f(xyonu1,yyonu1);
			}			
			glEnd();    

			//kalbin sol tarafi
			yr2=0.4;
			xr2=0.4;
			glBegin (GL_POLYGON);
			glColor3f (1.0f, 0.0f, 0.0f);
			for(int i=45;i<=225;i+=1){
				xyonu2=xr2 * cos((i * 2 * 3.1456)/360)-0.284;
				yyonu2=yr2 * sin((i * 2 * 3.1456)/360)+0.28;
				
				glVertex2f(xyonu2,yyonu2);
			}			
			glEnd();


/*			konumx1 = yr2 * (cos(315 * 2 * 3.1456)/360);
			konumy1 = yr2 * (sin(315 * 2 * 3.1456)/360);
			konumx2 = yr2 * (cos(495 * 2 * 3.1456)/360);
			konumy2 = yr2 * (sin(495 * 2 * 3.1456)/360);
			konumx3 = yr2 * (cos(225 * 2 * 3.1456)/360);
			konumy3 = yr2 * (sin(255 * 2 * 3.1456)/360);
			konumx4 = (-1) * konumx3;
			konumy4 = (-1) * konumy3;    */
			
			glBegin (GL_QUADS);
			glColor3f(1.0f, 0.0f, 0.0f);  glVertex2f(0.565685424949238f, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);  glVertex2f(0.0f, 0.565685424949238f);
			glColor3f(1.0f, 0.0f, 0.0f);  glVertex2f(-0.565685424949238f, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);  glVertex2f(0.0f, -0.565685424949238f);
			glEnd();




            SwapBuffers (hDC);

 //           theta += 1.0f;
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
