#pragma once
#include <string>


struct Cell {
    int row;           // Fila (0-indexed internamente)
    int col;           // Columna (0-indexed internamente)
    std::string value; // Valor almacenado (numérico o texto)
    Cell* nextInRow;   // Siguiente nodo en la misma fila
    Cell* nextInCol;   // Siguiente nodo en la misma columna

    Cell(int r, int c, const std::string& v)
        : row(r), col(c), value(v),
          nextInRow(nullptr), nextInCol(nullptr) {}
};
