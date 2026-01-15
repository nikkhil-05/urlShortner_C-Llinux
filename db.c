#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "db.h"

static char* generate_short_code() {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char buff[20];
    srand(time(NULL) ^ clock());
    int num = rand();
    int i = 0;

    while (num > 0 && i < 19) {
        int idx = num % 64;
        buff[i++] = charset[idx];
        num /= 64;
    }
    buff[i] = '\0';
    return strdup(buff); 
}

char* fetch(const char *input_url) {
    MYSQL *conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "mysql_init() failed\n");
        return NULL;
    }

    if (!mysql_real_connect(conn, "localhost", "url_user", "Strong@1234", "url_shortner", 0, NULL, 0)) {
        fprintf(stderr, "Connection failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    printf("Connected to MySQL successfully!\n");

    // Check if URL exists
    char query[512];
    snprintf(query, sizeof(query),
             "SELECT short_code FROM urls WHERE long_url = '%s'", input_url);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "SELECT failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(res);

    if (row) {
        // URL exists
       // printf("URL already exists! Short code: %s\n", row[0]);
        char *existing_code = strdup(row[0]);
        mysql_free_result(res);
        mysql_close(conn);
        return existing_code;
    }

    //URL not found → generate new code
    char *new_code = generate_short_code();
    //printf("Generated new short code: %s\n", new_code);

    snprintf(query, sizeof(query),
             "INSERT INTO urls (long_url, short_code) VALUES ('%s', '%s')",
             input_url, new_code);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "INSERT failed: %s\n", mysql_error(conn));
        free(new_code);
        mysql_close(conn);
        return NULL;
    }

   // printf("Mapped successfully in DB!\n");

    mysql_free_result(res);
    mysql_close(conn);
    return new_code;
}

