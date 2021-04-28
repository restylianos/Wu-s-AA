#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "helperFun.h"
#include <stdio.h>

//set global vars
int def_x1=20, def_y1=30, def_x2=550, def_y2=150;
//def stands for default!
int first_x,first_y,second_x,second_y;

void myInit() {
	glClearColor( 0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
	
	gluOrtho2D(0, 640, 0, 480);
    return;
}

void draw_pixels( int x , int y , float brightness)
{
    glColor4f((1-brightness),(1-brightness),(1-brightness),1);
	glVertex2i(x, y);
    return;
}

void draw_normal_pixels(int x,int y){
    //use y+20 to create a new simple line 20 px higher than the AA line
    y +=20;
    glColor3f(1,0,0);
    glVertex2i(x,y);
}

void draw_lines(int x0 , int y0 , int x1 , int y1)
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
            draw_normal_pixels(x,intersectY);
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
            draw_normal_pixels(x,intersectY);
            intersectY += gradient;
        }
    }
  return;
}


void myDisplay() {
    if(first_x && second_y){
        draw_lines(first_x,first_y,second_x,second_y);
    }
    else{
        draw_lines(def_x1,def_y1,def_x2,def_y2);
    }
	
    glEnd();
	glFlush();
    return;
}


int main(int argc, char **argv) {

	printf( "\033[32;1mUsage:\nCoordinates given via terminal: ./a.out x1,y1,x2,y2\nUsing default coordinates which are: (x1,y1) = [20,30] && (x2,y2) = [550, 150]\033[0m\n");
    
    if(argc > 1){
        printf("ok");
        first_x = strtol(argv[1],NULL,10);
        first_y = strtol(argv[2],NULL,10);
        second_x = strtol(argv[3],NULL,10);
        second_y = strtol(argv[4],NULL,10);
    }

    

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Anti-aliased line");
    glMatrixMode(GL_PROJECTION);
	myInit();
    glutDisplayFunc(myDisplay);
    
	
    glPointSize(2.0f);
	glutMainLoop();

    return 0;
}