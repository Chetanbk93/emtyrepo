//calcaulator funcation
#include <stdio.h>

//Decrlate funcation :
int Addition(int a, int b);
int Subtraction(int a, int b);
int Multiplication(int a, int b);
double Division(float a, double b);

 double a, b;
int choice;
void main()
{
    printf("please let me know what operation you want to perform");
    printf("1 for addition");
    printf("2 for subtraction");
    printf("3 for multiplication"); 
    printf("4 for division");
    scanf("%lf", &choice);
    printf("Enter two numbers:");
    scanf("%lf%lf",&a,&b);
    switch(choice)
    {
        case 1:{
        int Addition(int a, int b);
        break;}
case 2:{
        int Subtraction(int a, int b);
        break;
}
case 3:{
        int Multiplication(int a, int b);
        break;
    }
case 4:{
        double Division(float a, double b);
        break;
        
    }
}
Addition(a,b);
{
    int sum = a + b;
    printf("the sum is %d", sum);
}
Subtraction(a,b);
{
    int sub = a - b;    
    printf("the subtraction is %d", sub);  
}
Multiplication(a, b);
{
    int mul = a * b; 
    printf("the multiplication is %d", mul);
}
Division(a,b);
{
    if(b != 0){
        double div = a / b; 
        printf("the division is %lf", div);
    }
    else{
        printf("division by zero is not allowed");      
    }   
}
}
