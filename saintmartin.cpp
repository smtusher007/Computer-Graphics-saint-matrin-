#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include<math.h>>
#include<MMSystem.h>
#include<cstdio>
# define PI           3.14159265358979323846

float _moveb1 = 0.00f; //bus
float _moveSun = 0.00f;
float _movet1= 0.00f;
float _movecar1= 0.00f;
float _movecar2= 0.00f;
float _moveObject =0.0f;
float _movePlane = 0.0f;
float _moveCloud =0.0f;
float _moveCloudleft=0.0f;
float _moveWater= -0.12f;


void init()
{

        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
         gluOrtho2D(-0.64,0.64,-0.64,0.64);


}


void updateb1(int value) {
 _moveb1 += .02;
if(_moveb1 > 1.5)
{
_moveb1 = -1.5;
}
glutPostRedisplay();
glutTimerFunc(70, updateb1, 0);
}

void updateSun(int value) {
 _moveSun -= .02;
if(_moveSun > +0.27)
{
_moveSun= +0.64;
}
glutPostRedisplay();
glutTimerFunc(800, updateSun, 0);
}

void updatet1(int value) {
 _movet1 += .02;
if(_movet1 > 1.00)
{
_movet1 = -1.00;
}
glutPostRedisplay();
glutTimerFunc(200, updatet1, 0);
}

void updateObject(int value) {
 _moveObject += .02;
if(_moveObject > 1.00)
{
_moveObject = -1.00;
}
glutPostRedisplay();
glutTimerFunc(400, updateObject, 0);
}


void updateCar1(int value) {
 _movecar1 -= .02;
if(_movecar1 < -1.5)
{
_movecar1 = 1.5;
}
glutPostRedisplay();
glutTimerFunc(80, updateCar1, 0);
}


void updateCar2(int value) {
 _movecar2 += .02;
if(_movecar2 > 1.5)
{
_movecar2 = -1.5;
}
glutPostRedisplay();
glutTimerFunc(80, updateCar2, 0);
}


void updatePlane(int value) {
 _movePlane += .02;
if(_movePlane > 1.5)
{
_movePlane  = -1.5;
}
glutPostRedisplay();
glutTimerFunc(130, updatePlane, 0);
}


void updateCloud(int value) {               //left to right
 _moveCloud += .02;
if(_moveCloud > 1.5)
{
_moveCloud  = -1.5;
}
glutPostRedisplay();
glutTimerFunc(190, updateCloud, 0);
}


void updateCloudleft(int value) {           //right to left
 _moveCloudleft -= .02 ;
if(_moveCloudleft < -1.5)
{
_moveCloudleft  = 1.5;
}


glutTimerFunc(190, updateCloudleft, 0);
}

void updateWater(int value) {
 _moveWater += .008;
if(_moveWater >0)
{
  _moveWater  = -0.1;
}

glutPostRedisplay();
    glutTimerFunc(300, updateWater, 0);
}


///...............Rain
GLfloat position8 = 0.0f;
GLfloat Speed8= 0.02f;

GLfloat position9 = 0.0f;
GLfloat Speed9= 0.06f;

GLfloat position10 = 0.0f;
GLfloat Speed10= 0.02f;

///.......................................Rain

void update8 (int value)
{
   if(position8 <-1.0)
      position8 =0.2f;

      position8 -= Speed8;

      glutPostRedisplay();

    if(position9 >1.0)
      position9 =-1.0f;

      position9 += Speed9;

      glutPostRedisplay();


    if(position10 <1.0)
      position10 =-0.1f;

      position10 -= Speed10;

      glutPostRedisplay();

   glutTimerFunc(100,update8,0);
}
/*rain*/


void circleSolid(float x, float y, float radius)
{

    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}


void sun()

{
///sun day

glPushMatrix();
    glTranslatef( 0.0f, _moveSun,0.00f);

    glColor3ub( 253, 208, 23);
    circleSolid(0.08f,0.40f,0.07);

     glPopMatrix();
    glutSwapBuffers();

}
void sunN()

{
///sun night
    glColor3ub( 255, 255, 255);
    circleSolid(0.08f,0.40f,0.05);
}




void sky()
{

    glBegin(GL_QUADS);
    glColor3ub(130, 202, 255);
    glVertex2f(-0.64f,0.01f);
    glVertex2f(0.64f,0.01f);
    glVertex2f(0.64f,.64f);
    glVertex2f(-0.64f,.64f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(169, 171, 73);
    glVertex2f(-0.64f,0.01f);
    glVertex2f(0.64f,0.01f);
    glVertex2f(0.64f,.00f);
    glVertex2f(-0.64f,.00f);
    glEnd();

}


void skyN()
{

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-0.64f,0.00f);
    glVertex2f(0.64f,0.00f);
    glVertex2f(0.64f,.64f);
    glVertex2f(-0.64f,.64f);
    glEnd();

    glColor3ub( 255, 255, 255);
    circleSolid(-0.60f,0.38f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.50f,0.43f,0.003);
    glColor3ub( 255, 255, 255);
    circleSolid(-0.55f,0.53f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.40f,0.49f,0.003);



    glColor3ub( 255, 255, 255);
    circleSolid(-0.10f,0.48f,0.003);
    glColor3ub( 255, 255, 255);
    circleSolid(-0.5f,0.55f,0.003);




    glColor3ub( 255, 255, 255);
    circleSolid(-0.30f,0.48f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.21f,0.38f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.10f,0.60f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.21f,0.56f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.35f,0.39f,0.003);

    //***

    glColor3ub( 255, 255, 255);
    circleSolid(0.10f,0.53f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.21f,0.48f,0.003);

    glColor3ub( 255, 255, 255);

    circleSolid(0.31f,0.46f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.40f,0.50f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.50f,0.53f,0.003);


    glColor3ub( 255, 255, 255);
    circleSolid(0.40f,0.40f,0.003);


    glColor3ub( 255, 255, 255);
    circleSolid(0.55f,0.39f,0.003);


    glColor3ub( 255, 255, 255);
    circleSolid(0.31f,0.57f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.22f,0.55f,0.003);

}

void skyR()
{

    glBegin(GL_QUADS);
    glColor3ub(64, 98, 131);
    glVertex2f(-0.64f,0.01f);
    glVertex2f(0.64f,0.01f);
    glVertex2f(0.64f,.64f);
    glVertex2f(-0.64f,.64f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(169, 171, 73);
    glVertex2f(-0.64f,0.01f);
    glVertex2f(0.64f,0.01f);
    glVertex2f(0.64f,.00f);
    glVertex2f(-0.64f,.00f);
    glEnd();
}


void house()
{


    glBegin(GL_QUADS);
    glColor3ub(243, 252, 189);
    glVertex2f(0.22f, 0.1f);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.45f, -0.03f);
    glVertex2f(0.22f, -0.03f);
glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 115, 122);
    glVertex2f(0.19f, 0.1f);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.47f, 0.18f);
    glVertex2f(0.22f, 0.17f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3ub(105, 157, 240);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.47f, 0.18f);
    glVertex2f(0.51f, 0.1f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(240, 222, 105);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.51f, 0.1f);
    glVertex2f(0.51f, 0.0f);
    glVertex2f(0.45f, -0.03f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(82, 81, 75);
    glVertex2f(0.32f, -0.03f);
    glVertex2f(0.35f, -0.03f);
    glVertex2f(0.35f, 0.06f);
    glVertex2f(0.32f, 0.06f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(82, 81, 75);
    glVertex2f(0.28f, 0.0f);
    glVertex2f(0.28f, 0.05f);
    glVertex2f(0.24f, 0.05f);
    glVertex2f(0.24f, 0.0f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(82, 81, 75);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.42f, 0.0f);
    glVertex2f(0.42f, 0.05f);
    glVertex2f(0.38f, 0.05f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(82, 81, 75);
    glVertex2f(0.5f, 0.03f);
    glVertex2f(0.5f, 0.06f);
    glVertex2f(0.47f, 0.06f);
    glVertex2f(0.47f, 0.03f);
glEnd();

     /*left side*/

glBegin(GL_QUADS);//base
    glColor3ub(145, 99, 7);

    glVertex2f(-0.6f,0.0f);
    glVertex2f(-0.4f,0.0f);
    glVertex2f(-0.45f,0.01f);
    glVertex2f(-0.55f,0.01f);

    glEnd();

    glBegin(GL_QUADS);//structure
    glColor3ub(120, 61, 6);

    glVertex2f(-0.45f,0.01f);
    glVertex2f(-0.55f,0.01f);
    glVertex2f(-0.55f,0.1f);
    glVertex2f(-0.45f,0.1f);

    glEnd();

    glBegin(GL_QUADS);//roof
    glColor3ub(143, 24, 3);

    glVertex2f(-0.42f,0.1f);
    glVertex2f(-0.58f,0.1f);
    glVertex2f(-0.55f,0.14f);
    glVertex2f(-0.45f,0.14f);

    glEnd();

    glBegin(GL_QUADS);//windows
    glColor3ub(0,0,0);

    glVertex2f(-0.46f,0.02f);
    glVertex2f(-0.48f,0.02f);
    glVertex2f(-0.48f,0.09f);
    glVertex2f(-0.46f,0.09f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2f(-0.49f,0.02f);
    glVertex2f(-0.50f,0.02f);
    glVertex2f(-0.50f,0.07f);
    glVertex2f(-0.49f,0.07f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2f(-0.52f,0.02f);
    glVertex2f(-0.54f,0.02f);
    glVertex2f(-0.54f,0.09f);
    glVertex2f(-0.52f,0.09f);

    glEnd();//windows end

    glBegin(GL_QUADS);//house 2 base
    glColor3ub(82, 35, 2);

    glVertex2f(-0.32f,0.0f);
    glVertex2f(-0.18f,0.0f);
    glVertex2f(-0.21f,0.01f);
    glVertex2f(-0.29f,0.01f);

    glEnd();

    glBegin(GL_QUADS);//structure
    glColor3ub(128, 53, 0);

    glVertex2f(-0.21f,0.01f);
    glVertex2f(-0.29f,0.01f);
    glVertex2f(-0.29f,0.1f);
    glVertex2f(-0.21f,0.1f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(217, 197, 17);//roof

    glVertex2f(-0.32f,0.1f);
    glVertex2f(-0.18f,0.1f);
    glVertex2f(-0.20f,0.125f);
    glVertex2f(-0.30f,0.125f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);

    glVertex2f(-0.22f,0.01f);
    glVertex2f(-0.24f,0.01f);
    glVertex2f(-0.24f,0.09f);
    glVertex2f(-0.22f,0.09f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);

    glVertex2f(-0.25f,0.03f);
    glVertex2f(-0.28f,0.03f);
    glVertex2f(-0.28f,0.08f);
    glVertex2f(-0.25f,0.08f);

    glEnd();


    /* end of building */
}


void houseN()
{
    /*left side*/
    glBegin(GL_QUADS);
    glColor3ub(120, 70, 13);
    glVertex2f(0.22f, 0.1f);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.45f, -0.03f);
    glVertex2f(0.22f, -0.03f);
glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 115, 122);
    glVertex2f(0.19f, 0.1f);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.47f, 0.18f);
    glVertex2f(0.22f, 0.17f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3ub(105, 157, 240);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.47f, 0.18f);
    glVertex2f(0.51f, 0.1f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(214, 166, 111);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.51f, 0.1f);
    glVertex2f(0.51f, 0.0f);
    glVertex2f(0.45f, -0.03f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(82, 81, 75);
    glVertex2f(0.32f, -0.03f);
    glVertex2f(0.35f, -0.03f);
    glVertex2f(0.35f, 0.06f);
    glVertex2f(0.32f, 0.06f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(215, 255, 94);
    glVertex2f(0.28f, 0.0f);
    glVertex2f(0.28f, 0.05f);
    glVertex2f(0.24f, 0.05f);
    glVertex2f(0.24f, 0.0f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(215, 255, 94);
    glVertex2f(0.38f, 0.0f);
    glVertex2f(0.42f, 0.0f);
    glVertex2f(0.42f, 0.05f);
    glVertex2f(0.38f, 0.05f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(215, 255, 94);
    glVertex2f(0.5f, 0.03f);
    glVertex2f(0.5f, 0.06f);
    glVertex2f(0.47f, 0.06f);
    glVertex2f(0.47f, 0.03f);
glEnd();


    /*b1*/



glBegin(GL_QUADS);//base
    glColor3ub(105, 71, 5);

    glVertex2f(-0.6f,0.0f);
    glVertex2f(-0.4f,0.0f);
    glVertex2f(-0.45f,0.01f);
    glVertex2f(-0.55f,0.01f);

    glEnd();

    glBegin(GL_QUADS);//structure
    glColor3ub(74, 40, 7);

    glVertex2f(-0.45f,0.01f);
    glVertex2f(-0.55f,0.01f);
    glVertex2f(-0.55f,0.1f);
    glVertex2f(-0.45f,0.1f);

    glEnd();

    glBegin(GL_QUADS);//roof
    glColor3ub(102, 18, 3);

     glVertex2f(-0.42f,0.1f);
    glVertex2f(-0.58f,0.1f);
    glVertex2f(-0.55f,0.14f);
    glVertex2f(-0.45f,0.14f);

    glEnd();

    glBegin(GL_QUADS);//windows
    glColor3ub(255,255,0);

    glVertex2f(-0.46f,0.02f);
    glVertex2f(-0.48f,0.02f);
    glVertex2f(-0.48f,0.09f);
    glVertex2f(-0.46f,0.09f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);

    glVertex2f(-0.49f,0.02f);
    glVertex2f(-0.50f,0.02f);
    glVertex2f(-0.50f,0.07f);
    glVertex2f(-0.49f,0.07f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,0);

    glVertex2f(-0.52f,0.02f);
    glVertex2f(-0.54f,0.02f);
    glVertex2f(-0.54f,0.09f);
    glVertex2f(-0.52f,0.09f);

    glEnd();//windows end

    glBegin(GL_QUADS);//house 2 base
    glColor3ub(64, 27, 2);

    glVertex2f(-0.32f,0.0f);
    glVertex2f(-0.18f,0.0f);
    glVertex2f(-0.21f,0.01f);
    glVertex2f(-0.29f,0.01f);

    glEnd();

    glBegin(GL_QUADS);//structure
    glColor3ub(89, 37, 1);

    glVertex2f(-0.21f,0.01f);
    glVertex2f(-0.29f,0.01f);
    glVertex2f(-0.29f,0.1f);
    glVertex2f(-0.21f,0.1f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 122, 8);//roof

    glVertex2f(-0.32f,0.1f);
    glVertex2f(-0.18f,0.1f);
    glVertex2f(-0.20f,0.125f);
    glVertex2f(-0.30f,0.125f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-0.22f,0.01f);
    glVertex2f(-0.24f,0.01f);
    glVertex2f(-0.24f,0.09f);
    glVertex2f(-0.22f,0.09f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);

    glVertex2f(-0.25f,0.03f);
    glVertex2f(-0.28f,0.03f);
    glVertex2f(-0.28f,0.08f);
    glVertex2f(-0.25f,0.08f);

    glEnd();

    /* end of building */
}



void grass()
{

    /* grass part */
    glBegin(GL_QUADS);
    glColor3ub(0, 204, 0);
    glVertex2f(-0.64f,0.0f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.64f,-0.12f);
    glVertex2f(-0.64f,-0.12f);
    glEnd();
    /*end of grass part */
}


void grassN()
{

    /* grass part */
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 51);
    glVertex2f(-0.64f,0.0f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.64f,-0.12f);
    glVertex2f(-0.64f,-0.12f);
    glEnd();
    /*end of grass part */
}




void tree()
{

    /*starting Tree */

    glBegin(GL_QUADS);
    glColor3ub(92, 92, 61);
    glVertex2f(-0.05f,-0.01f);
    glVertex2f(-0.03f,-0.01f);
    glVertex2f(-0.03f,0.24f);
    glVertex2f(-0.05f,0.24f);
    glEnd();


    glLineWidth(8);
    glBegin(GL_LINES);        //left
    glColor3ub(92, 92, 61);
    glVertex2f(-0.04f, 0.23f);
    glVertex2f(-0.09f, 0.27f);

    glVertex2f(-0.04f, 0.23f);    //right
    glVertex2f(0.01f, 0.27f);

    glVertex2f(-0.04f, 0.24f);     //middle
    glVertex2f(-0.04f, 0.32f);
    glEnd();

    glColor3ub(0, 102, 0);
    circleSolid(-0.10f, 0.28f, 0.03);  //1
    glColor3ub(0, 204, 0);
    circleSolid(-0.11f, 0.31f, 0.03);         //2
    glColor3ub(0, 153, 51);
    circleSolid(-0.09f, 0.33f, 0.03);         //3

    glColor3ub( 0, 153, 0);

    circleSolid(-0.04f, 0.33f, 0.03);      //4

    circleSolid(0.0f, 0.33f, 0.03);     //5

    circleSolid(0.02f, 0.31f, 0.03);        //6

    glColor3ub( 0, 77, 0 );
    circleSolid(0.03f, 0.28f, 0.03);      //7





    /*End of  Tree */
}




void treeN()
{

    /*starting Tree */

    glBegin(GL_QUADS);
    glColor3ub(17, 51, 61);
    glVertex2f(-0.05f,-0.01f);
    glVertex2f(-0.03f,-0.01f);
    glVertex2f(-0.03f,0.24f);
    glVertex2f(-0.05f,0.24f);
    glEnd();


    glLineWidth(8);
    glBegin(GL_LINES);        //left
    glColor3ub(92, 92, 61);
    glVertex2f(-0.04f, 0.23f);
    glVertex2f(-0.09f, 0.27f);

    glVertex2f(-0.04f, 0.23f);    //right
    glVertex2f(0.01f, 0.27f);

    glVertex2f(-0.04f, 0.24f);     //middle
    glVertex2f(-0.04f, 0.32f);
    glEnd();

    glColor3ub(0, 102, 0);
    circleSolid(-0.10f, 0.28f, 0.03);  //1
    glColor3ub(0, 204, 0);
    circleSolid(-0.11f, 0.31f, 0.03);         //2
    glColor3ub(0, 153, 51);
    circleSolid(-0.09f, 0.33f, 0.03);         //3

    glColor3ub( 0, 153, 0);

    circleSolid(-0.04f, 0.33f, 0.03);      //4


    circleSolid(0.0f, 0.33f, 0.03);     //5

    circleSolid(0.02f, 0.31f, 0.03);        //6

    glColor3ub( 0, 77, 0 );
    circleSolid(0.03f, 0.28f, 0.03);      //7





    /*End of  Tree */
}

void bench(){
    glLineWidth(5.0);
    glBegin(GL_LINES);

    glColor3ub(214,171,119);
    glVertex2f(-0.01f,0.04f);
     glVertex2f(0.06f,0.04f);
     glEnd();

     glBegin(GL_LINES);

    glColor3ub(214,171,119);
    glVertex2f(-0.01f,0.0f);
     glVertex2f(-0.01f,0.04f);
     glEnd();

     glBegin(GL_LINES);

   glColor3ub(214,171,119);
    glVertex2f(0.06f,0.0f);
     glVertex2f(0.06f,0.04f);
     glEnd();


}


void roadside()
{

    /* Road Side */
    glBegin(GL_QUADS);
    glColor3ub(161,161,161); //white
    glVertex2f(-0.64f,-0.13f);
    glVertex2f(-0.64f,-0.12f);
    glVertex2f(-0.54f,-0.12f);
    glVertex2f(-0.54f,-0.13f);

    glColor3ub(0,0,0);                //black
    glVertex2f(-0.54f,-0.13f);
    glVertex2f(-0.54f,-0.12f);
    glVertex2f(-0.44f,-0.12f);
    glVertex2f(-0.44f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(-0.44f,-0.13f);
    glVertex2f(-0.44f,-0.12f);
    glVertex2f(-0.34f,-0.12f);
    glVertex2f(-0.34f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(-0.34f,-0.13f);
    glVertex2f(-0.34f,-0.12f);
    glVertex2f(-0.24f,-0.12f);
    glVertex2f(-0.24f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(-0.24f,-0.13f);
    glVertex2f(-0.24f,-0.12f);
    glVertex2f(-0.14f,-0.12f);
    glVertex2f(-0.14f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(-0.14f,-0.13f);
    glVertex2f(-0.14f,-0.12f);
    glVertex2f(-0.04f,-0.12f);
    glVertex2f(-0.04f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(-0.04f,-0.13f);
    glVertex2f(-0.04f,-0.12f);
    glVertex2f(0.06f,-0.12f);
    glVertex2f(0.06f,-0.13f);

    glColor3ub(161,161,161); //white
    glVertex2f(0.64f,-0.13f);
    glVertex2f(0.64f,-0.12f);
    glVertex2f(0.54f,-0.12f);
    glVertex2f(0.54f,-0.13f);

    glColor3ub(0,0,0);                //black
    glVertex2f(0.54f,-0.13f);
    glVertex2f(0.54f,-0.12f);
    glVertex2f(0.44f,-0.12f);
    glVertex2f(0.44f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(0.44f,-0.13f);
    glVertex2f(0.44f,-0.12f);
    glVertex2f(0.34f,-0.12f);
    glVertex2f(0.34f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(0.34f,-0.13f);
    glVertex2f(0.34f,-0.12f);
    glVertex2f(0.24f,-0.12f);
    glVertex2f(0.24f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(0.24f,-0.13f);
    glVertex2f(0.24f,-0.12f);
    glVertex2f(0.14f,-0.12f);
    glVertex2f(0.14f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(0.14f,-0.13f);
    glVertex2f(0.14f,-0.12f);
    glVertex2f(0.04f,-0.12f);
    glVertex2f(0.04f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(0.04f,-0.13f);
    glVertex2f(0.04f,-0.12f);
    glVertex2f(0.06f,-0.12f);
    glVertex2f(0.06f,-0.13f);

    glEnd();

///* End of Road Side */



}


void lamppost()
{
    /* starting LampPost  */
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 204); //Bar
    glVertex2f(0.09f,-0.12f);
    glVertex2f(0.08f,-0.12f);
    glVertex2f(0.08f,0.17f);
    glVertex2f(0.09f,0.17f);

    glColor3ub(255, 255, 204); //upSide
    glVertex2f(0.09f,0.17f);
    glVertex2f(0.09f,0.15f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.00f,0.22f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(198, 205, 207);
    glVertex2f(0.04f,0.18f);
    glVertex2f(0.04f,0.16f);
    glVertex2f(0.00f,0.18f);
    glVertex2f(0.00f,0.20f);
    glEnd();
    /* End of  LampPost  */


}



void lamppostN()
{
    /* starting LampPost  */
    glBegin(GL_QUADS);
    glColor3ub(186,186,149); //Bar
    glVertex2f(0.09f,-0.12f);
    glVertex2f(0.08f,-0.12f);
    glVertex2f(0.08f,0.17f);
    glVertex2f(0.09f,0.17f);

    glColor3ub(186,186,149); //upSide
    glVertex2f(0.09f,0.17f);
    glVertex2f(0.09f,0.15f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.00f,0.22f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(0.04f,0.18f);
    glVertex2f(0.04f,0.16f);
    glVertex2f(0.00f,0.18f);
    glVertex2f(0.00f,0.20f);
    glEnd();
    /* End of  LampPost  */
}

void water()
{
//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
    glTranslatef( 0.0f,_moveWater,0.0f);
    //glRotatef(_moveWater,0.1,0.0,0.0);
    glBegin(GL_QUADS);
    glColor3ub(26, 81, 219);
    glVertex2f(-0.64f,-0.22f);
    glVertex2f(0.64f,-0.22f);

    glVertex2f(0.64f,-0.15f);
    glVertex2f(-0.64f, -0.15f);
    glEnd();

        glPopMatrix();

    glutSwapBuffers();
}

void watern()
{
//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
    glTranslatef( 0.0f,_moveWater,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(122, 155, 163);
    glVertex2f(-0.64f,-0.22f);
    glVertex2f(0.64f,-0.22f);

    glVertex2f(0.64f,-0.15f);
    glVertex2f(-0.64f, -0.15f);
    glEnd();

        glPopMatrix();

    glutSwapBuffers();
}
void sean()
{
    glBegin(GL_QUADS);
    glColor3ub(122, 155, 163);          //color part
    //glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.64f,-0.13f);
    glVertex2f(0.64f,-0.13f);
    glVertex2f(0.64f,-0.64f);
    glVertex2f(-0.64f,-0.64f);
    glEnd();

    glBegin(GL_QUADS);//coconut tree
    glColor3ub(59, 32, 5);
    glVertex2f(-0.64f,-0.12f);
    glVertex2f(-0.63f,-0.12f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.64f,0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.65f,-0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.62f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.61f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.60f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.59f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.58f,0.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.57f,0.01f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.56f,0.02f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.55f,0.03f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.54f,0.04f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.635f,0.12f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(191, 180, 159); //bali
    glVertex2f(-0.64f,-0.13f);
    glVertex2f(-0.64f,-0.2f);
    glVertex2f(0.64f,-0.2f);
    glVertex2f(0.64f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);//coral start
   glColor3ub(73, 82, 79);
   glVertex2f(0.63f,-0.2f);
   glVertex2f(0.59f,-0.2f);
   glVertex2f(0.59f,-0.19f);
   glVertex2f(0.6f,-0.18f);
   glEnd();

      glColor3ub(73, 82, 79);
   glVertex2f(-0.6f,-0.2f);
   glVertex2f(-0.59f,-0.2f);
   glVertex2f(-0.59f,-0.19f);
   glVertex2f(-0.6f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.61f,-0.2f);
   glVertex2f(-0.6f,-0.18f);
   glVertex2f(-0.605f,-0.16f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.62f,-0.2f);
   glVertex2f(-0.61f,-0.2f);
   glVertex2f(-0.61f,-0.18f);
   glVertex2f(-0.62f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.63f,-0.2f);
   glVertex2f(-0.62f,-0.2f);
   glVertex2f(-0.62f,-0.18f);
   glVertex2f(-0.63f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.64f,-0.2f);
   glVertex2f(-0.63f,-0.2f);
   glVertex2f(-0.635f,-0.16f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.55f,-0.2f);
   glVertex2f(-0.53f,-0.2f);
   glVertex2f(-0.545f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.53f,-0.2f);
   glVertex2f(-0.52f,-0.2f);
   glVertex2f(-0.52f,-0.19f);
   glVertex2f(-0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.53f,-0.2f);
   glVertex2f(-0.52f,-0.2f);
   glVertex2f(-0.52f,-0.19f);
   glVertex2f(-0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.52f,-0.2f);
   glVertex2f(-0.51f,-0.2f);
   glVertex2f(-0.51f,-0.17f);
   glVertex2f(-0.52f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.55f,-0.18f);
   glVertex2f(-0.51f,-0.17f);
   glVertex2f(-0.51f,-0.16f);
   glVertex2f(-0.55f,-0.16f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.50f,-0.2f);
   glVertex2f(-0.49f,-0.2f);
   glVertex2f(-0.49f,-0.17f);
   glVertex2f(-0.50f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.45f,-0.2f);
   glVertex2f(-0.44f,-0.2f);
   glVertex2f(-0.44f,-0.18f);
   glVertex2f(-0.45f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.45f,-0.18f);
   glVertex2f(-0.44f,-0.18f);
   glVertex2f(-0.445f,-0.17f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.40f,-0.2f);
   glVertex2f(-0.41f,-0.2f);
   glVertex2f(-0.41f,-0.19f);
   glVertex2f(-0.40f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.40f,-0.2f);
   glVertex2f(-0.39f,-0.2f);
   glVertex2f(-0.395f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.39f,-0.2f);
   glVertex2f(-0.38f,-0.2f);
   glVertex2f(-0.385f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.38f,-0.2f);
   glVertex2f(-0.37f,-0.2f);
   glVertex2f(-0.37f,-0.18f);
   glVertex2f(-0.38f,-0.19f);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.61f,-0.2f);
   glVertex2f(0.6f,-0.18f);
   glVertex2f(0.605f,-0.16f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.62f,-0.2f);
   glVertex2f(0.61f,-0.2f);
   glVertex2f(0.61f,-0.18f);
   glVertex2f(0.62f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.63f,-0.2f);
   glVertex2f(0.62f,-0.2f);
   glVertex2f(0.62f,-0.18f);
   glVertex2f(0.63f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.64f,-0.2f);
   glVertex2f(0.63f,-0.2f);
   glVertex2f(0.635f,-0.16f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.55f,-0.2f);
   glVertex2f(0.53f,-0.2f);
   glVertex2f(0.545f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.53f,-0.2f);
   glVertex2f(0.52f,-0.2f);
   glVertex2f(0.52f,-0.19f);
   glVertex2f(0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.53f,-0.2f);
   glVertex2f(0.52f,-0.2f);
   glVertex2f(0.52f,-0.19f);
   glVertex2f(0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.52f,-0.2f);
   glVertex2f(0.51f,-0.2f);
   glVertex2f(0.51f,-0.17f);
   glVertex2f(0.52f,-0.19f);
   glEnd();

    glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.50f,-0.2f);
   glVertex2f(0.49f,-0.2f);
   glVertex2f(0.49f,-0.17f);
   glVertex2f(0.50f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.45f,-0.2f);
   glVertex2f(0.44f,-0.2f);
   glVertex2f(0.44f,-0.18f);
   glVertex2f(0.45f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.45f,-0.18f);
   glVertex2f(0.44f,-0.18f);
   glVertex2f(0.445f,-0.17f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.40f,-0.2f);
   glVertex2f(0.41f,-0.2f);
   glVertex2f(0.41f,-0.19f);
   glVertex2f(0.40f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.40f,-0.2f);
   glVertex2f(0.39f,-0.2f);
   glVertex2f(0.395f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.39f,-0.2f);
   glVertex2f(0.38f,-0.2f);
   glVertex2f(0.385f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.38f,-0.2f);
   glVertex2f(0.37f,-0.2f);
   glVertex2f(0.37f,-0.18f);
   glVertex2f(0.38f,-0.19f);
   glEnd(); //coral End


}


void sea()
{
    glBegin(GL_QUADS);
    glColor3ub(26, 81, 219);          //color part
    //glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.64f,-0.13f);
    glVertex2f(0.64f,-0.13f);
    glVertex2f(0.64f,-0.64f);
    glVertex2f(-0.64f,-0.64f);
    glEnd();

    glBegin(GL_QUADS);//coconut tree
    glColor3ub(59, 32, 5);
    glVertex2f(-0.64f,-0.12f);
    glVertex2f(-0.63f,-0.12f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.64f,0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.65f,-0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.62f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.61f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.60f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.59f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.58f,0.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.57f,0.01f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.56f,0.02f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.55f,0.03f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.54f,0.04f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(23, 77, 3);
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.63f,0.1f);
    glVertex2f(-0.635f,0.12f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(169, 171, 73); //bali
    glVertex2f(-0.64f,-0.13f);
    glVertex2f(-0.64f,-0.2f);
    glVertex2f(0.64f,-0.2f);
    glVertex2f(0.64f,-0.13f);
    glEnd();


 glBegin(GL_QUADS);//coral start
   glColor3ub(73, 82, 79);
   glVertex2f(0.63f,-0.2f);
   glVertex2f(0.59f,-0.2f);
   glVertex2f(0.59f,-0.19f);
   glVertex2f(0.6f,-0.18f);
   glEnd();

      glColor3ub(73, 82, 79);
   glVertex2f(-0.6f,-0.2f);
   glVertex2f(-0.59f,-0.2f);
   glVertex2f(-0.59f,-0.19f);
   glVertex2f(-0.6f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.61f,-0.2f);
   glVertex2f(-0.6f,-0.18f);
   glVertex2f(-0.605f,-0.16f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.62f,-0.2f);
   glVertex2f(-0.61f,-0.2f);
   glVertex2f(-0.61f,-0.18f);
   glVertex2f(-0.62f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.63f,-0.2f);
   glVertex2f(-0.62f,-0.2f);
   glVertex2f(-0.62f,-0.18f);
   glVertex2f(-0.63f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.64f,-0.2f);
   glVertex2f(-0.63f,-0.2f);
   glVertex2f(-0.635f,-0.16f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.55f,-0.2f);
   glVertex2f(-0.53f,-0.2f);
   glVertex2f(-0.545f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.53f,-0.2f);
   glVertex2f(-0.52f,-0.2f);
   glVertex2f(-0.52f,-0.19f);
   glVertex2f(-0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.53f,-0.2f);
   glVertex2f(-0.52f,-0.2f);
   glVertex2f(-0.52f,-0.19f);
   glVertex2f(-0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.52f,-0.2f);
   glVertex2f(-0.51f,-0.2f);
   glVertex2f(-0.51f,-0.17f);
   glVertex2f(-0.52f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.55f,-0.18f);
   glVertex2f(-0.51f,-0.17f);
   glVertex2f(-0.51f,-0.16f);
   glVertex2f(-0.55f,-0.16f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.50f,-0.2f);
   glVertex2f(-0.49f,-0.2f);
   glVertex2f(-0.49f,-0.17f);
   glVertex2f(-0.50f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.45f,-0.2f);
   glVertex2f(-0.44f,-0.2f);
   glVertex2f(-0.44f,-0.18f);
   glVertex2f(-0.45f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.45f,-0.18f);
   glVertex2f(-0.44f,-0.18f);
   glVertex2f(-0.445f,-0.17f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.40f,-0.2f);
   glVertex2f(-0.41f,-0.2f);
   glVertex2f(-0.41f,-0.19f);
   glVertex2f(-0.40f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.40f,-0.2f);
   glVertex2f(-0.39f,-0.2f);
   glVertex2f(-0.395f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.39f,-0.2f);
   glVertex2f(-0.38f,-0.2f);
   glVertex2f(-0.385f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(-0.38f,-0.2f);
   glVertex2f(-0.37f,-0.2f);
   glVertex2f(-0.37f,-0.18f);
   glVertex2f(-0.38f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.61f,-0.2f);
   glVertex2f(0.6f,-0.18f);
   glVertex2f(0.605f,-0.16f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.62f,-0.2f);
   glVertex2f(0.61f,-0.2f);
   glVertex2f(0.61f,-0.18f);
   glVertex2f(0.62f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.63f,-0.2f);
   glVertex2f(0.62f,-0.2f);
   glVertex2f(0.62f,-0.18f);
   glVertex2f(0.63f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.64f,-0.2f);
   glVertex2f(0.63f,-0.2f);
   glVertex2f(0.635f,-0.16f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.55f,-0.2f);
   glVertex2f(0.53f,-0.2f);
   glVertex2f(0.545f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.53f,-0.2f);
   glVertex2f(0.52f,-0.2f);
   glVertex2f(0.52f,-0.19f);
   glVertex2f(0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.53f,-0.2f);
   glVertex2f(0.52f,-0.2f);
   glVertex2f(0.52f,-0.19f);
   glVertex2f(0.53f,-0.18f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.52f,-0.2f);
   glVertex2f(0.51f,-0.2f);
   glVertex2f(0.51f,-0.17f);
   glVertex2f(0.52f,-0.19f);
   glEnd();

    glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.50f,-0.2f);
   glVertex2f(0.49f,-0.2f);
   glVertex2f(0.49f,-0.17f);
   glVertex2f(0.50f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.45f,-0.2f);
   glVertex2f(0.44f,-0.2f);
   glVertex2f(0.44f,-0.18f);
   glVertex2f(0.45f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.45f,-0.18f);
   glVertex2f(0.44f,-0.18f);
   glVertex2f(0.445f,-0.17f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.40f,-0.2f);
   glVertex2f(0.41f,-0.2f);
   glVertex2f(0.41f,-0.19f);
   glVertex2f(0.40f,-0.19f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.40f,-0.2f);
   glVertex2f(0.39f,-0.2f);
   glVertex2f(0.395f,-0.18f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3ub(73, 82, 79);
   glVertex2f(0.39f,-0.2f);
   glVertex2f(0.38f,-0.2f);
   glVertex2f(0.385f,-0.19f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(73, 82, 79);
   glVertex2f(0.38f,-0.2f);
   glVertex2f(0.37f,-0.2f);
   glVertex2f(0.37f,-0.18f);
   glVertex2f(0.38f,-0.19f);
   glEnd(); //coral End



}


void container()
{

//     glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);


     glPushMatrix();
    glTranslatef(_movecar2, 0.0f,0.00f);


    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);

    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.38f, -0.26f);
    glVertex2f(-0.35f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.63f, -0.25f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3b(112, 0, 0);

    glVertex2f(-0.60f,-0.25f);
    glVertex2f(-0.43f,-0.25f);
    glVertex2f(-0.43f,-0.20f);
    glVertex2f(-0.60f,-0.20f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(69, 46, 0);

    glVertex2f(-0.58f,-0.20f);
    glVertex2f(-0.57f,-0.20f);
    glVertex2f(-0.57f,-0.18f);
    glVertex2f(-0.58f,-0.18f);

    glEnd();


            glPopMatrix();
    glutSwapBuffers();

}

void containerF()
{

//     glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);


     glPushMatrix();
    glTranslatef(_movecar2, 0.0f,0.00f);


    glBegin(GL_POLYGON);
    glColor3ub(1, 8, 54);

    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.38f, -0.26f);
    glVertex2f(-0.35f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.63f, -0.25f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3b(77, 1, 11);

    glVertex2f(-0.60f,-0.25f);
    glVertex2f(-0.43f,-0.25f);
    glVertex2f(-0.43f,-0.20f);
    glVertex2f(-0.60f,-0.20f);

    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(69, 46, 0);

    glVertex2f(-0.58f,-0.20f);
    glVertex2f(-0.57f,-0.20f);
    glVertex2f(-0.57f,-0.18f);
    glVertex2f(-0.58f,-0.18f);

    glEnd();


            glPopMatrix();
    glutSwapBuffers();


}

void ship()
{



     glPushMatrix();
    glTranslatef(_movet1,0.0f,0.00f);



        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.4f);
        glVertex2f(0.25f, -0.4f);
        glVertex2f(0.275f, -0.375f);
        glVertex2f(-0.175f, -0.375f);
        glEnd();

        glColor3ub(67, 73, 107);
        glBegin(GL_QUADS);
        glVertex2f(-0.175f, -0.375f);
        glVertex2f(0.275f, -0.375f);
        glVertex2f(0.35f, -0.3f);
        glVertex2f(-0.25f, -0.3f);
        glEnd();

        glColor3ub(138, 132, 19);
        glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.275f);
        glVertex2f(0.35f, -0.275f);
        glVertex2f(0.35f, -0.3f);
        glVertex2f(-0.25f, -0.3f);
        glEnd();

        glColor3ub(57, 212, 176);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.275f);
        glVertex2f(0.3f, -0.275f);
        glVertex2f(0.3f, -0.225f);
        glVertex2f(-0.2f, -0.225f);
        glEnd();

        glColor3ub(2, 12, 92);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.175f);
        glVertex2f(0.25f, -0.175f);
        glVertex2f(0.285f, -0.225f);
        glVertex2f(-0.15f, -0.225f);
        glEnd();

        glColor3ub(191, 178, 19);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.175f);
        glVertex2f(0.25f, -0.175f);
        glVertex2f(0.2f, -0.15f);
        glVertex2f(-0.1f, -0.15f);
        glEnd();

        //main frame end

        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(-0.075f, -0.1f);
        glVertex2f(-0.025f, -0.1f);
        glVertex2f(-0.025f, -0.15f);
        glVertex2f(-0.075f, -0.15f);
        glEnd();

        glColor3ub(110, 102, 9);
        glBegin(GL_QUADS);
        glVertex2f(-0.075f, -0.1f);
        glVertex2f(-0.025f, -0.1f);
        glVertex2f(-0.025f, -0.075f);
        glVertex2f(-0.075f, -0.075f);
        glEnd();

        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(0.075f, -0.1f);
        glVertex2f(0.025f, -0.1f);
        glVertex2f(0.025f, -0.15f);
        glVertex2f(0.075f, -0.15f);
        glEnd();

        glColor3ub(110, 102, 9);
        glBegin(GL_QUADS);
        glVertex2f(0.075f, -0.1f);
        glVertex2f(0.025f, -0.1f);
        glVertex2f(0.025f, -0.075f);
        glVertex2f(0.075f, -0.075f);
        glEnd();

        glColor3ub(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.125f, -0.1f);
        glVertex2f(0.175f, -0.1f);
        glVertex2f(0.175f, -0.15f);
        glVertex2f(0.125f, -0.15f);
        glEnd();

        glColor3ub(110, 102, 9);
        glBegin(GL_QUADS);
        glVertex2f(0.125f, -0.1f);
        glVertex2f(0.175f, -0.1f);
        glVertex2f(0.175f, -0.075f);
        glVertex2f(0.125f, -0.075f);
        glEnd();



    glPopMatrix();
    glutSwapBuffers();

}


void shipF()
{
 glPushMatrix();
    glTranslatef(_movet1,0.0f,0.00f);



        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.4f);
        glVertex2f(0.25f, -0.4f);
        glVertex2f(0.275f, -0.375f);
        glVertex2f(-0.175f, -0.375f);
        glEnd();

        glColor3ub(67, 73, 107);
        glBegin(GL_QUADS);
        glVertex2f(-0.175f, -0.375f);
        glVertex2f(0.275f, -0.375f);
        glVertex2f(0.35f, -0.3f);
        glVertex2f(-0.25f, -0.3f);
        glEnd();

        glColor3ub(138, 132, 19);
        glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.275f);
        glVertex2f(0.35f, -0.275f);
        glVertex2f(0.35f, -0.3f);
        glVertex2f(-0.25f, -0.3f);
        glEnd();

        glColor3ub(57, 212, 176);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.275f);
        glVertex2f(0.3f, -0.275f);
        glVertex2f(0.3f, -0.225f);
        glVertex2f(-0.2f, -0.225f);
        glEnd();

        glColor3ub(2, 12, 92);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.175f);
        glVertex2f(0.25f, -0.175f);
        glVertex2f(0.285f, -0.225f);
        glVertex2f(-0.15f, -0.225f);
        glEnd();

        glColor3ub(191, 178, 19);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.175f);
        glVertex2f(0.25f, -0.175f);
        glVertex2f(0.2f, -0.15f);
        glVertex2f(-0.1f, -0.15f);
        glEnd();

        //main frame end

        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(-0.075f, -0.1f);
        glVertex2f(-0.025f, -0.1f);
        glVertex2f(-0.025f, -0.15f);
        glVertex2f(-0.075f, -0.15f);
        glEnd();

        glColor3ub(110, 102, 9);
        glBegin(GL_QUADS);
        glVertex2f(-0.075f, -0.1f);
        glVertex2f(-0.025f, -0.1f);
        glVertex2f(-0.025f, -0.075f);
        glVertex2f(-0.075f, -0.075f);
        glEnd();

        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(0.075f, -0.1f);
        glVertex2f(0.025f, -0.1f);
        glVertex2f(0.025f, -0.15f);
        glVertex2f(0.075f, -0.15f);
        glEnd();

        glColor3ub(110, 102, 9);
        glBegin(GL_QUADS);
        glVertex2f(0.075f, -0.1f);
        glVertex2f(0.025f, -0.1f);
        glVertex2f(0.025f, -0.075f);
        glVertex2f(0.075f, -0.075f);
        glEnd();

        glColor3ub(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.125f, -0.1f);
        glVertex2f(0.175f, -0.1f);
        glVertex2f(0.175f, -0.15f);
        glVertex2f(0.125f, -0.15f);
        glEnd();

        glColor3ub(110, 102, 9);
        glBegin(GL_QUADS);
        glVertex2f(0.125f, -0.1f);
        glVertex2f(0.175f, -0.1f);
        glVertex2f(0.175f, -0.075f);
        glVertex2f(0.125f, -0.075f);
        glEnd();



    glPopMatrix();
    glutSwapBuffers();

}


void boat()
{

//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_moveb1,0.0f,0.00f);
    glBegin(GL_QUADS);
    glColor3ub(48, 15, 3);

    glVertex2f(-0.55f,-0.50f);
    glVertex2f(-0.35f, -0.50f);
    glVertex2f(-0.40f, -0.55f);
    glVertex2f(-0.50f, -0.55f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);

    glVertex2f(-0.45f,-0.48f);
    glVertex2f(-0.40f, -0.48f);
    glVertex2f(-0.45f, -0.38f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);

    glVertex2f(-0.48f,-0.48f);
    glVertex2f(-0.46f, -0.48f);
    glVertex2f(-0.46f, -0.38f);

    glEnd();



        glPopMatrix();
    glutSwapBuffers();

}


void boatF()
{

//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_moveb1,0.0f,0.00f);
    glBegin(GL_QUADS);
    glColor3ub(28, 3, 1);

    glVertex2f(-0.55f,-0.50f);
    glVertex2f(-0.35f, -0.50f);
    glVertex2f(-0.40f, -0.55f);
    glVertex2f(-0.50f, -0.55f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(112, 8, 0);

    glVertex2f(-0.45f,-0.48f);
    glVertex2f(-0.40f, -0.48f);
    glVertex2f(-0.45f, -0.38f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(112, 8, 0);

    glVertex2f(-0.48f,-0.48f);
    glVertex2f(-0.46f, -0.48f);
    glVertex2f(-0.46f, -0.38f);

    glEnd();




        glPopMatrix();
    glutSwapBuffers();
}


void plane()
{

//         glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);


     glPushMatrix();
    glTranslatef(_movePlane,0.0f,0.00f);

    /* base */
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-0.23f,0.55f);
    glVertex2f(-0.40f,0.55f);
    glVertex2f(-0.40f,0.51f);
    glVertex2f(-0.21f,0.51f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.21f,0.51f);
    glVertex2f(-0.23f,0.47f);
    glVertex2f(-0.40f,0.47f);
    glVertex2f(-0.40f,0.51f);
    glEnd();
    /*base */

    /* down turbine*/
        glBegin(GL_POLYGON);
            glColor3ub(204, 255, 51);
    glVertex2f(-0.25f,0.51f);
    glVertex2f(-0.30f,0.51f);
    glVertex2f(-0.32f,0.43f);
    glVertex2f(-0.29f,0.43f);
    glEnd();
        /* up turbine*/
            glBegin(GL_POLYGON);
    glColor3ub(204, 255, 51);
    glVertex2f(-0.26f,0.55f);
    glVertex2f(-0.30f,0.55f);
    glVertex2f(-0.32f,0.59f);
    glVertex2f(-0.30f,0.59f);
    glEnd();
            /* back turbine*/
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.35f,0.55f);
    glVertex2f(-0.40f,0.55f);
    glVertex2f(-0.40f,0.61f);
    glVertex2f(-0.38f,0.61f);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();




}


void fontroad()
{
    /* screen font road */
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255);   //black part 2axis
    glVertex2f(-0.64f,-0.61f);
    glVertex2f(0.64f,-0.61f);
    glVertex2f(0.64f,-0.64f);
    glVertex2f(-0.64f,-0.64f);

    glColor3ub(0, 204, 0);  //green part 1axis
    glVertex2f(-0.64f,-0.60f);
    glVertex2f(0.64f,-0.60f);
    glVertex2f(0.64f,-0.61f);
    glVertex2f(-0.64f,-0.61f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); //yellow
    glVertex2f(-0.64f,-0.58f);
    glVertex2f(-0.64f,-0.60f);
    glVertex2f(-0.44f,-0.60f);
    glVertex2f(-0.44f,-0.58f);

    glColor3ub(204, 0, 0); //red
    glVertex2f(-0.44f,-0.58f);
    glVertex2f(-0.44f,-0.60f);
    glVertex2f(-0.24f,-0.60f);
    glVertex2f(-0.24f,-0.58f);

    glColor3ub(255, 255, 0); //yellow
    glVertex2f(-0.24f,-0.58f);
    glVertex2f(-0.24f,-0.60f);
    glVertex2f(-0.04f,-0.60f);
    glVertex2f(-0.04f,-0.58f);

    glColor3ub(204, 0, 0); //yellow
    glVertex2f(-0.04f,-0.58f);
    glVertex2f(-0.04f,-0.60f);
    glVertex2f(0.14f,-0.60f);
    glVertex2f(0.14f,-0.58f);

    glColor3ub(255, 255, 0); //yellow
    glVertex2f(0.14f,-0.58f);
    glVertex2f(0.14f,-0.60f);
    glVertex2f(0.34f,-0.60f);
    glVertex2f(0.34f,-0.58f);

    glColor3ub(204, 0, 0); //red
    glVertex2f(0.34f,-0.58f);
    glVertex2f(0.34f,-0.60f);
    glVertex2f(0.54f,-0.60f);
    glVertex2f(0.54f,-0.58f);

    glColor3ub(255, 255, 0); //yellow
    glVertex2f(0.54f,-0.58f);
    glVertex2f(0.54f,-0.60f);
    glVertex2f(0.64f,-0.60f);
    glVertex2f(0.64f,-0.58f);
    glEnd();
    /*End of  screen font road*/
}



void clouds()
{
glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_moveCloud,0.0f,0.00f);



    glColor3ub( 255, 255, 255);
    circleSolid(0.23f,0.43f,0.04);
    circleSolid(0.21f,0.42f,0.04);
    circleSolid(0.21f,0.40f,0.04);
    circleSolid(0.23f,0.41f,0.04);
    circleSolid(0.19f,0.43f,0.04);
    circleSolid(0.19f,0.40f,0.04);
    circleSolid(0.17f,0.42f,0.04);
    circleSolid(0.18f,0.41f,0.04);
    circleSolid(0.16f,0.41f,0.04);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.43f,0.38f,0.04);
    circleSolid(-0.41f,0.37f,0.04);
    circleSolid(-0.41f,0.36f,0.04);
    circleSolid(-0.43f,0.37f,0.04);
    circleSolid(-0.39f,0.38f,0.04);
    circleSolid(-0.39f,0.36f,0.04);
    circleSolid(-0.37f,0.37f,0.04);
    circleSolid(-0.38f,0.36f,0.04);
    circleSolid(-0.36f,0.37f,0.04);

           glPopMatrix();

     glPushMatrix();
    glTranslatef(_moveCloudleft,0.0f,0.00f);

    glColor3ub( 255, 255, 255);
    circleSolid(0.43f,0.38f,0.04);
    circleSolid(0.41f,0.37f,0.04);
    circleSolid(0.41f,0.36f,0.04);
    circleSolid(0.43f,0.37f,0.04);
    circleSolid(0.39f,0.38f,0.04);
    circleSolid(0.39f,0.36f,0.04);
    circleSolid(0.37f,0.37f,0.04);
    circleSolid(0.38f,0.36f,0.04);
    circleSolid(0.36f,0.37f,0.04);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.13f,0.43f,0.04);
    circleSolid(-0.11f,0.42f,0.04);
    circleSolid(-0.11f,0.40f,0.04);
    circleSolid(-0.13f,0.41f,0.04);
    circleSolid(-0.09f,0.43f,0.04);
    circleSolid(-0.09f,0.40f,0.04);
    circleSolid(-0.07f,0.42f,0.04);
    circleSolid(-0.04f,0.41f,0.04);
    circleSolid(-0.06f,0.41f,0.04);
   glPopMatrix();
    glutSwapBuffers();


}

void cloudsR()
{



glColor3ub( 41, 64, 86);
    circleSolid(0.23f,0.43f,0.04);
    circleSolid(0.21f,0.42f,0.04);
    circleSolid(0.21f,0.40f,0.04);
    circleSolid(0.23f,0.41f,0.04);
    circleSolid(0.19f,0.43f,0.04);
    circleSolid(0.19f,0.40f,0.04);
    circleSolid(0.17f,0.42f,0.04);
    circleSolid(0.18f,0.41f,0.04);
    circleSolid(0.16f,0.41f,0.04);

    glColor3ub( 41, 64, 86);
    circleSolid(-0.43f,0.38f,0.04);
    circleSolid(-0.41f,0.37f,0.04);
    circleSolid(-0.41f,0.36f,0.04);
    circleSolid(-0.43f,0.37f,0.04);
    circleSolid(-0.39f,0.38f,0.04);
    circleSolid(-0.39f,0.36f,0.04);
    circleSolid(-0.37f,0.37f,0.04);
    circleSolid(-0.38f,0.36f,0.04);
    circleSolid(-0.36f,0.37f,0.04);

    glColor3ub( 41, 64, 86);
    circleSolid(0.43f,0.38f,0.04);
    circleSolid(0.41f,0.37f,0.04);
    circleSolid(0.41f,0.36f,0.04);
    circleSolid(0.43f,0.37f,0.04);
    circleSolid(0.39f,0.38f,0.04);
    circleSolid(0.39f,0.36f,0.04);
    circleSolid(0.37f,0.37f,0.04);
    circleSolid(0.38f,0.36f,0.04);
    circleSolid(0.36f,0.37f,0.04);

    glColor3ub( 41, 64, 86);
    circleSolid(-0.13f,0.43f,0.04);
    circleSolid(-0.11f,0.42f,0.04);
    circleSolid(-0.11f,0.40f,0.04);
    circleSolid(-0.13f,0.41f,0.04);
    circleSolid(-0.09f,0.43f,0.04);
    circleSolid(-0.09f,0.40f,0.04);
    circleSolid(-0.07f,0.42f,0.04);
    circleSolid(-0.04f,0.41f,0.04);
    circleSolid(-0.06f,0.41f,0.04);


}



void rain()
{
    glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///701


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///709


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0); ///717


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///741


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///749


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///757


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///781


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///814


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();


    glTranslatef(0,0.2,0);

    glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///701


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///709


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0); ///717


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///741


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///749


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///757


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///781


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///814


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();


///,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
///2222222
 glTranslatef(0,0.4,0);

glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///877


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///909


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///917


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///925


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///941


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///949


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///982


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();


  glTranslatef(0,-0.4,0);

  ///;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///877


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///909


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///917


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///925


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///941


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///949


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///982


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();




///'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

    glTranslatef(0,-0.8,0);

    glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);

     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glLoadIdentity();

     glPopMatrix();



}


void display()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    init();

    sky();
    //plane();
    sun();
    clouds();
    grass();
    tree();
    bench();
    house();

    roadside();
    lamppost();

    sea();
    water();
    container();
    ship();
    boat();

/*glBegin (GL_LINES);
    glColor3f(0.65f,0.65f,0.65f);

    glVertex2f(-1.0f,0.1f);glVertex2f(1.0f,0.1f);glVertex2f(-1.0f,0.2f);glVertex2f(1.0f,0.2f);glVertex2f(-1.0f,0.3f);glVertex2f(1.0f,0.3f);glVertex2f(-1.0f,0.4f);glVertex2f(1.0f,0.4f);
    glVertex2f(-1.0f,0.5f);glVertex2f(1.0f,0.5f);glVertex2f(-1.0f,0.6f);glVertex2f(1.0f,0.6f);glVertex2f(-1.0f,0.7f);glVertex2f(1.0f,0.7f);glVertex2f(-1.0f,0.8f);glVertex2f(1.0f,0.8f);
    glVertex2f(-1.0f,0.9f);glVertex2f(1.0f,0.9f);glVertex2f(-1.0f,1.0f);glVertex2f(1.0f,1.0f);

    glVertex2f(-1.0f,-0.1f);glVertex2f(1.0f,-0.1f);glVertex2f(-1.0f,-0.2f);glVertex2f(1.0f,-0.2f);glVertex2f(-1.0f,-0.3f);glVertex2f(1.0f,-0.3f);glVertex2f(-1.0f,-0.4f);glVertex2f(1.0f,-0.4f);
    glVertex2f(-1.0f,-0.5f);glVertex2f(1.0f,-0.5f);glVertex2f(-1.0f,-0.6f);glVertex2f(1.0f,-0.6f);glVertex2f(-1.0f,-0.7f);glVertex2f(1.0f,-0.7f);glVertex2f(-1.0f,-0.8f);glVertex2f(1.0f,-0.8f);
    glVertex2f(-1.0f,-0.9f);glVertex2f(1.0f,-0.9f);glVertex2f(-1.0f,-1.0f);glVertex2f(1.0f,-1.0f);

    glVertex2f(-0.1f,1.0f);glVertex2f(-0.1f,-1.0f);glVertex2f(-0.2f,1.0f);glVertex2f(-0.2f,-1.0f);glVertex2f(-0.3f,1.0f);glVertex2f(-0.3f,-1.0f);glVertex2f(-0.4f,1.0f);glVertex2f(-0.4f,-1.0f);
    glVertex2f(-0.5f,1.0f);glVertex2f(-0.5f,-1.0f);glVertex2f(-0.6f,1.0f);glVertex2f(-0.6f,-1.0f);glVertex2f(-0.7f,1.0f);glVertex2f(-0.7f,-1.0f);glVertex2f(-0.8f,1.0f);glVertex2f(-0.8f,-1.0f);
    glVertex2f(-0.9f,1.0f);glVertex2f(-0.9f,-1.0f);glVertex2f(-1.0f,1.0f);glVertex2f(-1.0f,-1.0f);

    glVertex2f(0.1f,1.0f);glVertex2f(0.1f,-1.0f);glVertex2f(0.2f,1.0f);glVertex2f(0.2f,-1.0f);glVertex2f(0.3f,1.0f);glVertex2f(0.3f,-1.0f);glVertex2f(0.4f,1.0f);glVertex2f(0.4f,-1.0f);
    glVertex2f(0.5f,1.0f);glVertex2f(0.5f,-1.0f);glVertex2f(0.6f,1.0f);glVertex2f(0.6f,-1.0f);glVertex2f(0.7f,1.0f);glVertex2f(0.7f,-1.0f);glVertex2f(0.8f,1.0f);glVertex2f(0.8f,-1.0f);
    glVertex2f(0.9f,1.0f);glVertex2f(0.9f,-1.0f);glVertex2f(1.0f,1.0f);glVertex2f(1.0f,-1.0f);


    glBegin (GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-1.0f,0.0f);glVertex2f(1.0f,0.0f);
    glVertex2f(0.0f,1.0f);glVertex2f(0.0f,-1.0f);
    glEnd();*/
    glFlush();
}


void display2()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

     //gluOrtho2D(-0.64,0.64,-0.64,0.64);
     init();

    skyN();
    sunN();
    //plane();
   // sun();
    //clouds();
    grassN();
    tree();
    bench();
    houseN();

    roadside();
    lamppostN();
    sean();
    watern();
    containerF();
    //shipF();
    boatF();


    glFlush();
}


void display3()     //rain
{



     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    init();
    skyR();
    plane();
   // sun();
    cloudsR();
    grassN();
    tree();
    bench();
    house();

    roadside();

    lamppost();
    sea();
    water();
    container();
   ship();
    boat();

    rain();
    glFlush();
}


void display4()     //rainn
{
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    init();
    skyR();
    plane();
   // sun();
    cloudsR();
  grassN();
    tree();
    bench();
    houseN();

   roadside();
//railing();
    lamppostN();
     sean();
     watern();
    containerF();
    shipF();
    boatF();
    rain();

    glFlush();
}



void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


void display5()//cover page
{
glClearColor(0.56f, 0.819f, 0.949f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glColor3f(0.0,0.0,0.0);

renderBitmapString(-0.2f, 0.8f, 0.0f, GLUT_BITMAP_9_BY_15, "01054 - Computer Graphics[M]");
renderBitmapString(-0.1f, 0.7f, 0.0f, GLUT_BITMAP_HELVETICA_18, "St. Martin");
renderBitmapString(-0.17f, 0.65f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted by Group-9");
renderBitmapString(-0.8f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "ID");//ID
renderBitmapString(-0.8f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-41207-2");
renderBitmapString(-0.8f, 0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-40861-2");
renderBitmapString(-0.8f, 0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "18-39074-3");
renderBitmapString(-0.8f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-41386-3");
renderBitmapString(-0.8f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "19-41391-3");

renderBitmapString(-0.2f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Name");//Name
renderBitmapString(-0.2f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ABID HASAN EMON");
renderBitmapString(-0.2, 0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "S M TUSHER MUSTAKIM");
renderBitmapString(-0.2f, 0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MD. TUHIN REZA");
renderBitmapString(-0.2, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "S.M. RIZWANUL HASSAN");
renderBitmapString(-0.2f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ASIF IQBAL");

renderBitmapString(0.4f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Contribution");//Contribution
renderBitmapString(0.4f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ABID HASAN EMON");
renderBitmapString(0.4f, 0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "S M TUSHER MUSTAKIM");
renderBitmapString(0.4f, 0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "0%");
renderBitmapString(0.4f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "S.M. RIZWANUL HASSAN");
renderBitmapString(0.4f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "0%");

renderBitmapString(-0.16f, -0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Submitted To");//submitted to
renderBitmapString(-0.20f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MAHFUJUR RAHAMAN");
renderBitmapString(-0.23f, -0.55f, 0.0f, GLUT_BITMAP_HELVETICA_12, "FACULTY OF SCIENCE & TECHNOLOGY");
renderBitmapString(-0.25f, -0.60f, 0.0f, GLUT_BITMAP_HELVETICA_10, "AMERICAN INTERNATION UNIVERSITY-BANGLADESH");
 glFlush();
}




void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {

case 'n':
            glutDestroyWindow(1);
            glutInitWindowSize(1386, 788); // Initialize GLUT
            glutInitWindowPosition(50, 50);
            glutCreateWindow("Night "); // Create a window with the given title
            glutDisplayFunc(display2);
            PlaySound(TEXT("nightwav.wav"), NULL, SND_ASYNC);
            glutKeyboardFunc(handleKeypress);
            glutMainLoop();
break;
case 'd':
            glutDestroyWindow(1);
            glutCreateWindow("Day"); // Create a window with the given title
            glutDisplayFunc(display);
            PlaySound(TEXT("daywav.wav"), NULL, SND_ASYNC);
            glutKeyboardFunc(handleKeypress);
            glutMainLoop();
           break;

    case 'r':
            glutDestroyWindow(1);
            glutInitWindowSize(1386, 788); // Initialize GLUT
            glutInitWindowPosition(50, 50);
            glutCreateWindow("Rain "); // Create a window with the given title
            glutDisplayFunc(display3);
            PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC);
            glutKeyboardFunc(handleKeypress);

break;
case 'e':
            glutDestroyWindow(1);

            glutInitWindowSize(1386, 788); // Initialize GLUT
            glutInitWindowPosition(50, 50);
            glutCreateWindow("snow "); // Create a window with the given title
            glutDisplayFunc(display4);
            PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC);
           glutKeyboardFunc(handleKeypress);

break;
case 'c':
            glutDestroyWindow(1);

            glutInitWindowSize(1386, 788); // Initialize GLUT
            glutInitWindowPosition(50, 50);
            glutCreateWindow("Front page"); // Create a window with the given title
            glutDisplayFunc(display5);

            glutKeyboardFunc(handleKeypress);

break;




	}
}



int main(int argc, char** argv)
{


    glutInit(&argc, argv);
        glutInitWindowSize(1386, 788); // Initialize GLUT
glutInitWindowPosition(50, 50);


    glutCreateWindow("St. matrin");

    glutDisplayFunc(display5);

    glutTimerFunc(20, updateb1, 0);
    glutTimerFunc(300, updateSun, 0);

    glutTimerFunc(20, updatet1, 0);
    glutTimerFunc(400, updateObject, 0);

    glutTimerFunc(80, updateCar1, 0);

    glutTimerFunc(70, updateCar2, 0);
    glutTimerFunc(70, updatePlane, 0);

    glutTimerFunc(70, updateCloud, 0);

    glutTimerFunc(100, updateCloudleft, 0);
    glutTimerFunc(300, updateWater, 0);
    glutTimerFunc(100,update8,0);


    glutKeyboardFunc(handleKeypress);



    glutMainLoop();
    return 0;
}


