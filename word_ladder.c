#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5000
#define WORD_LEN 15
#define QUEUE_SIZE 10000

typedef struct {
    char word[WORD_LEN];
    int steps;
} Node;

// Checks if two words differ by only one character
int oneLetterDiff(const char* a, const char* b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return 0;
    }
    return diff == 1;
}

// BFS to find shortest transformation
int ladderLength(char* beginWord, char* endWord, char wordList[][WORD_LEN], int wordCount) {
    int visited[MAX_WORDS] = {0};
    Node queue[QUEUE_SIZE];
    int front = 0, rear = 0;

    // enqueue beginWord
    strcpy(queue[rear].word, beginWord);
    queue[rear++].steps = 1;

    while (front < rear) {
        Node current = queue[front++];

        if (strcmp(current.word, endWord) == 0)
            return current.steps;

        for (int i = 0; i < wordCount; i++) {
            if (!visited[i] && oneLetterDiff(current.word, wordList[i])) {
                visited[i] = 1;
                strcpy(queue[rear].word, wordList[i]);
                queue[rear++].steps = current.steps + 1;
            }
        }
    }

    return 0; // not reachable
}
int main() {
    char beginWord[] = "hit";
    char endWord[] = "cog";
    char wordList[MAX_WORDS][WORD_LEN] = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };
    int wordCount = 6;

    int result = ladderLength(beginWord, endWord, wordList, wordCount);
    printf("Shortest transformation length: %d\n", result);

    return 0;
}
