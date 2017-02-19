#ifndef LIST_H
#define LIST_H

template <typename D, typename P>
class List {
public:
    List() {}
    virtual ~List() {}

    virtual void insert(double d) = 0; //insertar
    virtual void remove(D d) = 0; //remover
    virtual P find(D d) = 0; //buscar
    virtual D get(P k) = 0; //obtener
    virtual void assign(P k, D d) = 0; //asignar
    virtual void sort() = 0; //ordenar
    virtual int getSize() = 0; //tamaño
    virtual void printList() = 0; //imprimir
    virtual P next(P k) = 0; //siguiente
    virtual P prev(P k) = 0; //anterior
    virtual void emptyList() = 0; //vaciar

protected:
    int n; //num. elementos
    P last; //ultimo

};

#endif /* LIST_H */

