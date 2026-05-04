#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QLabel>
#include <QStatusBar>
#include <QAction>
#include <QToolBar>
#include "SparseMatrix.h"
#include "FormulaParser.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override = default;

private slots:

    void onCellSelected(int row, int col);
    void onFormulaBarReturnPressed();
    void onTableCellChanged(int row, int col);


    void onDeleteRow();
    void onDeleteColumn();
    void onDeleteRange();


    void onSumRow();
    void onSumColumn();
    void onSumRange();
    void onAvgRow();
    void onAvgColumn();
    void onAvgRange();
    void onMaxRange();
    void onMinRange();


    void onAbout();

private:

    SparseMatrix matrix;


    QTableWidget*  table;
    QLineEdit*     formulaBar;
    QLabel*        cellLabel;
    QStatusBar*    statusBar;


    bool blockTableSignals = false;


    static constexpr int INIT_ROWS = 50;
    static constexpr int INIT_COLS = 26;


    void setupUi();
    void setupMenuBar();
    void setupToolBar();


    void refreshTable();


    std::pair<int,int> currentCell() const;


    void status(const QString& msg);


    static QString colHeader(int col);


    void styleCell(int row, int col, bool occupied);


    void ensureSize(int row, int col);


    std::string displayValue(int row, int col);


    std::pair<int,int> askCellRef(const QString& title, bool* ok = nullptr);


    int askRow(const QString& title, bool* ok = nullptr);


    int askCol(const QString& title, bool* ok = nullptr);


    std::tuple<int,int,int,int> askRange(const QString& title, bool* ok = nullptr);
};
