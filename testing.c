#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "helperFun.h"
#include <stdio.h>

//set global vars
int x1, myy1, x2, y2;

void myInit() {
	glClearColor( 0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 640, 0, 480);
    return;
}

void draw_pixels( int x , int y , float brightness)
{
    glColor4f((1-brightness),(1-brightness),(1-brightness),1);
	glVertex2i(x, y);
    return;
}


void draw_line(int x0 , int y0 , int x1 , int y1)
{
    glBegin(GL_POINTS);
    int steep = get_abs_num(y1 - y0) > get_abs_num(x1 - x0) ;
    //get slope


    // swap the co-ordinates if slope > 1 or we
    // draw backwards
    if (steep){
        swap_nums(&x0 , &y0);
        swap_nums(&x1 , &y1);
    }

    if (x0 > x1){
        swap_nums(&x0 ,&x1);
        swap_nums(&y0 ,&y1);
    }
  
    //compute the slope
    float dx = x1-x0;
    float dy = y1-y0;
    float gradient = dy/dx;
    if (dx == 0.0)
        gradient = 1;
  
    int xpxl1 = x0;
    int xpxl2 = x1;
    float intersectY = y0;
  
    // main loop
    if (steep){
        int x;
        for (x = xpxl1 ; x <=xpxl2 ; x++)
        {
            // pixel coverage is determined by fractional
            // part of y co-ordinate
            draw_pixels(get_integer_part(intersectY), x,get_round_fract(intersectY));
            draw_pixels(get_integer_part(intersectY)-1, x, get_fract_part(intersectY));
            intersectY += gradient;
        }
    }
    else{
        int x;
        for (x = xpxl1 ; x <=xpxl2 ; x++)
        {
            // pixel coverage is determined by fractional
            // part of y co-ordinate
            draw_pixels(x, get_integer_part(intersectY),get_round_fract(intersectY));
            draw_pixels(x, get_integer_part(intersectY)-1,get_fract_part(intersectY));
            intersectY += gradient;
        }
    }
  glEnd();
  return;
}


void myDisplay() {
	draw_line(20 , 300 , 620, 400);
    // draw_normal_line(20,600,250,70);
	glFlush();
    return;
}


int main(int argc, char **argv) {

	printf( "(x1,y1) = [20,30] && (x2,y2) = [550, 150]\n");
	// scanf("%d %d %d %d", &x1, &myy1, &x2, &y2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Anti-aliased line");

	myInit();
	glutDisplayFunc(myDisplay);
    glPointSize(1.0f);
	glutMainLoop();

    return 0;
}