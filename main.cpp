/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>

float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
float sx=10.0, sy=7.0, sz=-15.0;
float kx=5.0, ky=7.0, kz=-15.0;
float bz=3.0, btz=6.0;
float mz=-15.0, mtz=-15.0;
float rx=0,ry=0;
//int timer=0;
//float m1x=-2.2 ,m1y= 1.3, m1z=6.0 ;
//float m4x=-1.8 ,m4y=1.3 , m4z=6.0 ;

//------------------------------  reshapeFunc  ---------------------------------
void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}


//------------------------------  display   -------------------------------
void moon(){
    glColor3f(1.0,1.0,1.0);
    glTranslatef(10.0,7.0,0.0);
    glRotatef(180,100,60,0);
    glRotatef(zRotated,0,0,1);
    glutSolidSphere(1.5,40,30);
    //glPopMatrix();
}
void stone(){
    glLoadIdentity();                  // Reset the model-view matrix
    glTranslatef(-4.0f, 0.0, -5.5);
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
    // Front
      glColor3ub(1.0, 0.0, 1.0);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);

      // Back
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);

      // Left
      glColor3f(1.0f,0.0f,1.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid

   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}


void sun(){
    glColor3f(1.0,1.0,0.0);
    glTranslatef(sx,sy,sz);
    glRotatef(180,100,60,0);
    //glRotatef(angle,0,0,1);
    glutSolidSphere(1.5,40,30);
    //glPopMatrix();
}

void sky(){
    glColor3f(0.0,0.0,5.5);
    glTranslatef(kx,ky,kz);
    glRotatef(180,0,0,0);
    //glRotatef(angle,0,0,1);
    glutSolidCube(30);

}


void snowman(){
    glColor3f(1.0,1.0,1.0);
	glPushMatrix();//snowman body
	glTranslatef(-3.0,1.5,bz);
    glRotatef(180,0,0,0);
    glutSolidSphere(1.0,30,30);
    glPopMatrix();

    glPushMatrix();//snowman body
    glTranslatef(-3.0,-0.5,bz);
    glRotatef(180,0,0,0);
    glutSolidSphere(1.5,30,30);
    glPopMatrix();

    glPushMatrix();//snowman body
    glTranslatef(-3.0,-3.0,bz);
    glRotatef(180,0,0,0);
    glutSolidSphere(2.0,30,30);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);//left eye
    glTranslatef(-2.5,2.0,btz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidSphere(0.1,30,30);
    glPopMatrix();

    glPushMatrix();//right eye
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-1.5,2.0,btz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidSphere(0.1,30,30);
    glPopMatrix();

    glPushMatrix();//nose
    glColor3f(1.5, 0.0, 0.0);
    glTranslatef(-2.0,1.8,btz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidCone(0.1,2,20,30);
    glPopMatrix();

    glPushMatrix(); //left hand
    glColor3ub(116, 52, 32);
    glTranslatef(-3.0,0.5,btz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidCone(0.1,3,10,10);
    glPopMatrix();

    glPushMatrix(); //right hand
    glColor3ub(116, 52, 32);
    glTranslatef(-1.0,0.5,btz);
    glRotatef(180,0,3,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidCone(0.1,7,10,10);
    glPopMatrix();


}
void Melting(){
    glColor3f(1.0,1.0,1.0);
	glPushMatrix();//snowman body
	glTranslatef(-3.0,-2.0,mz);
    glRotatef(180,0,0,0);
    glutSolidSphere(2.0,10,5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);//left eye
    glTranslatef(-2.0,-2.0,mtz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidSphere(0.1,30,30);
    glPopMatrix();

    glPushMatrix();//right eye
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-2.0,-2.0,mtz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidSphere(0.1,30,30);
    glPopMatrix();

    glPushMatrix();//nose
    glColor3f(1.5, 0.0, 0.0);
    glTranslatef(-2.0,-1.5,mtz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidCone(0.1,2,20,30);
    glPopMatrix();

    glPushMatrix(); //left hand
    glColor3ub(116, 52, 32);
    glTranslatef(-2.0,-1.0,mtz);
    glRotatef(180,0,0,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidCone(0.1,3,10,10);
    glPopMatrix();

    glPushMatrix(); //right hand
    glColor3ub(116, 52, 32);
    glTranslatef(-1.0,-1.0,mtz);
    glRotatef(180,0,3,0);
    //glRotatef(zRotated,0,1,0);
    glutSolidCone(0.1,7,10,10);
    glPopMatrix();

}
void keyspeed(int key, int x,int y){
    if (key==GLUT_KEY_UP) {
        sx=10.0; sy=7.0; sz=1.0;
        kx=5.0; ky=7.0; kz=-14.0;
        bz=-15.0; btz=-15.0;
        mz=3.0; mtz=6.0;

    }
    else if (key==GLUT_KEY_DOWN) {
        sx=10.0, sy=7.0, sz=-15.0;
        kx=5.0, ky=7.0, kz=-15.0;
        bz=3.0; btz=6.0;
        mz=-15.0; mtz=-15.0;
    }
   /* else if (key==GLUT_KEY_RIGHT) {
        sx=10.0, sy=7.0, sz=-15.0;
        kx=5.0, ky=7.0, kz=-15.0;
    }
    else if (key==GLUT_KEY_LEFT) {
        sx=10.0, sy=7.0, sz=-15.0;
        kx=5.0, ky=7.0, kz=-15.0;
    }*/

}

void timer(int)
{
      glutPostRedisplay();
    glutTimerFunc(10000/60,timer,0);

      if(rx<14&& rx>-6)
        {
            rx+= 2;
        }


        //if(rx>-6)
        //{
            //rx -= 2;
      //  }

    /*else if(key == GLUT_KEY_UP)
    {
        ry += 5;
        ry +=2;
    }
    else if(key == GLUT_KEY_DOWN)
    {
        ry -= 5;
        ry -=2;
    }*/


}
void mountain(){
    glColor3f(1.0,1.0,1.0);

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-3.0,0.0,-3.0);
    glRotatef(180,0,0,0);
    glutSolidSphere(5,40,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.4,0.0,-3.0);
    glRotatef(180,0,0,0);
    glutSolidSphere(5,40,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.0,0.0,-3.0);
    glRotatef(180,0,0,0);
    glutSolidSphere(5,40,10);
    glPopMatrix();

}
void ground(){

    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);     // Green
    glVertex3f( 17.0f, 0.0f, -1.0f);
    glVertex3f(-9.0f, 0.0f, -1.0f);
    glVertex3f(-9.0f, 0.0f,  1.0f);
    glVertex3f( 17.0f, 0.0f,  1.0f);

      // Bottom face (y = -1.0f)
    glColor3f(1.0, 1.0, 1.0);     // Orange
    glVertex3f( 17.0f, -3.0f,  1.0f);
    glVertex3f(-9.0f, -3.0f,  1.0f);
    glVertex3f(-9.0f, -3.0f, -1.0f);
    glVertex3f( 17.0f, -3.0f, -1.0f);

      // Front face  (z = 1.0f)
    glColor3f(1.0, 1.0, 1.0);     // Red
    glVertex3f( 17.0f,  0.0f, 1.0f);
    glVertex3f(-9.0f,  0.0f, 1.0f);
    glVertex3f(-9.0f, -4.0f, 1.0f);
    glVertex3f( 17.0f, -4.0f, 1.0f);

      // Back face (z = -1.0f)
    glColor3f(1.0, 1.0, 1.0);     // Yellow
    glVertex3f( 17.0f, -4.0f, -1.0f);
    glVertex3f(-9.0f, -4.0f, -1.0f);
    glVertex3f(-9.0f,  0.0f, -1.0f);
    glVertex3f( 17.0f,  0.0f, -1.0f);

      // Left face (x = -1.0f)
    glColor3f(1.0, 1.0, 1.0);     // Blue
    glVertex3f(-9.0f,  0.0f,  1.0f);
    glVertex3f(-9.0f,  0.0f, -1.0f);
    glVertex3f(-9.0f, -4.0f, -1.0f);
    glVertex3f(-9.0f, -4.0f,  1.0f);

      // Right face (x = 1.0f)
    glColor3f(1.0, 1.0, 1.0);     // Magenta
    glVertex3f(17.0f, 0.0f, -1.0f);
    glVertex3f(17.0f,  0.0f,  1.0f);
    glVertex3f(17.0f, -4.0f,  1.0f);
    glVertex3f(17.0f, -4.0f, -1.0f);
    glEnd();
    glPopMatrix();
}

void display (void)
{

    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (-3.0, -3.0, -20.5);



     glPushMatrix();
     moon();
     glPopMatrix();

     glPushMatrix();
     sun();
     glPopMatrix();

     glPushMatrix();
     mountain();
     glPopMatrix();

     glPushMatrix();
     ground();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(rx,ry,2.0);
     snowman();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(rx,ry,2.0);
     Melting();
     glPopMatrix();

     glPushMatrix();
     sky();
     glPopMatrix();

     glPushMatrix();
     stone();
     glPopMatrix();

    glutSwapBuffers();
    glutPostRedisplay();
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glutInitWindowSize     (1200, 700);
    glutInitWindowPosition (200, 0);
    glutCreateWindow       ("Mariam Elkady 20102372");

    glClearColor (0.0,0.0,0.25,0.0);

    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);
    glutTimerFunc(0,timer,0);
    glRotatef(180,0,0,0);
    glClearColor(0.0,0.0,0.25,0.0);
    texture(); // Lighting and textures
    glutSpecialFunc(keyspeed);
    //glutSpecialFunc(sKeys);

    glutMainLoop();
}
