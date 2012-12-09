/* 
 * File:   Avl.h
 * Author: javier
 *
 * Created on 7 de diciembre de 2012, 10:08
 */

#ifndef AVL_H
#define	AVL_H

#include <vector>
#include <stack>

using namespace std;

template <class T> class Avl;

template <class T>
class Nodo {
    friend class Avl<T>;
    
    Nodo<T> *izq, *der;
    short bal;
    T dato;

private:
    Nodo(): izq(0), der(0), bal(0) {
    }
    
    Nodo(const T &dato): izq(0), der(0), bal(0), dato(dato) {
    }
    
}; // EOC Nodo

template <class T>
class Avl {
    Nodo<T> *raiz;
    
public:
    Avl(): raiz(0) {
    }
    
    virtual ~Avl() {
        // Recorrido postOrden no recursivo con 2 pilas
        stack< Nodo<T>* > s;
        stack< Nodo<T>* > z;
        
        s.push(raiz);
        
        while ( !s.empty() ) {
            Nodo<T> *p = s.top();
            z.push(p);
            s.pop();
            
            if ( p->izq ) {
                s.push(p->izq);
            }
            if ( p->der ) {
                s.push(p->der);
            }
        }
        
        while ( !z.empty() ) {
            delete z.top();
            z.pop();
        }
    }
    
    bool insertar(const T &dato) {
        return _insertar(dato, raiz);
    }
    
    pair<T*,bool> buscar( const T &ele ) {
        Nodo<T> *p = _buscar(ele, raiz);
        if (p) {
            return pair<T*,bool>(&(p->dato),true);
        }
        return pair<T*,bool>(0,false);
    }
    
    vector<T> obtenerEntradas() {
        vector<T> output;
        
        // Recorrido del árbol mediante inorden no recursivo
        Nodo<T> *p = raiz;
        stack < Nodo<T>* > pila;
     
        bool delta = true;
        while (delta) {
            if (p) {
                pila.push(p);
                p = p->izq;
            }
            else {
                if ( !pila.empty() ) {
                    p = pila.top();
                    pila.pop();
                    
                    output.push_back(p->dato);
                    p = p->der;
                }
                else {
                    delta = false;
                }
            }
        }
        
        return output;
    }
    
private:
    bool _insertar(const T &dato, Nodo<T>* &c) {
        Nodo<T> *p = c;
        bool delta = false;

        // solo insertaramos cuando p = 0 (llegamos al final de la rama)
        if (!p) {
            p = new Nodo<T > (dato);
            c = p;
            delta = true;
        } else if (dato > p->dato) {
            if (_insertar(dato, p->der)) {
                p->bal++;
                if (p->bal == 1) {
                    delta = true;
                } else if (p->bal == 2) {
                    if (p->der->bal == -1) {
                        _rotarDer(p->der);
                    }
                    _rotarIzq(c);
                }
            }
        } else if (dato < p->dato) {
            if (_insertar(dato, p->izq)) {
                p->bal--;
                if (p->bal == -1) {
                    delta = true;
                } else if (p->bal == -2) {
                    if (p->izq->bal == 1) {
                        _rotarIzq(p->izq);
                    }
                    _rotarDer(c);
                }
            }
        }

        return delta;
    }
    
    Nodo<T> *_buscar(const T &ele, Nodo<T> *p) {
        if (!p) {
            return 0;
        }
        else if (ele < p->dato) {
            return _buscar(ele, p->izq);
        }
        else if (ele > p->dato) {
            return _buscar(ele, p->der);
        }
        return p;
    }
    
    void _rotarIzq(Nodo<T>* &p) {
        Nodo<T> *q = p, *r;

        p = r = q->der;
        q->der = r->izq;
        r->izq = q;

        q->bal--;
        if (r->bal > 0) {
            q->bal -= r->bal;
        }

        r->bal--;
        if (q->bal < 0) {
            r->bal += q->bal;
        }
    }

    void _rotarDer(Nodo<T>* &p) {
        Nodo<T> *q = p, *l;

        p = l = q->izq;
        q->izq = l->der;
        l->der = q;

        q->bal++;
        if (l->bal < 0) {
            q->bal -= l->bal;
        }

        l->bal++;
        if (q->bal > 0) {
            l->bal += q->bal;
        }
    }

};

#endif	/* AVL_H */

