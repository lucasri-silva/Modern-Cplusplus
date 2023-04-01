#include <iostream>
#include <csignal>
#include <chrono>

using namespace std;

bool endApp = false;

void handler(int signum) {
    if (endApp) {
        exit(signum);
    } else {
        cout << "Para encerrar, pressione Ctrl + c novamente" << endl;
        endApp = true;
    }
}

int main() {
    cout << "Tente encerrar esse processo..." << endl;
    signal(SIGINT, handler);

    while (true) {
    }

    return 0;
}