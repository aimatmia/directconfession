#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int directstats(DIR* direct){

  struct dirent *ent;
  struct stat st;
  int sum;
  
  if (!direct){
        printf("No such directory.");
        return ;
  }
  else{ 
    /* print all the files and directories within directory */
  while ((ent = readdir (direct)) != NULL) {
     fstatat(dirfd(direct), ent->d_name, &st, 0);
     if (S_ISDIR(st.st_mode)) 
        printf ("Directory: %s\n", ent->d_name);
     else {
        printf ("File: %s\n", ent->d_name);
        stat(ent->d_name, &st);
        sum += st.st_size;
     }
   }
   return sum; 
}
  
int main(){
  char path[] = ".";
  DIR* direct = opendir(path);
  printf("\n Stats of Directory %s: \n", path);
  int sum = directstats(direct);
  if (sum>1000000000) printf("size: %ld GB \n", sum/1000000000);
  if (sum>1000000) printf("size: %ld MB \n", sum/1000000);
  if (sum>1000) printf("size: %ld KB \n", sum/1000);
  else printf("size: %ld B", sum);
  closedir(direct);
  return 0;
}
