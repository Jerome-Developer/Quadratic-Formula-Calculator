#include <inttypes.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

void printVals(double complex output1){
    if(cimag(output1)==0){
        printf("Root: %g\n", creal(output1));
    }
    else if (creal(output1)==0){
        printf("Root: %gi\n", cimag(output1));
    }
    else{
        printf("Root: %g+%gi\n", creal(output1), cimag(output1));
    }
}


int main(){
    double a;
    double b;
    double c;
    double d;

    double m;
    double n;

    char conf;

    printf("Do you have the depressed cubic? [Y/N]\n");
    scanf(" %c", &conf);
    if (conf == 'Y' || conf == 'y'){
        printf("P: ");
        scanf("%lf", &m);
        printf("Q: ");
        scanf("%lf", &n);
    }

    //getting the depressed cubic
    else if (conf == 'N' || conf == 'n'){
        printf("A: ");
        scanf("%lf", &a);
        printf("B: ");
        scanf("%lf", &b);
        printf("C: ");
        scanf("%lf", &c);
        printf("D: ");
        scanf("%lf", &d);

        m = ((3*a*c)-(b*b))/(3*(a*a));
        n = ((2*(b*b*b))+(27*(a*a)*d)-(9*a*b*c))/(27*(a*a*a));

        printf("\nYour depressed cubic is x³+%gx=%g\n",m,n);

    }
    else {
        printf("I think you mistyped something...");
        return 0;
    }

    double complex u;
    double complex v;

    //finding the first root (CubicZero)
    //How is this the easy part

    //I have to find the discriminant first

    double delta = (n*n)/4.0 + (m*m*m)/27.0;

    //Now a decision must be made, is there a real root?

    if (delta>=0){
        double A = -n/2.0 + sqrt(delta);
        double B = -n/2.0 - sqrt(delta);

        u = (A >= 0) ? cbrt(A) : -cbrt(-A);
        v = (B >= 0) ? cbrt(B) : -cbrt(-B);
    }
    else if (delta<0){
        u = cpow((-n/2 + csqrt((n*n)/4 + (m*m*m)/27)), 1.0/3.0);
        v = cpow((-n/2 - csqrt((n*n)/4 + (m*m*m)/27)), 1.0/3.0);
    }
    double complex y1 = u+v;

    //Oh my lord that was a lot of work
    //Like seriously apparently the video I watched was bad or something
    //Next, I am going to do something called the Cube Roots of Unity
    /*
    Essentially,
    A cubic equation falls on the complex plane. This is because all numbers are consider complex. Why? An imaginary number is written as A+Bi, and all real 
    numbers can be written as A+0i. Meaning all graphs show up on the complex plane as well. On the complex plane, a cubic function has 3 roots always. This
    is because a polynomial function has as many roots as its degree (the largest exponent on an x), so a seventh degree polynomial will have 7 roots, sixth has 6
    and so on. On the complex plane, a cubic functions root are evenly spaced out on the unit circle on root at 0 degrees, one at 120, and one at 240.

    what does all that mean?
    Honestly I have no idea.

    anyways here are the rest of the roots.
    */

    double complex omega = -0.5 + I*sqrt(3)/2;

    double complex y2 = omega*u + omega*omega*v;
    double complex y3 = omega*omega*u + omega*v;
    


    //A depressed Cubic function moves the middle root to x=0, the functions below shift it back to the original cubic function.

    y1 = y1-b/(3.0*a);
    y2 = y2-b/(3.0*a);
    y3 = y3-b/(3.0*a);


    //oml we are finally done

    printf("\nZeroes:\n");
    printVals(y1);
    printVals(y2);
    printVals(y3);


}