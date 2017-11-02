#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(){

  DIR * d;
  d = opendir("work9");
  struct dirent *flop;
  struct stat sb;
  flop = readdir(d);
  // printf("%p\n", flop);
  stat("", &sb);

  printf("Statistics for directory: work9\n");
  printf("Total Directory size: %d bytes\n", size);
  int size;
  while(flop){
    size += file.st_size;
  }


  printf("Regular files:");
  while(flop){
    printf("\t%s\n", d_name);
  }
  
  d = closedir("work9");
  return 0;

}
