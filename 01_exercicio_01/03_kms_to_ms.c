#include <stdio.h>

int main() {
    float km_h;
    float m_s;

    printf("Velocity in km/s: ");
    scanf("%f", &km_h);

    m_s = km_h/3.6;

    printf("%0.2f km/h is equals to %0.2f m/s", km_h, m_s);
}