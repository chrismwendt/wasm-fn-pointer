#include <stdio.h>
#include <string>

int main() {
  printf("hello, world!\n");
  return 0;
}

class LSPLoop {
public:
  LSPLoop(void (*respond)(char *))
    : respond(respond)
  {}

  void send(char *message) {
    respond(message);
  }

private:
  void (*respond)(char *);
};

extern "C" {
LSPLoop *newLSPLoop(void (*respond)(char *)) {
    return new LSPLoop(respond);
}

void LSPLoop_send(LSPLoop *loop, char *message) {
    loop->send(message);
}
}
