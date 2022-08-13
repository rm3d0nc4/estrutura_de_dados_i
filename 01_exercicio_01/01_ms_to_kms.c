#include <stdio.h>

int main() {
    float m_s;
    float km_h;

    printf("Velocity in m/s: ");
    scanf("%f", &m_s);

    km_h = m_s * 3.6;

    printf("%0.2f m/s is equals to %.02f", m_s, km_h);
}