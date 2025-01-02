
#include "file_util.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <dirent.h>

#define MAX_FILE_LINE 1024
#define MAX_LINE_LEN 1024

struct LINE_INFO{
    char *line;
    int line_num;
    int if_in;
};

//计算部分匹配表（前缀函数）
void compute_prefix_function(const char *pattern, int *prefix, int m) {
    int length = 0;
    prefix[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            prefix[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = prefix[length - 1];
            } else {
                prefix[i] = 0;
                i++;
            }
        }
    }
}

int contains(const char *text_p, const char *pattern, int i_option) {
    char *text;
    if(i_option){
        text = strdup(text_p);
        for (int i = 0; text[i]; i++) 
            text[i] = tolower(text[i]);
    }else{
        text = strdup(text_p);
    }

    int n = strlen(text);
    int m = strlen(pattern);
    int *prefix = (int *)malloc(m * sizeof(int));
    compute_prefix_function(pattern, prefix, m);

    int i = 0; // text的索引
    int j = 0; // pattern的索引
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == m) {
            free(prefix);
            return 1; // 找到匹配
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                i++;
            }
        }
    }
    free(prefix);
    return 0;
}


struct LINE_INFO* search(FILE *file, const char *pattern_p, int i_option)
{
    struct LINE_INFO *result = (struct LINE_INFO *)malloc(MAX_FILE_LINE * sizeof(struct LINE_INFO));
    char line[MAX_LINE_LEN];
    int line_num = 0;
    int i = 0;
    char *pattern;

    if(i_option){
        pattern = strdup(pattern_p);
        for (int j = 0; pattern[j]; j++) 
            pattern[j] = tolower(pattern[j]);
    }else{
        pattern = strdup(pattern_p);
    }

    while(fgets(line, sizeof(line), file)){
        line_num++;
        result[i].line = strdup(line);
        result[i].line_num = line_num;
        if(contains(line, pattern, i_option)){
            result[i].if_in = 1;
        } else {
            result[i].if_in = 0;
        }
        i++;
    }
    return result;
}

struct LINE_INFO* multi_search(FILE *file, const char *patterns_p[],int pattern_count ,int i_option,int r_option)
{
    struct LINE_INFO *result = (struct LINE_INFO *)malloc(MAX_FILE_LINE * sizeof(struct LINE_INFO));
    char line[MAX_LINE_LEN];
    int line_num = 0;
    int i = 0;
    char *patterns[pattern_count];

    for(int j = 0; j < pattern_count; j++){
        print(patterns_p[j]);
        print("\n");
    }
    if(r_option){
        regex_t regex;
        int reti;
        if (i_option) {
            reti = regcomp(&regex, patterns_p[0], REG_ICASE | REG_EXTENDED);
        } else {
            reti = regcomp(&regex, patterns_p[0], REG_EXTENDED);
        }
        if (reti) {
            print("Could not compile regex\n");
            exit(1);
        }
        ///// to do
        ////////////////////////////////////////////////////////////
        while(fgets(line, sizeof(line), file)){
            line_num++;
            result[i].line = strdup(line);
            result[i].line_num = line_num;
            result[i].if_in = 0;
            // print(line);
            reti = regexec(&regex, line, 0, NULL, 0);
            if (!reti) 
                result[i].if_in = 1;
            i++;
        ////////////////////////////////////////////////////////////////////
        }
        regfree(&regex);
    }else{
        if(i_option){
            for (int j = 0; j < pattern_count; j++){
                patterns[j] = strdup(patterns_p[j]);
                for (int k = 0; patterns[j][k]; k++) 
                    patterns[j][k] = tolower(patterns[j][k]);
            }                          
        }else{
            for (int j = 0; j < pattern_count; j++){
                patterns[j] = strdup(patterns_p[j]);
                }
        }
        while(fgets(line, sizeof(line), file)){
            line_num++;
            result[i].line = strdup(line);
            result[i].line_num = line_num;
            result[i].if_in = 0;
            for (int j = 0; j < pattern_count; j++)
            {
                if (contains(line, patterns[j], i_option))
                {
                    // print("  find\n");
                    // print(line);
                    result[i].if_in = 1;
                    break;
                }
            }
            i++;
        }
    }
    return result;
}

char * get_abs_path(const char* filename)
{
    if(contains(filename,"/",0)){
        return strdup(filename);
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        // print("Current working dir: ");
        // print(cwd);
        // print("\n");
        perror("getcwd() error");
        exit(1);
    } 
    char *full_path = malloc(1024);
    int l = 0;
    for (l; cwd[l];l++)
        full_path[l] = cwd[l];
    full_path[l] = '/';
    int m = 0;
    for (m; filename[m]; m++)
        full_path[l+m+1] = filename[m];
    full_path[l+m+1] = '\0';
    return full_path;
}

struct LINE_INFO *search_dir(const char *dir_p, const char *pattern_p, int i_option, int full_path_option)
{
    DIR *dir; //目录流
    struct dirent *entry; //目录项
    struct LINE_INFO *result = (struct LINE_INFO *)malloc(MAX_FILE_LINE * sizeof(struct LINE_INFO));
    char *pattern;
    pattern = strdup(pattern_p);

    if(i_option){
        for (int j = 0; pattern[j]; j++) 
            pattern[j] = tolower(pattern[j]);
    }
    if ((dir = opendir(dir_p)) == NULL) {
        perror("opendir() error");
        exit(1);
    } 
    
    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
            char *file_name = entry->d_name;
            if (contains(file_name, pattern, i_option)) {
                    if(full_path_option){
                    char *full_path = get_abs_path(file_name);
                    result[i].line = strdup(full_path);
                    free(full_path);
                    }else{
                        result[i].line = strdup(file_name);
                    }
                result[i].line_num = i + 1;
                result[i].if_in = 1;
                i++;
            }
        
    }

    return result;
}

////////////////////////////////////////////////////////////////