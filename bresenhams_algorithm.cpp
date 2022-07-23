#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>

int x1,d1,x2,y2;

void init(){
    gluOrtho2D(500,0,500,0);
}

void draw_pixel(int x, int y){
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void draw_line(int x1,int y1,int x2 ,int y2){
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int td=2*(dy-dx);int tdy=2*dy;
    int tdd=2*dy-dx;
    int x,y;
    if(x1>x2){
        x=x2;
        y=y2;
        x2=x1;
    }
    else{
        x=x1;
        y=y1;
    }
    draw_pixel(x,y);
    while(x<x2){
        x++;
        if(tdd<0){
            tdd+=tdy;
        }
        else{
            y++;
            tdd+=td;
        }
        draw_pixel(x,y);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    draw_line(x1,d1,x2,y2);
    glEnd();
    glFlush();
}

int main(int argc,char **argv){
    printf("enter values for x1,y1,x2,y2:\n");
    scanf("%d%d%d%d",&x1,&d1,&x2,&y2);
    glutInit(&argc,argv);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("bresenhams line drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}