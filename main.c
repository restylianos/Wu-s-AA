#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "helper_funs.h"
#include <stdio.h>

//set global vars
int def_x1=20, def_y1=30, def_x2=550, def_y2=150;
//def stands for default!
int first_x,first_y,second_x,second_y;

void myDisplay();

int main(int argc, char **argv) {

	printf( "\033[32;1m[+] Usage:\n[1] Coordinates given via terminal: ./a.out x1,y1,x2,y2\n[2] Using default coordinates which are: (x1,y1) = [20,30] && (x2,y2) = [550, 150]\033[0m\n");
    printf( "\033[31;1mRed line is made using a simple drawing algorithm\nWhite line shows the AA line\033[0m\n");

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
    
	glutMainLoop();

    return 0;
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