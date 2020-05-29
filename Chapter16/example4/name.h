#ifndef __NAME_H__
#define __NAME_H__
#include <stdio.h>
#include <string.h>
#define SIZE 40

struct name_struct {
    char first_name[SIZE];
    char last_name[SIZE];
};

typedef struct name_struct names;

void get_name(names *pts);
void show_name(names *pts);
char *s_gets(char *str, int n);

#endif