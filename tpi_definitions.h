#ifndef tpi_definitions_h
#define tpi_definitions_h

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "libtree.h"
#include "tpi_iana.h"
#include "utlist.h"

#define TPI_IANA_TXT "./ports_txt"
#define TPI_SRV_SOCK "/var/run/tpisrv.sock"
#define TPI_CLI_SOCK "/var/run/tpicli%ld.sock"
#define TPI_REGEXP_VALIDATION "(^-){0,1}[:digit:]*/[:upper:]*"

struct tpi_prot_serv_name {
    int prot;
    char *serv_name;
    struct tpi_prot_serv_name *next;
};

struct tpi_node {
    int port;
    struct rbtree_node node;
    struct tpi_prot_serv_name *list;
};

struct tpi_line_parsed {
    char *port_number;
    char *prot;
    char *serv_name;
};

struct tpi_prot_initial {
    int prot;
    const char *initial;
};

struct tpi_port_interval {
    unsigned int min_port;
    unsigned int max_port;
    int prot;
    const char *serv_name;
};

struct sockaddr_un addr;
int sock;

const char *protocols[TPI_NUMBER_OF_PROTOCOLS] = TPI_IANA_TRANSPORT_PROTOCOL_INIT;
struct tpi_prot_initial prot_initial[TPI_NUMBER_OF_PROTOCOLS] = TPI_IANA_TRANSPORT_PROTOCOL_NAME_INIT;
struct tpi_port_interval port_interval[TPI_NUMBER_OF_PORT_INTERVAL] = TPI_IANA_PORT_RANGES_INIT;

#endif /* tpi_definitions_h */
