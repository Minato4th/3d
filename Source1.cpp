//#include <windows.h>
//
//#include <GL/gl.h>
//#pragma comment(lib,"OpenGL32.lib")
//#include <GL/glu.h>
//#pragma comment(lib,"Glu32.lib")
//
//#include "glaux.h"
//#pragma comment(lib,"glaux.lib")
//#pragma comment(lib, "legacy_stdio_definitions.lib")
//
//#include <math.h>
//
//#include<cmath>
//#include <iostream>
//
//#define RADGRAD 0.0174532925199433
//
//#define MAXH 150
//#define MAXS 150
//
//#define MAX_STEPS   25.0f       // Число шагов, составляющих линию
//
//// Создадим простенький класс для хранения вершин
//struct CVector3
//{
//public:
//	double x, y, z;
//};
//
//
//CVector3 PointOnCurve(CVector3 p1, CVector3 p2, CVector3 p3, CVector3 p4, double t)
//{
//	double var1, var2, var3;
//	CVector3 vPoint = { 0.0f, 0.0f, 0.0f };
//
//	var1 = 1 - t;
//	var2 = var1 * var1 * var1;
//	var3 = t * t * t;
//
//	vPoint.x = var2*p1.x + 3 * t*var1*var1*p2.x + 3 * t*t*var1*p3.x + var3*p4.x;
//	vPoint.y = var2*p1.y + 3 * t*var1*var1*p2.y + 3 * t*t*var1*p3.y + var3*p4.y;
//	vPoint.z = var2*p1.z + 3 * t*var1*var1*p2.z + 3 * t*t*var1*p3.z + var3*p4.z;
//
//	return(vPoint);
//}
//
//
////class cone0
////{
////protected:
////	int nh;
////	int ns;
////	double c[MAXH][MAXS][3];
////public:
////	cone0(int, int);
////	void drawcon();
////};
////
////cone0::cone0(int heightsegm, int sectors)
////{
////	int i, j;
////	nh = heightsegm;
////	ns = sectors;
////	if (nh > MAXH)
////		nh = MAXH;
////	else
////		if (nh < 1)
////			nh = 10;
////	if (ns > MAXS)
////		ns = MAXS;
////	else
////		if (ns < 3)
////			ns = 10;
////	double hstep = 1.0 / nh;
////	double astep = -360.0 / ns;
////	double hcur, acur, rcur;
////	hcur = 0.0;
////	for (i = 0; i<nh; i++)
////	{
////		hcur += hstep;
////		acur = 0.0;
////		rcur = hcur;
////		for (j = 0; j<ns; j++)
////		{
////			c[i][j][0] = rcur*cos(RADGRAD*acur);
////			c[i][j][1] = rcur*sin(RADGRAD*acur);
////			c[i][j][2] = hcur;
////			acur += astep;
////		}
////	}
////}
////void cone0::drawcon()
////{
////	int i, j;
////	glBegin(GL_TRIANGLE_FAN);
////	glVertex3d(0., 0., 0.);
////	for (j = 0; j<ns; j++)
////		glVertex3dv(c[0][j]);
////	glVertex3dv(c[0][0]);
////	glEnd();
////	for (i = 0; i<nh - 1; i++)
////	{
////		glBegin(GL_TRIANGLE_STRIP);
////		for (j = 0; j<ns; j++)
////		{
////			glVertex3dv(c[i + 1][j]);
////			glVertex3dv(c[i][j]);
////		}
////		glVertex3dv(c[i + 1][0]);
////		glVertex3dv(c[i][0]);
////		glEnd();
////	}
////}
////static cone0 c1(10, 30);
//
//void CALLBACK resize(int width, int height)
//{
//	// Здесь указывается часть окна в пределах которой
//	// будут рисовать функции OpenGL.
//	GLuint wp = width<height ? width - 20 : height - 20;
//	glViewport(10, 10, wp, wp);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	// Устанавливаем тип проекции.
//	// glOrtho - параллельная
//	// glFrustum - перспектива
//	// Параметры о обеих функции идентичны:
//	// они задают объем видимости
//	glOrtho(-6.2, 6.2, -6.2, 6.2, 2., 12.);
//	// glFrustum(-5,5, -5,5, 2,12);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//GLdouble gl = 90;
//void CALLBACK display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	// glClear( GL_COLOR_BUFFER_BIT );
//	// glClear( GL_DEPTH_BUFFER_BIT );
//	glPushMatrix();
//	glTranslated(0., 0., -6.0);
//	//glRotated(35., 1., 0., 0.);
//	//glRotated(-35., 0., 1., 0.);
//
//	//glRotated(90, 0., 1., 0.);
//	glRotated(gl, 1., 1., 1.);
//	//glRotated(gl, 0., 0., 1.);
//
//	gl = gl + 0.01;
//	glPointSize(10.0f);
//	glEnable(GL_POINT_SMOOTH);
//	glBegin(GL_POINTS);
//	glColor3d(0, 0, 0);
//	glVertex3f(0.f, 0.f, 0.f);
//	glEnd();
//	glDisable(GL_POINT_SMOOTH);
//	glLineWidth(1.5f);
//	glEnable(GL_LINE_SMOOTH);
//	glBegin(GL_LINES);
//	// Axa X RED
//	glColor3d(0., 0., 0.);
//	glVertex3d(-5.5, 0., 0.);
//
//	glColor3d(1., 0., 0.);
//	glVertex3d(5.5, 0., 0.);
//	// Axa Y Green
//	glColor3d(0., 0., 0.);
//	glVertex3d(0., -5.5, 0.);
//	glColor3d(0., 1., 0.);
//	glVertex3d(0., 5.5, 0.);
//	// Axa Z Blue
//	glColor3d(0., 0., 0.);
//	glVertex3d(0., 0., -5.5);
//	glColor3d(0., 0., 1.);
//	glVertex3d(0., 0., 5.5);
//	glEnd();
//	// Con X
//	glColor3d(1, 0, 0);
//	glPushMatrix();
//	glTranslated(5.3f, 0.0f, 0.0f);
//	glRotated(90, 0.0f, 1.0f, 0.0f);
//	auxSolidCone(0.1f, 0.2f);
//	glPopMatrix();
//	// Con Y
//	glColor3d(0, 1, 0);
//	glPushMatrix();
//	glTranslated(0.0f, 5.3f, 0.0f);
//	glRotated(-90, 1.0f, 0.0f, 0.0f);
//	auxSolidCone(0.1f, 0.2f);
//	glPopMatrix();
//	// Con Z
//	glColor3d(0, 0, 1);
//	glPushMatrix();
//	glTranslated(0.0f, 0.0f, 5.3f);
//	auxSolidCone(0.1f, 0.2f);
//	glPopMatrix();
//	//VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
//	// Здесь будем вставлять фрагменты кода для различных примеров
//	// в процессе изучения функций OpenGL
//
//
//	//bizie1
//
//	double g_CurrentTime = 0.0f; // Текущая позиция сферы на кривой (между 0 и 1)
//
//	CVector3 g_vStartPoint = { 0.16,  1,  3 };   // Стартовая точка кривой
//	CVector3 g_vControlPoint1 = { 0.66,  1,  1.65 };   // Первая контрольная точка
//	CVector3 g_vControlPoint2 = { 1.3,  1,  1.65 };   // Вторая контрольная точка
//	CVector3 g_vEndPoint = { 1.88,  1,  3 };   // Конечная точка кривой
//
//
//	CVector3 vPoint = { 0.0f, 0.0f, 0.0f };
//
//	glBegin(GL_LINE_STRIP);
//	for (double t = 0; t <= (1 + (1.0f / MAX_STEPS)); t += 1.0f / MAX_STEPS)
//	{
//
//		vPoint = PointOnCurve(g_vStartPoint, g_vControlPoint1, g_vControlPoint2, g_vEndPoint, t);
//
//		glVertex3f(vPoint.x, vPoint.y, vPoint.z);
//	}
//
//	glEnd();
//
//	//bizie2
//	g_CurrentTime = 0.0f; // Текущая позиция сферы на кривой (между 0 и 1)
//
//	g_vStartPoint = { 0.16,  1,  -3 };   // Стартовая точка кривой
//	g_vControlPoint1 = { 0.66,  1,  -1.65 };   // Первая контрольная точка
//	g_vControlPoint2 = { 1.3,  1, -1.65 };   // Вторая контрольная точка
//	g_vEndPoint = { 1.88,  1,  -3 };   // Конечная точка кривой
//
//	vPoint = { 0.0f, 0.0f, 0.0f };
//
//	glBegin(GL_LINE_STRIP);
//	for (double t = 0; t <= (1 + (1.0f / MAX_STEPS)); t += 1.0f / MAX_STEPS)
//	{
//
//		vPoint = PointOnCurve(g_vStartPoint, g_vControlPoint1, g_vControlPoint2, g_vEndPoint, t);
//
//		glVertex3f(vPoint.x, vPoint.y, vPoint.z);
//	}
//
//	glEnd();
//
//
//	//bizie2
//	g_CurrentTime = 0.0f; // Текущая позиция сферы на кривой (между 0 и 1)
//
//	g_vStartPoint = { 0.16,  1,  -3 };   // Стартовая точка кривой
//	g_vControlPoint1 = { 0.66,  1,  -1.65 };   // Первая контрольная точка
//	g_vControlPoint2 = { 1.3,  1, -1.65 };   // Вторая контрольная точка
//	g_vEndPoint = { 1.88,  1,  -3 };   // Конечная точка кривой
//
//	vPoint = { 0.0f, 0.0f, 0.0f };
//
//	glBegin(GL_LINE_STRIP);
//	for (double t = 0; t <= (1 + (1.0f / MAX_STEPS)); t += 1.0f / MAX_STEPS)
//	{
//
//		vPoint = PointOnCurve(g_vStartPoint, g_vControlPoint1, g_vControlPoint2, g_vEndPoint, t);
//
//		glVertex3f(vPoint.x, vPoint.y, vPoint.z);
//	}
//
//	glEnd();
//
//
//	//bizie3
//	double g_spX = 0.84;
//	double g_spY = 0.0;
//	double g_spZ = 3.0; //-
//	double g_cp1X = 0.44;
//	double g_cp1Y = 0.0;
//	double g_cp1Z = 1.65; // -
//	double g_cp2X = -0.3;
//	double g_cp2Y = 0.0;
//	double g_cp2Z = 1.65; //-
//	double g_epX = -0.88;
//	double g_epY = 0.0;
//	double g_epZ = 3.0; // -
//
//	double x_start = 1.0;
//	double y_start = -1.0;
//	double z_start = 1.0;
//
//	double y_change = 1;
//	double radi_y = 4.07 - 0.415; //stan
//	double point_y = radi_y * sinf(y_change);
//
//	double x_change = 0.5;
//	double radi_x = 0.86; //stan
//	double point_x = radi_x * cosf(x_change);
//	//std::cout << point << std::endl;
//
//	double pr = 1; // от ноля до + бесконечности(надо додумать в зависимости от проекции)
//
//	for (double i = -1; i < 2; i = i + 2)
//	{
//
//		if (i == -1) {
//
//			g_vStartPoint = { (x_start - g_spX) * pr,  (y_start - g_spY + point_y + y_change) * pr,  (z_start - g_spZ * i) * pr };   // Стартовая точка кривой
//			g_vControlPoint1 = { (x_start - g_cp1X) * pr,  (y_start - g_cp1Y + point_y) * pr,  (z_start - g_cp1Z * i) * pr };   // Первая контрольная точка
//			g_vControlPoint2 = { (x_start - g_cp2X) * pr,  (y_start - g_cp2Y + point_y) * pr,  (z_start - g_cp2Z * i) * pr };   // Вторая контрольная точка
//			g_vEndPoint = { (x_start - g_epX) * pr,  (y_start - g_epY + point_y + y_change) * pr,  (z_start - g_epZ * i) * pr };   // Конечная точка кривой
//
//		}
//		else
//		{
//			g_vStartPoint = { (x_start - g_spX) * pr,  (y_start - g_spY) * pr,  (z_start - g_spZ * i + 0.5) * pr };   // Стартовая точка кривой
//			g_vControlPoint1 = { (x_start - g_cp1X) * pr,  (y_start - g_cp1Y + y_change*i) * pr,  (z_start - g_cp1Z * i - 0.5) * pr };   // Первая контрольная точка
//			g_vControlPoint2 = { (x_start - g_cp2X) * pr,  (y_start - g_cp2Y + y_change*i) * pr,  (z_start - g_cp2Z * i - 0.5) * pr };   // Вторая контрольная точка
//			g_vEndPoint = { (x_start - g_epX) * pr,  (y_start - g_epY) * pr,  (z_start - g_epZ * i + 0.5) * pr };   // Конечная точка кривой
//
//		}
//
//
//		vPoint = { 0.0f, 0.0f, 0.0f };
//
//		g_CurrentTime = 0.0f; // Текущая позиция сферы на кривой (между 0 и 1)
//
//		glBegin(GL_LINE_STRIP);
//		for (double t = 0; t <= (1 + (1.0f / MAX_STEPS)); t += 1.0f / MAX_STEPS)
//		{
//			vPoint = PointOnCurve(g_vStartPoint, g_vControlPoint1, g_vControlPoint2, g_vEndPoint, t);
//			glVertex3f(vPoint.x, vPoint.y, vPoint.z);
//		}
//
//		glEnd();
//
//	}
//
//
//
//
//
//
//	//glPointSize(5);
//	//glEnable(GL_POINT_SMOOTH);
//	//glBegin(GL_POINTS);
//	//glColor3d(0, 0, 0);
//	//glVertex3d(1, 2, 0); // первая точка
//	//glEnd();
//
//	// изменение будет порпорциаональное при росте или уменьшении
//	// построить согласно точке в пространстве исходя из соотношений
//	// построить согласно углу для y z
//
//
//	/*glPushMatrix();
//	glTranslated(0., 0., 1.);
//	glScaled(2., 2., 3.);
//	glColor3d(1., 0., 1.);
//	c1.drawcon();
//	glPopMatrix();*/
//
//	/*const GLubyte mask[32 * 4] =
//	{
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0xF0, 0xF0, 0xF0, 0xF0,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F,
//	0x0F, 0x0F, 0x0F, 0x0F
//	};
//
//	glEnable(GL_POLYGON_STIPPLE);
//	glPolygonStipple(mask);
//	glBegin(GL_QUADS);
//	glColor3d(1., 0., 0.);
//	glVertex3d(-5., -5., -2.);
//	glVertex3d(-5., 5., -2.);
//	glVertex3d(5., 5., -2.);
//	glVertex3d(5., -5., -2.);
//	glEnd();*/
//
//
//	/*glBegin(GL_TRIANGLE_STRIP);
//	glColor3d(1., 0., 0.);
//	glVertex3d(-2.5, -2.5, -1.);
//	glVertex3d(-2.5, 2.5, -1.);
//	glVertex3d(2.5, 2.5, -1.);
//	glVertex3d(2.5, 5., 10.);
//	glVertex3d(2.5, -2.5, -1.);
//	glEnd();*/
//	/*glEnable(GL_POLYGON_SMOOTH);
//	glBegin(GL_QUADS);
//	glColor3d(1., 0., 0.);
//	glVertex3d(-5., -5., -2.);
//	glVertex3d(-5., 5., -2.);
//	glVertex3d(5., 5., -2.);
//	glVertex3d(5., -5., -2.);
//	glEnd();*/
//
//
//	/*glBegin(GL_TRIANGLE_FAN);
//	glColor3d(0, 0, 0);
//
//	int amountSegments = 50;
//	int r = 1;
//	int r2 = 2;
//	float x = 0.1;
//	float y = 0.1;
//
//	glVertex3f(0, 0, -2);
//
//	for (size_t i = 0; i < amountSegments / 2 + 1; i++)
//	{
//	float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
//
//	float dx = r * cosf(angle);
//	float dy = r2 * sinf(angle);
//
//	glVertex3f(x + dx, y + dy, 4);
//	}
//
//	glEnd();*/
//
//
//	// Oval1
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	int amountSegments = 100;
//	int r = 1;
//	int r2 = 2;
//	float x = 1;
//	float y = -4;
//
//	/*float y1 = 1;
//	float y2 = -2;
//	float lin3 = (y2 - y1) / amountSegments;
//	y1 = 0;*/
//
//	for (size_t i = 0; i < amountSegments / 2 + 1; i++)
//	{
//		//y1 = y1 + lin3;
//		if (i > amountSegments / 2 * 0.15 && i < amountSegments / 2 * 0.85)
//		{
//			float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
//
//			float dx = r * cosf(angle);
//			float dy = r2 * sinf(angle);
//			/*float dz = y1 * atan(angle);
//			y1 = y1 + lin3;*/
//			glVertex3f(x + dx, 2, y + dy);
//
//		}
//
//	}
//	glEnd();
//
//	// Oval2
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	amountSegments = 50;
//	r = -1;
//	r2 = -2;
//	x = 1;
//	y = 4;
//
//	for (size_t i = 0; i < amountSegments / 2 + 1; i++)
//	{
//
//		if (i > amountSegments / 2 * 0.15 && i < amountSegments / 2 * 0.85)
//		{
//			float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
//
//			float dx = r * cosf(angle);
//			float dy = r2 * sinf(angle);
//
//			glVertex3f(x + dx, 2, y + dy);
//
//		}
//
//
//	}
//	glEnd();
//
//
//	//BigLine1
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	amountSegments = 50;
//	x = -2.05; //begin
//	y = 2.02; // end
//	float lin = (abs(x) + abs(y)) / amountSegments;
//
//	for (size_t i = 0; i < amountSegments; i++)
//	{
//
//		x = x + lin;
//		glVertex3f(1, 2, x);
//
//
//		//std::cout << x << std::endl;
//	}
//	glEnd();
//
//	//BigLine2
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	amountSegments = 50;
//	x = -1.05; //begin
//	y = 3.02; // end
//	lin = (abs(x) + abs(y)) / amountSegments;
//
//	for (size_t i = 0; i < amountSegments; i++)
//	{
//
//		x = x + lin;
//		glVertex3f(x, 2, 0);
//
//
//		//std::cout << x << std::endl;
//	}
//	glEnd();
//
//
//	//LittleLine1
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	amountSegments = 50;
//	x = -2.0; //begin
//	y = -1.0; // end
//	lin = (y - x) / amountSegments;
//
//	float z1 = -1.0; //begin
//	float z2 = 0.0; // end
//	float lin2 = (abs(z1) + abs(z2)) / amountSegments;
//	z2 = (z2 - z1) / 2;
//
//	for (size_t i = 0; i < amountSegments; i++)
//	{
//		z1 = z1 + lin2;
//		x = x + lin;
//		glVertex3f(x, 2, z1);
//
//		//std::cout << x << std::endl;
//	}
//	glEnd();
//
//
//	//LittleLine2
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	amountSegments = 50;
//	x = -2.0; //begin
//	y = -1.0; // end
//	lin = (y - x) / amountSegments;
//
//	z1 = 1.0; //begin
//	z2 = 0.0; // end
//	lin2 = (z2 - z1) / amountSegments;
//
//
//	for (size_t i = 0; i < amountSegments; i++)
//	{
//		z1 = z1 + lin2;
//		x = x + lin;
//		glVertex3f(x, 2, z1);
//
//		//std::cout << x << std::endl;
//	}
//	glEnd();
//
//	//LittleLine3
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	amountSegments = 50;
//	x = 3.0; //begin
//	y = 4.0; // end
//	lin = (y - x) / amountSegments;
//
//	z1 = 0.0; //begin
//	z2 = -1.0; // end
//	lin2 = (z2 - z1) / amountSegments;
//
//	for (size_t i = 0; i < amountSegments; i++)
//	{
//		z1 = z1 + lin2;
//		x = x + lin;
//		glVertex3f(x, 2, z1);
//
//		//std::cout << x << std::endl;
//	}
//	glEnd();
//
//
//	//LittleLine4
//	glBegin(GL_LINE_STRIP);
//	glColor3d(100, 0, 0);
//
//	amountSegments = 50;
//	x = 3.0; //begin
//	y = 4.0; // end
//	lin = (y - x) / amountSegments;
//
//	z1 = 0.0; //begin
//	z2 = 1.0; // end
//	lin2 = (z2 - z1) / amountSegments;
//
//	for (size_t i = 0; i < amountSegments; i++)
//	{
//		z1 = z1 + lin2;
//		x = x + lin;
//		glVertex3f(x, 2, z1);
//
//		//std::cout << x << std::endl;
//	}
//	glEnd();
//
//	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//	glPopMatrix();
//	auxSwapBuffers();
//}
//void main()
//{
//	// Устанавливаем координаты окна на экране
//	// левый верхний угол (0,0)
//	// ширина и высота - 500
//	auxInitPosition(0, 0, 500, 500);
//	// Устанавливаем параметры контекста OpenGL
//	auxInitDisplayMode(AUX_RGB | AUX_DEPTH | AUX_DOUBLE);
//	// Создаем окно на экране
//	auxInitWindow((LPCWSTR)("OpenGL"));
//	// Это окно будет получать сообщения о событиях
//	// от клавиатуры, мыши, таймера и любые другие сообщения.
//	// Пока не поступают никакие сообщения циклически будет
//	// вызываться функция display().
//	// Так можно создавать анимации.
//	// Если нужно статическое изображение
//	// следующая строка может быть закомментирована
//	auxIdleFunc(display);
//	// В случае изменения размеров окна – поступает
//	// соответствующее сообщение
//	// В Windows - это WM_SIZE.
//	// Указываем, что функция resize() должна быть вызвана
//	// каждый раз когда изменяются размеры окна
//	auxReshapeFunc(resize);
//	// Далее задаем ряд тестов и параметров
//	// Включается тест прозрачности, т.е. будет приниматься во
//	// внимание 4-й параметр при в glColor()
//	glEnable(GL_ALPHA_TEST);
//	// Тест глубины
//	glEnable(GL_DEPTH_TEST);
//	// Функция glColor() будет задавать
//	// свойства материалов.
//	// Следовательно, отсутствует необходимость
//	// в дополнительном вызове функции glMaterialfv()
//	glEnable(GL_COLOR_MATERIAL);
//	// Разрешаем освешение
//	glEnable(GL_LIGHTING);
//	// Активируем источник освещения с нлмером 0
//	glEnable(GL_LIGHT0);
//	// Задаем позицию источника освещения
//	float pos[4] = { 3,3,3,1 };
//	float dir[3] = { -1,-1,-1 };
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
//	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
//	// Разрешаем смешивание цветов (для прозрачных поверхностей)
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	// Устанавливаем цвет начальной закраски окна
//	glClearColor(1.f, 1.f, 1.f, 1.f);
//	// Указываем, что функция display() должна использоваться для
//	// перерисовки окна.
//	// Эта функция будет вызвана каждый раз когда возникает
//	// необходимость в перерисовки окна,
//	// т.е. при поступлении сообщения WM_PAINT от Windows
//	// Например, когда окно развертывается на весь экран.
//	auxMainLoop(display);
//}
