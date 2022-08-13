# include <stdio.h>

int main() {
    float salary, new_salary;

    printf("Salary:");
    scanf("%f", &salary);

    new_salary = salary * 1.25;

    printf("Your new salary is: %0.2f", new_salary);

}