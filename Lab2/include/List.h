/**
 * @brief Libreria que genera un template de una clase abstracta list
 * @author Luis Adrian Aguilar - B00092
 * @author Robin Gonzalez Ricz - B43011
 * @author Giancarlo Marin - B54099
 * @date 21-02-2017	
 */
#ifndef LIST_H
#define LIST_H

template <typename D, typename P> /**Libreria que genera un template de una clase abstracta list que toma un tipo de dato para los datos contenidos en la lista (D) y otro para los indices de las misma (P)*/
class List {
public:
/**
 * Constructor de la clase List
 */
    List() {} 
/**
 * Destructor de la clase List
 */
    virtual ~List() {}
/**
 * Metodo virtual puro para insercion de datos en List
 * @param d 	Dato de tipo D que se desea insertar en List 
 */
    virtual void insert(D d) = 0;

/**
 * Metodo virtual puro para la remocion de un dato especifico de List
 * @param d 	Dato de tipo D que se desea remover de List 
 */
    virtual void remove(D d) = 0;

/**
 * Metodo virtual puro para la busqueda de un dato especifico en List
 * @param d 	Dato que se desea buscar en List
 * @return 	Indice de tipo P dentro de List
 */
    virtual P find(D d) = 0;

/**
 * Metodo virtual puro para obtener un dato en List
 * @param k 	Indice de tipo P dentro de List del que se desea obtener dato
 * @return 	Dato contenido en k de tipo D  
 */
    virtual D get(P k) = 0;

/**
 * Metodo virtual puro para asignar un valor especifico a un dato en List
 * @param k 	Indice de tipo P dentro de list donde se asignara el nuevo valor 
 * @param d	Dato de tipo D que se asigna en la posicion k 
 */
    virtual void assign(P k, D d) = 0;

/**
 * Metodo virtual puro para ordenar List
 */
    virtual void sort() = 0; //ordenar

/**
 * Metodo virtual puro para obtener el tamaño de List
 */
    virtual int getSize() = 0;

/**
 * Metodo virtual puro para imrprimir List
 */
    virtual void printList() = 0;

/**
 * Metodo virtual puro para obtener el siguiente elemento de una posicion especifica de List
 * @param k 	Indice de tipo P dentro de List del que se desea el siguiente elemento 
 * @return 	Siguiente elemento de k de tipo P
 */
    virtual P next(P k) = 0;

/**
 * Metodo virtual puro para obtener el elemento anterior de una posicion especifica de List
 * @param k 	Indice de tipo P dentro de List del que se desea el elemento anterior
 * @return 	Elemento anterior de k de tipo P
 */
    virtual P prev(P k) = 0;

/**
 * Metodo virtual puro para vaciar List: Deja sin ningun elemento List
 */
    virtual void emptyList() = 0;

protected:
    int n; /**<Atrib. protegido de tipo entero que indica el numero de elementos en list*/
    P last; /**<Atrib. protegido de tipo P que indica el indice del ultimo elemento de list*/

};

#endif /* LIST_H */

