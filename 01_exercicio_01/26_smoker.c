#include <stdio.h>

int main() {
    float years, cigarette_n, wallet_price;
    float money;

    printf("Years that you smoske: ");
    scanf("%f", &years);

    printf("number of daily smoked cigarettes: ");
    scanf("%f", &cigarette_n);

    printf("wallet cigarette price: ");
    scanf("%f", &wallet_price);

    money = (cigarette_n / 20) * wallet_price * years * 365;
    
    printf("You spent R$ %0.2f in cigarettes!", money);

}