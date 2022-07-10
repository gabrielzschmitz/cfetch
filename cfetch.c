/*
//         .             .              .		    
//         |             |              |           .	    
// ,-. ,-. |-. ,-. . ,-. |  ,_, ,-. ,-. |-. ,-,-. . |- ,_,  
// | | ,-| | | |   | |-' |   /  `-. |   | | | | | | |   /   
// `-| `-^ ^-' '   ' `-' `' '"' `-' `-' ' ' ' ' ' ' `' '"'  
//  ,|							    
//  `'							    
// cfetch.c
*/

/* LIBRARYS */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include "xlibwrap.h"

/* AUXILIAR */
char* read_grep(char* file, char* pattern, int offset, int cut) {
    FILE *fp;
    fp = fopen(file, "r");
    char* line = "";
    char* cmp = pattern;
    size_t len = 0;
    while(strstr(line, cmp) == NULL) {
        if(getline(&line, &len, fp) == -1)
        break;
    }

    if(strstr(line, cmp) == NULL) return "";
    line += strlen(pattern) + offset;
    line[strlen(line)-cut-1] = 0;
    char* rtn = malloc (sizeof (char) * strlen(line));
    strcpy(rtn, line);
    return rtn;
}

char* read_all(char* file) {
    FILE* fp = fopen(file, "r");
    char* line = NULL;
    char* lines = malloc(1);
    strcpy(lines, "");
    size_t len;
    while(getline(&line, &len, fp) != -1) {
        lines = realloc(lines, strlen(lines)+strlen(line));
        strcat(lines, line);
    }
    return lines;
}

/* FETCHING */
char* fetch_wm_name() {
    Window root = DefaultRootWindow(xwrap_dpy);
    Window wm_check = prop_get_window(root, "_NET_SUPPORTING_WM_CHECK");
    char* name = prop_get_str(wm_check, "_NET_WM_NAME");
    return name;
}

char* fetch_distro() {
    char* distro_name = read_grep("/etc/os-release", "PRETTY_NAME=", 1, 1);
    struct utsname uts_name;
    uname(&uts_name);
    char* arch = uts_name.machine;
    char* distro_line = malloc(strlen(distro_name)+strlen(arch));
    sprintf(distro_line, "%s %s", distro_name, arch);
    return distro_line;
}

char* fetch_kernel() {
    char* kernel = read_all("/proc/sys/kernel/osrelease");
    kernel[strlen(kernel)-1] = 0;
    return kernel;
}

char* fetch_shell() {
    struct passwd* passwd_entry = getpwuid(getuid());
    return basename(passwd_entry->pw_shell);
}

float fetch_uptime() {
    struct sysinfo info;
    sysinfo(&info);
    printf("%02ld", info.uptime/3600);
    printf("%s ", "h");
    printf("%02ld", info.uptime%3600/60);
    printf("%s\n", "m");
}

/* MAIN */
#define ART_OFFSET 1

int main(int argc, char* argv[]) {
    xwrap_init();
    char art_name[4096];
    strcpy(art_name, "/usr/share/cfetch/coffee.art");
    FILE* art = fopen(art_name, "r");
    if(art == NULL) {
        printf("Art file not found! Make it at \e[96m/usr/share/cfetch/yourart.art\e[39m.\n");
        return 1;
    }
    char* line = NULL;
    ssize_t size;
    getline(&line, &size, art);
    char* color = malloc(strlen(line)+3);
    sprintf(color, "\e[%dm", atoi(line));
    int art_width = 0;
    bool file_read = false;
    bool run = true;
    for(int i = 0; run; i++) {
        if(file_read || getline(&line, &size, art) == -1) {
            sprintf(line, "%*s", art_width,"");
            file_read = true;
        }

        if(i >= 2){
            sprintf(color, "\e[37m");
        }

        line[strlen(line)-1] = 0;
        art_width = fmax(strlen(line), art_width);
        printf("\e[1m%s%s",color, line);
        printf("%*s", ART_OFFSET, "");
        switch(i) {
            case 0:
                printf("\e[31m\e[1m \e[37m· \e[30m\e[0m%s%s\n", fetch_distro(), color);
            break;                                
            case 1:                               
                printf("\e[36m\e[1m \e[37m· \e[30m\e[0m%s%s\n", fetch_kernel(), color);
            break;                                
            case 2:                               
                printf("\e[32m\e[1m神\e[37m· \e[30m\e[0m");
                fetch_uptime();                   
            break;                                
            case 3:                               
                printf("\e[33m\e[1m缾\e[37m· \e[30m\e[0m%s%s\n", fetch_wm_name(), color);
            break;                                
            case 4:                               
                printf("\e[34m\e[1m \e[37m· \e[30m\e[0m%s%s\n", fetch_shell(), color);
            break;
            case 5:
                printf("\e[30m \e[31m \e[32m \e[33m \e[34m \e[35m \e[36m \e[37m \e[0m");
            break;
            case 6:
                if(file_read) run = false;
            break;
            default:
            break;
        }
    }
    printf("\e[0m");
    free(color);
}

