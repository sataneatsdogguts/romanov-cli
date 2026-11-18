#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cjson/cJSON.h>

const char * getRand(int min, int max){
    static char buffer[5];
    int num = min + rand() % (max - min + 1);
    snprintf(buffer, sizeof(buffer), "%d", num);
    return buffer;
}

int getJSON(cJSON **json){
    FILE * file = fopen(QUOTES_PATH, "rb");
    if (file == NULL){
        printf("failed to load quotes:(\n");
        return 1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        printf("fseek error\n");
        return 3;
    }

    long size = ftell(file);
    rewind(file);
    
    char * buffer = malloc((size_t)size + 1);
    fread(buffer, sizeof(char), size, file);
    buffer[size] = '\0';
    fclose(file);

    *json = cJSON_Parse(buffer);
    free(buffer);
    if (json == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL){
            printf("error: %s\n", error_ptr);
        }
        return 2;
    }
    return 0;
}

void getQuote(cJSON * json, const char * idx){
    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, idx);
    if (cJSON_IsString(name) && (name->valuestring != NULL)){
        printf("%s\n", name->valuestring);
    }
}

int main() {
    srand(time(NULL));

    cJSON *json;
    int g = getJSON(&json);
    if (g>0) return g;

    const int max_idx = cJSON_GetArraySize(json);
    const char * idx = getRand(1, max_idx);
    getQuote(json, idx);

    cJSON_Delete(json);
    return 0;
}
