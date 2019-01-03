#include "config_tool.h"
#include "ui_config_tool.h"

extern bool g_flag_running;


Config_Tool::Config_Tool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Config_Tool)
{
    ui->setupUi(this);

//    qRegisterMetaType<signal_name>("signl_name");

    /* create thread to do data processing */
    m_wthread = new QThread;
    m_worker   = new Worker();
    m_worker->moveToThread(m_wthread);
    m_timer = new QTimer(nullptr);
    m_timer->setSingleShot(true);
    connect(m_timer, SIGNAL(timeout()), m_worker, SLOT(run()));
    connect(this, SIGNAL(signal_main_worker()),
            m_worker, SLOT(signal_handler()));
    connect(m_wthread, SIGNAL(finished()), m_wthread, SLOT(deleteLater()));
    m_wthread->start();

}

Config_Tool::~Config_Tool()
{
    delete ui;
}


void Config_Tool::on_actionScan_triggered()
{
    m_timer->start(0);

    ui->textBrowser->append("Clicked");
    QTimer::singleShot(100, this, SLOT(timer_handler()));

}

void Config_Tool::on_actionQuit_triggered()
{
    QApplication::quit();
}


void Config_Tool::timer_handler(void)
{
    printf("here\n");
    g_flag_running = false;
//    emit signal_main_worker();
}
