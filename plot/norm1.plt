set terminal qt size 800, 800;

set key top right

set title 'HW6 - Eigen System - Jacobi Method - norm1'
set xlabel 'norm'
set ylabel 'eigen system'
set grid
set xrange [3:10]
set yrange [0.00000000000000001:1000000]
set xtics 1
set logscale y 100
set xzeroaxis
set yzeroaxis
set pointintervalbox 5
set sample 1000
# set size ratio -1
set parametric

plot "./norm1/norm1_3.dat" with linespoints title "norm1 3", \
     "./norm1/norm1_4.dat" with linespoints title "norm1 4", \
     "./norm1/norm1_5.dat" with linespoints title "norm1 5", \
     "./norm1/norm1_6.dat" with linespoints title "norm1 6", \
     "./norm1/norm1_7.dat" with linespoints title "norm1 7", \
     "./norm1/norm1_8.dat" with linespoints title "norm1 8", \
     "./norm1/norm1_9.dat" with linespoints title "norm1 9", \
     "./norm1/norm1_10.dat" with linespoints title "norm1 10", \
     "./norm1/norm1_11.dat" with linespoints title "norm1 11", \
     "./norm1/norm1_12.dat" with linespoints title "norm1 12", \
     "./norm1/norm1_13.dat" with linespoints title "norm1 13", \
     "./norm1/norm1_14.dat" with linespoints title "norm1 14", \
     "./norm1/norm1_15.dat" with linespoints title "norm1 15", \
     "./norm1/norm1_16.dat" with linespoints title "norm1 16", \
     "./norm1/norm1_17.dat" with linespoints title "norm1 17", \
     "./norm1/norm1_18.dat" with linespoints title "norm1 18", \
     "./norm1/norm1_19.dat" with linespoints title "norm1 19", \
     "./norm1/norm1_20.dat" with linespoints title "norm1 20"