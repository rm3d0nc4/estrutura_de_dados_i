#include <iostream>

using namespace std;


int binarySearch(int item, int vetor[], int tamanho ) {
    int first = 0;
    int last = tamanho - 1;
    while(first <= last) {
        int meio = (first + last) / 2;
        if(item == vetor[meio]) return 1;
        if(item < vetor[meio]) last = meio - 1;
        else first = meio + 1;
    }
    return 0;
}

int recursiveBinarySearch(int item, int vetor[], int first, int last) {
    if(first > last) return 0;
    int meio = (first + last) / 2;
    if(item == vetor[meio]) return 1;
    if(item < vetor[meio]) return recursiveBinarySearch(item, vetor, first, meio - 1);
    else return recursiveBinarySearch(item, vetor, meio + 1, last);
}

int main() {
    int vetor[9] = {1,2,3,4,5,6,7,8,9};
    int tamanho = (sizeof(vetor) / sizeof(int)) - 1;
    cout << recursiveBinarySearch(2, vetor, 0, tamanho) << endl;
}
