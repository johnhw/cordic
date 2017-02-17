#include "generated/cordic-32.h"
#include <math.h> // for testing only!
#include <stdio.h>

//Print out sin(x) vs fp CORDIC sin(x)
int main(int argc, char **argv)
{
    double p;
    double total_error = 0, max_error=0, error;
    int s,c;
    int i;    
    int n;
    printf("CORDIC   \tFloat   \tError\n");
    n = 100;
    
    for(i=0;i<n;i++)
    {
        p = (i/(double)n)*M_PI/2;        
        //use 32 iterations
        cordic((p*MUL), &s, &c, 32);
        //these values should be nearly equal
        error = s/MUL-sin(p);
        printf("%.12f \t %.12f \t %.4e\n", s/MUL, sin(p), error);
        total_error += error;
        if(error>max_error) 
            max_error = error;
        
    }      
    printf("\nMean error: %.6e", total_error/n);
    printf("\nMax error: %.6e", max_error);
}