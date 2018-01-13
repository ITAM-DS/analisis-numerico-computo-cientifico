#include<stdio.h>
#include<math.h>

#define ARITHMETIC_5(x) (truncf( x * 1e5) / 1e5)

void print_number(char s[], double number){
	printf("%s = %1.8f\n", s, number);
}
void print_row(char s[], double value_8, double machine, double abs_error, double rel_error){
	printf("%s \t %1.8f \t %1.5f \t %1.8f \t %1.8f \n", s, value_8, machine, abs_error, rel_error);
}
int main(){
	double x_8 = 0.71428571;
	double x_5 = ARITHMETIC_5(x_8);
	double y_8 = 0.33333333;
	double y_5 = ARITHMETIC_5(y_8);
	double u_8 = 0.714251;
	double u_5 = ARITHMETIC_5(u_8);
	double v_8 = 98765.9;
	double v_5 = truncf(v_8); // I want the number to have 5 decimal positions, I just remove everything after the decimal point.
	double w_8 = .111111e-4;
	double w_5 = ARITHMETIC_5(w_8);

	print_number("x_8", x_8);
    print_number("x_5", x_5);
    print_number("y_8", y_8);
    print_number("y_5", y_5);
    print_number("u_8", u_8);
    print_number("u_5", u_5);
    print_number("v_8", v_8);
    print_number("v_5", v_5);
    print_number("w_8", w_8);
    print_number("w_5", w_5);

	print_row("x-y", x_8 - y_8, ARITHMETIC_5(x_5 - y_5), fabs((x_8 - y_8) - ARITHMETIC_5(x_5 - y_5)), fabs((x_8 - y_8) - ARITHMETIC_5(x_5 - y_5)) / fabs(x_8 - y_8));
	print_row("x/y", x_8 / y_8, ARITHMETIC_5(x_5 / y_5), fabs((x_8 / y_8) - ARITHMETIC_5(x_5 / y_5)), fabs((x_8 / y_8) - ARITHMETIC_5(x_5 / y_5)) / fabs(x_8 / y_8));
	print_row("(x-u)/w", (x_8 - u_8) / w_8, ARITHMETIC_5((x_5 - u_5) / w_5), fabs(((x_8 - u_8) / w_8) - ARITHMETIC_5((x_5 - u_5) / w_5)), fabs(((x_8 - u_8) / w_8) - ARITHMETIC_5((x_5 - u_5) / w_5)) / fabs((x_8 - u_8) / w_8));
	print_row("u+v", u_8 + v_8, ARITHMETIC_5(u_5 + v_5), fabs((u_8 + x_8) - ARITHMETIC_5(u_5 + v_5)), fabs((u_8 + v_8) - ARITHMETIC_5(u_5 + v_5)) / fabs(u_8 + v_8));
	return 0;
}