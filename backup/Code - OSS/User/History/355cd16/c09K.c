#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;

    char buffer[1024];

    char command[] =
        "curl -s "
        "'https://cfyscdckroowoxcjqexm.supabase.co/rest/v1/Farmer' "
        "-H 'apikey: eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImNmeXNjZGNrcm9vd294Y2pxZXhtIiwicm9sZSI6ImFub24iLCJpYXQiOjE3Nzg1MTg1NDgsImV4cCI6MjA5NDA5NDU0OH0.9HOiFI5dcbyvjyRZq9BGw1bwGo1lWv7Lh5S0nmJNRb4
        "-H 'Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImNmeXNjZGNrcm9vd294Y2pxZXhtIiwicm9sZSI6ImFub24iLCJpYXQiOjE3Nzg1MTg1NDgsImV4cCI6MjA5NDA5NDU0OH0.9HOiFI5dcbyvjyRZq9BGw1bwGo1lWv7Lh5S0nmJNRb4

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