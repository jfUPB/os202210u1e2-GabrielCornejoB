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
    char *s1 = "DEBUG: Subject: addObserver()";
    printf("%-40s", s1);
    int bool = 0;
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == NULL){
            this->observers[i] = observer;
            bool = 1;
            break;
        }
    }
    if(bool == 0){
        printf("\n\t\tSubject's list full, could not add new Observer\n\n");
    }
}
//Remove Observer from list
static void _removeObserver(Subject *this, Observer *observer){
    printf("DEBUG: Subject: removeObserver()\n");
    int bool = 0;
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] == observer){
            this->observers[i] = NULL;
            bool = 1;
            break;
        }
    }
    if(bool == 0){
        printf("\n\t\tObserver wasn't found on list\n\n");
    }
}
//Notify all Observers in list
static void _notifyObservers(Subject *this){
    printf("DEBUG: Subject: notifyObservers()\n");
    for (int i = 0; i < LEN_OBSERVERS; i++){
        if(this->observers[i] != NULL){
            this->observers[i]->update(this->observers[i], this->impl);   
        }
    }
}
//Subject constructor
Subject *subject_new(void *impl){
    char *s1 = "DEBUG: Subject: subject_new()";
    printf("%-40s", s1);
    Subject *this = malloc(sizeof(*this));
    this->destroySu = _destroySu;
    this->impl = impl;
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    this->notifyObservers = _notifyObservers;
    return this;
}
