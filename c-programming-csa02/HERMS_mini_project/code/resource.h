#ifndef RESOURCE_H
#define RESOURCE_H

#include "types.h"

void calculateStatus(Resource *r);
int findIndexByID(Resource resources[], int count, int id);
void addResource(Resource resources[], int *count);
void updateResource(Resource resources[], int count);
void displayResources(Resource resources[], int count);
void displayResourceRow(Resource r);

#endif
