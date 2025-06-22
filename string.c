#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison 1: Lexicographically non-decreasing
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// Comparison 2: Lexicographically non-increasing
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Helper to count number of distinct characters
int count_distinct_characters(const char* s) {
    int count[26] = {0}, distinct = 0;
    while (*s) {
        if (!count[*s - 'a']++) {
            distinct++;
        }
        s++;
    }
    return distinct;
}

// Comparison 3: By number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int diff = count_distinct_characters(a) - count_distinct_characters(b);
    return diff != 0 ? diff : strcmp(a, b);
}

// Comparison 4: By length
int sort_by_length(const char* a, const char* b) {
    int diff = strlen(a) - strlen(b);
    return diff != 0 ? diff : strcmp(a, b);
}

// Custom string sort function using selection sort
void string_sort(const char **arr, const int cnt, int (*cmp_func)(const char*, const char*)) {
    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = i + 1; j < cnt; ++j) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                const char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    char strings[50][100];
    const char* arr[50];

    for (int i = 0; i < n; ++i) {
        scanf("%s", strings[i]);
        arr[i] = strings[i];
    }

    // 1. Lexicographic sort
    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);

    // 2. Lexicographic reverse
    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);

    // 3. By number of distinct characters
    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);

    // 4. By length
    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);

    return 0;
}
