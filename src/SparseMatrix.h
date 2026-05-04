#pragma once
#include "Cell.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>
#include <stdexcept>

class SparseMatrix {
public:
    SparseMatrix();
    ~SparseMatrix();

    void insertCell(int row, int col, const std::string& value);

    std::string queryCell(int row, int col) const;

    bool modifyCell(int row, int col, const std::string& value);


    bool deleteCell(int row, int col);


    void deleteRow(int row);

    void deleteColumn(int col);


    void deleteRange(int r1, int c1, int r2, int c2);


    double sumRow(int row) const;
    double sumColumn(int col) const;
    double sumRange(int r1, int c1, int r2, int c2) const;

    double avgRow(int row) const;
    double avgColumn(int col) const;
    double avgRange(int r1, int c1, int r2, int c2) const;

    double maxRange(int r1, int c1, int r2, int c2) const;
    double minRange(int r1, int c1, int r2, int c2) const;


    std::vector<Cell*> getAllCells() const;

    int getMaxRow() const;
    int getMaxCol() const;
    bool isEmpty() const;

private:

    std::unordered_map<int, Cell*> rowHeaders;

    std::unordered_map<int, Cell*> colHeaders;


    Cell* findCell(int row, int col) const;


    Cell* findPrevInRow(int row, int col) const;


    Cell* findPrevInCol(int row, int col) const;


    void unlinkFromRow(Cell* node);


    void unlinkFromCol(Cell* node);


    static bool toDouble(const std::string& value, double& out);
};
