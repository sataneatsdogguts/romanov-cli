#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cjson/cJSON.h>

const char * getRand(int min, int max){
    static char buffer[16];
    int num = min + rand() % (max - min + 1);
    snprintf(buffer, sizeof(buffer), "%d", num);
    return buffer;
}

int getJSON(cJSON **json){
    FILE * file = fopen("data/quotes.json", "r");
    if (file == NULL){
        printf("failed to load quotes:(\n");
        return 1;
    }
    char buffer[1024*4] = {0};
    fread(buffer, sizeof(char), sizeof(buffer), file);
    fclose(file);

    *json = cJSON_Parse(buffer);
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

    const char * idx = getRand(1, 11);
    getQuote(json, idx);

    cJSON_Delete(json);
    return 0;
}
