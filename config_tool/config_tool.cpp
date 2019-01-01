#include "config_tool.h"
#include "ui_config_tool.h"

Config_Tool::Config_Tool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Config_Tool)
{
    ui->setupUi(this);
}

Config_Tool::~Config_Tool()
{
    delete ui;
}


void Config_Tool::on_actionScan_triggered()
{
    ui->textBrowser->append("Clicked");
}

void Config_Tool::on_actionQuit_triggered()
{
    QApplication::quit();
}
