#ifndef COMM_H
#define COMM_H


//extern "C" {
//    #include "coap.h"
//}

class Comm
{
public:
    Comm();
    ~Comm();

    void stop_run(void);

//    int send(const char *server_ip,
//               const char *server_uri,
//               uint8_t method,
//               uint16_t timeout,
//               coap_response_handler_t 	response_handler);

    void test(void);


    bool    m_is_running;

private:



};

#endif // COMM_H
