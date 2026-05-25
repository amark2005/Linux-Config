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


int main(int argc,char *argv[]){
  int battery=getBatteryLevel();
  if (argc != 2) {
    printf("Usage:\n");
    printf("batcheck --show\n");
    printf("batcheck --safe\n");
    return 1;
  }
  else if (strcmp(argv[1],"--show")==0){
    printf("Battery: %d%%\n", battery);
  }
  else if (strcmp(argv[1],"--safe")==0){
    if (battery >= 20 && battery <= 80) {
      printf("Battery is in safe range.\n");
  } else {
      printf("Battery outside safe range.\n");
  }}
return 0;
}