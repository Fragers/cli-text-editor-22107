/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void show_last(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showlastnonspace(text txt)
{
    /* Применяем функцию show_last к каждой строке текста */
    process_forward(txt, show_last, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_last(int index, char *contents, int cursor, void *data)
{
    /* Функция-обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    UNUSED(cursor);
    
    /* Находим последний непробельный символ */
    int last_char = strlen(contents) - 1;
    while ((contents[last_char] == '\n' || contents[last_char] == ' ') && (last_char >= 0))
        last_char--;
    
    /* Выводим символ на экран */
    if (last_char > -1)
        printf("%c\n", contents[last_char]);
}
