#include <stdlib.h>
#include <stdio.h>
#include "subject.h"

void _destroySu(Subject *this){
    printf("DEBUG: Subject: destroy()\n");
    free(this);
}

static void _addObserver(Subject *this, Observer *observer){
    printf("DEBUG: Subject: addObserver()\n");
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == NULL){
            this->observers[i] = observer;
            //printf("Subject: Se colocó el observer en la lista\n");
            break;
        }
    }
    //printf("Lista de Observers llena:(\n");
}
static void _removeObserver(Subject *this, Observer *observer){
    printf("DEBUG: Subject: removeObserver()\n");
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == observer){
            this->observers[i] = NULL;
            break;
        }
    }
    //printf("No se encontró el Observer a eliminar\n");
}
static void _notifyObservers(Subject *this){
    printf("DEBUG: Subject: notifyObservers()\n");
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] != NULL){
            //printf("Subject: se notificara a los observers en la lista\n");
            this->observers[i]->update(this->observers[i], this->state, this->impl);   
        }
    }
}
Subject *subject_new(void *impl, int state){
    printf("DEBUG: Subject: subject_new()\n");
    Subject *this = (Subject*)malloc(sizeof(*this));
    this->destroySu = _destroySu;
    this->impl = impl;
    this->state = state;
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    this->notifyObservers = _notifyObservers;
    return this;
}
