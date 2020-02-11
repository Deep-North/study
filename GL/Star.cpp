// GL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//#include "stdafx.h"

float gx = 0.35f, gy = 0.58f, gw, gh;

//==== Макроподстановка для изображения одной линии. Знаки переноса важны !!!
#define Line(x1,y1,x2,y2) \
glBegin(GL_LINES);  \
	glVertex2f((x1),(y1)); \
	glVertex2f((x2),(y2)); \
glEnd();

GLubyte Spade[] = 	// Узор – пики
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x1f, 0xff, 0xff, 0xf8, 0x1f, 0x00, 0x00, 0xf8,
	0x01, 0xc0, 0x03, 0x80, 0x00, 0x70, 0x0e, 0x00,
	0x00, 0x20, 0x04, 0x00, 0x00, 0x30, 0x0c, 0x00,
	0x00, 0x10, 0x08, 0x00, 0x00, 0x18, 0x18, 0x00,
	0x07, 0xc4, 0x23, 0xe0, 0x0f, 0xf8, 0x1f, 0xf0,
	0x38, 0x1c, 0x38, 0x1c, 0x30, 0x00, 0x00, 0x0c,
	0x60, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x06,
	0x60, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x06,
	0x60, 0x00, 0x00, 0x06, 0x30, 0x00, 0x00, 0x0c,
	0x30, 0x00, 0x00, 0x0c, 0x18, 0x00, 0x00, 0x18,
	0x0e, 0x00, 0x00, 0x70, 0x03, 0x00, 0x00, 0xc0,
	0x00, 0xc0, 0x03, 0x00, 0x00, 0x70, 0x0e, 0x00,
	0x00, 0x18, 0x18, 0x00, 0x00, 0x0c, 0x30, 0x00,
	0x00, 0x07, 0xe0, 0x00, 0x00, 0x03, 0xc0, 0x00,
	0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00
};

GLubyte Strip[] = // Другой узор — «в полоску»
{
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
	0x66, 0x66, 0x66, 0x66, 0x33, 0x33, 0x33, 0x33,
};


void OnPaint()
{
	static byte clrs[][3] =	// На сей раз испробуем задание цвета с помощью байтов
	{
		255, 0, 255,  0, 0, 255,  0, 255, 255,  255, 255, 0,  255, 100, 50
	};

	glClear(GL_COLOR_BUFFER_BIT);
	double
		pi = acos(-1.),
		angle = pi / 2,
		da = 0.8 * pi;

	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; i++, angle += da)
	{
		glColor3ubv(clrs[i]);
		glVertex2d(cos(angle), sin(angle));
	}
	glEnd();
	glFlush();
}





void OnSize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1); 	// Режим ортографической проекции

	gw = w;
	gh = h;
	glScissor((int)(gx * w), (int)(gy * h), (int)(0.3f * w), (int)(0.3f * h));

}

void Init()
{
	glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);
	glPointSize(10);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_POLYGON_STIPPLE);
	//glDisable(GL_POLYGON_STIPPLE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);	// Режим изображения полигона
}


void OnSpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: gx -= 0.005f; break;
	case GLUT_KEY_RIGHT: gx += 0.005f; break;
	case GLUT_KEY_DOWN: gy -= 0.005f; break;
	case GLUT_KEY_UP:  gy += 0.005f; break;
	}
	glScissor((int)(gx * gw), (int)(gy * gh), (int)(0.3f * gw), (int)(0.3f * gh));
	glutPostRedisplay();
}


void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("");
	Init();
	glutSpecialFunc(OnSpecialKey);
	glutReshapeFunc(OnSize);
	glutDisplayFunc(OnPaint);
	glutMainLoop();
	//=== Здесь нельзя размещать код, так как предыдущий оператор является псевдо бесконечным циклом выборки сообщений о событиях
}

