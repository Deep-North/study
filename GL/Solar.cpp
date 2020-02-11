// GL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//#include "stdafx.h"

float sun, year, day, moon;		// Углы вращения
float
speedX, speedY,
rotMatrix[16] = {
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
},

dx = 0.0f, dy = 0.0, dz = -10.0f,
pos0[]       = { dx, dy, dz, 1 },
pos1[]       = { 1, 1, 1, 1},
spec[]       = { 0.9f, 0.9f, 0.9f },
spec1[]      = { 0.5f, 0.5f, 0.5f },
specPos1[]   = { 0.1f, 0.1f,0.1f },
colorSun[]   = { 1, 1, 0, 0.5 },
colorEarth[] = { 0, 0, 1, 0.5 },
colorMoon[]  = { 0.5, 0.5, 0.5, 1 },
colorEndl[]  = { 0, 0, 0, 1 },

speed = .1;

short posX, posY, deep;
bool leftButton, twoSide, normale = 1, deepType = 0, normaleLine = 0, sunRun, dayRun, yearRun, moonRun, flat = false;
//int maxDeep = 6;
float speedTest = 1;
//// Lighting values
//float  whiteLight1[] = { 0.1f, 0.1f, 0.1f, 1.0f };
float  whiteLight[] = { 0.3, 0.3, 0.3 };
float  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
float	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };


void addRotation(float angle, float x, float y, float z)
{
	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle, x, y, z);
	glMultMatrixf(rotMatrix);
	glGetFloatv(GL_MODELVIEW_MATRIX, rotMatrix);
	glPopMatrix();
}


void OnPaint(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();	// Запоминаем единичное значение ММ в стеке
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix); // Изменяем ММ


	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glRotatef(sun, 0, 1, 0);	// Вращаем систему координат

	glMaterialfv(GL_FRONT, GL_EMISSION, colorSun);
	glutSolidSphere(1, 30, 30);	// Рисуем Солнце
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glMaterialfv(GL_FRONT, GL_EMISSION, colorEndl);

	glPopMatrix();
	// sun end


	// earth
	glPushMatrix();

	glRotatef(year, 0, 1, 0);
	glTranslatef(3, 0, 0);
	glPushMatrix();

	glRotatef(day, 0, 1, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, colorEarth);
	glutSolidSphere(0.3, 20, 20); // Рисуем Землю

	glPopMatrix();

	//moon
	glRotatef(moon, 0, 1, 0);
	glTranslatef(0.7, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, colorMoon);
	glutSolidSphere(0.08, 20, 20);
	glPopMatrix();
	// end moon

	glPopMatrix();
	// earth end 

	glutSwapBuffers();
}


void OnSize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35, float(w) / h, .1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawScene() {}

void Init() {

	glClearColor(0.3, 0.3, 0.3, 0);

	if (flat) glShadeModel(GL_SMOOTH);
	else glShadeModel(GL_FLAT);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);

	glLightfv(GL_LIGHT1, GL_SPECULAR, spec1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  whiteLight);
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	DrawScene();
}



void onIdle() {
	//addRotation(speedY * .1, 0, 1, 0);
	//addRotation(speedX * .1, 1, 0, 0);

	if (sunRun)		sun		+= 0.1;
	if (moonRun)	moon	+= 0.5;
	if (dayRun)		day		+= 0.2;
	if (yearRun)	year	+= 0.1;

	glutPostRedisplay();
}



void onKeyboardFunc(byte key, int x, int y)
{
	switch (key) {
	case 's':
		sunRun = !sunRun;
		break;
	case 'd':
		dayRun = !dayRun;
		break;
	case 'm':
		moonRun = !moonRun;
		break;
	case 'y':
		yearRun = !yearRun;
		break;
	case 'z':
		dz -= speed;
		break;
	case 'x':
		dz += speed;
		break;
	case 'f':
		flat = !flat;
		if (flat) glShadeModel(GL_SMOOTH);
		else glShadeModel(GL_FLAT);
		break;
	}

	if (sunRun || dayRun || moonRun || yearRun) glutIdleFunc(onIdle);
	glutPostRedisplay();
}



void onSpecialKey(int key, int x, int y) {
	switch (key) {
	case 102:
		dx += speed;
		break;
	case 100:
		dx -= speed;
		break;
	case 101:
		dy += speed;
		break;
	case 103:
		dy -= speed;
		break;
	}
	glutPostRedisplay();
}


void onMouse(int button, int state, int x, int y) {
	leftButton = button == GLUT_LEFT_BUTTON;

	if (state == GLUT_DOWN) {
		speedX = speedY = 0;
		glutIdleFunc(0);
	}
	else {
		if (fabs(speedY) > 1. || fabs(speedX) > 1.) {
			glutIdleFunc(onIdle);
		}
	}
	posX = x;	// Запоминаем координаты мыши
	posY = y;
}


void onMouseMove(int x, int y)
{
	speedX = y - posY;
	speedY = x - posX;

	if (leftButton) {
		addRotation(speedY * .1, 0, 1, 0);
		addRotation(speedX * .1, 1, 0, 0);
	}
	else {
		dz += (speedY + speedX) / 60.;
	}
	posX = x;
	posY = y;
	glutPostRedisplay();
}


int main(int argc, char** argv) {

	//std::cout << "Start" << std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar system");

	Init();
	glutKeyboardFunc(onKeyboardFunc);
	glutSpecialFunc(onSpecialKey);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMouseMove);
	glutReshapeFunc(OnSize);
	glutDisplayFunc(OnPaint);
	glutIdleFunc(onIdle);
	glutMainLoop();
}