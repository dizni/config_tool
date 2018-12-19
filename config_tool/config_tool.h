#ifndef CONFIG_TOOL_H
#define CONFIG_TOOL_H

#include <QMainWindow>

namespace Ui {
class Config_Tool;
}

class Config_Tool : public QMainWindow
{
    Q_OBJECT

public:
    explicit Config_Tool(QWidget *parent = nullptr);
    ~Config_Tool();

private:
    Ui::Config_Tool *ui;
};

#endif // CONFIG_TOOL_H
