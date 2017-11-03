#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  DIR * d = opendir(".");
  struct dirent * entry = readdir(d);
  int ts = 0;
  int size = 0;
  while(entry){
    if(entry->d_type == DT_REG){
      struct stat sb;
      stat(entry->d_name, &sb);
      size = sb.st_size;
      ts += size;
    }
    entry = readdir(d);
  }
  printf("\nTotal Size: %d bytes\n", ts);
  closedir(d);

  printf("\nDirectories: \n");
  d = opendir(".");
  entry = readdir(d);
  while(entry){
    if(entry->d_type == DT_DIR){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
  d = opendir(".");
  entry = readdir(d);
  printf("\nFiles: \n");
  while(entry){
    if(entry->d_type == DT_REG){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
  return 0;
}
