#include <stdio.h>

int main() {
    
    float factory_cost;
    float consumer_cost;

    printf("Factory cost:");
    scanf("%f", &factory_cost);

    consumer_cost = factory_cost + (factory_cost * 0.28) + (factory_cost * 0.45);

    printf("Consumer cost: R$ %0.2f", consumer_cost);
}