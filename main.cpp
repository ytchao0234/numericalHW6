#include "functions.hpp"

int main()
{
    for( int n = 3; n <= 20; n++ )
    {
        Matrix symmetricMatrix = generateSymmetricMatrix(n);

        pair<int, vector<pair<double, vector<double>>>> result
            = JacobiMethod( symmetricMatrix, n );

        int iterationTime = result.first;
        vector<pair<double, vector<double>>> eigenSystem = result.second;

        cout << "matrix size: " << n << endl;
        cout << "iterationTime: " << iterationTime << endl;

        #ifdef _DEBUG
            cout << "matrix: " << endl;
            symmetricMatrix.printData();
            cout << endl;

            cout << setprecision(numeric_limits<double>::digits10) << fixed;

            for( int i = 0; i < n; i++ )
            {
                cout << "verify " << i + 1 << endl;
                cout << "eigenValue: " << eigenSystem[i].first << endl;
                cout << "eigenVector: ";
                for( int j = 0; j < n; j++ ) cout << eigenSystem[i].second[j] << " ";
                cout << endl;
                verify( symmetricMatrix, eigenSystem[i].first, eigenSystem[i].second, n);
                cout << "-----------------------------------\n";
            }
        #endif
        
        cout << "-----------------------------------\n";
    }

    return 0;
}