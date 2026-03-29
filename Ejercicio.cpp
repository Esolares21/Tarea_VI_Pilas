#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    string accion;
    Nodo* siguiente;
};

void mostrarUsuario() {
    cout << "========================================" << endl;
    cout << "   Erix Alejandro Solares Flores  " << endl;
    cout << "   CARNE: 9941-20-23978                " << endl;
    cout << "========================================" << endl;
}

void push(Nodo*& pila, string valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->accion = valor;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

string pop(Nodo*& pila) {
    if (pila == NULL) return "";
    Nodo* aux = pila;
    string valor = aux->accion;
    pila = aux->siguiente;
    delete aux;
    return valor;
}

void limpiarPila(Nodo*& pila) {
    while (pila != NULL) {
        pop(pila);
    }
}

void mostrarPila(Nodo* pila, string nombrePila) {
    if (pila == NULL) {
        cout << " La " << nombrePila << " esta vacia." << endl;
        return;
    }
    cout << "--- " << nombrePila << " ---" << endl;
    Nodo* aux = pila;
    while (aux != NULL) {
        cout << " - " << aux->accion << endl;
        aux = aux->siguiente;
    }
}

int main() {
    Nodo* pilaPrincipal = NULL;
    Nodo* pilaRehacer = NULL;
    int opcion;
    string nuevaAccion;

    do {
        mostrarUsuario();
        cout << "1. Realizar accion" << endl;
        cout << "2. Deshacer (Undo)" << endl;
        cout << "3. Rehacer (Redo)" << endl;
        cout << "4. Mostrar acciones actuales" << endl;
        cout << "5. Mostrar pila de rehacer" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Describe la accion: ";
                getline(cin, nuevaAccion);
                push(pilaPrincipal, nuevaAccion);
                limpiarPila(pilaRehacer);
                cout << " Accion guardada." << endl;
                break;

            case 2:
                if (pilaPrincipal != NULL) {
                    string deshecho = pop(pilaPrincipal);
                    push(pilaRehacer, deshecho);
                    cout << " Se deshizo: " << deshecho << endl;
                } else {
                    cout << " No hay acciones para deshacer." << endl;
                }
                break;

            case 3:
                if (pilaRehacer != NULL) {
                    string rehecho = pop(pilaRehacer);
                    push(pilaPrincipal, rehecho);
                    cout << " Se rehizo: " << rehecho << endl;
                } else {
                    cout << " No hay nada para rehacer." << endl;
                }
                break;

            case 4:
                mostrarPila(pilaPrincipal, "Pila de Acciones");
                break;

            case 5:
                mostrarPila(pilaRehacer, "Pila de Rehacer");
                break;

            case 6:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 6);

    return 0;
}