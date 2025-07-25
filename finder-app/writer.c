#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

void write_to_file(const char *filename, const char *string) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file: %s", filename);
        return;
    }

    fprintf(file, "%s\n", string);
    syslog(LOG_DEBUG, "Writing %s to %s", string, filename);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Invalid arguments");
        return 1;
    }

    const char *filename = argv[1];
    const char *string = argv[2];

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    write_to_file(filename, string);
    closelog();
    return 0;
}