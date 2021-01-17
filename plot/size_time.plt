set terminal qt size 800, 800;

set key top right

set title 'HW6 - Eigen System - Jacobi Method - sumOffDiagonal'
set xlabel 'matrix size'
set ylabel 'iteration time'
set grid
set xrange [3:20]
set yrange [0:800]
set xtics 1
set ytics 50
set xzeroaxis
set yzeroaxis

plot "./size_time.dat" with linespoints title "matrix size - iteration time"