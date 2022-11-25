#include "iostream"
using namespace std;

bool linearSearch(int x, int vetor[], int tamanho) {
    if (x == vetor[tamanho]) {
        return true;
    }

    if (tamanho == 0) {
        return false;
    }

    linearSearch(x, vetor, tamanho-1);
}

int main() {
    int vetor[] = {46, 18, 35, 9};

    int tamanho = sizeof(vetor)/sizeof(0);

    cout << linearSearch(123, vetor, tamanho) << endl;
}