#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

typedef chrono::high_resolution_clock::time_point Clock;
typedef chrono::high_resolution_clock::duration Diff;
typedef chrono::high_resolution_clock Timer;

struct Param {
  int threadCnt_{1};
  Diff duration_{chrono::seconds(10)};

  bool parse(int argc, char* argv[]) {
    if (argc != 3) {
      usage();
      return false;
    }
    threadCnt_ = stoi(argv[1]);
    duration_ = Diff(strtoll(argv[2], nullptr, 0) * 1000000000);
    return true;
  }

  void usage() {
    cout << "cpu_test <thread count> <duration(sec)>\n";
    cout << "example : cpu_test 1 10\n";
  }
};

void run(Diff* duration) {
  Timer timer;
  Clock begin = timer.now();
  while (true) {
    Clock now = timer.now();
    Diff diff = now - begin;
    if (diff > *duration)
      break;
  }
}

int main(int argc, char *argv[])
{
  Param param;
  if (!param.parse(argc, argv))
    return 0;

  vector<thread*> threads;
  for (int i = 0; i < param.threadCnt_; i++)
    threads.push_back(new thread(run, &param.duration_));

  for (int i = 0; i < param.threadCnt_; i++)
    threads[i]->join();

  for (int i = 0; i < param.threadCnt_; i++)
    delete threads[i];

  return 0;
}
