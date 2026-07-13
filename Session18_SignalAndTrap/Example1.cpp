#include <iostream>
#include <signal.h>

using namespace std;

void sig_handler(int signo)
{
  if (signo == SIGINT)
    cout << "received SIGINT" << endl;
}

int main(void)
{
  if (signal(SIGINT, sig_handler) == SIG_ERR)
  cout << "can't catch SIGINT" << endl;
  // A long long wait so that we can easily issue a signal to this 
  // process
  while(1) {
    sleep(1);
  }
  return 0;
}
