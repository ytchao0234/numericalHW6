#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define _DEBUG

#define EPSILON 0.000'001

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
                        cout << 0.0 << " ";
                    else
                        cout << j << " ";
                }
                cout << endl;
            }
        }
};

inline void verification( Matrix A, double eigenValue, vector<double> eigenVector )
{
    if( A.sizeColumn != eigenVector.size() )
    {
        cout << "ERROR: size error.\n";
        return;
    }

    vector<double> result(eigenVector.size());

    for( int i = 0; i < A.sizeRow; i++ )
    {
        result[i] = 0;

        for( int j = 0; j < A.sizeColumn; j++ )
        {
            result[i] += A.data[i][j] * eigenVector[j];
        }
    }

    for( auto rs: result )
    {
        cout << rs << " ";
    }
    cout << endl;

    for( int i = 0; i < eigenVector.size(); i++ )
    {
        result[i] = eigenValue * eigenVector[i];
    }

    for( auto rs: result )
    {
        cout << rs << " ";
    }
    cout << endl;
}

multiset<pair<double, pair<int, int>>> makeMaxHeap( Matrix matrix )
{
    multiset<pair<double, pair<int, int>>> maxHeap;
    pair<double, pair<int, int>> heapValue;

    for( int i = 0; i < matrix.sizeRow; i++ )
    {
        for( int j = i + 1; j < matrix.sizeColumn; j++ )
        {
            heapValue.first = fabs(matrix.data[i][j]);
            heapValue.second.first = i;
            heapValue.second.second = j;
            maxHeap.insert( heapValue );
        }
    }
    
    return maxHeap;
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

void printMaxHeap( multiset<pair<double, pair<int, int>>> maxHeap )
{
    for( auto value : maxHeap )
    {
        cout << value.first << " " << value.second.first << " " << value.second.second << endl;
    }
    cout << endl;
}

pair<int, int> findMaxpq( multiset<pair<double, pair<int, int>>>& maxHeap )
{
    int p = maxHeap.rbegin()->second.first;
    int q = maxHeap.rbegin()->second.second;

    multiset<pair<double, pair<int, int>>>::iterator maxHeapIt;
    maxHeapIt = maxHeap.end();
    maxHeap.erase(--maxHeapIt);

    return make_pair( p, q );
}

void updateP( Matrix& P, int p, int q, double cosTheta, double sinTheta )
{
    for(int k = 0; k < P.sizeRow; k++ )
    {
        P.data[k][p] = cosTheta * P.data[k][p] + sinTheta * P.data[k][q];
        P.data[k][q] = -sinTheta * P.data[k][p] + cosTheta * P.data[k][q];
    }
}

void updateA( Matrix& A, multiset<pair<double, pair<int, int>>>& maxHeap,
              int p, int q, double cosTheta, double sinTheta )
{
    Matrix B(A);

    B.data[p][p] = cosTheta * cosTheta * A.data[p][p] + 
                   2 * sinTheta * cosTheta * A.data[p][q] + 
                   sinTheta * sinTheta * A.data[q][q];

    B.data[q][q] = sinTheta * sinTheta * A.data[p][p] - 
                   2 * sinTheta * cosTheta * A.data[p][q] + 
                   cosTheta * cosTheta * A.data[q][q];

    for( int k = 0; k < B.sizeColumn; k++ )
    {
        if( k == p || k == q ) continue;
        B.data[p][k] = cosTheta * A.data[k][p] + sinTheta * A.data[k][q];
        B.data[q][k] = -sinTheta * A.data[k][p] + cosTheta * A.data[k][q];
    }

    for( int k = 0; k < A.sizeRow; k++ )
    {
        A.data[p][k] = A.data[k][p] = B.data[p][k];
        A.data[q][k] = A.data[k][q] = B.data[q][k];
    }

    A.data[p][q] = A.data[q][p] = 0.0;

    maxHeap = makeMaxHeap( A );
}

int JacobiMethod( Matrix matrix, multiset<pair<double, pair<int, int>>> maxHeap )
{
    Matrix A(matrix);
    int iterationTime = 0;
    bool isIdentity = true;
    Matrix P(A.sizeRow, A.sizeColumn, isIdentity );

    pair<int, int> pq = findMaxpq( maxHeap );
    int p = pq.first;
    int q = pq.second;

    double theta;
    double sinTheta;
    double cosTheta;

    while( fabs( A.data[p][q] ) > EPSILON )
    {
        theta = 0.5 * atan2( 2 * A.data[p][q],
                            A.data[p][p] - A.data[q][q] );

        sinTheta = sin( theta );
        cosTheta = cos( theta );

        updateP( P, p, q, cosTheta, sinTheta );
        updateA( A, maxHeap, p, q, cosTheta, sinTheta );
        
        #ifdef _DEBUG
            P.printData();
            cout << endl;
            A.printData();
            cout << "-------------------------\n";
        #endif

        pq = findMaxpq( maxHeap );
        p = pq.first;
        q = pq.second;

        iterationTime++;
    }

    vector<double> eigenVector(A.sizeRow);
    double eigenValue;

    for( int i = 0; i < P.sizeRow; i++ )
    {
        for( int j = 0; j < P.sizeColumn; j++ )
        {
            eigenVector[j] = P.data[i][j];
        }

        cout << "--------------------------------\n";
        cout << "verify " << i + 1 << endl;
        eigenValue = A.data[i][i];
        verification( matrix, eigenValue, eigenVector );
        cout << "--------------------------------\n";
    }

    return iterationTime;
}
