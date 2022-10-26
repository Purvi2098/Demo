 #include <string.h>
   #include <stdio.h>
   
   FILE *get_server_file(char *user_input) {
     char base_dir[128] = "/home/user_server/";
     strncat(base_dir, user_input, 64);
     return fopen(base_dir, "r");
   }
   
  int main() {
    char user_input[64];
    FILE * fp;
    int i = 0;
    int c = 0;
  
    do {
      c = getchar();
      if (c == EOF) {
          user_input[i] = 0;
          break;
      }
      user_input[i] = (char) c;
      i++;
    } while (i<64);
  
    fp = get_server_file(user_input);
  
    if (fp){
       send_file_to_user(fp);  // sends file contents to the user
        fclose(fp);
        return 0;
    }
   return -1;
  }
