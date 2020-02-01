#ifndef HOTE_H_INCLUDED
#define HOTE_H_INCLUDED
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

void showHost();
void hote();
void* EnvoieHote(void* data);
void* ReceptionHote(void* data);

#endif
