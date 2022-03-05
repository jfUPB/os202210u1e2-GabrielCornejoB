#include <stdlib.h>
#include <stdio.h>
#include "subject.h"

//Destroy subject
void _destroySu(Subject *this){
    printf("DEBUG: Subject: destroy()\n");
    free(this);
}
//Add Observer to list
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
//Remove Observer from list
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
//Notify all Observers in list
static void _notifyObservers(Subject *this){
    printf("DEBUG: Subject: notifyObservers()\n");
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] != NULL){
            //printf("Subject: se notificara a los observers en la lista\n");
            this->observers[i]->update(this->observers[i], this->impl);   
        }
    }
}
//Subject constructor
Subject *subject_new(void *impl){
    printf("DEBUG: Subject: subject_new()\n");
    Subject *this = malloc(sizeof(*this));
    this->destroySu = _destroySu;
    this->impl = impl;
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    this->notifyObservers = _notifyObservers;
    return this;
}
