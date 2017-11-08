#include <windows.h>

#include <GL/gl.h>
#pragma comment(lib,"OpenGL32.lib")
#include <GL/glu.h>
#pragma comment(lib,"Glu32.lib")

#include "glaux.h"
#pragma comment(lib,"glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

#include <math.h>

#include <cmath>
#include <iostream>

#define kSpeed  0.03f 
#define INITIAL 1
#define POINTS 20
#define HIGHT 1.25
#define SECTORS 2


struct CVector3
{
public:
	double x, y, z;
};

CVector3 PointOnCurve(CVector3 p1, CVector3 p2, CVector3 p3, CVector3 p4, double t)
{
	double var1, var2, var3;
	CVector3 vPoint = { 0.0f, 0.0f, 0.0f };

	var1 = 1 - t;
	var2 = var1 * var1 * var1;
	var3 = t * t * t;

	vPoint.x = var2*p1.x + 3 * t*var1*var1*p2.x + 3 * t*t*var1*p3.x + var3*p4.x;
	vPoint.y = var2*p1.y + 3 * t*var1*var1*p2.y + 3 * t*t*var1*p3.y + var3*p4.y;
	vPoint.z = var2*p1.z + 3 * t*var1*var1*p2.z + 3 * t*t*var1*p3.z + var3*p4.z;

	return(vPoint);
}

class Bizie {

	protected:

		double maxsteps;
		double heightsegm;
		double sectors;
		double points;

		CVector3 g_vStartPoint;
		CVector3 g_vControlPoint1;
		CVector3 g_vControlPoint2;
		CVector3 g_vEndPoint;

		CVector3 vPoint;
		CVector3 Points[2][POINTS * 2 * (SECTORS) + SECTORS * 2];

	public:
		Bizie(double, double, double, double, double, double, double, double, double, double, double,double, double, double, double, double);
		void drawBizie();
};

Bizie::Bizie(double maxstp, double overal, double height, double sect, double g_spX, double g_spY, double g_spZ, double g_cp1X, double g_cp1Y, double g_cp1Z, double g_cp2X,
	double g_cp2Y, double g_cp2Z, double g_epX, double g_epY, double g_epZ)
{
	maxsteps = maxstp;
	heightsegm = height;
	sectors = sect;
	points = overal;
	double step = heightsegm / sectors;
	
	g_vStartPoint = { g_spX * maxsteps,  g_spY * maxsteps,  g_spZ * maxsteps };
	g_vControlPoint1 = { g_cp1X * maxsteps, g_cp1Y  * maxsteps,  g_cp1Z * maxsteps };
	g_vControlPoint2 = { g_cp2X * maxsteps,  g_cp2Y * maxsteps,  g_cp2Z * maxsteps };
	g_vEndPoint = { g_epX * maxsteps,  g_epY * maxsteps,  g_epZ * maxsteps };

	vPoint = { 0.0f, 0.0f, 0.0f };

	int count = 0;
	for (double t = 0; t <= (1 + (1.0f / overal)); t += 1.0f / overal)
	{
		vPoint = PointOnCurve(g_vStartPoint, g_vControlPoint1, g_vControlPoint2, g_vEndPoint, t);
		Points[0][count] = vPoint;
		count++;
	}

	count = 0;
	for (size_t i = 0; i < sectors; i++)
	{

		vPoint = { 0.0f, 0.0f, 0.0f };

		for (double t = 0; t <= (1 + (1.0f / overal)); t += 1.0f / overal)
		{

			g_vStartPoint = { g_spX * maxsteps,  g_spY * maxsteps,  g_spZ * maxsteps };
			g_vControlPoint1 = { g_cp1X * maxsteps, g_cp1Y  * maxsteps,  g_cp1Z * maxsteps };
			g_vControlPoint2 = { g_cp2X * maxsteps,  g_cp2Y * maxsteps,  g_cp2Z * maxsteps };
			g_vEndPoint = { g_epX * maxsteps,  g_epY * maxsteps,  g_epZ * maxsteps };

			vPoint = PointOnCurve(g_vStartPoint, g_vControlPoint1, g_vControlPoint2, g_vEndPoint, t);
			Points[1][count] = vPoint;
			count++;

			maxsteps += step;

			g_vStartPoint = { g_spX * maxsteps,  g_spY * maxsteps,  g_spZ * maxsteps };
			g_vControlPoint1 = { g_cp1X * maxsteps, g_cp1Y  * maxsteps,  g_cp1Z * maxsteps };
			g_vControlPoint2 = { g_cp2X * maxsteps,  g_cp2Y * maxsteps,  g_cp2Z * maxsteps };
			g_vEndPoint = { g_epX * maxsteps,  g_epY * maxsteps,  g_epZ * maxsteps };

			vPoint = PointOnCurve(g_vStartPoint, g_vControlPoint1, g_vControlPoint2, g_vEndPoint, t);
			Points[1][count] = vPoint;
			count++;

			maxsteps -= step;
		}

		maxsteps += step;
	}
}

void Bizie::drawBizie()
{
	for (double e = -1; e < 2; e+=2)
	{
		glBegin(GL_TRIANGLE_FAN);
		glVertex3d(0., 0., 0.);

		for (int t = 0; t < points; t++)
		{
			glVertex3f(Points[0][t].x, Points[0][t].y, e*Points[0][t].z);
		}

		glEnd();


		int counter = 0;
		for (size_t i = 0; i < sectors; i++)
		{
			glBegin(GL_TRIANGLE_STRIP);

			for (int t = 0; t < points * 2; t++)
			{
				glVertex3f(Points[1][counter].x, Points[1][counter].y, e*Points[1][counter].z);
				counter++;
			}
			counter += 2;

			glEnd();
		}
	}
	
};

class Lines
{
	protected:

		double maxsteps;
		double heightsegm;
		double sectors;
		double points;

		CVector3 vPoint;
		CVector3 Points[2][POINTS * 2 * (SECTORS)+SECTORS * 2];

	public:
		Lines(double, double, double, double, double, double, double, double, double, double);
		void drawLine();
}; 

Lines::Lines(double maxstp, double overal, double height, double sect, double X_start, double Y_start, double Z_start, double X_end, double Y_end, double Z_end){

	maxsteps = maxstp;
	heightsegm = height;
	sectors = sect;
	points = overal;
	double step = heightsegm / sectors;

	double x_change = X_start * maxsteps;
	double y_change = Y_start * maxsteps;
	double z_change = Z_start * maxsteps;
	double x_lin = X_end * maxsteps / points;
	double y_lin = Y_end * maxsteps / points;
	double z_lin = Z_end * maxsteps / points;


	for (size_t i = 0; i < points; i++)
	{
		if (i != 0)
		{
			x_change = x_change + x_lin;
			y_change = y_change + y_lin;
			z_change = z_change + z_lin;
		}
		
		vPoint = { x_change, y_change, z_change };
		Points[0][i] = (vPoint);

	}

	int count = 0;
	for (size_t i = 0; i < sectors; i++)
	{

		x_change = X_start * maxsteps;
		y_change = Y_start * maxsteps;
		z_change = Z_start * maxsteps;
		x_lin = X_end * maxsteps / points;
		y_lin = Y_end * maxsteps / points;
		z_lin = Z_end * maxsteps / points;

		maxsteps += step;
		double x_change1 = X_start * maxsteps;
		double y_change1 = Y_start * maxsteps;
		double z_change1 = Z_start * maxsteps;
		double x_lin1 = X_end * maxsteps / points;
		double y_lin1 = Y_end * maxsteps / points;
		double z_lin1 = Z_end * maxsteps / points;
		
		for (size_t i = 0; i < points; i++)
		{

			if (i != 0)
			{
				x_change = x_change + x_lin;
				y_change = y_change + y_lin;
				z_change = z_change + z_lin;
			}


			vPoint = { x_change, y_change, z_change };
			Points[1][count] = (vPoint);

			count++;

			if (i != 0)
			{
				x_change1 = x_change1 + x_lin1;
				y_change1 = y_change1 + y_lin1;
				z_change1 = z_change1 + z_lin1;
			}

			vPoint = { x_change1, y_change1, z_change1 };
			Points[1][count] = (vPoint);
			
			count++;
		}

	}

}

void Lines::drawLine()
{
	for (double e = -1; e < 2; e += 2)
	{
		glBegin(GL_TRIANGLE_FAN);
		glVertex3d(0., 0., 0.);

		for (int t = 0; t < points; t++)
		{
			glVertex3f(Points[0][t].x, Points[0][t].y, e*Points[0][t].z);
		}

		glEnd();


		int counter = 0;
		for (size_t i = 0; i < sectors; i++)
		{
			glBegin(GL_TRIANGLE_STRIP);

			for (int t = 0; t < points * 2; t++)
			{
				glVertex3f(Points[1][counter].x, Points[1][counter].y, e*Points[1][counter].z);
				counter++;
			}
			//counter += -1;

			glEnd();
		}
	}
}


static Bizie bizie1(INITIAL, POINTS, HIGHT, SECTORS, -2, 0.5, 1, -1, 0.3, 1, -1, -0.3, 1, -2, -0.5, 1);
static Bizie bizie2(INITIAL, POINTS, HIGHT, SECTORS, 2, 0.5, 1, 1, 0.3, 1, 1, -0.3, 1, 2, -0.5, 1);

static Lines line1(INITIAL, POINTS, HIGHT, SECTORS, -1.25, 0, 1, 2.6315, 0, 0);
static Lines line2(INITIAL, POINTS, HIGHT, SECTORS, 0, -1.25, 1, 0, 2.6315, 0);

static Lines lLine1(INITIAL, POINTS, HIGHT, SECTORS, 0, -1.25, 1, 0.7, -0.7, 0);
static Lines lLine2(INITIAL, POINTS, HIGHT, SECTORS, 0, -1.25, 1, -0.7, -0.7, 0);
static Lines lLine3(INITIAL, POINTS, HIGHT, SECTORS, 0, 1.25, 1, -0.7, 0.7, 0);
static Lines lLine4(INITIAL, POINTS, HIGHT, SECTORS, 0, 1.25, 1, 0.7, 0.7, 0);


// *Camera Class*
// Будет использоватся для запоминания позиции камеры, нашего взгляда и вертикального вектора.
// Сейчас у нас есть 3 CVector'а, которые будут запоминать эту информацию.
// Кроме того, пара вспомогательных функций. Мы сделаем все данные 
// public, чтобы в любой момент узнать свою позицию.
// Т.к. все данные - public, можно было использовать структуру. 
// Но я стараюсь все, что содержит в себе методы, делать классом.

class CCamera {

public:

	CVector3 m_vPosition;   // Позиция камеры.
	CVector3 m_vView;   // Направление камеры.
	CVector3 m_vUpVector;   // Вертикальный вектор.
			
	CCamera();// Конструктор класса Camera

	// Тут изменяется положение, направление и верт. вектор камеры.
	// В основном используется при инициализации.
	void PositionCamera(float positionX, float positionY, float positionZ, float viewX, float viewY, float viewZ, 
		float upVectorX, float upVectorY, float upVectorZ);

	// Эта ф-я передвигает камеру вперед/назад
	void MoveCamera(float speed);
};

// Ну и наконец добавим глобальную переменную данных камеры.
//extern CCamera  g_Camera;           // Глобальные данные камеры


CCamera::CCamera()
{
	CVector3 vZero = { 0.0, 0.0, 0.0 };		//Инициализируем вектор нашей позиции в нулевые координаты
	CVector3 vView = { 0.0, 1.0, 0.5 };     // Иниц. вектор взгляда
	CVector3 vUp = { 0.0, 0.0, 1.0 };       // Вертикальный вектор

	m_vPosition = vZero;
	m_vView = vView;
	m_vUpVector = vUp;
}


/////   Устанавливает позицию, взгляд, верт. вектор камеры

GLvoid CCamera::PositionCamera(float positionX, float positionY, float positionZ,float viewX, float viewY, float viewZ,
	float upVectorX, float upVectorY, float upVectorZ)
{
	CVector3 vPosition = { positionX, positionY, positionZ };
	CVector3 vView = { viewX, viewY, viewZ };
	CVector3 vUpVector = { upVectorX, upVectorY, upVectorZ };

	//Обширный код просто делает легче назначение переменных.
	//Можно просто сразу присвоить переменным класса переданные функции значения.

	m_vPosition = vPosition;
	m_vView = vView;
	m_vUpVector = vUpVector;
}


/////   Движение камеры вперед-назад с заданной скоростью
void CCamera::MoveCamera(float speed)
{
	CVector3 vVector = { 0 };     //Иниц. вектор направления взгляда

	// Получаем вектор направления. Чтобы получить вектор из 2х 
	// точек, мы вычитаем первую точку из второй.
	// Это дает нам направление, куда мы смотрим. 
	// Позже мы напишем ф-ю, вычисляющую направление
	// по-другому.

	//Получаем направление взгляда (напр-е, куда мы повернуты "лицом")
	vVector.x = m_vView.x - m_vPosition.x;      //Направление по X
	vVector.y = m_vView.y - m_vPosition.y;      //Направление по Y
	vVector.z = m_vView.z - m_vPosition.z;      //Направление по Z

	// Следующий код двигает камеру вперед или назад.
	// Мы прибавляем к текущему положению направление взгляда, помноженное на скорость.
	// Может быть, вы думаете, что проще было бы просто прибавить к позиции скорость. Да,
	// сейчас это сработает - вы смотрите прямо по оси Х. Но как только начнется вращение, код
	// перестанет действовать. Поверьте мне.
	// Итак, если мы смотрим в направлении 45 градусов, мы и пойдем в этом направлении.
	// Если движемся назад - просто передаём в ф-ю отрицательную скорость.

	m_vPosition.x += vVector.x * speed;
	m_vPosition.z += vVector.z * speed;
	m_vView.x += vVector.x * speed;
	m_vView.y += vVector.z * speed;
}

CCamera g_Camera;

//void Init(HWND hWnd)
//{
//	g_hWnd = hWnd;
//	GetClientRect(g_hWnd, &g_rRect);
//	InitializeOpenGL(g_rRect.right, g_rRect.bottom);
//
//	Font = new CFont("arial.ttf", 16, 16);
//	FPS = 0;
//
//	// Ниже мы инициализируем камеру. Устанавливаем позицию, из которой будем смотреть на
//	// цветной треугольник.
//	// Помните, эта инициализация необходима только _единожды_, 
//	// и больше мы её вызывать не будем.
//
//	//          Позиция      Напр-е     верт. вектор
//	g_Camera.PositionCamera(0, 0.5f, 6, 0, 0.5f, 0, 0, 1, 0);
//}

void CALLBACK resize(int width, int height)
{
	GLuint wp = width<height ? width - 20 : height - 20;
	glViewport(10, 10, wp, wp);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-6.2, 6.2, -6.2, 6.2, 2., 12.);
	// glFrustum(-5,5, -5,5, 2,12);
	glMatrixMode(GL_MODELVIEW);

	g_Camera.PositionCamera(0, 0.5f, 6, 0, 0.5f, 0, 0, 1, 0);
	
}

GLdouble gl = 90;

void CALLBACK Key_DOWN(void)
{
	g_Camera.MoveCamera(-kSpeed);
}
void CALLBACK Key_UP(void)
{
	g_Camera.MoveCamera(kSpeed);
	//RenderScene();      // Перерисовываем сцену
}

void CALLBACK display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glClear( GL_COLOR_BUFFER_BIT );
	// glClear( GL_DEPTH_BUFFER_BIT );
	glPushMatrix();
	glTranslated(0., 0., -6.0);	
	//glRotated(35., 1., 0., 0.);
	//glRotated(-35., 0., 1., 0.);

	//glRotated(45, 0., 1., 0.);
	//glRotated(gl, 1., 1., 1.);
	//glRotated(gl, 0., 1., 0.);
	gluLookAt(g_Camera.m_vPosition.x, g_Camera.m_vPosition.y, g_Camera.m_vPosition.z,
		g_Camera.m_vView.x, g_Camera.m_vView.y, g_Camera.m_vView.z,
		g_Camera.m_vUpVector.x, g_Camera.m_vUpVector.y, g_Camera.m_vUpVector.z);

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



	glPushMatrix();
		glTranslated(0., 0., 0.);
		glScaled(1., 1., 1.);
	
		//glRotated(45, 0, 1, 1);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
		bizie1.drawBizie();
		bizie2.drawBizie();

		glColor3d(1, 0, 0);
		line1.drawLine();
		line2.drawLine();

		glColor3d(0, 1, 0);
		lLine1.drawLine();
		lLine2.drawLine();
		lLine3.drawLine();
		lLine4.drawLine();
	glPopMatrix();


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

	//auxKeyFunc(AUX_LEFT, Key_LEFT);
	//auxKeyFunc(AUX_RIGHT, Key_RIGHT);
	auxKeyFunc(AUX_UP, Key_UP);
	auxKeyFunc(AUX_DOWN, Key_DOWN);


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
