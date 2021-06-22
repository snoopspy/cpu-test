#include <chrono>
#include <iostream>
#include <string>
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
		cout << "syntax: cpu_test <thread count> <duration(sec)>\n";
		cout << "sample: cpu_test 4 10\n";
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

int main(int argc, char *argv[]) {
	Param param;
	if (!param.parse(argc, argv))
		return 0;

	vector<thread*> threads;
	for (int i = 0; i < param.threadCnt_; i++)
		threads.push_back(new thread(run, &param.duration_));

	for (thread* thrd: threads)
		thrd->join();

	for (thread* thrd: threads)
		delete thrd;

	return 0;
}
