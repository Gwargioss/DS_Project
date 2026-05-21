#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cityGraph = new Graph<std::string>();
     setupConnections();
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::setupConnections()
{
    connect(ui->addEdgeButton, &QPushButton::clicked, this, &MainWindow::on_addEdgeButton_clicked);
    connect(ui->addCityButton, &QPushButton::clicked, this, &MainWindow::on_addCityButton_clicked);
    connect(ui->graphTraverseButton, &QPushButton::clicked, this, &MainWindow::on_graphTraverseButton_clicked);
     connect(ui->shortestButton, &QPushButton::clicked, this, &MainWindow::on_shortestButton_clicked);
     connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
     connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
     connect(ui->displayButton, &QPushButton::clicked, this, &MainWindow::on_displayButton_clicked);
     connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::on_exitButton_clicked);
    // action button connections
    connect(ui->cityButton, &QPushButton::clicked, this, &MainWindow::on_cityButton_clicked);
     connect(ui->edgeButton, &QPushButton::clicked, this, &MainWindow::on_edgeButton_clicked);
    connect(ui->traverseButton, &QPushButton::clicked, this, &MainWindow::on_traverseButton_clicked);
     connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::on_findButton_clicked);
    connect(ui->deletevertexButton, &QPushButton::clicked, this, &MainWindow::on_deletevertexButton_clicked);
     connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::on_loadButton_clicked);

     connect(ui->deleteedgeButton, &QPushButton::clicked, this, &MainWindow::on_deleteedgeButton_clicked);
}
// going to specific page
void MainWindow::on_addEdgeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_addCityButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
bool functionRunning3 = false;

void MainWindow::on_graphTraverseButton_clicked(){
    if (functionRunning3){
        functionRunning3 = false;
        return;
    }

    functionRunning3 = true;
    for(auto & key : cityGraph->getGraph()){
        ui->startBox->addItem(QString::fromStdString(key.first));
}
   ui->stackedWidget->setCurrentIndex(2);

}
bool functionRunning4 = false;
void MainWindow::on_shortestButton_clicked()
{    if (functionRunning4){
        functionRunning4 = false;
        return;
    }

    functionRunning4 = true;
    for(auto & key : cityGraph->getGraph()){
        ui->sourceBox->addItem(QString::fromStdString(key.first));
        ui->destinationBox->addItem(QString::fromStdString(key.first));

    }
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_deleteButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_displayButton_clicked()
{
 ui->stackedWidget->setCurrentIndex(7);
    QString graphText;
 for (const auto& element : cityGraph->getGraph()) {
        graphText += QString::fromStdString(element.first + " : ");
        for (const auto& inner : element.second) {
            graphText += QString::fromStdString(inner.first + " ");
        }
        graphText += "\n";
    }
        ui->graphDisplayTextEdit->setText(graphText);
}



void MainWindow::on_saveButton_clicked()
{
   cityGraph->saveGraph();
   ui->loadResultText->setPlainText("Graph saved successfully.");
  ui->stackedWidget->setCurrentIndex(4);

}

// addcity
bool functionRunning = false;

void MainWindow::on_cityButton_clicked()
{
    if (functionRunning){
         functionRunning = false;
        return;
    }
         // Prevent re-entrant call
    functionRunning = true;
QString city = ui->cityEdit->text();
ui->cityButton->setAutoRepeat(false);
if (city.isEmpty()) {
    QMessageBox::warning(this, "Input Error", "Please enter a city name.");
    return;
}

bool added = cityGraph->addVertex(city.toStdString());

if (added) {
    QMessageBox::information(this, "Success", "City added successfully!");

} else {
    QMessageBox::warning(this, "Duplicate", "This city already exists.");

}
ui->cityEdit->clear();
}
// addedge
bool functionRunning2 = false;

void MainWindow::on_edgeButton_clicked()
{    if (functionRunning2){
        functionRunning2 = false;
        return;
    }
    // Prevent re-entrant call
    functionRunning2 = true;
    // Get input values
    QString city1 = ui->frcityEdit->text();
    QString city2 = ui->secityEdit->text();
    QString distance = ui->distanceEdit->text();

   if (distance.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a distance value.");
        return;
    }
    int  distanceint = distance.toInt();
    if(city1.isEmpty() || city2.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both cities!");
        return;
    }
  bool added = cityGraph->addEdge(city1.toStdString(),city2.toStdString(),distanceint);
    if(added){
    QMessageBox::information(this,"succes", "Edge added successfully!");

    }
    else{
        QMessageBox::warning(this, "Error", "cities not exist");
        return;
    }


    ui->frcityEdit->clear();
    ui->secityEdit->clear();
    ui->distanceEdit->clear();
}

//traversal
 void MainWindow::on_traverseButton_clicked()
 {   QString result;
     QString startCity = ui->startBox->currentText();
    if (ui->bfsButton->isChecked()) {

     result = QString::fromStdString( cityGraph->bfsTraversal(startCity.toStdString()));

   } else if (ui->dfsButton->isChecked()) {

        result = QString::fromStdString(cityGraph->DFS(startCity.toStdString()));
     }


    ui->resultTraverse->setText("Traversal result...\n"+result);
}






// short and cheap(dijestra and fillmin)
 void MainWindow::on_findButton_clicked()
{
    QString source = ui->sourceBox->currentText();
     QString destination = ui->destinationBox->currentText();
    QString result;
     if (ui->shortradioButton->isChecked()){
 result = QString::fromStdString( cityGraph->dijkstraShortestPath(source.toStdString(),destination.toStdString()));
    }
     else if(ui->cheapradioButton->isChecked()){
        result = QString::fromStdString( cityGraph->bellmanFordShortestPath(source.toStdString(),destination.toStdString()));
    }

       ui->resultShortest->setText(" path result...\n"+result);
 }

void MainWindow::on_exitButton_clicked()
{
      QApplication::quit();
}

bool functionRunning5=false;
void MainWindow::on_deletevertexButton_clicked()
{ if (functionRunning5){
        functionRunning5 = false;
        return;
    }
    // Prevent re-entrant call
    functionRunning5 = true;
   std::string v = ui->deleteVertexInput->text().toStdString();
    if (cityGraph->getGraph().find(v) == cityGraph->getGraph().end()) {
        QMessageBox::warning(this, "Delete Vertex", "Vertex doesn't exist.");
        return;
    }
    cityGraph->removeVertex(v);
    QMessageBox::information(this, "Delete Vertex", "Vertex deleted successfully.");
    ui->deleteVertexInput->clear();

}

bool functionRunning6=false;
void MainWindow::on_deleteedgeButton_clicked()
{if (functionRunning5){
        functionRunning5 = false;
        return;
    }
    // Prevent re-entrant call
    functionRunning5 = true;
    std::string v1 = ui->deleteEdgeV1Input->text().toStdString();
    std::string v2 = ui->deleteEdgeV2Input->text().toStdString();
    if (cityGraph->getGraph().find(v1) == cityGraph->getGraph().end() || cityGraph->getGraph().find(v2) == cityGraph->getGraph().end()) {
        QMessageBox::warning(this, "Delete Edge", "One or both vertices don't exist.");
        ui->deleteEdgeV1Input->clear();
        ui->deleteEdgeV2Input->clear();
        return;
    }
   cityGraph->removeEdge(v1, v2);
    QMessageBox::information(this, "Delete Edge", "Edge deleted successfully.");
   ui->deleteEdgeV1Input->clear();
    ui->deleteEdgeV2Input->clear();
}







void MainWindow::on_loadButton_clicked()
{bool loaded=cityGraph->loadGraph();
    if(loaded){
    ui->loadEdit->setText("Data Successfully Loaded");
    }else{
        ui->loadEdit->setText("Can`t Open File");
    }
    ui->stackedWidget->setCurrentIndex(8);
}


MainWindow::~MainWindow()
{
    delete cityGraph;
    delete ui;

}
