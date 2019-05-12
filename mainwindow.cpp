#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonCreate, SIGNAL(clicked()), this, SLOT(doJob()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doJob()
{
    int nodesCount = ui->spinBoxNodesCount->value();
    int routersCount = ui->spinBoxRoutersCount->value();
    int hostsPerSwitch = ui->spinBoxHostsPerRouter->value();
    QString packageName = ui->lineEditPackageName->text();
    QString networkName = ui->lineEditNetworkName->text();
    QString iniName = ui->lineEditIniName->text();
    QString nedName = ui->lineEditNedName->text();

    QString command = "python createNetwork.py " + QString::number(nodesCount) + " "
            + QString::number(routersCount) + " "
            + QString::number(hostsPerSwitch) + " "
            + nedName + " "
            + packageName + " "
            + networkName + " "
            + iniName;
    QProcess::execute(command);

}
