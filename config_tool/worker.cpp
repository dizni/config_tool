#include "worker.h"

#include "QTimer"
#include "QThread"

Worker::Worker(QObject *parent) : QObject(parent)
{

    m_comm = new Comm;

}

/**********************************************************************
 *
 *
 *
 *********************************************************************/
Worker::~Worker()
{

}


/**********************************************************************
 *
 *
 *
 *********************************************************************/
void Worker::run(void)
{
//    m_comm->send("ff03::1", "/.well-known/core?rt=urn:zcl:c.3.s",
//                 COAP_REQUEST_GET, 10, CoapRawResponse);

    m_comm->test();

}

/**********************************************************************
 *
 *
 *
 *********************************************************************/
void Worker::stop_run(void)
{
    m_comm->stop_run();

}

void Worker::signal_handler()
{
    m_comm->m_is_running = false;
    printf("stop\n");

}


