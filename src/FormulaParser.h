#pragma once
#include "SparseMatrix.h"
#include <string>
#include <stdexcept>


namespace CellAddress {


    inline std::string colToStr(int col) {
        std::string result;
        col++;
        while (col > 0) {
            col--;
            result = char('A' + col % 26) + result;
            col /= 26;
        }
        return result;
    }


    inline int strToCol(const std::string& s) {
        int result = 0;
        for (char c : s) result = result * 26 + (toupper(c) - 'A' + 1);
        return result - 1;
    }


    inline std::pair<int,int> parse(const std::string& ref) {
        if (ref.empty()) throw std::invalid_argument("Referencia vacía.");
        size_t i = 0;
        std::string colStr;
        while (i < ref.size() && isalpha(ref[i])) colStr += toupper(ref[i++]);
        if (colStr.empty() || i == ref.size())
            throw std::invalid_argument("Referencia de celda inválida: " + ref);
        int rowNum = std::stoi(ref.substr(i)) - 1;
        int colNum = strToCol(colStr);
        if (rowNum < 0 || colNum < 0)
            throw std::invalid_argument("Coordenadas negativas en: " + ref);
        return {rowNum, colNum};
    }


    inline std::string toString(int row, int col) {
        return colToStr(col) + std::to_string(row + 1);
    }
}



class FormulaParser {
public:

    static std::string evaluate(const std::string& formula,
                                const SparseMatrix& matrix);

private:
    const std::string& src;
    size_t pos;
    const SparseMatrix& matrix;

    FormulaParser(const std::string& s, const SparseMatrix& m)
        : src(s), pos(0), matrix(m) {}

    double parseExpression();
    double parseTerm();
    double parseFactor();

    void skipSpaces();
    double readNumber();
    double readCellRef();
    char peek();
    char consume();
};
