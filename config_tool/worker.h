#ifndef WORKER_H
#define WORKER_H

#include <QObject>

#include "comm.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();


signals:

public slots:
    void run(void);
    void stop_run(void);

    void signal_handler();


private:
    Comm    *m_comm;

};

#endif // WORKER_H
