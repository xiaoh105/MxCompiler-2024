#define bool _Bool
#define size_t unsigned

#define BUFFER_SIZE 256

int printf(const char *format, ...);

int sscanf(const char *str, const char *format, ...);

int scanf(const char *format, ...);

int sprintf(char *str, const char *format, ...);

void *malloc(size_t size);

void *calloc(size_t num, size_t size);

size_t strlen(const char *str);

int strcmp(const char *str1, const char *str2);

char *strcpy(char *dest, const char *src);

char *strcat( char *dest, const char *src );

void print(const char *str) {
  printf("%s", str);
}

void println(const char *str) {
  printf("%s\n", str);
}

void printInt(int val) {
  printf("%d", val);
}

void printlnInt(int val) {
  printf("%d\n", val);
}

const char *getString() {
  char *str = malloc(BUFFER_SIZE);
  scanf("%s", str);
  return str;
}

int getInt() {
  int ret;
  scanf("%d", &ret);
  return ret;
}

const char *toString(int val) {
  char *str = malloc(16);
  sprintf(str, "%d", val);
  return str;
}

void builtin_printBool(bool val) {
  printf(val ? "true" : "false");
}

void *builtin_allocArrayInt(size_t len) {
  int *ptr = calloc(len + 1, 4);
  ptr[0] = len;
  return ptr + 1;
}

void *builtin_allocArrayBool(size_t len) {
  int *ptr = malloc(len + 4);
  ptr[0] = len;
  return ptr + 1;
}

void *builtin_stringConcatenate(const char *str1, const char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *ret = malloc(len1 + len2);
  strcpy(ret, str1);
  strcat(ret, str2);
  return ret;
}
