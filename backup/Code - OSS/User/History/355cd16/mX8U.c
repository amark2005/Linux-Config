#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;

    char buffer[1024];

    char command[] =
    "curl -s "
    "'https://cfyscdckroowoxcjqexm.supabase.co/rest/v1/Farmer' "
    "-H 'apikey: YOUR_KEY' "
    "-H 'Authorization: Bearer YOUR_KEY' ";

    fp = popen(command, "r");

    if (fp == NULL) {
        printf("Failed to run curl\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);

    return 0;
}