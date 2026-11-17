#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>


int main() {
    printf("hello");

    FILE * file = fopen("data/quotes.json", "r");
    if (file == NULL){
        printf("failed to load quotes:(\n");
        return 1;
    }

    char buffer[1024];
    int l = fread(buffer, sizeof(char), sizeof(buffer), file);
    fclose(file);
    printf("%d", l);
    printf("%s", buffer);

    cJSON *json = cJSON_Parse(buffer);
    if (json == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL){
            printf("error: %s\n", error_ptr);
        }
        cJSON_Delete(json);
        return 1;
    }
    
    cJSON *name = cJSON_GetObjectItemCaseSensitive(json, "1");
    if (cJSON_IsString(name) && (name->valuestring != NULL)){
        printf("name: %s\n", name->valuestring);
    }

    cJSON_Delete(json);

    return 0;
}
