#include "functions.hpp"

int main()
{
    Matrix symmetricMatrix = generateSymmetricMatrix(3);
    multiset<pair<double, pair<int, int>>> maxHeap = makeMaxHeap( symmetricMatrix );

    #ifdef _DEBUG
        cout << setprecision( 6 ) << fixed;
        cout << "initial: \n";
        symmetricMatrix.printData();
        cout << "--------------------\n";
    #endif

    int time = JacobiMethod( symmetricMatrix, maxHeap );

    cout << "time: " << time << endl; 

    return 0;
}