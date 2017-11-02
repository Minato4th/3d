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
//#include <math.h>
//
//#define RADGRAD 0.0174532925199433
//
//#define MAXH 150
//#define MAXS 150
//
//class cone0
//{
//protected:
//	int nh;
//	int ns;
//	double c[MAXH][MAXS][3];
//public:
//	cone0(int, int);
//	void drawcon();
//};
//
//cone0::cone0(int heightsegm, int sectors)
//{
//	int i, j;
//	nh = heightsegm;
//	ns = sectors;
//	if (nh > MAXH)
//		nh = MAXH;
//	else
//		if (nh < 1)
//			nh = 10;
//	if (ns > MAXS)
//		ns = MAXS;
//	else
//		if (ns < 3)
//			ns = 10;
//	double hstep = 1.0 / nh;
//	double astep = -360.0 / ns;
//	double hcur, acur, rcur;
//	hcur = 0.0;
//	for (i = 0; i<nh; i++)
//	{
//		hcur += hstep;
//		acur = 0.0;
//		rcur = hcur;
//		for (j = 0; j<ns; j++)
//		{
//			c[i][j][0] = rcur*cos(RADGRAD*acur);
//			c[i][j][1] = rcur*sin(RADGRAD*acur);
//			c[i][j][2] = hcur;
//			acur += astep;
//		}
//	}
//}
//void cone0::drawcon()
//{
//	int i, j;
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex3d(0., 0., 0.);
//	for (j = 0; j<ns; j++)
//		glVertex3dv(c[0][j]);
//	glVertex3dv(c[0][0]);
//	glEnd();
//	for (i = 0; i<nh - 1; i++)
//	{
//		glBegin(GL_TRIANGLE_STRIP);
//		for (j = 0; j<ns; j++)
//		{
//			glVertex3dv(c[i + 1][j]);
//			glVertex3dv(c[i][j]);
//		}
//		glVertex3dv(c[i + 1][0]);
//		glVertex3dv(c[i][0]);
//		glEnd();
//	}
//}
//static cone0 c1(10, 30);