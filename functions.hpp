#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

// #define _DEBUG

#define EPSILON 0.000'000'000'000'001

class Matrix
{
    public:
        vector<vector<double>> data;
        int sizeRow;
        int sizeColumn;

        Matrix(): sizeRow(0), sizeColumn(0) {}

        Matrix( int m, int n, bool isIdentity = false )
        : sizeRow(m), sizeColumn(n)
        {
            data.assign(m, vector<double>(n, 0));

            if( isIdentity )
            {
                if( m != n )
                {
                    cout << "ERROR: Can't be identity matrix.\n";
                }
                else
                {
                    for( int i = 0; i < n; i++ )
                    {
                        data[i][i] = 1.0;
                    }
                }
                
            }
        }

        Matrix( const Matrix& that )
        {
            sizeRow = that.sizeRow;
            sizeColumn = that.sizeColumn;
            data = that.data;
        }

        void setData( int i, int j, double value )
        {
            bool toResize = false;

            if( sizeRow <= i )
            {
                sizeRow = i + 1;
                toResize = true;
            }
            if( sizeColumn <= j )
            {
                sizeColumn = j + 1;
                toResize = true;
            }
            if( toResize )
            {
                data.resize( sizeRow );

                for( auto d : data )
                {
                    d.resize( sizeColumn );
                }
            }

            data[i][j] = value;
        }

        void printData()
        {
            for( auto i : data )
            {
                for( auto j : i )
                {
                    if( fabs(j) < EPSILON )
                        cout << 0.0 << "\t";
                    else
                        cout << j << "\t";
                }
                cout << endl;
            }
        }
};

inline void verify( Matrix A, double eigenValue, vector<double> eigenVector, int n )
{
    vector<double> result(n, 0);

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            result[i] += A.data[i][j] * eigenVector[j];
        }
    }

    cout << "Ax =\t\t";
    for( auto rs: result )
    {
        cout << rs << "\t";
    }
    cout << endl;

    for( int i = 0; i < n; i++ )
    {
        result[i] = eigenValue * eigenVector[i];
    }

    cout << "lambda x =\t";
    for( auto rs: result )
    {
        cout << rs << "\t";
    }
    cout << endl;
}

inline Matrix generateSymmetricMatrix( int n )
{
    srand( 0 );
    Matrix symmetricMatrix(n, n);
    double value;

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            value = (double)(rand()%20);
            symmetricMatrix.setData(i, j, value);
            symmetricMatrix.setData(j, i, value);
        }
    }

    return symmetricMatrix;
}

pair<int, int> findMaxpq( Matrix matrix, int n )
{
    pair<int, int> pq = make_pair(0, 1);
    double maximum = fabs(matrix.data[0][1]);

    for( int i = 0; i < n; i++ )
    {
        for( int j = i + 1; j < n; j++ )
        {
            if( fabs(matrix.data[i][j]) > maximum )
            {
                pq = make_pair( i, j );
                maximum = fabs(matrix.data[i][j]);
            }
        }
    }

    return pq;
}

void updateP( Matrix& P, int p, int q, double c, double s, int n )
{
    Matrix Q(P);

    for(int k = 0; k < n; k++ )
    {
        Q.data[p][k] = c * P.data[k][p] + s * P.data[k][q];
        Q.data[q][k] = -s * P.data[k][p] + c * P.data[k][q];
    }

    for(int k = 0; k < n; k++ )
    {
        P.data[k][p] = Q.data[p][k];
        P.data[k][q] = Q.data[q][k];
    }
}

void updateA( Matrix& A, int p, int q, double c, double s, int n )
{
    Matrix B(n,n);

    B.data[p][p] = c*c * A.data[p][p] + 2*s*c * A.data[p][q] + s*s * A.data[q][q];
    B.data[q][q] = s*s * A.data[p][p] - 2*s*c * A.data[p][q] + c*c * A.data[q][q];

    for( int k = 0; k < n; k++ )
    {
        if( k == p || k == q ) continue;
        B.data[p][k] = c * A.data[k][p] + s * A.data[k][q];
        B.data[q][k] = -s * A.data[k][p] + c * A.data[k][q];
    }

    for( int k = 0; k < n; k++ )
    {
        A.data[p][k] = A.data[k][p] = B.data[p][k];
        A.data[q][k] = A.data[k][q] = B.data[q][k];
    }

    // A.data[p][q] = A.data[q][p] = 0.0;
}

pair<int, vector<pair<double, vector<double>>>> JacobiMethod( Matrix matrix, int n )
{
    Matrix A(matrix);
    int iterationTime = 0;
    bool isIdentity = true;
    Matrix P( n, n, isIdentity );

    pair<int, int> pq = findMaxpq( A, n );
    int p = pq.first;
    int q = pq.second;

    double theta;
    double c;
    double s;

    while( fabs( A.data[p][q] ) > EPSILON )
    {
        theta = 0.5 * atan2( 2 * A.data[p][q],
                            A.data[p][p] - A.data[q][q] );

        c = cos( theta );
        s = sin( theta );

        updateP( P, p, q, c, s, n );
        updateA( A, p, q, c, s, n );

        pq = findMaxpq( A, n );
        p = pq.first;
        q = pq.second;

        iterationTime++;
    }

    vector<pair<double, vector<double>>> eigenSystem(n);

    for( int i = 0; i < n; i++ )
    {
        eigenSystem[i].first = A.data[i][i];

        for( int j = 0; j < n; j++ )
        {
            eigenSystem[i].second.push_back(P.data[j][i]);
        }
    }

    return make_pair( iterationTime, eigenSystem );
}
