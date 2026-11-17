#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{

    for (int i = 1; i < argc; i++)
    {
        if (float ArgvInput = atof(argv[i]) == 0)
        {
            cout << "Invalid input" << endl;
        }
        else
        {
            cout << argv[i] << endl;
        }

    }


    return 0;
}
