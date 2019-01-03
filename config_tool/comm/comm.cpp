#include "comm.h"
#include <arpa/inet.h>

#include "QTimer"

#define BUF_SIZE 100

bool g_flag_running = false;

Comm::Comm() : m_is_running(false)
{
}


Comm::~Comm()
{

}

void Comm::test(void)
{
    g_flag_running = true;

    while(g_flag_running) {

    }
    printf("test\n");

}

#if 0
int Comm::send(const char *server_ip,
               const char *server_uri,
               uint8_t method,
               uint16_t timeout,
               coap_response_handler_t 	response_handler)
{
    coap_context_t *ctx;
    coap_address_t src_addr;
    coap_address_t dst_addr;
    static coap_uri_t uri;
    coap_pdu_t *request;

    unsigned char _buf[BUF_SIZE];
    unsigned char *buf = _buf;
    size_t buflen = BUF_SIZE;

    fd_set  readfds;
    int res;

    /* Prepare coap socket*/
    coap_address_init(&src_addr);
    src_addr.addr.sin6.sin6_family      = AF_INET6;
    src_addr.addr.sin6.sin6_port        = htons(0);
    ctx = coap_new_context(&src_addr);

    /* The destination endpoint */
    coap_address_init(&dst_addr);
    dst_addr.addr.sin6.sin6_family      = AF_INET6;
    dst_addr.addr.sin6.sin6_port        = htons(5683);
    inet_pton(AF_INET6, server_ip, dst_addr.addr.sin6.sin6_addr.s6_addr);

    /* Prepare the request */
    request            = coap_new_pdu();
    request->hdr->type = COAP_MESSAGE_CON;
    request->hdr->id   = coap_new_message_id(ctx);
    request->hdr->code = method;

    res = coap_split_uri(reinterpret_cast < const unsigned char *> (server_uri), strlen(server_uri), &uri);
    if (res != 0) {
        return res;
    }

    if (uri.path.length) {
        res = coap_split_path(uri.path.s, uri.path.length, buf, &buflen);
        while (res--) {
            coap_add_option(request, COAP_OPTION_URI_PATH,
                            coap_opt_length(buf),
                            coap_opt_value(buf));
            buf += coap_opt_size(buf);
        }
    }

    if (uri.query.length) {
        buflen = 100;
        buf = _buf;
        res = coap_split_query(uri.query.s, uri.query.length, buf, &buflen);
        while (res--) {
            coap_add_option(request, COAP_OPTION_URI_QUERY,
                            coap_opt_length(buf),
                            coap_opt_value(buf));
            buf += coap_opt_size(buf);
        }
    }

    /* Set the handler and send the request */
    coap_register_response_handler(ctx, response_handler);
    coap_send_confirmed(ctx, ctx->endpoint, &dst_addr, request);
    FD_ZERO(&readfds);
    FD_SET( ctx->sockfd, &readfds );

    res = select(FD_SETSIZE, &readfds, nullptr, nullptr, nullptr);
    if ( res < 0 ) {
        return EXIT_FAILURE;
    } else if ( res > 0 && FD_ISSET( ctx->sockfd, &readfds )) {
        while(m_is_running) {
            coap_read( ctx );
        }
    }
    return 0;
}

#endif


void Comm:: stop_run(void)
{
    m_is_running = false;
    printf("stop_run\n");

}
