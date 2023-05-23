# Lista Enlazada Simple (Single Linked List)

## Descripción

En las ciencias de la computación y la programación las listas son unas de las estructuras de datos fundamentales y sencillas de implementar. A menudo son utilizadas como base para otras estructuras de datos más complejas.

Una lista enlazada es una colección lineal de elementos creados dinámicamente llamados Nodos. Lineal por que a cada elemento le puede seguir sólo otro elemento y dinámicas por que se puede manejar la memoria de manera flexible, sin necesidad de reservar una cantidad de memoria especifica anticipadamente.


Los `nodos` son los elementos que almacenan los datos y la referencia hacia el elemento siguiente, y la `lista` como tal es una referencia al primer nodo de la colección, también llamado `cabeza`.


<img src="_media/single_linked_list.jpg"
     alt="Markdown Monster icon"
     width="95%"
     style="margin: 5%;" />


---

## Operaciones sobre listas

### [Búsqueda](#bc3basqueda-1)
- Buscar un elemento dado un valor
- Buscar un elemento dado un índice

### [Inserción](#insercic3b3n-1)
- [Insertar un elemento al inicio de la lista](#inserción-al-inicio-de-la-lista)
- [Insertar un elemento al final de la lista](#inserción-al-final-de-la-lista)
- [Insertar un elemento después de otro elemento](#inserción-después-de-un-elemento)
- [Insertar un elemento antes de otro elemento](#inserción-antes-de-un-elemento)

### [Eliminación](#eliminacic3b3n-1)
- Eliminar el primer elemento de la lista
- Eliminar el último elemento de la lista
- Eliminar todos los elementos de una lista

---

# Búsqueda

### Búsqueda de un elemento dado un valor
| Complejidad   |        |
| :---          | :---:  |
| Mejor caso    | `O(1)` |
| Peor caso     | `O(n)` |
|
---
### Búsqueda de un elemento dado un índice
| Complejidad   |        |
| :---          | :---:  |
| Mejor caso    | `O(1)` |
| Peor caso     | `O(n)` |
|
---

# Inserción

### Inserción al inicio de la lista

| Complejidad   |        |
| :---          | :---:  |
| Constante     | `O(1)` |
|

Existen 2 casos en los que se puede realizar una inserción `al inicio` de
una lista:

- Caso 1: Lista vacía
<img src="_media/head_insertion_case_1.jpg"
     alt="Head insertion case 1"
     width="95%"
     style="margin: 5%;" />

- Caso 2: Lista no vacía
<img src="_media/head_insertion_case_2.jpg"
     alt="Head insertion case 1"
     width="95%"
     style="margin: 5%;" />




---

### Inserción al final de la lista

| Complejidad   |        |
| :---          | :---:  |
| Mejor caso    | `O(1)` |
| Peor caso     | `O(n)` |
|

Al igual que la inserción al inicio, la inserción `al final` tiene los mismos 2 casos:

- Caso 1: Lista vacía
<img src="_media/head_insertion_case_1.jpg"
     alt="Head insertion case 1"
     width="95%"
     style="margin: 5%;" />

- Caso 2: Lista no vacía
<img src="_media/tail_insertion_case_2.jpg"
     alt="Head insertion case 1"
     width="95%"
     style="margin: 5%;" />

---

### Inserción después de un elemento

| Complejidad   |        |
| :---          | :---:  |
| Mejor caso    | `O(1)` |
| Peor caso     | `O(n)` |
|

Existen 3 casos a considerar en los que se puede realizar una inserción `después` de un elemento de una lista:


- Caso 1: Lista vacía

        El nuevo elemento no se inserta en la lista.

- Caso 2: El elemento a buscar no existe en la lista

        El nuevo elemento no se inserta en la lista.

- Caso 3: El elemento a buscar si existe en la lista
<img src="_media/after_insertion_case.jpg"
     alt="Head insertion case 1"
     width="95%"
     style="margin: 5%;" />

---

### Inserción antes de un elemento

| Complejidad   |        |
| :---          | :---:  |
| Mejor caso    | `O(1)` |
| Peor caso     | `O(n)` |
|

Existen 3 casos a considerar en los que se puede realizar una inserción `antes` de un elemento de una lista:


- Caso 1: Lista vacía

        El nuevo elemento no se inserta en la lista.

- Caso 2: El elemento a buscar no existe en la lista

        El nuevo elemento no se inserta en la lista.

- Caso 3: El elemento a buscar si existe en la lista
<img src="_media/before_insertion_case.jpg"
     alt="Head insertion case 1"
     width="95%"
     style="margin: 5%;" />


---

# Eliminación

### Eliminación del primer elemento de la lista
| Complejidad   |        |
| :---          | :---:  |
| Constante    | `O(1)` |
|
---

### Eliminación del último elemento de la lista
| Complejidad   |        |
| :---          | :---:  |
| Constante    | `O(1)` |
|




## Ejemplos de esrtucturas de datos para manejo de listas


### Implementación en C

```c
// Datos a almacenar
typedef struct item {
    int value;
} item_t;


// Estructura de datos para el nodo
typedef struct node {
    item_t *item;
    struct node *next;
} node_t;


// Estructura de datos para la lista
typedef struct list {
    node_t* head;
} list_t;
```

### Implementación en C++

```c++

// Datos a almacenar
class Item {
    int value;
};


// Clase para el nodo
class Node {
    public:
    Item *item;
    Node *next;
}


// Clase para la lista
class List {
    public:
    Node * head;
}
```

### Implementación en Go

```golang

//Datos a almacenar
type Item struct {
    value int
}


// Estructura para el nodo
type Node struct {
    item *Item
    next *Node
}


// Estructura para la lista
type List struct {
    head *Node
}
```


### Implementación en Python

```python
from __future__ import annotations


class Item:
    """ Datos a almacenar """
    value: int


class Node:
    """ Clase para el nodo """
    item: Item
    node: Node


class List:
    """ Clase para la lista """
    head: Node

```


# Ejercicios


| Problema                                                          | Dificultad |
|:---                                                               | :---:      |
| Comparar 2 listas para conocer si son iguales                     | 😎         |
| Imprimir la lista en orden ascendente                             | 😎         |
| Eliminar todos los elementos de una lista                         | 😎         |
| Ontener el número de elementos de una lista                       | 😎         |
| Mover el primer elemento de una lista al final (shift left)       | 😎         |
| Mover el último elemento de una lista al inicio (shift right)     | 🤔         |
| Imprimir la lista en orden descendente                            | 🤔         |
| Unir 2 listas, una al final de la segunda (join)                  | 🤔         |
| Obtener el número de elementos de una lista que cumpla con `O(1)` | 🤔         |
| Dividir una lista por la mitad y devolver las 2 sub-listas        | 🤔         |
| Hacer la [Unión, Intersección y Diferencia](https://es.wikipedia.org/wiki/%C3%81lgebra_de_conjuntos) de 2 listas | 🥵         |
| Mejorar la inserción al final para que cumpla con `O(1)`          | 🥵         |
| Invertir los elementos de una lista (reverse)                     | 🥵         |