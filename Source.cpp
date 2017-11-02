#include <windows.h>

#include <GL/gl.h>
#pragma comment(lib,"OpenGL32.lib")
#include <GL/glu.h>
#pragma comment(lib,"Glu32.lib")

#include "glaux.h"
#pragma comment(lib,"glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

#include <math.h>

#include<cmath>
#include <iostream>

#define RADGRAD 0.0174532925199433

#define MAXH 150
#define MAXS 150

class cone0
{
protected:
	int nh;
	int ns;
	double c[MAXH][MAXS][3];
public:
	cone0(int, int);
	void drawcon();
};

cone0::cone0(int heightsegm, int sectors)
{
	int i, j;
	nh = heightsegm;
	ns = sectors;
	if (nh > MAXH)
		nh = MAXH;
	else
		if (nh < 1)
			nh = 10;
	if (ns > MAXS)
		ns = MAXS;
	else
		if (ns < 3)
			ns = 10;
	double hstep = 1.0 / nh;
	double astep = -360.0 / ns;
	double hcur, acur, rcur;
	hcur = 0.0;
	for (i = 0; i<nh; i++)
	{
		hcur += hstep;
		acur = 0.0;
		rcur = hcur;
		for (j = 0; j<ns; j++)
		{
			c[i][j][0] = rcur*cos(RADGRAD*acur);
			c[i][j][1] = rcur*sin(RADGRAD*acur);
			c[i][j][2] = hcur;
			acur += astep;
		}
	}
}
void cone0::drawcon()
{
	int i, j;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0., 0., 0.);
	for (j = 0; j<ns; j++)
		glVertex3dv(c[0][j]);
	glVertex3dv(c[0][0]);
	glEnd();
	for (i = 0; i<nh - 1; i++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (j = 0; j<ns; j++)
		{
			glVertex3dv(c[i + 1][j]);
			glVertex3dv(c[i][j]);
		}
		glVertex3dv(c[i + 1][0]);
		glVertex3dv(c[i][0]);
		glEnd();
	}
}
static cone0 c1(10, 30);

void CALLBACK resize(int width, int height)
{
	// Здесь указывается часть окна в пределах которой
	// будут рисовать функции OpenGL.
	GLuint wp = width<height ? width - 20 : height - 20;
	glViewport(10, 10, wp, wp);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Устанавливаем тип проекции.
	// glOrtho - параллельная
	// glFrustum - перспектива
	// Параметры о обеих функции идентичны:
	// они задают объем видимости
	glOrtho(-6.2, 6.2, -6.2, 6.2, 2., 12.);
	// glFrustum(-5,5, -5,5, 2,12);
	glMatrixMode(GL_MODELVIEW);
}

GLdouble gl = 0;
void CALLBACK display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glClear( GL_COLOR_BUFFER_BIT );
	// glClear( GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
	glTranslated(0., 0., -6.0);
	//glRotated(35., 0., 0., 0.);
	//glRotated(-35., 0., 0., 0.);
	glRotated(45, gl, gl, 0.);
	gl = gl + 0.01;
	glPointSize(10.0f);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3d(0, 0, 0);
	glVertex3f(0.f, 0.f, 0.f);
	glEnd();
	glDisable(GL_POINT_SMOOTH);
	glLineWidth(1.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	// Axa X RED
	glColor3d(0., 0., 0.);
	glVertex3d(-5.5, 0., 0.);

	glColor3d(1., 0., 0.);
	glVertex3d(5.5, 0., 0.);
	// Axa Y Green
	glColor3d(0., 0., 0.);
	glVertex3d(0., -5.5, 0.);
	glColor3d(0., 1., 0.);
	glVertex3d(0., 5.5, 0.);
	// Axa Z Blue
	glColor3d(0., 0., 0.);
	glVertex3d(0., 0., -5.5);
	glColor3d(0., 0., 1.);
	glVertex3d(0., 0., 5.5);
	glEnd();
	// Con X
	glColor3d(1, 0, 0);
	glPushMatrix();
	glTranslated(5.3f, 0.0f, 0.0f);
	glRotated(90, 0.0f, 1.0f, 0.0f);
	auxSolidCone(0.1f, 0.2f);
	glPopMatrix();
	// Con Y
	glColor3d(0, 1, 0);
	glPushMatrix();
	glTranslated(0.0f, 5.3f, 0.0f);
	glRotated(-90, 1.0f, 0.0f, 0.0f);
	auxSolidCone(0.1f, 0.2f);
	glPopMatrix();
	// Con Z
	glColor3d(0, 0, 1);
	glPushMatrix();
	glTranslated(0.0f, 0.0f, 5.3f);
	auxSolidCone(0.1f, 0.2f);
	glPopMatrix();
	//VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
	// Здесь будем вставлять фрагменты кода для различных примеров
	// в процессе изучения функций OpenGL

	/*glPushMatrix();
	glTranslated(0., 0., 1.);
	glScaled(2., 2., 3.);
	glColor3d(1., 0., 1.);
	c1.drawcon();
	glPopMatrix();*/

	/*const GLubyte mask[32 * 4] =
	{
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0xF0, 0xF0, 0xF0, 0xF0,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F,
		0x0F, 0x0F, 0x0F, 0x0F
	};

	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(mask);
	glBegin(GL_QUADS);
	glColor3d(1., 0., 0.);
	glVertex3d(-5., -5., -2.);
	glVertex3d(-5., 5., -2.);
	glVertex3d(5., 5., -2.);
	glVertex3d(5., -5., -2.);
	glEnd();*/


	/*glBegin(GL_TRIANGLE_STRIP);
	glColor3d(1., 0., 0.);
	glVertex3d(-2.5, -2.5, -1.);
	glVertex3d(-2.5, 2.5, -1.);
	glVertex3d(2.5, 2.5, -1.);
	glVertex3d(2.5, 5., 10.);
	glVertex3d(2.5, -2.5, -1.);
	glEnd();*/
	/*glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_QUADS);
	glColor3d(1., 0., 0.);
	glVertex3d(-5., -5., -2.);
	glVertex3d(-5., 5., -2.);
	glVertex3d(5., 5., -2.);
	glVertex3d(5., -5., -2.);
	glEnd();*/


	/*glBegin(GL_TRIANGLE_FAN);
	glColor3d(0, 0, 0);

	int amountSegments = 50;
	int r = 1;
	int r2 = 2;
	float x = 0.1;
	float y = 0.1;

	glVertex3f(0, 0, -2);

	for (size_t i = 0; i < amountSegments / 2 + 1; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);

		float dx = r * cosf(angle);
		float dy = r2 * sinf(angle);

		glVertex3f(x + dx, y + dy, 4);
	}

	glEnd();*/

	glBegin(GL_LINE_STRIP);
	glColor3d(100, 0, 0);

	int amountSegments = 50;
	int r = 1;
	int r2 = 2;
	float x = 1;
	float y = -2;

	for (size_t i = 0; i < amountSegments / 2 + 1; i++)
	{
		if (i > amountSegments / 2 * 0.15 && i < amountSegments / 2 * 0.85)
		{
			float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);

			float dx = r * cosf(angle);
			float dy = r2 * sinf(angle);

			glVertex3f(x + dx, 2, y + dy);

		}

	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3d(100, 0, 0);

	amountSegments = 50;
	r = -1;
	r2 = -2;
	x = 1;
	y = 4;

	for (size_t i = 0; i < amountSegments / 2 + 1; i++)
	{
		
		if (i > amountSegments/2 * 0.15 && i < amountSegments / 2 * 0.85)
		{
			float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);

			float dx = r * cosf(angle);
			float dy = r2 * sinf(angle);

			glVertex3f(x + dx, 2, y + dy);

		}
	

	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3d(100, 0, 0);

	amountSegments = 50;
	x = -1; //begin
	y = 1; // end
	float lin = (abs(x) + abs(y)) / amountSegments;

	for (size_t i = 0; i < amountSegments; i++)
	{
		
		x = x + lin;
		glVertex3f(0, 1, x);
		

		//std::cout << x << std::endl;
	}
	glEnd();

	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	glPopMatrix();
	auxSwapBuffers();
}
void main()
{
	// Устанавливаем координаты окна на экране
	// левый верхний угол (0,0)
	// ширина и высота - 500
	auxInitPosition(0, 0, 500, 500);
	// Устанавливаем параметры контекста OpenGL
	auxInitDisplayMode(AUX_RGB | AUX_DEPTH | AUX_DOUBLE);
	// Создаем окно на экране
	auxInitWindow((LPCWSTR)("OpenGL"));
	// Это окно будет получать сообщения о событиях
	// от клавиатуры, мыши, таймера и любые другие сообщения.
	// Пока не поступают никакие сообщения циклически будет
	// вызываться функция display().
	// Так можно создавать анимации.
	// Если нужно статическое изображение
	// следующая строка может быть закомментирована
	auxIdleFunc(display);
	// В случае изменения размеров окна – поступает
	// соответствующее сообщение
	// В Windows - это WM_SIZE.
	// Указываем, что функция resize() должна быть вызвана
	// каждый раз когда изменяются размеры окна
	auxReshapeFunc(resize);
	// Далее задаем ряд тестов и параметров
	// Включается тест прозрачности, т.е. будет приниматься во
	// внимание 4-й параметр при в glColor()
	glEnable(GL_ALPHA_TEST);
	// Тест глубины
	glEnable(GL_DEPTH_TEST);
	// Функция glColor() будет задавать
	// свойства материалов.
	// Следовательно, отсутствует необходимость
	// в дополнительном вызове функции glMaterialfv()
	glEnable(GL_COLOR_MATERIAL);
	// Разрешаем освешение
	glEnable(GL_LIGHTING);
	// Активируем источник освещения с нлмером 0
	glEnable(GL_LIGHT0);
	// Задаем позицию источника освещения
	float pos[4] = { 3,3,3,1 };
	float dir[3] = { -1,-1,-1 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
	// Разрешаем смешивание цветов (для прозрачных поверхностей)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Устанавливаем цвет начальной закраски окна
	glClearColor(1.f, 1.f, 1.f, 1.f);
	// Указываем, что функция display() должна использоваться для
	// перерисовки окна.
	// Эта функция будет вызвана каждый раз когда возникает
	// необходимость в перерисовки окна,
	// т.е. при поступлении сообщения WM_PAINT от Windows
	// Например, когда окно развертывается на весь экран.
	auxMainLoop(display);
}
