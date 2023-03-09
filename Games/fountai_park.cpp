
#define PI 3.14152653597689786
#define RandomFactor 2.0
#define ESCAPE 27
#define TEXTID  3
#include<windows.h>
#include<GL/glut.h>
#include <iostream>
//#include <unistd.h>
#include <time.h>
#include <math.h>

unsigned int i;
int flag=0,f=2;
int vflag=0;
GLfloat xt=0.0,yt=0.0,zt=0.0;
GLfloat xangle=0.0,yangle=0.0,zangle=0.0;
GLfloat X[3];
GLint ListNum;            //The number of the diplay list

GLfloat OuterRadius = 1.4;	//reservoir
GLfloat InnerRadius = 1.0;
GLint NumOfVerticesStone = 6;	// reservoir shape
GLfloat StoneHeight = 0.5;
GLfloat WaterHeight = 0.45;


int SCENE_ID;
// Variables for Animator Faders
GLfloat title_fade,
intro_next_text_appear, summary_next_text_appear,
summary_para1_fade, summary_para2_fade, summary_para3_fade,
summary_para4_fade,
kg_a_fade, kg_apple_fade, kg_b_fade, kg_ball_fade, kg_soon_fade,
kg_subtitle_1_appear,
ps_chap_fade, ps_title_fade,
ps_subtitle_1_appear, ps_subtitle_2_appear;
// Variables for Translation Animators
GLfloat trans_x_kid1, trans_x_kid2, trans_x_kid3,trans_y_kid4, trans_x_ball;
// Variables for Color Morphers
GLfloat sky_r = 12, sky_g = 172, sky_b = 232,
grass_r = 82, grass_g = 163, grass_b = 42;


void drawCircle(GLfloat x, GLfloat y,GLfloat r, GLfloat g, GLfloat b,GLfloat sx, GLfloat sy,GLfloat
radius) {
glPushMatrix();
glTranslatef(x, y, 0);
glScalef(sx, sy, 0);
glBegin(GL_POLYGON);
glColor3ub(r, g, b);
for (GLfloat i = 0; i < 360; i += 5)
glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
glEnd();
glPopMatrix();
}
// Function to Draw Circle
void drawSemiCircle(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy,GLfloat r, GLfloat g, GLfloat
b,GLfloat radius,GLfloat start_angle, GLfloat end_angle) {
glPushMatrix();
glTranslatef(tx, ty, 0);
glScalef(sx, sy, 0);
glBegin(GL_POLYGON);
glColor3ub(r, g, b);
for (GLfloat i = start_angle; i < end_angle; i += 5)
glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
glEnd();
glPopMatrix();
}
// Function to Draw Arc
void drawArc(GLfloat tx, GLfloat ty,GLfloat sx, GLfloat sy,GLfloat r, GLfloat g, GLfloat b) {
glPushMatrix();
glTranslatef(tx, ty, 0);
glScalef(sx, sy, 0);
glPointSize(2);
glBegin(GL_POINTS);
glColor3ub(r, g, b);
for ( GLfloat i = 90; i < 270; i++)
glVertex2f(15 * sin(i * PI / 180), 15 * cos(i * PI / 180));
glEnd();
glPointSize(1);
glPopMatrix();
}
void drawKidsShirtAndTrousers(GLfloat tx, GLfloat ty,
GLfloat sx, GLfloat sy,
GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
glPushMatrix();
glTranslatef(tx, ty, 0);
glScalef(sx, sy, 0);
// Bottom Shirt
glColor3ub(shirt_r, shirt_g, shirt_b);
glBegin(GL_POLYGON);
glVertex2f(0, 20);
glVertex2f(100, 20);
glVertex2f(100, 100);
glVertex2f(0, 100);
glEnd();
// Top Shirt
glBegin(GL_POLYGON);
glVertex2f(100, 100);
glVertex2f(135, 105);
glVertex2f(120, 175);
glVertex2f(100, 200);
glVertex2f(50, 180);
glVertex2f(0, 200);
glVertex2f(-20, 175);
glVertex2f(-35, 105);
glVertex2f(0, 100);
glEnd();
// Left Trouser
glColor3ub(37, 107, 202);
glBegin(GL_POLYGON);
glVertex2f(0, 25);
glVertex2f(0, -100);
glVertex2f(35, -100);
glVertex2f(65, 25);
glEnd();
// Right Trouser
glBegin(GL_POLYGON);
glVertex2f(35, 25);
glVertex2f(65, -100);
glVertex2f(100, -100);
glVertex2f(100, 25);
glEnd();
glPopMatrix();
}
void drawKid(GLfloat tx, GLfloat ty,
GLfloat sx, GLfloat sy,
GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
glPushMatrix();
glTranslatef(tx, ty, 0);
glScalef(sx, sy, 0);
// Neck
drawSemiCircle(-1, -35, .6, 1,
203, 166, 108,
20, -90, 90);
// Face
drawCircle(0, 0,
232, 190, 123,
1, 1,
24);
// Left Eye
drawCircle(-8, 0,
250, 250, 250,
1, 1,
4);
drawCircle(-6, 0,
10, 10, 10,
1, 1,
2);
// Right Eye
drawCircle(8, 0,
250, 250, 250,
1, 1,
4);
drawCircle(10, 0,
10, 10, 10,
1, 1,
2);
// Cap
drawSemiCircle(0, 10, 1, 1,
37, 107, 202,
24, -90, 90);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2f(20, 14);
glVertex2f(40, 16);
glEnd();
glLineWidth(1);
// Hands
drawCircle(-42, -82,
232, 190, 123,
1, 1,
10);
drawCircle(38, -82,
232, 190, 123,
1, 1,
10);
// Shirt and Trousers
drawKidsShirtAndTrousers(-32, -125,
.6, .5,
shirt_r, shirt_g, shirt_b);
// Left Shoe
drawSemiCircle(-21, -178,
1.2, 1,
20, 20, 20,
10,
-90, 90);
// Right Shoe
drawSemiCircle(18, -178,
1.2, 1,
20, 20, 20,
10,
-90, 90);
glPopMatrix();
}
void drawWoman(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,GLfloat hair_r, GLfloat hair_g,
GLfloat hair_b,GLfloat top_r, GLfloat top_g, GLfloat top_b,GLfloat ribbon_r, GLfloat ribbon_g,
GLfloat ribbon_b,GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
glPushMatrix();
glTranslatef(tx, ty, 0);
glScalef(sx, sy, 0);
// Neck
glLineWidth(10);
glBegin(GL_LINES);
glColor3ub(203, 166, 108); // Darker Skin
glVertex2f(507, 380);
glVertex2f(507, 360);
glVertex2f(513, 380);
glVertex2f(513, 360);
glEnd();
glLineWidth(1);
// Face
drawCircle(510, 407,
232, 190, 123, // Lighter Skin
1, 1,
30);
// Hair
drawSemiCircle(510, 420, 1, .6,hair_r, hair_g, hair_b,35, -90, 90);
drawSemiCircle(485, 400, .4, 1,hair_r, hair_g, hair_b,35, -180, 0);
// Left Eye
drawCircle(505, 410,250, 250, 250,1, 1,5);
drawCircle(508, 408,10, 10, 10,1, 1,2.5);
// Right Eye
drawCircle(530, 410,250, 250, 250,1, 1,5);
drawCircle(532, 408,
10, 10, 10,
1, 1,
2.5);
// Smile
drawArc(514, 388, .5, .3,
20, 20, 20);
// Nose
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(518, 405);
glVertex2f(522, 398);
glVertex2f(522, 398);
glVertex2f(518, 395);
glEnd();
glLineWidth(1);
// Arms
glLineWidth(10);
glBegin(GL_LINES);
glColor3ub(232, 190, 123); // Lighter Skin
glVertex2f(470, 340);
glVertex2f(470, 240);
glVertex2f(475, 340);
glVertex2f(475, 240);
glVertex2f(480, 340);
glVertex2f(480, 240);
glVertex2f(540, 340);
glVertex2f(540, 240);
glVertex2f(545, 340);
glVertex2f(545, 240);
glVertex2f(550, 340);
glVertex2f(550, 240);
glEnd();
glLineWidth(1);
// Top
glBegin(GL_POLYGON);
glColor3ub(top_r, top_g, top_b);
glVertex2f(460, 370);
glVertex2f(560, 370);
glVertex2f(540, 300);
glVertex2f(480, 300);
glEnd();
// Skirt
glBegin(GL_POLYGON);
glColor3ub(skirt_r, skirt_g, skirt_b);
glVertex2f(480, 300);
glVertex2f(540, 300);
glVertex2f(560, 180);
glVertex2f(460, 180);
glEnd();
// Ribbon
glLineWidth(10);
glBegin(GL_LINES);
glColor3ub(ribbon_r, ribbon_g, ribbon_b);
glVertex2f(480, 300);
glVertex2f(540, 300);
glEnd();
glLineWidth(1);
// Legs
glLineWidth(10);
glBegin(GL_LINES);
glColor3ub(232, 190, 123); // Lighter Skin
glVertex2f(490, 180);
glVertex2f(490, 150);
glVertex2f(495, 180);
glVertex2f(495, 150);
glVertex2f(525, 180);
glVertex2f(525, 150);
glVertex2f(530, 180);
glVertex2f(530, 150);
glEnd();
glLineWidth(1);
glPopMatrix();
}
void drawTree(GLfloat tx, GLfloat ty,
GLfloat sx, GLfloat sy) {
glPushMatrix();
glTranslatef(tx, ty, 0);
glScalef(sx, sy, 0);
// Bark
glBegin(GL_POLYGON);
glColor3ub(86, 46, 11);
glVertex2f(0, 0);
glVertex2f(40, 0);
glColor3ub(71, 36, 6);
glVertex2f(35, 200);
glVertex2f(5, 200);
glEnd();
// Tree
drawCircle(20, 200, 5, 80, 10, 1, 1, 80);
// Apples
drawCircle(27, 194, 255, 0, 0, 1, 1.2, 5);
drawCircle(-15, 170, 255, 0, 0, 1, 1.2, 5);
drawCircle(47, 155, 255, 0, 0, 1, 1.2, 5);
drawCircle(-2, 228, 255, 0, 0, 1, 1.2, 5);
drawCircle(72, 216, 255, 0, 0, 1, 1.2, 5);
glPopMatrix();
}
void EC_drawTrees() {

// Left Trees

drawTree(430, 600, .5, .5);
drawTree(360, 600, .48, .48);
drawTree(290, 600, .46, .46);
drawTree(220, 600, .44, .44);
// Right Trees
drawTree(940, 600, .5, .5);
drawTree(1010, 600, .48, .48);
drawTree(1080, 600, .46, .46);
drawTree(1150, 600, .44, .44);
}
void KG_Bench()
{
glBegin(GL_POLYGON);
glColor3ub(80, 80, 80); // gray
glVertex2f(1000, 550);
glVertex2f(960, 500);
glVertex2f(1300, 500);
glVertex2f(1310, 550);
glEnd();
// bench seating Edge
glBegin(GL_POLYGON);
glColor3ub(80, 80, 80); // gray
glVertex2f(960, 500);
glVertex2f(960, 490);
glVertex2f(1300, 490);
glVertex2f(1300, 500);
glEnd();
//bench back
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(80, 80, 80); //gray
glVertex2f(1000, 560);
glVertex2f(1310, 560);
glVertex2f(1000, 570);
glVertex2f(1310, 570);
glVertex2f(1000, 580);
glVertex2f(1310, 580);
glVertex2f(1000, 590);
glVertex2f(1310, 590);
glLineWidth(10);
glVertex2f(1030, 550);
glVertex2f(1030, 595);
glVertex2f(1270, 550);
glVertex2f(1270, 595);
glEnd();
// Left bench Leg
glBegin(GL_POLYGON);
glColor3ub(80, 80, 80); // gray
glVertex2f(1020, 490);
glVertex2f(1010, 490);
glVertex2f(1010, 430);
glVertex2f(1020, 430);
glEnd();
// Right bench Leg
glBegin(GL_POLYGON);
glColor3ub(80, 80, 80); // gray
glVertex2f(1270, 490);
glVertex2f(1260, 490);
glVertex2f(1260, 430);
glVertex2f(1270, 430);
glEnd();

}

void PS_parent() {
//glBegin(GL_POLYGON);
glColor3ub(247, 239, 187);
glVertex2f(950, 550);
glVertex2f(1300, 550);
glVertex2f(1300, 300);
glVertex2f(950, 300);
//glEnd();
// Mother
drawWoman(1630, 50, -1, 1,
20, 20, 20,
229, 49, 49, // top
37, 107, 202, // bottom
229, 49, 49 // skirt
);
}
void KG_slide() {
// slide
glBegin(GL_POLYGON);
glColor3ub(56, 1, 1); // Chocolate Brown
glVertex2f(90, 600);
glVertex2f(190, 350);
glVertex2f(280, 350);
glVertex2f(200, 600);
glEnd();
// Left slide Leg
glBegin(GL_POLYGON);
glColor3ub(56, 1, 1); // Darker Chocolate Brown
glVertex2f(85, 600);
glVertex2f(85, 400);
glVertex2f(95, 400);
glVertex2f(95, 600);
glEnd();
// Right slide Leg
glBegin(GL_POLYGON);
glColor3ub(56, 1, 1); // Darker Chocolate Brown
glVertex2f(145, 500);
glVertex2f(155, 500);
glVertex2f(155, 400);
glVertex2f(145, 400);
glEnd();
//steps
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(56, 1, 1);
glVertex2f(95, 420);
glVertex2f(145, 420);
glVertex2f(95, 450);
glVertex2f(145, 450);
glVertex2f(95, 480);
glVertex2f(145, 480);
glVertex2f(95, 510);
glVertex2f(145, 510);
glVertex2f(95, 540);
glVertex2f(145, 540);
glEnd();
drawKid(200 , 650 -trans_y_kid4,//kid on slide
-.3, .3,
255, 50, 0);
drawKid(210 , 550 -trans_y_kid4,
-.3, .3,
255, 50, 0);
}

struct SVertex
{
	GLfloat x,y,z;
};
class CDrop
{
private:
	GLfloat time;
	SVertex ConstantSpeed;
	GLfloat AccFactor;
public:
	void SetConstantSpeed (SVertex NewSpeed);
	void SetAccFactor(GLfloat NewAccFactor);
	void SetTime(GLfloat NewTime);
	void GetNewPosition(SVertex * PositionVertex);  //increments time, gets the new position
};

void CDrop::SetConstantSpeed(SVertex NewSpeed)
{
	ConstantSpeed = NewSpeed;
}

void CDrop::SetAccFactor (GLfloat NewAccFactor)
{
	AccFactor = NewAccFactor;
}

void CDrop::SetTime(GLfloat NewTime)
{
	time = NewTime;
}

void CDrop::GetNewPosition(SVertex * PositionVertex)
{
	SVertex Position;
	time += 0.15;
	Position.x = ConstantSpeed.x * time;
	Position.y = ConstantSpeed.y * time - AccFactor * time *time;
	Position.z = ConstantSpeed.z * time;
	PositionVertex->x = Position.x;
	PositionVertex->y = Position.y + WaterHeight;
	PositionVertex->z = Position.z;
	if (Position.y < 0.0)
	{
		time = time - int(time);
		if (time > 0.0) time -= 1.0;
	}

}

CDrop * FountainDrops;
SVertex * FountainVertices;
GLint Steps = 4;              //a fountain has several steps, each with its own height
GLint RaysPerStep =5;
GLint DropsPerRay = 80;
GLfloat DropsComplete = Steps * RaysPerStep * DropsPerRay;
GLfloat AngleOfDeepestStep = 80;
GLfloat AccFactor = 0.011;

GLfloat GetRandomFloat(GLfloat range)
{
	return (GLfloat)rand() / (GLfloat)RAND_MAX * range * RandomFactor;
}
void CreateList(void)
{
	SVertex * Vertices = new SVertex[NumOfVerticesStone*3];  //allocate mem for the required vertices
	ListNum = glGenLists(1);
  for (GLint i = 0; i<NumOfVerticesStone; i++)
	{
		Vertices[i].x = cos(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
		Vertices[i].y = StoneHeight;  //Top
		Vertices[i].z = sin(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
	}
  for (i = 0; i<NumOfVerticesStone; i++)
	{
		Vertices[i + NumOfVerticesStone*1].x = cos(2.0 * PI / NumOfVerticesStone * i) * InnerRadius;
		Vertices[i + NumOfVerticesStone*1].y = StoneHeight;  //Top
		Vertices[i + NumOfVerticesStone*1].z = sin(2.0 * PI / NumOfVerticesStone * i) * InnerRadius;
	}
  for (i = 0; i<NumOfVerticesStone; i++)
	{
		Vertices[i + NumOfVerticesStone*2].x = cos(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
		Vertices[i + NumOfVerticesStone*2].y = 0.0;  //Bottom
		Vertices[i + NumOfVerticesStone*2].z = sin(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
	}


	glNewList(ListNum, GL_COMPILE);

		glBegin(GL_QUADS);
		for (int j = 1; j < 3; j++)
		{
			if (j == 1) glColor3f(1.3,0.5,1.2);
			if (j == 2) glColor3f(0.4,0.2,0.1);
			for (i = 0; i<NumOfVerticesStone-1; i++)
			{
				glVertex3fv(&Vertices[i+NumOfVerticesStone*j].x);
				glVertex3fv(&Vertices[i].x);
				glVertex3fv(&Vertices[i+1].x);
				glVertex3fv(&Vertices[i+NumOfVerticesStone*j+1].x);
			}
			glVertex3fv(&Vertices[i+NumOfVerticesStone*j].x);
			glVertex3fv(&Vertices[i].x);
	        glVertex3fv(&Vertices[0].x);
			glVertex3fv(&Vertices[NumOfVerticesStone*j].x);
		}

		glEnd();

	    //The "water":
		glTranslatef(0.0,WaterHeight - StoneHeight, 0.0);
	    glBegin(GL_POLYGON);
        for (i = 0; i<NumOfVerticesStone; i++)
		{


			glVertex3fv(&Vertices[i+NumOfVerticesStone].x);
			GLint m1,n1,p1;
	         m1=rand()%255;
             n1=rand()%255;
             p1=rand()%255;

	         glColor3ub(m1,n1,p1);

		//	glColor3f(1.0,1.0,1.0);
		}

		glEnd();
		glEndList();

}

void InitFountain(void)
{
	//This function needn't be and isn't speed optimized
	FountainDrops = new CDrop [ (int)DropsComplete ];
	FountainVertices = new SVertex [ (int)DropsComplete ];
	SVertex NewSpeed;
	GLfloat DropAccFactor; //different from AccFactor because of the random change
	GLfloat TimeNeeded;
	GLfloat StepAngle; //Angle, which the ray gets out of the fountain with
	GLfloat RayAngle;	//Angle you see when you look down on the fountain
	GLint i,j,k;
	for (k = 0; k <Steps; k++)
	{
		for (j = 0; j < RaysPerStep; j++)
		{
			for (i = 0; i < DropsPerRay; i++)
			{
				DropAccFactor = AccFactor + GetRandomFloat(0.0005);
				StepAngle = AngleOfDeepestStep + (90.0-AngleOfDeepestStep)
						* GLfloat(k) / (Steps-1) + GetRandomFloat(0.2+0.8*(Steps-k-1)/(Steps-1));
				//This is the speed caused by the step:
				NewSpeed.x = cos ( StepAngle * PI / 180.0) * (0.2+0.04*k);
				NewSpeed.y = sin ( StepAngle * PI / 180.0) * (0.2+0.04*k);
				//This is the speed caused by the ray:

				RayAngle = (GLfloat)j / (GLfloat)RaysPerStep * 360.0;
				//for the next computations "NewSpeed.x" is the radius. Care! Dont swap the two
				//lines, because the second one changes NewSpeed.x!
				NewSpeed.z = NewSpeed.x * sin ( RayAngle * PI /180.0);
				NewSpeed.x = NewSpeed.x * cos ( RayAngle * PI /180.0);

				//Calculate how many steps are required, that a drop comes out and falls down again
				TimeNeeded = NewSpeed.y/ DropAccFactor;
				FountainDrops[i+j*DropsPerRay+k*DropsPerRay*RaysPerStep].SetConstantSpeed ( NewSpeed );
				FountainDrops[i+j*DropsPerRay+k*DropsPerRay*RaysPerStep].SetAccFactor (DropAccFactor);
				FountainDrops[i+j*DropsPerRay+k*DropsPerRay*RaysPerStep].SetTime(TimeNeeded * i / DropsPerRay);
			}
		}
	}


	//Tell OGL that we'll use the vertex array function
	glEnableClientState(GL_VERTEX_ARRAY);
	//Pass the data position
	glVertexPointer(	3,			//x,y,z-components
						GL_FLOAT,	//data type of SVertex
					    0,			//the vertices are tightly packed
	FountainVertices);

}

void DrawFountain(void)
{

if(flag==0)
	 glColor3f(1.0,0.0,1.1);
else if(flag==1)
    glColor3f(1.0,1.0,1.0);
else if(flag==2)
    glColor3f(0.0,1.0,0.0);
else if(flag==3)
    glColor3f(1.0,0.0,0.0);
else if(flag==4)
    glColor3f(1.0,1.0,0.0);
else if(flag==5)
    glColor3f(0.0,1.0,1.0);
else
    glColor3f(0.0,1.0,1.0);

	for (int i = 0; i < DropsComplete; i++)
	{
		FountainDrops[i].GetNewPosition(&FountainVertices[i]);
	}
	glDrawArrays(GL_POINTS,0,DropsComplete);
glutPostRedisplay();
}

void Reshape(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50.0,(GLdouble)x/(GLdouble)y,0.10,20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,x,y);  //Use the whole window for rendering
	//Adjust point size to window size
	glPointSize(GLfloat(x)/600.0);
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glFlush();
}
void display()
{

glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT );
glLoadIdentity();
glClearColor(0,0,0,0);

glPushMatrix();
glTranslatef(0.0,0.0,-7.0);
glTranslatef(0.0,-1.3,0.0);
glCallList(ListNum);
DrawFountain();
glPopMatrix();
glTranslatef(0.0,0.0,-1.5);
glTranslatef(0.0,-0.3,0.0);
gluOrtho2D(0,1400,0,800);
KG_Bench();
EC_drawTrees();
PS_parent();

if (trans_x_kid1 < 40)
trans_x_kid1 += .4;
if (trans_x_kid2 < 40)
trans_x_kid2 += .3;
if (trans_x_kid3 < 40)
trans_x_kid3 += .3;
if (trans_y_kid4 < 300)
trans_y_kid4 += 1.1;
if (trans_x_ball < 50)
trans_x_ball += .4;

KG_slide();
drawKid(360 + trans_x_kid1, 380,
-.3, .3,
80, 50, 20);
// Left Kid
drawKid(350 + trans_x_kid2, 350,
.3, .3,
255, 255, 0);
// Right Kid
drawKid(400 + trans_x_kid3, 350,
-.3, .3,
255, 50, 0);
drawKid(500 + trans_x_kid1, 380,
-.3, .3,
80, 50, 20);
drawKid(450 + trans_x_kid2, 350,
.3, .3,
255, 255, 0);
// Ball
drawCircle(380 + trans_x_ball, 305,
200, 200, 200,
1, 1,
6);
glFlush();
}


void NormalKey(GLubyte key, GLint x, GLint y)
{
    switch ( key )
	{
		case ESCAPE : exit(0);	break;
        case '1':
            flag=1;
            glutPostRedisplay();
            break;
        case '2':
            flag=2;
            glutPostRedisplay();
            break;
        case '3':
            flag=3;
            glutPostRedisplay();
            break;
        case '4':
            flag=4;
            glutPostRedisplay();
            break;

        case '5':
            flag=5;
            glutPostRedisplay();
            break;



      default:
				break;
    }


}

int main(int argc,char *argv[])
{
glutInit(&argc,argv);
glutInitWindowSize(1400,800);
glutInitWindowPosition(0, 0);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutCreateWindow("Line");
glutDisplayFunc(display);
init();
CreateList();
InitFountain();
glutReshapeFunc(Reshape);
glutKeyboardFunc(NormalKey);
glutMainLoop();
return 0;
}

