#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getBatteryLevel() {

    FILE *fp = fopen(
        "/sys/class/power_supply/BAT0/capacity",
        "r"
    );

    if (fp == NULL) {
        printf("Battery not found.\n");
        return -1;
    }

    int battery;

    fscanf(fp, "%d", &battery);

    fclose(fp);

    return battery;
}


int main(){

  
}