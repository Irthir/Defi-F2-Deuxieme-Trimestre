#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#pragma once

#include <windows.h>
#include <unistd.h>
#include <winsock2.h>
#include <pthread.h>
typedef int socklen_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PORT 23

void client();
void* ReceptionClient(void* data);
void* EnvoieClient(void* data);

#endif
