#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  
  typedef struct SEntry {
      char secret[32];
      char message[32];
  } SEntry;
 
 int verify_secret(SEntry *sentry) {
     // dynamic length, in case we upgrade security and use a longer secret
     // I've been telling them to use 64 bytes for years, one day they'll budge
     // I hope I get a raise for making this section extra dynamic
     int entry_size = sizeof(sentry);
     int secret_length = entry_size / 2;
     char entry_secret[secret_length];
     memcpy(entry_secret, sentry, secret_length);
     FILE *file = fopen("secret.txt", "rb");
     char *secret = malloc(secret_length * sizeof(char));
     if (file)
     {
         fread(secret, secret_length, 1, file);
         fclose(file);
     }
     int ret = strcmp(entry_secret, secret) == 0;
     free(secret);
     return ret;
 }
 
 int main() {
   SEntry *s = malloc(sizeof(SEntry));
   strcpy(s->secret, "hunter2");
   strcpy(s->message, "IT'S A SECRET TO EVERYBODY.");
   verify_secret(s);
}
