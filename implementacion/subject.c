#include <stdlib.h>
#include <stdio.h>
#include "subject.h"

static void _addObserver(subject *this, observer *observer){
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == NULL){
            this->observers[i] = observer;
            break;
        }
    }
    printf("Lista de Observers llena:(\n");
}
static void _removeObserver(subject *this, observer *observer){
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == observer){
            this->observers[i] = NULL;
            break;
        }
    }
    printf("No se encontró el Observer a eliminar\n");
}
static void _notifyObservers(subject *this){
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] != NULL){
            this->observers[i]->update;     //Creo que acá falta algo 
        }
    }
}

subject *subject_new(){
    return (subject*)malloc(sizeof(subject));
}
void subject_ctor(subject *this){
    this->state = 0;
    this->add = _addObserver;
    this->remove = _removeObserver;
    this->notify = _notifyObservers;
}
void subject_destroy(subject *this){
    free(this);
}
void setObserverState(subject *this, int val){
    this->state = val;
}