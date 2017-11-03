#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  DIR * d = opendir(".");
  struct dirent* entry = readdir(d);
  int total = 0;
  while(entry){
    if(entry -> d_type == DT_REG){
      struct stat data;
      stat(entry -> d_name, &data);
      size_t size = data.st_size;
      total += size;
    }
    entry = readdir(d);
  }
  printf("\nTotal Size: %d Bytes\n", total);
  closedir(d);

  printf("\nDirectories: \n");
  d = opendir(".");
  entry = readdir(d);
  while(entry){
    if(entry -> d_type == DT_DIR){
      printf("\t%s\n", entry -> d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
  d = opendir(".");
  entry = readdir(d);
  printf("\nFiles: \n");
  while(entry){
    if(entry->d_type == DT_REG){
      printf("\t%s\n", entry -> d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
  return 0;
}
