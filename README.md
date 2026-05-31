# Cards Matching Game — SET

![C++](https://img.shields.io/badge/C++-Programaci%C3%B3n%20Estructurada-00599c?style=for-the-badge&logo=cplusplus)&nbsp;![Juego](https://img.shields.io/badge/Tipo-Juego%20de%20Cartas-orange?style=for-the-badge)&nbsp;![Ficheros](https://img.shields.io/badge/Lectura-Ficheros-green?style=for-the-badge)&nbsp;![Consola](https://img.shields.io/badge/Interfaz-Consola-lightgrey?style=for-the-badge)

> **Cards Matching Game** es una implementación en C++ del juego de cartas **SET**, desarrollado como proyecto final de la asignatura de Introducción a la Programación. El juego consiste en identificar combinaciones válidas de tres cartas según sus atributos visuales.

---

## 📋 Descripción del Proyecto

**Cards Matching Game** recrea el popular juego de cartas SET en modo consola, usando C++ con programación estructurada.  
Cada carta tiene cuatro atributos (número, color, forma y relleno), y el objetivo es encontrar grupos de tres cartas que formen un **SET válido**.

Las funcionalidades principales incluyen:

- **Inicializar** el mazo completo de cartas con todos sus atributos.
- **Repartir** cartas en el tablero de juego.
- **Validar** si tres cartas forman un SET válido.
- **Buscar** automáticamente SETs en el tablero.
- **Gestionar** el turno del jugador y la puntuación.
- **Mostrar** el estado del tablero en consola.

---

## 🏗️ Estructura del Proyecto

```txt
Cards_Matching_Game/
├── JuegoSet/                  # Código fuente principal
│   ├── *.cpp                  # Implementaciones de clases y lógica del juego
│   └── *.h                    # Cabeceras de las clases
├── IP2122_Proyecto_Set.pdf    # Enunciado oficial del proyecto
└── README.md                  # Documentación del proyecto
```

---

## ⚙️ Compilación y Ejecución

Clonar el repositorio:

```bash
git clone https://github.com/sorgazb/Cards_Matching_Game.git
cd Cards_Matching_Game/JuegoSet
```

Compilar con g++:

```bash
g++ -o set_game *.cpp
```

Ejecutar:

```bash
./set_game
```

---

## 🖥️ Ejemplos de Ejecución

<p align="center">
  <img src="https://github.com/sorgazb/Set_Game/assets/150727714/21dd29d0-207a-46f9-9c85-54cedb8e9985" alt="Ejemplo 1" width="600"/>
</p>

<p align="center">
  <img src="https://github.com/sorgazb/Set_Game/assets/150727714/11974eef-030f-416f-b058-553f9b55efdb" alt="Ejemplo 2" width="600"/>
</p>

---

## 🤝 Contribución

Haz fork del repositorio.

Crea una rama de trabajo:

```bash
git checkout -b feature/mi-nueva-funcionalidad
```

Realiza tus cambios y haz commit.

Abre un Pull Request describiendo tus mejoras.

---

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/c/cc/UNEX.png" alt="Universidad de Extremadura" height="80"/>
  <br/><br/>
  <strong>Introducción a la Programación (IP)</strong> &nbsp;&middot;&nbsp; Grado en Ingeniería Informática en Computadores &nbsp;&middot;&nbsp; Universidad de Extremadura
  <br/>
  Sergio Orgaz Bravo
</p>
