#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <conio.h>
#include <string>

#define WINDOW_TITLE "Practical 1"

int page = 0;
LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case VK_LEFT:
			page--;
			break;
		case VK_RIGHT:
			page++;
			break;
		}
		break;


	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void drawCircle() {
	//Japan
	float x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
	float angle = 0.0;
	float radius = 0.5;

	
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x1, y1);

	for (angle = 0; angle <= 360.0; angle += 0.2) {
		x2 = x1 + cos(angle) * radius;
		y2 = y1 + sin(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawCircleSmile() {
	//Japan
	float x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
	float angle = 0.0;
	float radius = 0.5;


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(255, 255, 0.0);
	glVertex2f(x1, y1);

	for (angle = 0; angle <= 360.0; angle += 0.2) {
		x2 = x1 + cos(angle) * radius;
		y2 = y1 + sin(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void smileyFace() {

	float x, y;

	glEnable(GL_BLEND);
	drawCircleSmile();

	// outline
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < 180; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(180);
		float x = 0.5 * cosf(theta);
		float y = 0.5 * sinf(theta);
		glVertex2f(x + 0, y + 0);
	}
	glEnd();
	//1st eye
	int t;

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 360; t += 1)
	{
		x = 0.15 * sin((2 * t * 3.14) / 360) * 0.5 + 0.10;
		y = 0.20 * cos((2 * t * 3.14) / 360) * 0.5 + 0.13;
		float z = 0;
		glVertex3f(x, y, z);
	}
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 360; t += 1)
	{
		x = 0.15 * sin((2 * t * 3.14) / 360) * 0.5 + -0.10;
		y = 0.20 * cos((2 * t * 3.14) / 360) * 0.5 + 0.13;
		float z = 0;
		glVertex3f(x, y, z);
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 360; t += 1)
	{
		x = 0.15 * sin((2 * t * 3.14) / 360) * 0.25 + 0.08;
		y = 0.20 * cos((2 * t * 3.14) / 360) * 0.25 + 0.15;
		float z = 0;
		glVertex3f(x, y, z);
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 360; t += 1)
	{
		x = 0.15 * sin((2 * t * 3.14) / 360) * 0.25 +-0.12;
		y = 0.20 * cos((2 * t * 3.14) / 360) * 0.25 + 0.15;
		float z = 0;
		glVertex3f(x, y, z);
	}
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 360; t += 1)
	{
		x = 0.15 * sin((2 * t * 3.14) / 360) * 0.08 + 0.14;
		y = 0.20 * cos((2 * t * 3.14) / 360) * 0.08 + 0.10;
		float z = 0;
		glVertex3f(x, y, z);
	}
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 360; t += 1)
	{
		x = 0.15 * sin((2 * t * 3.14) / 360) * 0.08 + -0.06;
		y = 0.20 * cos((2 * t * 3.14) / 360) * 0.08 + 0.10;
		float z = 0;
		glVertex3f(x, y, z);
	}
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 360; t += 1)
	{
		x = 0.15 * sin((2 * t * 3.14) / 360) * 0.3 + 0.0;
		y = 0.20 * cos((2 * t * 3.14) / 360) * 0.3 + -0.10;
		float z = 0;
		glVertex3f(x, y, z);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	for (int i = 240; i < 300; i++)
	{
		glBegin(GL_POINTS);
		x = cos((2 * i * 3.14) / 360) * .2;
		y = sin((2 * i * 3.14) / 360) * .7 + 0.4;
		glVertex2f(x, y);
		glEnd();
	}



	
}

void drawFlag(int num) {
	if (num == -1)
	{
		page = 5;
	}
	if (num == 6)
	{
		page = 0;
	}

	switch (num)
	{
	
	case 0:
		//Pahang
		glBegin(GL_QUADS);
		{
			glColor3ub(255, 255, 255);

			glVertex2f(-1.0f, 1.0f);
			glVertex2f(1.0f, 1.0f);
			glVertex2f(1.0f, 0.0f);
			glVertex2f(-1.0f, 0.0f);
			glEnd();
		}

		glBegin(GL_QUADS);
		{
			glColor3ub(0, 0, 0);

			glVertex2f(-1.0f, 0.0f);
			glVertex2f(1.0f, 0.0f);
			glVertex2f(1.0f, -1.0f);
			glVertex2f(-1.0f, -1.0f);
			glEnd();
		}
		break;
	case 1:
		//Negeri Sembilan
		glBegin(GL_QUADS);
		{
			glColor3ub(255, 255, 51);
			glVertex2f(-1.0f, 1.0f);
			glVertex2f(1.0f, 1.0f);
			glVertex2f(1.0f, -1.0f);
			glVertex2f(-1.0f, -1.0f);
			glEnd();
		}

		glBegin(GL_TRIANGLES); {
			glColor3ub(0, 0, 0);
			glVertex2f(-1.0f,1.0f);
			glVertex2f(-1.0f,0.0f);
			glVertex2f(0.0f,1.0f);
			glEnd();
		}

		glBegin(GL_TRIANGLES); {
			glColor3ub(255, 0, 0);
			glVertex2f(0.0f, 1.0f);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(-1.0f, 0.0f);
			glEnd();
		}
	break;
	case 2:
		//England
		glBegin(GL_QUADS);
		glColor3f(255, 0, 0);
		glVertex2f(1, 0.1);
		glVertex2f(1, -0.1);
		glVertex2f(-1, -0.1);
		glVertex2f(-1, 0.1);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(255, 0, 0);
		glVertex2f(0.1, 1);
		glVertex2f(-0.1, 1);
		glVertex2f(-0.1, -1);
		glVertex2f(0.1, -1);
		glEnd();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glBegin(GL_QUADS);
		glColor4f(0.4f, 0.4f, 0.4f, 0.2);
		glVertex2f(-1, 1);
		glVertex2f(-0.1, 1);
		glColor4f(1, 1, 1, 0);
		glVertex2f(-0.1, 0.1);
		glVertex2f(-1, 0.1);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0.4f, 0.4f, 0.4f, 0.2);
		glVertex2f(0.1, 1);
		glVertex2f(1, 1);
		glColor4f(1, 1, 1, 0);
		glVertex2f(1, 0.1);
		glVertex2f(0.1, 0.1);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0.4f, 0.4f, 0.4f, 0.2);
		glVertex2f(-1, -0.1);
		glVertex2f(-0.1, -0.1);
		glColor4f(1, 1, 1, 0);
		glVertex2f(-0.1, -1);
		glVertex2f(-1, -1);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0.4f, 0.4f, 0.4f, 0.2);
		glVertex2f(0.1, -0.1);
		glVertex2f(1, -0.1);
		glColor4f(1, 1, 1, 0);
		glVertex2f(1, -1);
		glVertex2f(0.1, -1);
		glEnd();

		break;
	case 3:
		//Scotland
		glBegin(GL_QUADS);
		{
			glColor3ub(0, 76, 153);
			glVertex2f(-1.0f, 1.0f);
			glVertex2f(1.0f, 1.0f);
			glVertex2f(1.0f, -1.0f);
			glVertex2f(-1.0f, -1.0f);
			glEnd();
		}

		glBegin(GL_POLYGON);
		{
			glColor3ub(255, 255, 255);
			glVertex2f(-1.0f, 0.8f);
			glVertex2f(-1.0f, 1.0f);
			glVertex2f(-0.8f, 1.0f);

			glVertex2f(1.0f, -0.8f);
			glVertex2f(1.0f, -1.0f);
			glVertex2f(0.8f, -1.0f);

			glEnd();
		}

		glRotatef(90, 0, 0, 1);
		glBegin(GL_POLYGON);
		{
			glColor3ub(255, 255, 255);
			glVertex2f(-1.0f, 0.8f);
			glVertex2f(-1.0f, 1.0f);
			glVertex2f(-0.8f, 1.0f);

			glVertex2f(1.0f, -0.8f);
			glVertex2f(1.0f, -1.0f);
			glVertex2f(0.8f, -1.0f);

			glEnd();
		}
		glRotatef(-90, 0, 0, 1);
		break;
	case 4:
		glBegin(GL_QUADS);
		{
			glColor3ub(255, 255, 255);
			glVertex2f(-0.9f, 0.9f);
			glVertex2f(0.9f, 0.9f);
			glVertex2f(0.9f, -0.9f);
			glVertex2f(-0.9f, -0.9f);
		}
		glEnd();

		glColor3ub(255, 0, 0);
		drawCircle();
		break;
	case 5:
		smileyFace();
		break;
	
		
	default:
		break;
	}
}

void display()
{

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawFlag(page);

}
//--------------------------------------------------------------------

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance,
	_In_ LPSTR cmdLine, _In_ int nCmdShow) // FIXED
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------