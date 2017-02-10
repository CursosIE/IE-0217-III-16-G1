#include <cstdlib>
#include "Node.h"
#include "Tree.h"

#define NL cout << endl
#define SP " "

using namespace std;

int main(int argc, char** argv) {
//tiempos de ejecucion
    Tree<int>* T = new Tree<int>();//1

    // L,R,P,D
    Node<int>* _2 = new Node<int>(0x0, 0x0, 0x0, new int(2));//5
    Node<int>* _5 = new Node<int>(0x0, 0x0, 0x0, new int(5));//5
    Node<int>* _7 = new Node<int>(0x0, 0x0, 0x0, new int(7));//5
    Node<int>* _10 = new Node<int>(0x0, 0x0, 0x0, new int(10));//5
    Node<int>* _15 = new Node<int>(0x0, 0x0, 0x0, new int(15));//5
    Node<int>* _20 = new Node<int>(0x0, 0x0, 0x0, new int(20));//5
    Node<int>* _25 = new Node<int>(0x0, 0x0, 0x0, new int(25));//5


    _2->L = 0x0;//1
    _2->R = 0x0;//1
    _2->P = _5;//1
    _5->L = _2;//1
    _5->R = _10;//1
    _5->P = 0x0;//1
    _7->L = 0x0;//1
    _7->R = 0x0;//1
    _7->P = _10;//1
    _10->L = _7;//1
    _10->R = _20;//1
    _10->P = _5;//1
    _15->L = 0x0;//1
    _15->R = 0x0;//1
    _15->P = _20;//1
    _20->L = _15;//1
    _20->R = _25;//1
    _20->P = _10;//1
    _25->L = 0x0;//1
    _25->R = 0x0;//1
    _25->P = _20;//1

    T->root = _5;//1


    T->preOrder();
    NL;//1
    
    T->balance();
    
    T->preOrder();
    NL;//1

    return 0;
}

