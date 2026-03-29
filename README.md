# 💾 SIMULADOR DE DESHACER Y REHACER (PILAS)
> **Proyecto:** Tarea VI - Estructuras de Datos   

## 📝 Descripción del Proyecto
Este programa simula el comportamiento lógico de las funciones **Undo (Deshacer)** y **Redo (Rehacer)** que se encuentran en editores de texto modernos. Utiliza una arquitectura de **dos pilas dinámicas** para gestionar el historial de acciones del usuario de forma eficiente.

## ⚙️ Funcionamiento Lógico
El sistema se rige por las siguientes reglas de negocio:
* **Nueva Acción:** Se almacena en la pila principal y limpia automáticamente la pila de rehacer.
* **Deshacer (Undo):** Extrae el último elemento de la pila principal y lo traslada a la pila de rehacer.
* **Rehacer (Redo):** Recupera el último elemento deshecho y lo devuelve a la pila de historial principal.

## 💻 Detalles Técnicos
Para cumplir con los requisitos académicos, el desarrollo incluye:
* **Estructura Dinámica:** Implementación manual de nodos con punteros.
* **Gestión de Memoria:** Uso estricto de `new` y `delete` para evitar fugas de memoria.
* **Sin Librerías Externas:** No se utilizan contenedores STL, cumpliendo con la restricción de usar únicamente lógica propia de pilas.
