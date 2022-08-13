#include <stdio.h>

int main() {
    float radius, volume;
    
    const float pi = 3.14159265359;

    printf("Radius: ");
    scanf("%f", &radius);

    volume = (4 * pi * (radius * radius * radius)) / 3;

    printf("Volume: %0.2f", volume);    
}