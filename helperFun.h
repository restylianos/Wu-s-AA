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
    if (input_num < 0) return -input_num;
    else return input_num;
}
  
//returns integer part of a floating point number
int get_integer_part(float input_num)
{
    return (int)input_num;
}
  
//rounds off a number
// int get_round_number(float x)
// {
//     return get_integer_part(x + 0.5) ;
// }
  
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