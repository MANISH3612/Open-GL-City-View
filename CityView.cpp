#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<glut.h>
float x = 0, y = 0, k = 0;
void fun1();//Railway Station
void fun2();//Bus terminal
void fun3();//Buildings
void fun4();//Health care
void fun5();//Smart lighting
int inc = 0, inc1 = 0, inc2 = 0, inc3 = 0,flag=0;
float red = 0.6862, green = 0.9333, blue = 0.9333;
void DrawTextXY(double x, double y, double scale, const char *s)//to display text
{
int i;

glPushMatrix();
glTranslatef(x, y, 0);

glScalef(scale, scale, scale);
glColor3f(0.4, 0.4, 0.4);
for (i = 0; i < strlen(s); i++)
glutStrokeCharacter(GLUT_STROKE_ROMAN, s[i]);
//glColor3f(0, 0, 1);
glPopMatrix();
}
//initializations of various scenes
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 300, 0, 240);
glMatrixMode(GL_MODELVIEW);
}
void myinit1()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 1200, 0, 700, 0, 200);
glMatrixMode(GL_MODELVIEW);
}
void myinit2()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 500, 0, 500, 0, 200);
glMatrixMode(GL_MODELVIEW);
}
void start()
{
glClearColor(0, 0, 0, 1);
DrawTextXY(60, 200, 0.15, "SMART CITY VIEW");
glColor3ub(71, 47, 98);
glBegin(GL_POLYGON);
glVertex2f(90 + 20, 150 - 40);
glVertex2f(90 + 20, 130 - 40);
glVertex2f(150 + 20, 130 - 40);
glVertex2f(150 + 20, 150 - 40);
glEnd();
glColor3ub(255, 255, 255);
DrawTextXY(123, 95, 0.09, "BEGIN");
//flag=1;
DrawTextXY(70, 20, 0.05, "Click Right Button To Display Information");
glFlush();
}
int flag1 = 0;
void callback();// call back function for timer
void info()// information about components
{
glClearColor(0, 0, 0, 1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3ub(255, 255, 255);
DrawTextXY(10, 230, 0.07, "*] Railway Station:");
DrawTextXY(10, 220, 0.06, "This represents the animation of a maglev/electric train used in the  ");
DrawTextXY(10, 212, 0.06, "railway station of the city.");
DrawTextXY(10, 195, 0.07, "*] Bus Terminal:");
DrawTextXY(10, 185, 0.06, "This represents the view of the bus terminal present in the city along  ");
DrawTextXY(10, 177, 0.06, "with the animation of bus.");
DrawTextXY(10, 160, 0.07, "*] Health Care:");
DrawTextXY(10, 150, 0.06, "This represents the view of the health care available in the city ");
DrawTextXY(10, 133, 0.07, "*] Smart Lighting:");
DrawTextXY(10, 123, 0.06, "The background color ie., the sky color gradually changes from ");
DrawTextXY(10, 113, 0.06, "blue to black, ie., morning to night. As night arrives the view of smart ");
DrawTextXY(10, 103, 0.06, "lighting is shown. ");
glColor3ub(71, 47, 98);
glBegin(GL_POLYGON);
glVertex2f(90 + 20, 30);
glVertex2f(90 + 20, 10);
glVertex2f(150 + 20, 10);
glVertex2f(150 + 20, 30);
glEnd();
DrawTextXY(120, 15, 0.09, "START");
flag1 = 1;
glFlush();
}
void mouse(int b, int s, int x, int y)
{
if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
{
if (x <= 277 && x >= 187 && y >= 273 && y <= 305)
{
flag = 1; glutPostRedisplay();
}
if (x <= 277 && x >= 187 && y >= 438 && y <= 475)
glClearColor(0, 0, 0, 1);
glClear(GL_COLOR_BUFFER_BIT); start();
}

if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
info();
}
void changecolor()//to change color of background gradually
{
if (red != 0 && blue != 0 && green != 0)
{
red -= 0.0008;
green -= 0.0008;
blue -= 0.0008;
}
}
//idle functions for animation of various scenes
void idle()
{
if (100 + x > 3)
{
x -= 5;
float g = (50 * x - 1578) / 59;
k = 0.12*fabsf(g);
for (unsigned long int i = 0; i < 50000000; i++);
myinit();
glutDisplayFunc(fun1);
glutPostRedisplay();

}
}
void idle1()
{
if (inc < 1800)
{
inc += 4;
myinit1();
glutDisplayFunc(fun2);
glutPostRedisplay();

}

}
void idle2()
{
if (inc1 < 1500)
{
inc1 += 4;
myinit2();
glutDisplayFunc(fun3);
glutPostRedisplay();

}


}
void idle3()
{
if (inc2 < 1800)
{
inc2 += 4;
myinit2();
glutDisplayFunc(fun4);
glutPostRedisplay();

}


}
void idle4()
{

myinit2();
glutDisplayFunc(fun5);
glutPostRedisplay();


}

void bus(float x, int inc)
{
glPushMatrix();
glColor3f(0.5, 0, 1);
glBegin(GL_POLYGON);
glVertex2d(x *(inc + (-500)), 50);
glVertex2d(x*(inc + (-50)), 50);
glVertex2d(x*(inc + (-50)), 200);
glVertex2d(x*(inc + (-500)), 200);
glEnd();
glBegin(GL_LINES);
glLineWidth(2);
glVertex2d(x*(inc + (-50)), 180);
glVertex2d(x*(inc + (-30)), 180);
glLineWidth(5);
glVertex2d(x*(inc + (-30)), 180);
glVertex2d(x*(inc + (-30)), 150);
glEnd();
glColor3ub(105, 22, 113);
glBegin(GL_POLYGON);
glVertex2d(x*(inc + (-470)), 120);
glVertex2d(x*(inc + (-120)), 120);
glVertex2d(x*(inc + (-120)), 175);
glVertex2d(x*(inc + (-470)), 175);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(x*(inc + (-50)), 175);
glVertex2d(x*(inc + (-80)), 175);
glVertex2d(x*(inc + (-80)), 90);
glVertex2d(x*(inc + (-50)), 90);
glEnd();
glColor3f(1, 1, 1);
glLineWidth(3);
glBegin(GL_LINE_LOOP);
glVertex2d(x*(inc + (-470)), 120);
glVertex2d(x*(inc + (-120)), 120);
glVertex2d(x*(inc + (-120)), 175);
glVertex2d(x*(inc + (-470)), 175);
glEnd();
glBegin(GL_LINES);
for (int i = 170; i < 470; i = i + 50)
{
glVertex2d(x*(-i + inc), 120);
glVertex2d(x*(-i + inc), 175);
}
glVertex2d(x*(inc + (-50)), 175);
glVertex2d(x*(inc + (-80)), 175);
glVertex2d(x*(inc + (-80)), 175);
glVertex2d(x*(inc + (-80)), 90);
glVertex2d(x*(inc + (-80)), 90);
glVertex2d(x*(inc + (-50)), 90);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(x*(inc - 420 + 30 * cos(3.14*i / 180)), 55 + 30 * sin(3.14*i / 180));
}
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(x*(inc - 140 + 30 * cos(3.14*i / 180)), 55 + 30 * sin(3.14*i / 180));
}
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(x*(inc - 140 + 15 * cos(3.14*i / 180)), 55 + 15 * sin(3.14*i / 180));
}
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(x*(inc - 420 + 15 * cos(3.14*i / 180)), 55 + 15 * sin(3.14*i / 180));
}
glEnd();
glColor3f(1, 1, 0);
glBegin(GL_POLYGON);
for (int i = 90; i < 270; i++) {
glVertex2d(x*(inc - 50 + 10 * cos(3.14*i / 180)), 65 + 10 * sin(3.14*i / 180));
}
glEnd();
glPopMatrix();
for (long int i = 6500000; i > 0; i--);
}
void fun1()
{
changecolor();
glClearColor(red, green, blue, 1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1, 0, 0);
glColor3ub(169, 169, 169);
glBegin(GL_POLYGON);
glVertex2f(218, 158);
glVertex2f(100, 0);
glVertex2f(0, 0);
glVertex2f(0, 60);
glEnd();
glColor3ub(192, 192, 192);
glBegin(GL_POLYGON);
glVertex2f(0, 50);
glVertex2f(77, 47);
glVertex2f(75, 42);
glVertex2f(0, 45);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(0, 35);
glVertex2f(72, 32);
glVertex2f(68, 27);
glVertex2f(0, 30);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(0, 20);
glVertex2f(58, 18);
glVertex2f(53, 13);
glVertex2f(0, 15);
glEnd();
glColor3ub(128, 128, 128);
glBegin(GL_POLYGON);
glVertex2f(12, 58);
glVertex2f(25, 58);
glVertex2f(0, 40);
glVertex2f(0, 50);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(87, 60);
glVertex2f(100, 60);
glVertex2f(40, 0);
glVertex2f(25, 0);
glEnd();
glColor3ub(178, 34, 34);
y = (50 * x - 1578) / 59;
glBegin(GL_TRIANGLES);
glColor3ub(219, 165, 165);
glVertex2f(218, 158);
glVertex2f(193, 240);
glVertex2f(300, 240);
glColor3f(0.6862, 0.9333, 0.9333);
glVertex2f(218, 158);
glVertex2f(310, 210);
glVertex2f(300, 0);
glColor3ub(206, 121, 123);
glVertex2f(218, 158);
glVertex2f(300, 0);
glVertex2f(134, 0);
glColor3ub(250, 128, 114);
glVertex2f(218, 158);
glVertex2f(134, 0);
glVertex2f(95, 0);
glColor3ub(255, 160, 122);
glVertex2f(218, 158);
glVertex2f(95, 0);
glVertex2f(65, 0);
glColor3ub(128, 0, 0);
glVertex2f(218, 158);
glVertex2f(100 + x, 60 + y);
glVertex2f(100 + x, 125 + y);
glColor3ub(165, 42, 42);
glVertex2f(218, 158);
glVertex2f(100 + x, 125 + y);
glVertex2f(80 + x, 137 + y);
glColor3ub(205, 92, 92);
glVertex2f(218, 158);
glVertex2f(80 + x, 137 + y);
glVertex2f(28 + x, 137 + y);
glEnd();
glColor3ub(178, 34, 34);
glBegin(GL_POLYGON);
glVertex2f(28 + x, 137 + y);
glVertex2f(80 + x, 137 + y);
glVertex2f(100 + x, 125 + y);
glVertex2f(100 + x, 60 + y);
glVertex2f(12 + x, 58 + y);
glVertex2f(12 + x, 122 + y);
glEnd();
//
glColor3ub(220, 220, 220);
glLineWidth(4);
glBegin(GL_LINES);
glVertex2f(15 + x, 122 + y);
glVertex2f(15 + x, 82 + y);
glEnd();
glLineWidth(2);
glBegin(GL_POLYGON);
glVertex2f(14 + x, 82 + y);
glVertex2f(30 + x, 82 + y);
glVertex2f(30 + x, 90 + y);
glVertex2f(14 + x, 90 + y);
glEnd();
glColor3ub(255, 255, 0);
glBegin(GL_POLYGON);
glVertex2f(17 + x, 84 + y);
glVertex2f(17 + x, 88 + y);
glVertex2f(25 + x, 88 + y);
glVertex2f(25 + x, 84 + y);
glEnd();
glColor3ub(192, 192, 192);
glLineWidth(4);
glBegin(GL_LINES);
glVertex2f(97 + x, 123 + y);
glVertex2f(97 + x, 83 + y);
glEnd();
glLineWidth(2);
glBegin(GL_POLYGON);
glVertex2f(97 + x, 91 + y);
glVertex2f(81 + x, 91 + y);
glVertex2f(81 + x, 83 + y);
glVertex2f(97 + x, 83 + y);
glEnd();
glColor3ub(255, 255, 0);
glBegin(GL_POLYGON);
glVertex2f(84 + x, 85 + y);
glVertex2f(84 + x, 89 + y);
glVertex2f(93 + x, 89 + y);
glVertex2f(93 + x, 85 + y);
glEnd();
//main window
glColor3ub(180, 239, 243);
glBegin(GL_POLYGON);
glVertex2f(18 + x, 122 + y);
glVertex2f(94 + x, 122 + y);
glVertex2f(94 + x, 92 + y);
glVertex2f(18 + x, 92 + y);
glEnd();
glColor3ub(100, 109, 145);
glLineWidth(4);
glBegin(GL_LINE_LOOP);
glVertex2f(19 + x, 122 + y);
glVertex2f(93 + x, 122 + y);
glVertex2f(93 + x, 92 + y);
glVertex2f(19 + x, 92 + y);
glEnd();
glLineWidth(8);
glBegin(GL_LINES);
glVertex2f(19 + x, 115 + y);
glVertex2f(93 + x, 115 + y);
glVertex2f(56 + x, 122 + y);
glVertex2f(56 + x, 92 + y);
glColor3ub(255, 255, 255);
glVertex2f(26 + x, 97 + y);
glVertex2f(42 + x, 110 + y);
glVertex2f(64 + x, 97 + y);
glVertex2f(78 + x, 110 + y);
glEnd();
glColor3ub(204, 76, 78);
glBegin(GL_POLYGON);
glVertex2f(100 + x, 60 + y);
glVertex2f(12 + x, 58 + y);
glVertex2f(12 + x, 75 + y);
glVertex2f(100 + x, 75 + y);
glEnd();
glColor3ub(100, 109, 145);
glBegin(GL_POLYGON);
glVertex2f(95 + x, 62 + y);
glVertex2f(19 + x, 62 + y);
glVertex2f(19 + x, 71 + y);
glVertex2f(95 + x, 71 + y);
glEnd();
glColor3ub(100, 109, 145);//line1
glLineWidth(2);
glBegin(GL_POLYGON);
glVertex2f(125 + x, 84 + y);
glVertex2f(126 + x, 137 + y);
glVertex2f(129 + x, 138 + y);
glVertex2f(128 + x, 86 + y);

glEnd();
//window1
glColor3ub(180, 239, 243);
glBegin(GL_POLYGON);
glVertex2f(140 + x, 120 + y - 0.2*k);
glVertex2f(140 + x, 135 + y - 0.2*k);
glVertex2f(157 + x, 147 + y - 0.2*k);
glVertex2f(157 + x, 135 + y - 0.2*k);
glEnd();
glColor3ub(100, 109, 145);
glLineWidth(3.5 + 0.12*k);
glBegin(GL_LINE_LOOP);
glVertex2f(140 + x, 120 + y - 0.2*k);
glVertex2f(140 + x, 135 + y - 0.2*k);
glVertex2f(157 + x, 147 + y - 0.2*k);
glVertex2f(157 + x, 135 + y - 0.2*k);
glEnd();
glBegin(GL_LINES);
glVertex2f(148 + x, 125 + y);
glVertex2f(148 + x, 138 + y);
glLineWidth(1);
glVertex2f(167 + x, 159 + y + 0.8*k);
glVertex2f(165 + x, 134 + y - 0.8*k);
glEnd();
//window2
glColor3ub(180, 239, 243);
glBegin(GL_POLYGON);
glVertex2f(174 + x, 146 + y - 0.2*k);
glVertex2f(174 + x, 156 + y - 0.2*k);
glVertex2f(185 + x, 163 + y - 0.2*k);
glVertex2f(185 + x, 154 + y - 0.2*k);
glEnd();
glColor3ub(100, 109, 145);
glLineWidth(2.5 + 0.12*k);
glBegin(GL_LINE_LOOP);
glVertex2f(174 + x, 146 + y - 0.2*k);
glVertex2f(174 + x, 156 + y - 0.2*k);
glVertex2f(185 + x, 163 + y - 0.2*k);
glVertex2f(185 + x, 154 + y - 0.2*k);
glEnd();
glLineWidth(2 * 0.12*k);
glBegin(GL_LINES);
glVertex2f(179 + x, 147 + y);
glVertex2f(179 + x, 157 + y);
glEnd();
glLineWidth(3 * 0.12*k);

glBegin(GL_LINES);
glVertex2f(195 + x, 175 + y + 0.8*k);
glVertex2f(193 + x, 161 + y - 0.8*k);
glEnd();
//door
glBegin(GL_POLYGON);
glVertex2f(109 + x, 69 + y);
glVertex2f(109 + x, 115 + y);
glVertex2f(119 + x, 121 + y);
glVertex2f(119 + x, 79 + y);
glEnd();
//pillars
glColor3ub(169, 169, 169);
glBegin(GL_POLYGON);
glVertex2f(253, 88);
glVertex2f(240, 88);
glVertex2f(240, 200);
glVertex2f(253, 200);
glEnd();
glColor3ub(192, 192, 192);
glBegin(GL_POLYGON);
glVertex2f(240, 88);
glVertex2f(240, 200);
glVertex2f(234, 190);
glVertex2f(234, 100);
glEnd();
glColor3ub(169, 169, 169);
glBegin(GL_POLYGON);
glVertex2f(300, 0);
glVertex2f(288, 0);
glVertex2f(288, 240);
glVertex2f(300, 240);
glEnd();
glColor3ub(192, 192, 192);
glBegin(GL_POLYGON);
glVertex2f(288, 0);
glVertex2f(288, 240);
glVertex2f(278, 240);
glVertex2f(278, 15);
glEnd();
//glutSwapBuffers();
glutIdleFunc(idle);
glFlush();
}
void fun2()
{
//gluOrtho2D(0, 1200, 0, 700);
changecolor();
glClearColor(red, green, blue, 1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1, 0, 0);
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(0, 150);
glVertex2d(1200, 150);
glVertex2d(1200, 350);
glVertex2d(0, 350);
glEnd();
glLineWidth(10);
//1st block
glBegin(GL_LINE_LOOP);
glVertex2d(300, 690);
glVertex2d(900, 690);
glVertex2d(900, 610);
glVertex2d(300, 610);
glEnd();
glLineWidth(1);
glColor3ub(230, 92, 92);
glBegin(GL_POLYGON);
glVertex2d(300, 690);
glVertex2d(900, 690);
glVertex2d(900, 610);
glVertex2d(300, 610);
glEnd();
glLineWidth(3);
glColor3ub(115, 58, 58);
int x = 355;
glBegin(GL_LINES);
while (x < 880) {
glVertex2d(x, 690);
glVertex2d(x, 610);
glVertex2d(x + 5, 690);
glVertex2d(x + 5, 610);
x = x + 60;
}
glEnd();
//2nd block
glColor3ub(8, 83, 88);
glBegin(GL_POLYGON);
glVertex2d(330, 603);
glVertex2d(450, 603);
glVertex2d(450, 530);
glVertex2d(330, 530);
glEnd();
glColor3ub(239, 209, 13);
glBegin(GL_POLYGON);
glVertex2d(450, 603);
glVertex2d(750, 603);
glVertex2d(750, 530);
glVertex2d(450, 530);
glEnd();
glColor3f(0, 0, 0);
char s[] = " BUS TERMINAL ";
glRasterPos2i(460, 560);
for (int i = 0; i < strlen(s); i++)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
glColor3ub(8, 83, 88);
glBegin(GL_POLYGON);
glVertex2d(750, 603);
glVertex2d(870, 603);
glVertex2d(870, 530);
glVertex2d(750, 530);
glEnd();
glColor3ub(136, 145, 52);
glBegin(GL_LINE_LOOP);
glVertex2d(330, 603);
glVertex2d(450, 603);
glVertex2d(450, 530);
glVertex2d(330, 530);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(450, 603);
glVertex2d(750, 603);
glVertex2d(750, 530);
glVertex2d(450, 530);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(750, 603);
glVertex2d(870, 603);
glVertex2d(870, 530);
glVertex2d(750, 530);
glEnd();
glBegin(GL_LINES);
glVertex2d(330, 570);
glVertex2d(450, 570);
glVertex2d(370, 605);
glVertex2d(370, 530);
glVertex2d(410, 605);
glVertex2d(410, 530);
glVertex2d(750, 570);
glVertex2d(870, 570);
glVertex2d(790, 605);
glVertex2d(790, 530);
glVertex2d(830, 605);
glVertex2d(830, 530);
glEnd();
//3rd block
glColor3ub(242, 223, 103);
glBegin(GL_POLYGON);
glVertex2d(200, 400);
glVertex2d(300, 525);
glVertex2d(300, 400);
glVertex2d(490, 400);
glVertex2d(464, 350);
glVertex2d(200, 350);
glVertex2d(200, 400);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(1000, 350);
glVertex2d(1000, 400);
glVertex2d(900, 525);
glVertex2d(900, 400);
glVertex2d(700, 400);
glVertex2d(728, 350);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(300, 528);
glVertex2d(495, 528);
glVertex2d(495, 400);
glVertex2d(300, 400);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(695, 528);
glVertex2d(900, 528);
glVertex2d(900, 400);
glVertex2d(695, 400);
glEnd();
glColor3ub(8, 83, 88);
glBegin(GL_POLYGON);
glVertex2d(495, 528);
glVertex2d(695, 528);
glVertex2d(695, 400);
glVertex2d(495, 400);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(300, 525);
glVertex2d(495, 525);
glVertex2d(495, 400);
glVertex2d(300, 400);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(695, 525);
glVertex2d(900, 525);
glVertex2d(900, 400);
glVertex2d(695, 400);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINES);
for (int i = 495; i <= 700; i = i + 100) {
glVertex2d(i, 528);
glVertex2d(i, 400);
}
glVertex2d(495, 400);
glVertex2d(695, 400);
glVertex2d(495, 525);
glVertex2d(695, 525);
glColor3f(0.3, 0.3, 0.3);
glVertex2d(300, 400);
glVertex2d(200, 400);
glVertex2d(300, 525);
glVertex2d(200, 400);
glVertex2d(300, 515);
glVertex2d(210, 400);
glVertex2d(900, 400);
glVertex2d(1000, 400);
glVertex2d(900, 525);
glVertex2d(1000, 400);
glVertex2d(900, 515);
glVertex2d(990, 400);
glVertex2d(200, 400);
glVertex2d(200, 350);
glVertex2d(1000, 400);
glVertex2d(1000, 380);
glEnd();

//Final Block
glBegin(GL_LINES);
glColor3f(0, 0, 0);
glVertex2d(492, 390);
glVertex2d(698, 390);
glVertex2d(489, 380);
glVertex2d(702, 380);
glVertex2d(485, 370);
glVertex2d(706, 370);
glVertex2d(481, 360);
glVertex2d(710, 360);


glColor3f(1, 0.5, 0);
glVertex2d(0, 350);
glVertex2d(810, 350);
glVertex2d(1040, 350);
glVertex2d(1200, 350);
glVertex2d(495, 400);
glVertex2d(370, 150);
glVertex2d(695, 400);
glVertex2d(830, 150);
glVertex2d(200, 350);
glVertex2d(40, 150);
glVertex2d(1070, 350);
glVertex2d(1195, 150);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_QUADS);
glVertex2d(500, 350);
glVertex2d(690, 350);
glVertex2d(710, 320);
glVertex2d(480, 320);
glVertex2d(480, 300);
glVertex2d(710, 300);
glVertex2d(730, 270);
glVertex2d(460, 270);
glVertex2d(460, 250);
glVertex2d(730, 250);
glVertex2d(750, 220);
glVertex2d(440, 220);
glVertex2d(440, 200);
glVertex2d(750, 200);
glVertex2d(770, 170);
glVertex2d(420, 170);
glEnd();

//this is bus!!
x = 40;
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(x + 850, 150);
glVertex2d(x + 1040, 150);
glVertex2d(x + 1040, 320);
glVertex2d(x + 850, 320);
glEnd();

glColor3f(0.5, 0, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 850, 150);
glVertex2d(x + 830, 180);
glVertex2d(x + 830, 180);
glVertex2d(x + 830, 200);
glVertex2d(x + 830, 200);
glVertex2d(x + 810, 220);
glVertex2d(x + 810, 220);
glVertex2d(x + 810, 190);
glVertex2d(x + 810, 190);
glVertex2d(x + 790, 220);
glVertex2d(x + 790, 220);
glVertex2d(x + 790, 240);
glVertex2d(x + 790, 240);
glVertex2d(x + 770, 260);
glVertex2d(x + 770, 260);
glVertex2d(x + 770, 240);
glVertex2d(x + 775, 380);
glVertex2d(x + 850, 320);
glEnd();

glColor3f(0.3, 0.3, 0.3);
glBegin(GL_POLYGON);
glVertex2d(x + 1040, 320);
glVertex2d(x + 965, 380);
glVertex2d(x + 775, 380);
glVertex2d(x + 850, 320);
glEnd();

glColor3f(0.5, 0, 1);
glBegin(GL_LINES);
glVertex2d(x + 850, 150);
glVertex2d(x + 830, 180);
glVertex2d(x + 830, 180);
glVertex2d(x + 830, 200);
glVertex2d(x + 830, 200);
glVertex2d(x + 810, 220);
glVertex2d(x + 810, 220);
glVertex2d(x + 810, 190);
glVertex2d(x + 810, 190);
glVertex2d(x + 790, 220);
glVertex2d(x + 790, 220);
glVertex2d(x + 790, 240);
glVertex2d(x + 790, 240);
glVertex2d(x + 770, 260);
glVertex2d(x + 770, 260);
glVertex2d(x + 770, 240);
glVertex2d(x + 775, 380);
glVertex2d(x + 850, 320);
glVertex2d(x + 850, 150);
glVertex2d(x + 830, 180);
glVertex2d(x + 830, 180);
glVertex2d(x + 830, 200);
glVertex2d(x + 830, 200);
glVertex2d(x + 810, 220);
glVertex2d(x + 810, 220);
glVertex2d(x + 810, 190);
glVertex2d(x + 810, 190);
glVertex2d(x + 790, 220);
glVertex2d(x + 790, 220);
glVertex2d(x + 790, 240);
glVertex2d(x + 790, 240);
glVertex2d(x + 770, 260);
glVertex2d(x + 770, 260);
glVertex2d(x + 770, 240);

glVertex2d(x + 850, 320);
glVertex2d(x + 775, 380);

glVertex2d(x + 770, 260);
glVertex2d(x + 770, 380);

glVertex2d(x + 850, 300);
glVertex2d(x + 1040, 300);
glVertex2d(x + 1040, 280);
glVertex2d(x + 850, 280);
glEnd();
glColor3ub(105, 22, 113);
glBegin(GL_POLYGON);
glVertex2d(x + 850, 300);
glVertex2d(x + 1040, 300);
glVertex2d(x + 1040, 280);
glVertex2d(x + 850, 280);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(x + 850, 300);
glVertex2d(x + 1040, 300);
glVertex2d(x + 1040, 320);
glVertex2d(x + 850, 320);
glEnd();


glBegin(GL_POLYGON);
glVertex2d(x + 850, 210);
glVertex2d(x + 1040, 210);
glVertex2d(x + 1040, 150);
glVertex2d(x + 850, 150);
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 3; i++) {
glVertex2d(x + 910, 170 + 10 * i);
glVertex2d(x + 980, 170 + 10 * i);
glVertex2d(x + 980, 180 + 10 * i);
glVertex2d(x + 910, 180 + 10 * i);
}
glEnd();

glColor3f(0, 0.9, 0.9);
glBegin(GL_POLYGON);
glVertex2d(893, 212);
glVertex2d(1079, 212);
glVertex2d(1079, 278);
glVertex2d(893, 278);
glEnd();


glColor3f(1, 0, 0);
glBegin(GL_LINES);
glVertex2d(x + 850, 210);
glVertex2d(x + 1040, 210);
glColor3f(0, 0, 0);
glVertex2d(x + 870, 230);
glVertex2d(x + 910, 230);
glVertex2d(x + 1020, 230);
glVertex2d(x + 980, 230);
glVertex2d(x + 890, 230);
glVertex2d(x + 910, 210);
glVertex2d(x + 1000, 230);
glVertex2d(x + 980, 210);
glEnd();

glColor3f(1, 1, 0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++)
glVertex2d(20 * cos(3.14*i / 180) + x + 880, 20 * sin(3.14*i / 180) + 185);
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++)
glVertex2d(20 * cos(3.14*i / 180) + x + 1010, 20 * sin(3.14*i / 180) + 185);
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++)
glVertex2d(15 * cos(3.14*i / 180) + x + 815, 15 * sin(3.14*i / 180) + 185);
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++)
glVertex2d(15 * cos(3.14*i / 180) + x + 775, 15 * sin(3.14*i / 180) + 225);
glEnd();

glColor3ub(105, 22, 113);
glBegin(GL_POLYGON);
glVertex2d(x + 830, 300);
glVertex2d(x + 790, 330);
glVertex2d(x + 790, 300);
glVertex2d(x + 830, 270);
glEnd();
glColor3f(0.3, 0.3, 0.3);
glBegin(GL_POLYGON);
glVertex2d(1200, 120);
glVertex2d(0, 120);
glVertex2d(0, 0);
glVertex2d(1200, 0);
glEnd();
glColor3f(1, 1, 1);
glLineWidth(8);
glBegin(GL_LINES);
for (int i = 50; i < 1200; i = i + 100) {
glVertex2d(i, 60);
glVertex2d(i + 50, 60);
}
glEnd();
bus(1, inc);
glutIdleFunc(idle1);
glFlush();
}
void fun3()
{
//gluOrtho2D(0, 500, 0, 500);
changecolor();
glClearColor(red, green, blue, 1);
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(3);
glColor3ub(160, 160, 160);
glBegin(GL_POLYGON);
glVertex2d(0, 120);
glVertex2d(500, 120);
glVertex2d(500, 80);
glVertex2d(0, 80);
glEnd();
glColor3ub(255, 153, 153);
glBegin(GL_POLYGON);
glVertex2d(325, 120);
glVertex2d(480, 120);
glVertex2d(480, 470);
glVertex2d(325, 470);
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(315, 470);
glVertex2d(490, 470);
glVertex2d(490, 490);
glVertex2d(315, 490);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(315, 470);
glVertex2d(490, 470);
glVertex2d(490, 490);
glVertex2d(315, 490);
glEnd();

for (int j = 440; j > 240; j = j - 70) {
for (int i = 0, x = 340; i < 3; i++, x = x + 45) {
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(x, j);
glVertex2d(x + 30, j);
glVertex2d(x + 30, j - 40);
glVertex2d(x, j - 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, j - 2);
glVertex2d(x + 27, j - 2);
glVertex2d(x + 27, j - 38);
glVertex2d(x + 3, j - 38);
glEnd();
}
}
int a[] = { 370,402 };
for (int i = 0; i < 2; i++) {
glColor3f(0, 0, 1);
glLineWidth(3);
glBegin(GL_LINE_LOOP);
glVertex2d(a[i], 133);
glVertex2d(a[i] + 30, 133);
glVertex2d(a[i] + 30, 237);
glVertex2d(a[i], 237);
glEnd();
glLineWidth(1);
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(a[i], 131);
glVertex2d(a[i] + 30, 131);
glVertex2d(a[i] + 30, 239);
glVertex2d(a[i], 239);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(a[i] + 2, 135);
glVertex2d(a[i] + 28, 135);
glVertex2d(a[i] + 28, 235);
glVertex2d(a[i] + 2, 235);
glEnd();
}

glLineWidth(5);
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_LINES);
glVertex2d(370, 185);
glVertex2d(400, 185);
glVertex2d(402, 185);
glVertex2d(432, 185);
glEnd();

glLineWidth(3);
glColor3ub(204, 102, 0);
glBegin(GL_POLYGON);
glVertex2d(25, 120);
glVertex2d(300, 120);
glVertex2d(300, 440);
glVertex2d(25, 440);
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(15, 440);
glVertex2d(310, 440);
glVertex2d(310, 460);
glVertex2d(15, 460);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(15, 440);
glVertex2d(310, 440);
glVertex2d(310, 460);
glVertex2d(15, 460);
glEnd();

for (int j = 410; j > 240; j = j - 60) {
for (int i = 0, x = 55; i < 5; i++, x = x + 45) {
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(x, j);
glVertex2d(x + 30, j);
glVertex2d(x + 30, j - 40);
glVertex2d(x, j - 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, j - 2);
glVertex2d(x + 27, j - 2);
glVertex2d(x + 27, j - 38);
glVertex2d(x + 3, j - 38);
glEnd();
}
}
int b[] = { 130,162 };
for (int i = 0; i < 2; i++) {
glColor3f(0, 0, 1);
glLineWidth(3);
glBegin(GL_LINE_LOOP);
glVertex2d(b[i], 133);
glVertex2d(b[i] + 30, 133);
glVertex2d(b[i] + 30, 237);
glVertex2d(b[i], 237);
glEnd();
glLineWidth(1);
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(b[i], 131);
glVertex2d(b[i] + 30, 131);
glVertex2d(b[i] + 30, 239);
glVertex2d(b[i], 239);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(b[i] + 2, 135);
glVertex2d(b[i] + 28, 135);
glVertex2d(b[i] + 28, 235);
glVertex2d(b[i] + 2, 235);
glEnd();
}
glLineWidth(3);
for (int j = 230; j > 130; j = j - 50) {
for (int i = 0, x = 40; i < 2; i++, x = x + 45) {
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(x, j);
glVertex2d(x + 30, j);
glVertex2d(x + 30, j - 40);
glVertex2d(x, j - 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, j - 2);
glVertex2d(x + 27, j - 2);
glVertex2d(x + 27, j - 38);
glVertex2d(x + 3, j - 38);
glEnd();
}
}
for (int j = 230; j > 130; j = j - 50) {
for (int i = 0, x = 210; i < 2; i++, x = x + 45) {
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(x, j);
glVertex2d(x + 30, j);
glVertex2d(x + 30, j - 40);
glVertex2d(x, j - 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, j - 2);
glVertex2d(x + 27, j - 2);
glVertex2d(x + 27, j - 38);
glVertex2d(x + 3, j - 38);
glEnd();
}
}

glLineWidth(5);
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_LINES);
glVertex2d(130, 185);
glVertex2d(160, 185);
glVertex2d(162, 185);
glVertex2d(192, 185);
glEnd();

glColor3f(0.3, 0.3, 0.3);
glBegin(GL_POLYGON);
glVertex2d(500, 80);
glVertex2d(0, 80);
glVertex2d(0, 0);
glVertex2d(500, 0);
glEnd();
glColor3f(1, 1, 1);
glLineWidth(8);
glBegin(GL_LINES);
for (int i = 30; i < 500; i = i + 60) {
glVertex2d(i, 40);
glVertex2d(i + 30, 40);
}
glEnd();
bus(0.5, inc1);
glutIdleFunc(idle2);
glFlush();
}
void fun4()
{
changecolor();
glClearColor(red, green, blue, 1);
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(3);
glColor3ub(160, 160, 160);
glBegin(GL_POLYGON);
glVertex2d(0, 80);
glVertex2d(500, 80);
glVertex2d(500, 170);
glVertex2d(0, 170);
glEnd();

glColor3ub(156, 83, 56);
glBegin(GL_POLYGON);
glVertex2d(70, 170);
glVertex2d(225, 170);
glVertex2d(225, 370);
glVertex2d(70, 370);
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(70, 170);
glVertex2d(225, 170);
glVertex2d(225, 370);
glVertex2d(70, 370);
glEnd();
glColor3ub(255, 204, 153);
glBegin(GL_POLYGON);
glVertex2d(225, 170);
glVertex2d(325, 170);
glVertex2d(325, 480);
glVertex2d(225, 480);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(225, 170);
glVertex2d(325, 170);
glVertex2d(325, 480);
glVertex2d(225, 480);
glEnd();
glColor3ub(156, 83, 56);
glBegin(GL_POLYGON);
glVertex2d(325, 170);
glVertex2d(480, 170);
glVertex2d(480, 370);
glVertex2d(325, 370);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(325, 170);
glVertex2d(480, 170);
glVertex2d(480, 370);
glVertex2d(325, 370);
glEnd();

glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(60, 370);
glVertex2d(225, 370);
glVertex2d(225, 390);
glVertex2d(60, 390);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(60, 370);
glVertex2d(225, 370);
glVertex2d(225, 390);
glVertex2d(60, 390);
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(210, 480);
glVertex2d(340, 480);
glVertex2d(340, 500);
glVertex2d(210, 500);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(210, 480);
glVertex2d(340, 480);
glVertex2d(340, 500);
glVertex2d(210, 500);
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(325, 370);
glVertex2d(490, 370);
glVertex2d(490, 390);
glVertex2d(325, 390);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(325, 370);
glVertex2d(490, 370);
glVertex2d(490, 390);
glVertex2d(325, 390);
glEnd();
for (int i = 0, y = 460; i < 5; i++, y = y - 60) {
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(235, y);
glVertex2d(265, y);
glVertex2d(265, y - 40);
glVertex2d(235, y - 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(238, y - 3);
glVertex2d(262, y - 3);
glVertex2d(262, y - 37);
glVertex2d(238, y - 37);
glEnd();
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(285, y);
glVertex2d(315, y);
glVertex2d(315, y - 40);
glVertex2d(285, y - 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(288, y - 3);
glVertex2d(312, y - 3);
glVertex2d(312, y - 37);
glVertex2d(288, y - 37);
glEnd();
}


glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(60, 279);
glVertex2d(222, 279);
glVertex2d(222, 301);
glVertex2d(60, 301);
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(60, 280);
glVertex2d(222, 280);
glVertex2d(222, 300);
glVertex2d(60, 300);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(90, 173);
glVertex2d(100, 173);
glVertex2d(100, 277);
glVertex2d(90, 277);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(195, 173);
glVertex2d(205, 173);
glVertex2d(205, 277);
glVertex2d(195, 277);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(90, 173);
glVertex2d(100, 173);
glVertex2d(100, 277);
glVertex2d(90, 277);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(195, 173);
glVertex2d(205, 173);
glVertex2d(205, 277);
glVertex2d(195, 277);
glEnd();

for (int i = 0, x = 85; i < 3; i++, x = x + 45) {
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(x, 315);
glVertex2d(x + 30, 315);
glVertex2d(x + 30, 355);
glVertex2d(x, 355);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, 317);
glVertex2d(x + 27, 317);
glVertex2d(x + 27, 353);
glVertex2d(x + 3, 353);
glEnd();
}

for (int i = 0, x = 340; i < 3; i++, x = x + 45) {
glColor3f(0, 0, 1);
glBegin(GL_LINE_LOOP);
glVertex2d(x, 300);
glVertex2d(x + 30, 300);
glVertex2d(x + 30, 340);
glVertex2d(x, 340);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, 302);
glVertex2d(x + 27, 302);
glVertex2d(x + 27, 338);
glVertex2d(x + 3, 338);
glEnd();
}
int a[] = { 115,148,370,402 };
for (int i = 0; i < 4; i++) {
glColor3f(0, 0, 1);
glLineWidth(3);
glBegin(GL_LINE_LOOP);
glVertex2d(a[i], 173);
glVertex2d(a[i] + 30, 173);
glVertex2d(a[i] + 30, 277);
glVertex2d(a[i], 277);
glEnd();
glLineWidth(1);
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(a[i], 171);
glVertex2d(a[i] + 30, 171);
glVertex2d(a[i] + 30, 279);
glVertex2d(a[i], 279);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(a[i] + 2, 175);
glVertex2d(a[i] + 28, 175);
glVertex2d(a[i] + 28, 275);
glVertex2d(a[i] + 2, 275);
glEnd();
}

glLineWidth(5);
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_LINES);
glVertex2d(115, 225);
glVertex2d(145, 225);
glVertex2d(148, 225);
glVertex2d(178, 225);
glVertex2d(370, 225);
glVertex2d(400, 225);
glVertex2d(402, 225);
glVertex2d(432, 225);
glEnd();

glLineWidth(2);
glColor3f(0, 0, 0);
char s[] = " HOSPITAL ";
glRasterPos2i(360, 440);
for (int i = 0; i < strlen(s); i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
glBegin(GL_LINES);
glVertex2d(350, 390);
glVertex2d(350, 460);
glVertex2d(350, 460);
glVertex2d(470, 460);
glVertex2d(470, 460);
glVertex2d(470, 390);
glEnd();
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(400, 410);
glVertex2d(410, 410);
glVertex2d(410, 400);
glVertex2d(420, 400);
glVertex2d(420, 410);
glVertex2d(430, 410);
glVertex2d(430, 420);
glVertex2d(420, 420);
glVertex2d(420, 430);
glVertex2d(410, 430);
glVertex2d(410, 420);
glVertex2d(400, 420);
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(10, 120);
glVertex2d(140, 120);
glVertex2d(140, 250);
glVertex2d(10, 250);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(10, 120);
glVertex2d(140, 120);
glVertex2d(140, 250);
glVertex2d(10, 250);
glEnd();
char s1[] = " AMBULANCE ";
glRasterPos2i(15, 220);
for (int i = 0; i < strlen(s); i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s1[i]);
glColor3f(1, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(55, 180);
glVertex2d(70, 180);
glVertex2d(70, 165);
glVertex2d(85, 165);
glVertex2d(85, 180);
glVertex2d(100, 180);
glVertex2d(100, 195);
glVertex2d(85, 195);
glVertex2d(85, 210);
glVertex2d(70, 210);
glVertex2d(70, 195);
glVertex2d(55, 195);
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(140, 120);
glVertex2d(140, 215);
glVertex2d(175, 215);
glVertex2d(175, 180);
glVertex2d(200, 180);
glVertex2d(200, 120);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(140, 120);
glVertex2d(140, 215);
glVertex2d(175, 215);
glVertex2d(175, 180);
glVertex2d(200, 180);
glVertex2d(200, 120);
glEnd();

glColor3f(0, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(145, 210);
glVertex2d(170, 210);
glVertex2d(170, 185);
glVertex2d(145, 185);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(145, 210);
glVertex2d(170, 210);
glVertex2d(170, 185);
glVertex2d(145, 185);
glEnd();

glColor3f(1, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(155, 215);
glVertex2d(160, 225);
glVertex2d(165, 225);
glVertex2d(170, 215);
glEnd();

glColor3f(0, 0, 0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(50 + 20 * cos(3.14*i / 180), 120 + 20 * sin(3.14*i / 180));
}
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(165 + 20 * cos(3.14*i / 180), 120 + 20 * sin(3.14*i / 180));
}
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(50 + 10 * cos(3.14*i / 180), 120 + 10 * sin(3.14*i / 180));
}
glEnd();
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
glVertex2d(165 + 10 * cos(3.14*i / 180), 120 + 10 * sin(3.14*i / 180));
}
glEnd();

glLineWidth(10);
glBegin(GL_LINES);
glVertex2d(5, 120);
glVertex2d(20, 120);
glVertex2d(195, 120);
glVertex2d(210, 120);
glEnd();
glLineWidth(5);
glBegin(GL_LINES);
glVertex2d(145, 170);
glVertex2d(165, 170);
glEnd();
glColor3f(1, 1, 0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
if (i == 91) {
i = 269;
continue;
}
glVertex2d(201 + 10 * cos(3.14*i / 180), 142 + 10 * sin(3.14*i / 180));
}
glEnd();

glColor3f(0.3, 0.3, 0.3);
glBegin(GL_POLYGON);
glVertex2d(500, 80);
glVertex2d(0, 80);
glVertex2d(0, 0);
glVertex2d(500, 0);
glEnd();
glColor3f(1, 1, 1);
glLineWidth(8);
glBegin(GL_LINES);
for (int i = 30; i < 500; i = i + 60) {
glVertex2d(i, 40);
glVertex2d(i + 30, 40);
}
glEnd();
glutIdleFunc(idle3);
bus(0.5, inc2);
glFlush();
}
void fun5()
{
changecolor();
glClearColor(red, green, blue, 1);
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(3);
glColor3ub(80, 35, 57);
glBegin(GL_POLYGON);
glVertex2d(40, 120);
glVertex2d(225, 120);
glVertex2d(225, 470);
glVertex2d(40, 470);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(40, 120);
glVertex2d(225, 120);
glVertex2d(225, 470);
glVertex2d(40, 470);
glEnd();

glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(20, 470);
glVertex2d(245, 470);
glVertex2d(245, 490);
glVertex2d(20, 490);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(20, 471);
glVertex2d(245, 471);
glVertex2d(245, 491);
glVertex2d(20, 491);
glEnd();


glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(20, 239);
glVertex2d(242, 239);
glVertex2d(242, 261);
glVertex2d(20, 261);
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(20, 240);
glVertex2d(242, 240);
glVertex2d(242, 260);
glVertex2d(20, 260);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(80, 123);
glVertex2d(90, 123);
glVertex2d(90, 237);
glVertex2d(80, 237);
glEnd();
glBegin(GL_POLYGON);
glVertex2d(185, 123);
glVertex2d(195, 123);
glVertex2d(195, 237);
glVertex2d(185, 237);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(80, 123);
glVertex2d(90, 123);
glVertex2d(90, 237);
glVertex2d(80, 237);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(185, 123);
glVertex2d(195, 123);
glVertex2d(195, 237);
glVertex2d(185, 237);
glEnd();

for (int j = 0, y = 280; j < 3; j++, y = y + 60) {
for (int i = 0, x = 50; i < 4; i++, x = x + 45) {
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(x, y);
glVertex2d(x + 30, y);
glVertex2d(x + 30, y + 40);
glVertex2d(x, y + 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, y + 3);
glVertex2d(x + 27, y + 3);
glVertex2d(x + 27, y + 37);
glVertex2d(x + 3, y + 37);
glEnd();
}
}

glColor3ub(145, 101, 99);
glBegin(GL_POLYGON);
glVertex2d(265, 120);
glVertex2d(480, 120);
glVertex2d(480, 470);
glVertex2d(265, 470);
glEnd();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_POLYGON);
glVertex2d(255, 470);
glVertex2d(490, 470);
glVertex2d(490, 490);
glVertex2d(255, 490);
glEnd();
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(255, 470);
glVertex2d(490, 470);
glVertex2d(490, 490);
glVertex2d(255, 490);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2d(265, 120);
glVertex2d(480, 120);
glVertex2d(480, 470);
glVertex2d(265, 470);
glEnd();

glLineWidth(3);
for (int j = 450; j > 240; j = j - 70) {
for (int i = 0, x = 290; i < 4; i++, x = x + 45) {
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(x, j);
glVertex2d(x + 30, j);
glVertex2d(x + 30, j - 40);
glVertex2d(x, j - 40);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(x + 3, j - 2);
glVertex2d(x + 27, j - 2);
glVertex2d(x + 27, j - 38);
glVertex2d(x + 3, j - 38);
glEnd();
}
}
int a[] = { 105,138,342,375 };
for (int i = 0; i < 4; i++) {
glColor3f(0, 0, 0);
glLineWidth(3);
glBegin(GL_LINE_LOOP);
glVertex2d(a[i], 123);
glVertex2d(a[i] + 30, 123);
glVertex2d(a[i] + 30, 237);
glVertex2d(a[i], 237);
glEnd();
glLineWidth(1);
glColor3f(0, 0, 0);
glBegin(GL_LINE_LOOP);
glVertex2d(a[i], 121);
glVertex2d(a[i] + 30, 121);
glVertex2d(a[i] + 30, 239);
glVertex2d(a[i], 239);
glEnd();
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2d(a[i] + 2, 125);
glVertex2d(a[i] + 28, 125);
glVertex2d(a[i] + 28, 235);
glVertex2d(a[i] + 2, 235);
glEnd();
}


glLineWidth(5);
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_LINES);
glVertex2d(105, 180);
glVertex2d(135, 180);
glVertex2d(138, 180);
glVertex2d(168, 180);
glEnd();
glBegin(GL_LINES);
glVertex2d(340, 180);
glVertex2d(370, 180);
glVertex2d(374, 180);
glVertex2d(404, 180);
glEnd();

glColor3f(0.3, 0.3, 0.3);
glBegin(GL_POLYGON);
glVertex2d(500, 80);
glVertex2d(0, 80);
glVertex2d(0, 0);
glVertex2d(500, 0);
glEnd();
glColor3f(1, 1, 1);
glLineWidth(8);
glBegin(GL_LINES);
for (int i = 30; i < 500; i = i + 60) {
glVertex2d(i, 40);
glVertex2d(i + 30, 40);
}
glEnd();

glColor3ub(160, 160, 160);
glBegin(GL_POLYGON);
glVertex2d(0, 80);
glVertex2d(500, 80);
glVertex2d(500, 120);
glVertex2d(0, 120);
glEnd();


glLineWidth(10);
glBegin(GL_LINES);
glColor3f(1, 1, 1);
glVertex2d(25, 202);
glVertex2d(25, 195);
glVertex2d(250, 202);
glVertex2d(250, 195);
glColor3f(0.3, 0.3, 0.3);
glVertex2d(10, 120);
glVertex2d(10, 200);
glVertex2d(10, 200);
glVertex2d(35, 210);
glVertex2d(235, 120);
glVertex2d(235, 200);
glVertex2d(235, 200);
glVertex2d(260, 210);
glEnd();
glutIdleFunc(idle4);
glFlush();
}
void callback(int value) {
switch (value) {
case 1: fun1(); changecolor(); break;
case 2: fun2(); changecolor(); break;
case 3: fun3(); changecolor(); break;
case 4: fun4(); changecolor(); break;
case 5: fun5(); changecolor(); break;

}
};
void display()
{
start();
if (flag == 1) {
glutTimerFunc(0, callback, 1);
glutTimerFunc(3500, callback, 2);
glutTimerFunc(12050, callback, 3);
glutTimerFunc(19130, callback, 4);
glutTimerFunc(26640, callback, 5);
}

}
//Reshape function to adjust window size wrt change
void reshape(int w, int h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
int t1 = (float)w / (float)h;
int t2 = (float)h / (float)w;
if (w > h)
gluOrtho2D(0 * t1, 300 * t1, 0, 240);
else
gluOrtho2D(0, 300, 0 * t2, 240 * t2);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glutPostRedisplay();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutCreateWindow("Smart City View");
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutReshapeFunc(reshape);
glutMainLoop();
}
