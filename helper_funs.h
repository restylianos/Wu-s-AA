#include <math.h>


// swap two numbers
void swap_nums(int* fist_num , int* second_num)
{
    int temp = *fist_num;
    *fist_num = *second_num;
    *second_num = temp;
}
  
// returns absolute value of number
float get_abs_num(float input_num)
{
    return abs(input_num);
}
  
//returns integer part of a floating point number
int get_integer_part(float input_num)
{
    return (int)input_num;
}
//returns fractional part of a num

float get_fract_part(float input_num)
{
    if (input_num>0) return input_num - get_integer_part(input_num);
    else return input_num - (get_integer_part(input_num)+1);
  
}
  
//returns 1 - fractional part of number
float get_round_fract(float input_num)
{
    return 1 - get_fract_part(input_num);
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

void myInit() {
	glClearColor( 0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 640, 0, 480);
    //make pointers bigger to make results more clear
    glPointSize(5.0f);
    return;
}

void draw_lines(int x0 , int y0 , int x1 , int y1)
{
    int i;

    glBegin(GL_POINTS);

    int slope = get_abs_num(y1 - y0) > get_abs_num(x1 - x0) ;
    //get slope


    // swap if slope > 1 

    // draw backwards
    if (slope){
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

    float grad = dy/dx;

    if (dx == 0.0) grad = 1;
        
    float f_y = y0;
    //get y as float

    //condition check and draw part
    if (slope){
        for (i=x0;i<=x1;i++){
            draw_pixels(get_integer_part(f_y), i,get_round_fract(f_y));
            draw_pixels(get_integer_part(f_y)-1, i, get_fract_part(f_y));
            draw_normal_pixels(i,f_y);
            f_y += grad;
        }
    }
    else{
        for (i=x0;i<=x1;i++){
            draw_pixels(i, get_integer_part(f_y),get_round_fract(f_y));
            draw_pixels(i, get_integer_part(f_y)-1,get_fract_part(f_y));
            draw_normal_pixels(i,get_integer_part(f_y));
            f_y += grad;
        }
    }
    return;
}