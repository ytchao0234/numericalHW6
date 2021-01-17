#include "functions.hpp"

int main()
{
    ofstream file_NM("./size_time.dat");
    file_NM << "# matrix size\titeration time\n";

    ofstream file_norm1( "norm1.dat" );
    file_norm1 << setprecision(numeric_limits<double>::digits10) << fixed;
    file_norm1 << "# size\tnorm\n";

    ofstream file_norm2( "norm2.dat" );
    file_norm2 << setprecision(numeric_limits<double>::digits10) << fixed;
    file_norm2 << "# size\tnorm\n";

    ofstream file_normInf( "normInf.dat" );
    file_normInf << setprecision(numeric_limits<double>::digits10) << fixed;
    file_normInf << "# size\tnorm\n";

    vector<double> norm1List;
    vector<double> norm2List;
    vector<double> normInfList;

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

        ofstream file_norm1s( "norm1/norm1_" + to_string(n) + ".dat" );
        file_norm1s << setprecision(numeric_limits<double>::digits10) << fixed;
        file_norm1s << "# index\tnorm\n";

        ofstream file_norm2s( "norm2/norm2_" + to_string(n) + ".dat" );
        file_norm2s << setprecision(numeric_limits<double>::digits10) << fixed;
        file_norm2s << "# index\tnorm\n";

        ofstream file_normInfs( "normInf/normInf_" + to_string(n) + ".dat" );
        file_normInfs << setprecision(numeric_limits<double>::digits10) << fixed;
        file_normInfs << "# index\tnorm\n";

        norm1List.assign(n, 0);
        norm2List.assign(n, 0);
        normInfList.assign(n, 0);

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
            file_norm1s << i << "\t\t" << norm << endl;

            norm1List[i] = norm;

            norm = normOfAx_lambdax( Ax_lambdax.first, Ax_lambdax.second, n, &norm2 );
            file_norm2s << i << "\t\t" << norm << endl;

            norm2List[i] = norm;

            norm = normOfAx_lambdax( Ax_lambdax.first, Ax_lambdax.second, n, &normInfinity );
            file_normInfs << i << "\t\t" << norm << endl;

            normInfList[i] = norm;
        }

        file_norm1 << n << "\t" << norm1(norm1List, n) << endl;
        file_norm2 << n << "\t" << norm1(norm2List, n) << endl;
        file_normInf << n << "\t" << norm1(normInfList, n) << endl;

        file_eigen.close();
        file_norm1s.close();
        file_norm2s.close();
        file_normInfs.close();

        cout << "-----------------------------------\n";
    }

    file_NM.close();
    file_norm1.close();
    file_norm2.close();
    file_normInf.close();

    return 0;
}