#include "cmd_random_number_generator.hpp"

void readArgs(int argc, char *argv[])
{
    bool naturalNum = false;
    int qtdNum = 1;
    int LI = 1;
    int LS = 100;
    int decimalPlaces = 1;
    // Get current timestamp in milliseconds
    auto now = chrono::system_clock::now().time_since_epoch();
    int64_t seed = chrono::duration_cast<chrono::milliseconds>(now).count();

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-i") == 0)
            naturalNum = true;
        else if (strcmp(argv[i], "-n") == 0)
            qtdNum = atoi(argv[i+1]);
        else if (strcmp(argv[i], "-r") == 0)
        {
            LI = atoi(argv[i+1]);
            LS = atoi(argv[i+2]);
        }
        else if (strcmp(argv[i], "-p") == 0)
            decimalPlaces = atoi(argv[i+1]);
        else if (strcmp(argv[i], "-s") == 0)
            seed = atoi(argv[i+1]);
    }

    generateRandomNumbers(naturalNum, qtdNum, LI, LS, decimalPlaces, seed);
}

void generateRandomNumbers(bool naturalNum, int qtdNum, int LI, int LS, int decimalPlaces, int64_t seed)
{
    mt19937 gen(seed);

    if (naturalNum) {
        uniform_int_distribution<int> naturalDis(LI, LS);
        for (int i = 0; i < qtdNum; ++i) {
            cout << naturalDis(gen) << endl;
        }
    } else {
        uniform_real_distribution<double> dis(LI, LS);
        for (int i = 0; i < qtdNum; ++i) {
            cout << fixed << setprecision(decimalPlaces) << dis(gen) << endl;
        }
    }
}