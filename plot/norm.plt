set terminal qt size 800, 800;

set key top right

set title 'HW6 - Eigen System - Jacobi Method - norm'
set xlabel 'matrix size'
set ylabel 'norm of \{Ax - lambda x\}'
set grid
set xrange [3:20]
set yrange [0.00000000000001:0.00000000001]
set xtics 1
set logscale y 100
set xzeroaxis
set yzeroaxis
set pointintervalbox 5
set sample 1000
# set size ratio -1
set parametric

plot "./norm1.dat" with linespoints title "norm1", \
     "./norm2.dat" with linespoints title "norm2", \
     "./normInf.dat" with linespoints title "normInf"