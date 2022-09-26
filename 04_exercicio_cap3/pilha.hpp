#include <iostream>

using namespace std;

template <typename T>

class Pilha {
    public:
        int max;
        int topo;
        T * item;

        Pilha(int tamanho) {
            max = tamanho;
            topo = -1;
            item =  new T[tamanho];
        }

        bool vazia() {
            return topo == -1;
        }

        bool cheia() {
            return topo == max-1;
        }

        T getTopo() {
            return item[topo];
        }

        void push(T itemp) {
            if( !cheia()) {
                topo++;
                item[topo] = itemp;
            }
        }

        T pop() {
            if( !vazia()) {
                T itemT = item[topo];
                topo--;
                
                return itemT;
            }
            
        }

        void fullUnstack() {
            while (!cheia()){
                cout << pop() << endl;
            }
            
        }
};

// template <class V>
// void destruirPilha(Pilha<V>* pilha) {
//     free(*pilha->item);
//     free(pilha);
// }

// int main() {
//     Pilha<char> pilha(5);

//     cout << pilha.max << endl;
//     pilha.push('a');
//     cout << pilha.item[pilha.topo] << endl;
//}


