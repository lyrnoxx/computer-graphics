#include<stdio.h>
#include<GL/glut.h>
int x,y;
int where_to_rotate=0;
float tx=0,ty=0,rotate_angle=0.0;

void draw_pixel(float x1,float y1){
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(x1,y1);
    glEnd();
}

void triangle(int x, int y){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+400,y+400);
        glVertex2f(x+300,y);
    glEnd();
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,0,0);
    draw_pixel(0,0);
    if(where_to_rotate==1){
        tx=0;
        ty=0;
        rotate_angle+=0.09;
    }
    if(where_to_rotate==2){
        tx=x;
        ty=y;
        rotate_angle+=0.09;
        glColor3f(0,0,1);
        draw_pixel(x,y);
    }
    glTranslatef(tx,ty,0);
    glRotatef(rotate_angle,0.0,0.0,1.0);
    glTranslatef(-tx,-ty,0);
    triangle(tx,ty);
    glutPostRedisplay();
    glutSwapBuffers();
}

void myInit(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800,800,-800,800);
    glMatrixMode(GL_MODELVIEW);
}

void rotate_menu(int option){
    if(option==1)
        where_to_rotate=1;
    if(option==2)
        where_to_rotate=2;
    if(option==3)
        where_to_rotate=3;
    display();
}

int main(int argc,char **argv){
    printf("\nenter position for rotation(x,y): ");
    scanf("%d%d",&x,&y);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("rotate created triangle");
        myInit();
    glutDisplayFunc(display);
    glutCreateMenu(rotate_menu);
        glutAddMenuEntry("rotate around origin",1);
        glutAddMenuEntry("rotate around fixed point",2);
        glutAddMenuEntry("stop rotation",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}