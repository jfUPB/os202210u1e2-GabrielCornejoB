#include <stdlib.h>
#include <stdio.h>
#include "subject.h"

static void _addObserver(Subject *this, Observer *observer){
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == NULL){
            this->observers[i] = observer;
            break;
        }
    }
    printf("Lista de Observers llena:(\n");
}
static void _removeObserver(Subject *this, Observer *observer){
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == observer){
            this->observers[i] = NULL;
            break;
        }
    }
    printf("No se encontró el Observer a eliminar\n");
}
static void _notifyObservers(Subject *this){
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] != NULL){
            this->observers[i]->update(this->observers[i], this->state, this->impl);   
        }
    }
}
Subject *subject_new(void *impl, int state){
    Subject *this = (Subject*)malloc(sizeof(Subject));
    this->state = 0;
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    this->notifyObservers = _notifyObservers;
}
void subject_destroy(Subject *this){
    free(this);
}