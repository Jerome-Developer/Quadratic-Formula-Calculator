#include <inttypes.h>
#include <stdio.h>
#include <complex.h>


//get rekt jerome you've been c'd
//cwned even


//cause
//y'know
//instead of pwned

int main(){
    int format;
    float a;
    float b;
    float c;

    float a1;
    float a2;
    float b1;
    float b2;

    double complex output1;
    double complex output2;

    printf("Which format would you like to use?\n(1.) (a1+a2)(b1+b2)=0 (2) ax²+bx+x=0\n");
    scanf("%d", &format);

    if(format == 1){
        //Why would you ever need this function lol
        printf("Enter the variables:\n");
        printf("a1: ");
        scanf("%f", &a1);

        printf("\na2: ");
        scanf("%f", &a2);

        printf("\nb1: ");
        scanf("%f", &b1);

        printf("\nb2: ");
        scanf("%f", &b2);

        a = (a1*b1);
        b = (a1*b2)+(a2*b1);
        c = (a2*b2);
        
        output1 = (-b + csqrt((b*b)-(4*(a)*(c))))/(2*a);
        output2 = (-b - csqrt((b*b)-(4*(a)*(c))))/(2*a);

        if(cimag(output1)==0){
            printf("\nPositive Discriminant: %g\n", creal(output1));
        }
        else if (creal(output1)==0){
            printf("\nPositive Discriminant: %gi\n", cimag(output1));
        }
        //Im pretty sure imaginary zeroes here are impossible lol
        else{
            printf("\nPositive Discriminant: %g+%gi\n", creal(output1), cimag(output1));
        }
        if(cimag(output2)==0){
            printf("Negative Discriminant: %g\n", creal(output2));
        }
        else if (creal(output2)==0) {
            printf("Negative Discriminant: %gi\n", cimag(output2));
        }
        //same as last comment
        else{
            printf("Negative Discriminant: %g+%gi\n", creal(output2), cimag(output2));
        }

    }
    else if (format == 2) {
        printf("Enter the variables:\n");
        printf("a: ");
        scanf("%f", &a);

        printf("\nb: ");
        scanf("%f", &b);

        printf("\nc: ");
        scanf("%f", &c);
        
        output1 = (-b + csqrt((b*b)-(4*(a)*(c))))/(2*a);
        output2 = (-b - csqrt((b*b)-(4*(a)*(c))))/(2*a);

        if(cimag(output1)==0){
            printf("\nPositive Discriminant: %g\n", creal(output1));
        }
        else if (creal(output1)==0){
            printf("\nPositive Discriminant: %gi\n", cimag(output1));
        }
        //I know there can be imaginary numbers here
        else{
            printf("\nPositive Discriminant: %g+%gi\n", creal(output1), cimag(output1));
        }
        if(cimag(output2)==0){
            printf("Negative Discriminant: %g\n", creal(output2));
        }
        else if (creal(output2)==0) {
            printf("Negative Discriminant: %gi\n", cimag(output2));
        }
        // I mean i did pass 9th grade math despite hating the class
        else{
            printf("Negative Discriminant: %g+%gi\n", creal(output2), cimag(output2));
        }
        
    }
    return 0;
}