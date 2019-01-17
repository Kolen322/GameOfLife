#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GameWidget= new game();
    ui->verticalLayout->addWidget(GameWidget);
    connect(ui->start,SIGNAL(clicked()),GameWidget,SLOT(startgame()));
    connect(ui->stop,SIGNAL(clicked()),GameWidget,SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

