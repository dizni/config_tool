#ifndef COMM_H
#define COMM_H

#include "QObject"

extern "C" {
    #include "coap.h"
}

class Comm: public QObject
{
    Q_OBJECT
public:
    explicit Comm(QObject *parent = nullptr);
    ~Comm();

    int send(const char *server_ip,
               const char *server_uri,
               uint8_t method,
               uint16_t timeout,
               coap_response_handler_t 	response_handler);

private:
    bool   m_is_running;


private slots:
    void timer_handler(void);

};

#endif // COMM_H
