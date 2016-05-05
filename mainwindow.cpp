#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createTray();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
}

void MainWindow::createTray(){

    //create tray
    tray= new QSystemTrayIcon(this);

    //setup tray icon
    QPixmap icon(":/pencil.png");
    trayIcon= QIcon(icon);
    tray->setIcon(trayIcon);
    tray->setToolTip("ToolTip");

    //setup restore
    restoreAction = new QAction(QIcon(":/pencil.png"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));

    //create system tray menu
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    tray->setContextMenu(trayIconMenu);

    tray->setVisible(true);
}
