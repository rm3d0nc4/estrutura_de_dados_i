#include "iostream"
using namespace std;

int binarySearch(int element, int vetor[], int tamanho) {
    int p = 0;
    int u = tamanho - 1;
    while (p <= u) {
        int m = (p + u)/2;
        if (vetor[m] == element) return 1;
        if (element > vetor[m]) p = m + 1;
        else u = m - 1;
    }
    return 0;
}

int binarySearchRecursivo(int element, int vetor[], int primeiro, int ultimo) {
    //int tamanho = primeiro + ultimo + 1;
    int meio = (primeiro + ultimo)/2;
    if (primeiro > ultimo) {
        return 0;
    }

    if (vetor[meio] == element) {
        return 1;
    }

    if (vetor[meio] > element) {
        binarySearchRecursivo(element, vetor, primeiro, meio - 1);
    } else {
        binarySearchRecursivo(element, vetor, meio + 1, ultimo);
    }
}

int main() {
    int vetor[] = {9, 18, 65, 75};
    cout << binarySearchRecursivo(75, vetor, 0, 4) << endl; //true
    cout << binarySearchRecursivo(675, vetor, 0, 4) << endl; //false

}