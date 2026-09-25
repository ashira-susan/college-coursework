#ifndef FILEIO_H
#define FILEIO_H

#include "types.h"

void saveResources(Resource resources[], int count);
int loadResources(Resource resources[], int *count);
void generateReport(Resource resources[], int count);

#endif
