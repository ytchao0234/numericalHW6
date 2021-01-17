#include "functions.hpp"

int main()
{
    ofstream file_NM("./size_time.dat");
    file_NM << "# matrix size\titeration time\n";

    for( int n = 3; n <= 20; n++ )
    {
        Matrix symmetricMatrix = generateSymmetricMatrix(n);

        pair<int, vector<pair<double, vector<double>>>> result
            = JacobiMethod( symmetricMatrix, n );

        int iterationTime = result.first;
        vector<pair<double, vector<double>>> eigenSystem = result.second;

        cout << "matrix size: " << n << endl;
        cout << "iterationTime: " << iterationTime << endl;

        file_NM << n << "\t\t\t\t" << iterationTime << endl;

        ofstream file_eigen( "eigenSystem/eigen_" + to_string(n) + ".dat" );
        file_eigen << setprecision(numeric_limits<double>::digits10) << fixed;
        file_eigen << "# eigen value\t\teigen vector\n";

        ofstream file_norm1( "norm1/norm1_" + to_string(n) + ".dat" );
        file_norm1 << setprecision(numeric_limits<double>::digits10) << fixed;
        file_norm1 << "# index\tnorm\n";

        ofstream file_norm2( "norm2/norm2_" + to_string(n) + ".dat" );
        file_norm2 << setprecision(numeric_limits<double>::digits10) << fixed;
        file_norm2 << "# index\tnorm\n";

        ofstream file_normInf( "normInf/normInf_" + to_string(n) + ".dat" );
        file_normInf << setprecision(numeric_limits<double>::digits10) << fixed;
        file_normInf << "# index\tnorm\n";

        for( int i = 0; i < n; i++ )
        {
            pair<vector<double>, vector<double>> Ax_lambdax
                = verify( symmetricMatrix, eigenSystem[i].first, eigenSystem[i].second, n );

            file_eigen << eigenSystem[i].first << "\t{";
            for( auto eigenVectorEntity : eigenSystem[i].second )
            {
                file_eigen << eigenVectorEntity << "\t";
            }
            file_eigen << "}\n";

            double norm;
            norm = normOfAx_lambdax( Ax_lambdax.first, Ax_lambdax.second, n, &norm1 );
            file_norm1 << i << "\t\t" << norm << endl;

            norm = normOfAx_lambdax( Ax_lambdax.first, Ax_lambdax.second, n, &norm2 );
            file_norm2 << i << "\t\t" << norm << endl;

            norm = normOfAx_lambdax( Ax_lambdax.first, Ax_lambdax.second, n, &normInfinity );
            file_normInf << i << "\t\t" << norm << endl;
        }

        file_eigen.close();
        file_norm1.close();
        file_norm2.close();
        file_normInf.close();

        cout << "-----------------------------------\n";
    }

    file_NM.close();

    return 0;
}