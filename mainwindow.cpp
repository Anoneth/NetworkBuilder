#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonCreate, SIGNAL(clicked()), this, SLOT(doJob()));
    connect(ui->checkBoxParsim, SIGNAL(toggled(bool)), ui->spinBoxNodesCount, SLOT(setEnabled(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doJob()
{
    int nodesCount = ui->spinBoxNodesCount->value();
    int size = ui->spinBoxSize->value();
    QString packageName = ui->lineEditPackageName->text();
    QString networkName = ui->lineEditNetworkName->text();
    QString iniName = ui->lineEditIniFileName->text();

    QStringList args;
    args.push_back("networkCreator.py");
    args.push_back("--size=" + QString::number(size));
    args.push_back("--network-name=" + networkName);
    args.push_back("--package-name=" + packageName);
    args.push_back("--ini-filename=" + iniName);

    if (ui->checkBoxParsim->isChecked())
        args.push_back("--node-count=" + QString::number(nodesCount));

    QProcess p;
    p.setProgram("python");
    p.setArguments(args);
    p.start();
    p.waitForReadyRead();
    QMessageBox box;
    box.setText(p.readAllStandardOutput());
    box.exec();

}
