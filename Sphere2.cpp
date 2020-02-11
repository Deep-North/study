// GL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//#include "stdafx.h"

float gx = 0.35f, gy = 0.58f, gw, gh;
float
rotX, rotY,	//углы поворота
ax = 10, ay = 30, // Углы поворота изображения вокруг осей X и Y
dx, dy, dz = -6, // Сдвиги вдоль координат
color[] = { 0.1f, 0.6f, 0.1f };
short posX, posY; // Текущая позиция указателя мыши
bool leftButton, twoSide, // Нажата левая кнопка мыши. Свет отражается от обеих поверхностей (лицевой и обратной)
flat;

float v[8][3] = { -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1 }; //координаты точек куба
float norm[6][3] = { 0, 0, -1, 0, 0, 1, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1, 0 }; //нормали куба. их 6 штук по количеству граней

float rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }; //Матрица, суммирующая малые вращения

int id[6][4] = //массив определяет порядок выбора вершин (из массива v[8][3]) при создании 6 граней куба
{
	0, 1, 2, 3,	// Rear (CCW - counterclockwise)
	4, 5, 6, 7,	// Front
	0, 3, 5, 4,	// Left
	7, 6, 2, 1,	// Right
	0, 4, 7, 1,	// Top
	5, 3, 2, 6,	// Bottom
};

const uint
nRings = 20,	// Количество колец (широта)
nSects = 20, 	// Количество секций (долгота)
nTria = 2 * (nRings + 1) * nSects, // Общее количество треугольников
nVert = (nRings + 1) * nSects + 2; 	// Общее количество вершин

const uint clr1 = RGB(0, 255, 0), clr2 = RGB(0, 0, 255);	// Два цвета
const float
rad = 1.5f, 		// Радиус сферы
PI = acos(-1.0f);
float
pos[] = { 0, 0, 5, 0 },	// Позиция источника света
amb[] = { 0.05f, 0.05f, 0.05f },	// Фоновая подсветка 
dif[] = { 0.9f, 0.9f, 0.9f },	// Свет, обеспечивающий иллюзию трехмерности
spec[] = { 0.8f, 0.8f, 0.8f };	// Свет, обеспечивающий блик
char buf[128];		// Буфер текста
int shine = 40; 	// Блескость материала

//класс Point3D, инкапсулирующий функциональность точки трехмерного пространства(нормаль/координата точки)
class Point3D //координаты вершины (вещественных переменных x, y, z), вектор нормали (вещественных переменных x, y, z) и цвет
{
public:
	float x, y, z;//координаты

	Point3D() { x = y = z = 0.; }
	Point3D(float xx, float yy, float zz) { x = xx; y = yy; z = zz; }
	Point3D(float v[3]) { x = v[0]; y = v[1]; z = v[2]; }

	void operator+= (Point3D& p) { x += p.x;	 y += p.y; z += p.z; }
};

struct VERT { Point3D v, n; uint c; };  // Координаты вершины, нормали и ее цвет

struct TRIA { int i1, i2, i3; }; 	// Индексы трех вершин треугольника, выбираемых из массива вершин типа VERT



void OnSize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, double(w) / h, 0.6, 100);

	gw = w;
	gh = h;
	glScissor((int)(gx * w), (int)(gy * h), (int)(0.3f * w), (int)(0.3f * h));

}

void DrawScene()
{
	glNewList(1, GL_COMPILE); 	// Создаем новый список команд OpenGL
	glColor3fv(color);
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++)
	{
		glNormal3fv(norm[i]);
		for (int j = 0; j < 4; j++)
			glVertex3fv(v[id[i][j]]);
	}
	glEnd();
	glEndList();
}

void Sphere(VERT *v, TRIA* t)
{
	uint last = nVert - 1; // Индекс последней вершины (на южном полюсе)

	v[0].v = Point3D(0, rad, 0); // Формирование массива вершин. Северный полюс
	v[0].n = Point3D(0, 1, 0);
	v[0].c = clr2;

	v[last].v = Point3D(0, -rad, 0); // Южный полюс
	v[last].n = Point3D(0, -1, 0);
	v[last].c = nVert & 1 ? clr2 : clr1;

	float
		da = PI / (nRings + 2),
		db = 2 * PI / nSects,
		af = PI - da / 2,
		bf = 2 * PI - db / 2;

	uint n = 1;	// Индекс вершины, следующей за северным полюсом

	for (float a = da; a < af; a += da) 	// Цикл по широте
	{
		float
			y = rad * cos(a), 		// Координата y постоянна для всего кольца
			xz = rad * sin(a);

		for (float b = 0.; b < bf; n++, b += db) // Цикл по долготе
		{
			float // Координаты проекции в экваториальной плоскости
				x = xz * sin(b),
				z = xz * cos(b);

			v[n].v = Point3D(x, y, z);
			v[n].n = Point3D(x / rad, y / rad, z / rad);
			v[n].c = n & 1 ? clr1 : clr2;
		}
	}

	for (n = 0; n < nSects; n++) 	// Формирование массива индексов. Треугольники вблизи полюсов
	{
		t[n].i1 = 0; // Индекс общей вершины  (северный полюс)
		t[n].i2 = n + 1; // Индекс текущей вершины
		t[n].i3 = n == nSects - 1 ? 1 : n + 2; // Замыкание

		t[nTria - nSects + n].i1 = nVert - 2 - ((1 + n) % nSects); 	// Южный полюс
		t[nTria - nSects + n].i2 = nVert - 1;
		t[nTria - nSects + n].i3 = nVert - 2 - n;
	}

	int k = 1;		// Вершина, следующая за полюсом
	n = nSects;
	for (uint i = 0; i < nRings; i++, k += nSects) // Треугольники разбиения колец
	{
		for (uint j = 0; j < nSects; j++, n += 2)
		{
			t[n].i1 = k + j;
			t[n].i2 = k + nSects + j;
			t[n].i3 = k + nSects + ((j + 1) % nSects);

			t[n + 1].i1 = t[n].i1;
			t[n + 1].i2 = t[n].i3;
			t[n + 1].i3 = k + ((j + 1) % nSects);
		}
	}
}

void Init()
{
	strcpy_s(buf, "Directional");
	glClearColor(0, 0, 0, 0);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_CULL_FACE); 		// Culling говорит о том, что невидимые поверхности можно не рисовать
	glShadeModel(flat ? GL_FLAT : GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb); // Небольшая фоновая подсветка
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	VERT *Vert = new VERT[nVert];
	TRIA *Tria = new TRIA[nTria];

	Sphere(Vert, Tria); 	// Вычисление координат, нормалей и индексов

	// Задание адресов трех массивов (вершин, нормалей и цветов),  а также шага перемещения по ним
	glVertexPointer(3, GL_FLOAT, sizeof(VERT), &Vert->v);
	glNormalPointer(GL_FLOAT, sizeof(VERT), &Vert->n);
	glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(VERT), &Vert->c);

	glNewList(1, GL_COMPILE); 	// Формирование списка рисующих команд
	glDrawElements(GL_TRIANGLES, nTria * 3, GL_UNSIGNED_INT, Tria);
	glEndList();
	delete[] Vert;
	delete[] Tria;
}

void Print(float x, float y, const char *format, ...)
{
	va_list args;
	char buffer[200];
	va_start(args, format);
	vsprintf_s(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	for (char* p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p); // GLUT_STROKE_MONO_ROMAN // GLUT_STROKE_ROMAN
	glPopMatrix();
}

void DrawInfo()
{
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 3000, 0, 3000);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.7f, 1, 0);
	Print(80, 2800, "Rings: %d", nRings);
	Print(80, 2650, "Sects: %d", nSects);
	Print(80, 2500, "Triangles: %d", nTria);
	const char* direct = "directional";
	const char* positional = "positional";

	if (pos[3] == 0)	Print(80, 200, "Light is: %s", direct);
	else	Print(80, 200, "Light is: %s", positional);

	Print(80, 60, "Coordinates: (%3.1f, %3.1f, %3.1f, %3.1f)", pos[0], pos[1], pos[2], pos[3]);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}

void OnPaint()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	DrawInfo();

	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix);

	glCallList(1);

	glPopMatrix();
	glutSwapBuffers();
}


void AddRotation(float angle, float x, float y, float z)
{
	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle, x, y, z);
	glMultMatrixf(rotMatrix);
	glGetFloatv(GL_MODELVIEW_MATRIX, rotMatrix);
	glPopMatrix();
}

void OnIdle()
{
	AddRotation(rotX / 200, 1, 0, 0);
	AddRotation(rotY / 200, 0, 1, 0);
	glutPostRedisplay();
}

void OnMouse(int button, int state, int x, int y)
{
	leftButton = button == GLUT_LEFT_BUTTON;
	if (state == GLUT_DOWN)
	{
		glutIdleFunc(0);
		rotX = rotY = 0;
	}
	else
	{
		if (fabs(rotX) > 1 || fabs(rotY) > 1)
			glutIdleFunc(OnIdle);
		else
			glutIdleFunc(0);
	}
	posX = x;
	posY = y;
}


void OnMouseMove(int x, int y)
{
	rotX = y - posY;
	rotY = x - posX;

	if (leftButton)
	{
		AddRotation(rotX / 10, 1, 0, 0);
		AddRotation(rotY / 10, 0, 1, 0);
	}
	else
		dz += (rotX + rotY) / 60;
	posX = x;
	posY = y;
	glutPostRedisplay();
}


void OnKey(byte ch, int x, int y)
{
	switch (ch)
	{
	case 27: exit(0); break;
	case '2': glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, (twoSide = !twoSide)); break;
	}
	glutPostRedisplay();
}

void main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("");
	Init();
	glutMouseFunc(OnMouse);
	glutMotionFunc(OnMouseMove);
	glutKeyboardFunc(OnKey);

	glutReshapeFunc(OnSize);
	glutDisplayFunc(OnPaint);
	glutMainLoop();
	//=== Здесь нельзя размещать код, так как предыдущий оператор является псевдо бесконечным циклом выборки сообщений о событиях
}

