#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    resize(600,400);

    QMenuBar* mainMenuBar = menuBar();
    QMenu* fileMenu = mainMenuBar->addMenu(tr("&File"));
    QToolBar* fileToolBar = addToolBar(tr("File"));
    QStatusBar* mainStatusBar = statusBar();
    mainTextEdit = new QTextEdit(this);

    QAction* newFile = new QAction(QIcon(":/images/new.png"),tr("&New File"),this);
    newFile->setShortcut(QKeySequence(tr("Ctrl+N")));
    newFile->setToolTip(tr("New File"));
    newFile->setStatusTip(tr("New file"));

    QAction* openFile = new QAction(QIcon(":/images/open.png"),tr("&Open File"),this);
    openFile->setShortcut(QKeySequence(tr("Ctrl+O")));
    openFile->setToolTip(tr("Open File"));
    openFile->setStatusTip(tr("Open file"));

    QAction* saveFile = new QAction(QIcon(":/images/save.png"),tr("&Save File"),this);
    saveFile->setShortcut(QKeySequence(tr("Ctrl+S")));
    saveFile->setToolTip(tr("Save File"));
    saveFile->setStatusTip(tr("Save file"));

    QAction* quit = new QAction(tr("&Quit"),this);
    quit->setShortcut(QKeySequence(tr("Ctrl+W")));
    quit->setToolTip(tr("Quit"));
    quit->setStatusTip(tr("Quit"));

    fileMenu->addAction(newFile);
    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);
    fileMenu->addAction(quit);

    fileToolBar->addAction(newFile);
    fileToolBar->addAction(openFile);
    fileToolBar->addAction(saveFile);

    setCentralWidget(mainTextEdit);

    QObject::connect(openFile,SIGNAL(triggered()),this,SLOT(openFile()));
    QObject::connect(saveFile,SIGNAL(triggered()),this,SLOT(saveFile()));
    QObject::connect(quit,SIGNAL(triggered()),this,SLOT(quitApp()));
}

void MainWindow::openFile(){
    qDebug() << "openFile";
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open"),"/",
                                                    tr("Text Files (*.txt); HTML files(*.html)"));
    if(fileName != NULL){
        QFile *file = new QFile(fileName);
        file->open(QIODevice::ReadOnly);

        QTextStream stream(file);
        QString content = stream.readAll();

        if(fileName.endsWith(".html"))
            mainTextEdit->setHtml(content);
        else
            mainTextEdit->setPlainText(content);

        file->close();
    }
}

void MainWindow::saveFile(){
    qDebug() << "saveFile";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save"),"/",
                                                    tr("Text Files (*.txt); HTML files(*.html)"));
}


void MainWindow::quitApp(){
    qDebug() << "quitApp";
}

MainWindow::~MainWindow()
{
    delete ui;
}
