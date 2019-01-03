#ifndef CONFIG_TOOL_H
#define CONFIG_TOOL_H

#include <QMainWindow>
#include "QThread"
#include "QTimer"

#include "worker.h"

namespace Ui {
class Config_Tool;
}

class Config_Tool : public QMainWindow
{
    Q_OBJECT

public:
    explicit Config_Tool(QWidget *parent = nullptr);
    ~Config_Tool();


signals:
    void signal_main_worker();

private slots:
    void timer_handler(void);

    void on_actionScan_triggered();

    void on_actionQuit_triggered();

private:
    Ui::Config_Tool *ui;

    QThread     *m_wthread;
    Worker      *m_worker;
    QTimer      *m_timer;
};

#endif // CONFIG_TOOL_H
