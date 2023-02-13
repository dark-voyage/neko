//
// Created by Sokhibjon Orzikulov on 13/02/23.
//

#include "http.h"

#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CONNECTIONS 1024
#define BUF_SIZE 65535
#define QUEUE_SIZE 1000000

static int listenfd;
int *clients;
static void start_serve(const char *);
static void respond(int);

static char *buf;

// Client request
char *method,
        *uri,
        *qs,
        *prot,
        *payload;

int payload_size;



void serve_forever(const char *PORT) {
  struct sockaddr_in clientaddr;
  socklen_t addrlen;

  int slot = 0;

  printf("Server started %shttp://127.0.0.1:%s%s",
         "\033[1;32m",
         PORT,
         "\033[0m"
         );

  // Shared slot memory for clients
  clients = mmap(
      NULL,
      MAX_CONNECTIONS * sizeof(*clients) * MAX_CONNECTIONS,
      PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED,
      -1, 0
      );

  int i;
  for (i = 0; i < MAX_CONNECTIONS; i++)
    clients[i] = -1;
  start_serve(PORT);

  // Ignore child process termination
  signal(SIGCHILD, SIG_IGN);

  while (1) {
    addrlen = sizeof(clientaddr);
    clients[slot] = accept(listenfd, (struct sockaddr *) &clientaddr, &addrlen);

    if (clients[slot] < 0) {
      perror("accept() error");
      exit(1);
    } else {
      if (fork() == 0) {
        close(listenfd);
        respond(slot);
        close(clients[slot]);
        clients[slot] = -1;
        exit(0);
      } else {
        close(clients[slot]);
      }
    }

    while (clients[slot] != -1) slot = (slot + 1) % MAX_CONNECTIONS;
  }
}



