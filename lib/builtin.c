#define bool _Bool
#define size_t unsigned

#define BUFFER_SIZE 256

int printf(const char *format, ...);

int putchar(int ch);

int sscanf(const char *str, const char *format, ...);

int scanf(const char *format, ...);

int sprintf(char *str, const char *format, ...);

void *malloc(size_t size);

void *calloc(size_t num, size_t size);

size_t strlen(const char *str);

int strcmp(const char *str1, const char *str2);

char *strcpy(char *dest, const char *src);

char *strcat(char *dest, const char *src);

void *memcpy(void *dest, const void *src, size_t count);

void print(const char *str) {
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] != '\\') {
	  putchar(str[i]);
    } else if (str[++i] == 'n') {
      putchar('\n');
    } else if (str[i] == '\\') {
      putchar('\\');
    } else if (str[i] == '\"') {
      putchar('\"');
    }
  }
}

void println(const char *str) {
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] != '\\') {
	  putchar(str[i]);
    } else if (str[++i] == 'n') {
      putchar('\n');
    } else if (str[i] == '\\') {
      putchar('\\');
    } else if (str[i] == '\"') {
      putchar('\"');
    }
  }
  putchar('\n');
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

int ptr_length(const char *str) {
  return strlen(str);
}

char *ptr_substring(const char *str, int start, int end) {
  char *ret = malloc(end - start + 1);
  memcpy(ret, str + start, end - start);
  ret[end - start] = 0;
  return ret;
}

int ptr_parseInt(const char *str) {
  int ret;
  sscanf(str, "%d", &ret);
  return ret;
}

int ptr_ord(const char *str, int pos) {
  return str[pos];
}

size_t builtin_getSize(int *ptr) {
  return *(ptr - 1);
}

void builtin_printBool(char val) {
  printf(val ? "true" : "false");
}

void *builtin_allocArray(size_t len) {
  int *ptr = calloc(len + 1, 4);
  ptr[0] = len;
  return ptr + 1;
}

void *builtin_stringConcatenate(const char *str1, const char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *ret = malloc(len1 + len2 + 1);
  strcpy(ret, str1);
  strcat(ret, str2);
  ret[len1 + len2] = '\0';
  return ret;
}
