// 画图.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class point
{
private :
	double xx;
	double yy;
	double zz;
	int x;
	int y;
public:
	point(double _xx,double _yy,double _zz)
	{
		xx = _xx;
		yy = _yy;
		zz = _zz;
		getnowxy();
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	void getnowxy()
	{
		x = (-sqrt(2) / 2)*xx + yy;
		y = (-sqrt(2) / 2)*xx + zz;
	}
	void changezuobiao(double juzhen[3][3]) 
	{
		double _xx, _yy, _zz;
		_xx = xx;
		_yy = yy;
		_zz = zz;
		xx = juzhen[0][0] * _xx + juzhen[0][1] * _yy + juzhen[0][2] * _zz;
		yy = juzhen[1][0] * _xx + juzhen[1][1] * _yy + juzhen[1][2] * _zz;
		zz = juzhen[2][0] * _xx + juzhen[2][1] * _yy + juzhen[2][2] * _zz;
		getnowxy();
	}
	void xycircle()
	{
		double juzhen[3][3] = { cos(0.01),-sin(0.01),0,sin(0.01),cos(0.01),0,0,0,1 };
		changezuobiao(juzhen);
	}
	void _xycircle()
	{
		double juzhen[3][3] = { cos(-0.01),-sin(-0.01),0,sin(-0.01),cos(-0.01),0,0,0,1 };
		changezuobiao(juzhen);
	}
	void yzcircle()
	{
		double juzhen[3][3] = { 1,0,0,0,cos(0.01),-sin(0.01),0,sin(0.01),cos(0.01) };
		changezuobiao(juzhen);
	}
	void xzcircle()
	{
		double juzhen[3][3] = { cos(0.01),0,-sin(0.01),0,1,0,sin(0.01),0,cos(0.01) };
		changezuobiao(juzhen);
	}
};
class Line
{
private:
	point *p1;
	point *p2;
public:
	Line(double x1, double y1, double z1, double x2, double y2 ,double z2)
	{
		p1 = new point(x1, y1,z1);
		p2 = new point(x2, y2, z2);
	}
	void drawline()
	{
		int x1, y1, x2, y2;
		x1 = p1->getx();
		x2 = p2->getx();
		y1 = p1->gety();
		y2 = p2->gety();
		line(x1, y1, x2, y2);
	}
	void xychange()
	{
		p1->xycircle();
		p2->xycircle();
		p1->yzcircle();
		p2->yzcircle();
		p1->xzcircle();
		p2->xzcircle();
	}
	void _xychange()
	{
		p1->_xycircle();
		p2->_xycircle();
		p1->yzcircle();
		p2->yzcircle();
		p1->xzcircle();
		p2->xzcircle();
	}
	~Line()
	{
		delete p1;
		delete p2;
	}
};
int main()
{
	initgraph(1280, 768);
	setorigin(640, 384);
	setaspectratio(1, -1);
	Line a1(-100, -100, -100, 100, -100, -100);
	Line a2(100, -100, -100, 100, 100, -100);
	Line a3(100, 100, -100, -100, 100, -100);
	Line a4(-100, 100, -100, -100, -100, -100);

	Line b1(-100, -100, 100, 100, -100, 100);
	Line b2(100, -100, 100, 100, 100, 100);
	Line b3(100, 100, 100, -100, 100, 100);
	Line b4(-100, 100, 100, -100, -100, 100);

	Line h1(-100, -100, -100, -100, -100, 100);
	Line h2(100, -100, -100, 100, -100, 100);
	Line h3(100, 100, -100, 100, 100, 100);
	Line h4(-100, 100, -100, -100, 100, 100);

	Line s1(0, 150, 0, 0, 200, 0);
	Line s2(-25, 175, 0, 0, 150, 0);
	Line s3(-25, 175, 0, 0, 200, 0);

	Line sh1(0, 150, 0, -12.5, 175, 25);
	Line sh2(-25, 175, 0, -12.5, 175, 25);
	Line sh3(-12.5, 175, 25, 0, 200, 0);

	//point : -200,-200,-200  -200,-300,-200 -300,-300,-200  -250 -250 -250
	Line s4(-200, -200, -200, -200, -300, -200);
	Line s5(-200, -200, -200, -300, -300, -200);
	Line s6(-200, -300, -200, -300, -300, -200);

	Line sh4(-200, -200, -200, -250 ,- 250 ,- 250);
	Line sh5(-200, -300, -200, -250 ,- 250 ,- 250);
	Line sh6(-300, -300, -200, -250, - 250, - 250);

	while (1)
	{
		cleardevice();
		a1.drawline();
		a2.drawline();
		a3.drawline();
		a4.drawline();

		b1.drawline();
		b2.drawline();
		b3.drawline();
		b4.drawline();

		h1.drawline();
		h2.drawline();
		h3.drawline();
		h4.drawline();

		s1.drawline();
		s2.drawline();
		s3.drawline();

		sh1.drawline();
		sh2.drawline();
		sh3.drawline();

		s4.drawline();
		s5.drawline();
		s6.drawline();

		sh4.drawline();
		sh5.drawline();
		sh6.drawline();

		a1.xychange();
		a2.xychange();
		a3.xychange();
		a4.xychange();

		b1.xychange();
		b2.xychange();
		b3.xychange();
		b4.xychange();

		h1.xychange();
		h2.xychange();
		h3.xychange();
		h4.xychange();

		s1.xychange();
		s2.xychange();
		s3.xychange();

		sh1.xychange();
		sh2.xychange();
		sh3.xychange();

		s4._xychange();
		s5._xychange();
		s6._xychange();

		sh4._xychange();
		sh5._xychange();
		sh6._xychange();

		Sleep(5);
	}
	closegraph();
	
	return 0;
}

