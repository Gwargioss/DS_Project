#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QMainWindow>
#include "Graph.cpp"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addEdgeButton_clicked();

    void on_addCityButton_clicked();

    void on_graphTraverseButton_clicked();

    void on_shortestButton_clicked();


    void on_loadButton_clicked();

    void on_cityButton_clicked();

    void on_edgeButton_clicked();

    void on_traverseButton_clicked();

   void on_findButton_clicked();

    void on_exitButton_clicked();

    void on_deletevertexButton_clicked();

    void on_deleteedgeButton_clicked();

    void on_deleteButton_clicked();

    void on_displayButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
     Graph<std::string> *cityGraph;
    void setupConnections();
};
#endif // MAINWINDOW_H
