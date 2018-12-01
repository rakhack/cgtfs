#ifndef CGTFS_READING_UTILS_H
#define CGTFS_READING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LEN 10000

int read_header(FILE *fp, char ***field_names);
int read_record(FILE *fp, int fields_number, char ***record_values);

#endif
