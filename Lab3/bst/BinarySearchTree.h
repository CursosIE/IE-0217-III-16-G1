#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename Data>
class BinarySearchTree {
public:

    BinarySearchTree() {
    }

    BinarySearchTree(Node<Data>* r) {
        this->root = r;
    }

    BinarySearchTree(Data* d) {
        this->root = new Node<Data>(nullptr, nullptr, d, nullptr);
    }

    BinarySearchTree(const BinarySearchTree& orig) {
    }

    virtual ~BinarySearchTree() {
    }

    void insert(Data* d) {
        if (this->root == nullptr) {
            root = new Node<Data>(nullptr, nullptr, d, nullptr);
        } else {
            Node<Data>* t = root;
            bool end = 0;
            while (!end) {
                if (*d < *(t->d)) {
                    if (t->l == nullptr) {
                        t->l = new Node<Data>(nullptr, nullptr, d, t);
                        end = 1;
                    } else {
                        if (t->l != nullptr) {
                            t = t->l;
                        }
                    }
                } else {
                    if (t->r == nullptr) {
                        t->r = new Node<Data>(nullptr, nullptr, d, t);
                        end = 1;
                    } else {
                        if (t->r != nullptr) {
                            t = t->r;
                        }
                    }
                }
            }
        }
    }

    void removing(Node<Data>* n) {
        if (n && n->l == n->r && n->r == nullptr) // es hoja?
        {
            delete n; // =)
        } else {
            Node<Data>* t = replacementFor(n);
            if (t) {
                *(n->d) = *(t->d);
                removing(t);
            }
        }
    }

    void remove(Data* d) {
        removing(find(d));
    }

    Data* get(Node<Data>* n) {
	return n->d;
    }

    void set(Node<Data>* n, Data * d) {
	n->d = d;
    }

    Node<Data>* finding(Data* d, Node<Data>* n) {
        if (n && *(n->d) == *d) {

            return n;
        } else {
            if (n && *(n->d) > *d) {
                return finding(d, n->l);
            } else {
                if (n) {
                    return finding(d, n->r);
                } else {
                    return nullptr;
                }
            }
        }
    }

    Node<Data>* find(Data* d) {
        return finding(d, this->root);
    }

    void balance() {
    }

    Node<Data>* replacementFor(Node<Data>* n) {
        if (n) {
            if (n->l) {
                return maxLesser(n);
            } else {
                if (n->r) {
                    return minGreater(n);
                }
            }
        }
        return nullptr;
    }

    Node<Data>* minGreater(Node<Data>* n) {
        Node<Data>* t = n->r;
        while (t->l) {
            t = t->l;
        }
        return t;
    }

    Node<Data>* maxLesser(Node<Data>* n) {

        Node<Data>* t = n->l;

        while (t->r) {
            t = t->r;
        }
        return t;
    }

    void printTree() {
	cout << "Printed tree:" << endl;
	inO(this->root, "\t");
    }

	void inOrder(){
	cout << "InOrder" << endl;
		inO(this->root, "\t");
	}

    void inO(Node<Data>* n, string s) {
        if (n) {
            cout << s << *(n->d) << "@" << n << endl;
            inO(n->r, s + "\t");
            inO(n->l, s + "\t");
        }

    }

    void postOrder() {
	cout << "PostOrder" << endl;
	postO(this->root,"\t");
    }
	void postO(Node<Data>* n, string s){
		if(n){
			postO(n->l, s + "\t");
			postO(n->r, s + "\t");
			cout<< s<< *(n->d) << "@" << n <<endl;
		}
			
	}

    void preOrder() {
	cout << "PreOrder" << endl;
	preO(this->root,"\t");
    }
	
	void preO(Node<Data>* n, string s){
		if(n){
			cout<< s<< *(n->d) << "@" << n <<endl;
			preO(n->l, s + "\t");
			preO(n->r, s + "\t");
		}
			
	}

    Node<Data>* root;
    int level, nodes;
};

#endif /* BINARYSEARCHTREE_H */

