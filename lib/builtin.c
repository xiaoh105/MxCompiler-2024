#define bool _Bool
#define size_t unsigned

#define BUFFER_SIZE 256

int printf(const char *format, ...);

int sscanf(const char *str, const char *format, ...);

int scanf(const char *format, ...);

int sprintf(char *str, const char *format, ...);

void *malloc(size_t size);

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
