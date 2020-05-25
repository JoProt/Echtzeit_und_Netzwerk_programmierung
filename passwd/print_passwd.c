#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

void writePW(struct passwd *MyPasswd) {
        printf("Name: %s\n", MyPasswd->pw_name);
        printf("UID: %ld\n", (long)MyPasswd->pw_uid);
        printf("GID: %ld\n", (long)MyPasswd->pw_gid);
        printf("Home: %s\n", MyPasswd->pw_dir);
        printf("Shell: %s\n", MyPasswd->pw_shell);
}