set terminal qt size 800, 800;

set key top right

set title 'HW6 - Eigen System - Jacobi Method - norm2'
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

plot "./norm2/norm2_3.dat" with linespoints title "norm2 3", \
     "./norm2/norm2_4.dat" with linespoints title "norm2 4", \
     "./norm2/norm2_5.dat" with linespoints title "norm2 5", \
     "./norm2/norm2_6.dat" with linespoints title "norm2 6", \
     "./norm2/norm2_7.dat" with linespoints title "norm2 7", \
     "./norm2/norm2_8.dat" with linespoints title "norm2 8", \
     "./norm2/norm2_9.dat" with linespoints title "norm2 9", \
     "./norm2/norm2_10.dat" with linespoints title "norm2 10", \
     "./norm2/norm2_11.dat" with linespoints title "norm2 11", \
     "./norm2/norm2_12.dat" with linespoints title "norm2 12", \
     "./norm2/norm2_13.dat" with linespoints title "norm2 13", \
     "./norm2/norm2_14.dat" with linespoints title "norm2 14", \
     "./norm2/norm2_15.dat" with linespoints title "norm2 15", \
     "./norm2/norm2_16.dat" with linespoints title "norm2 16", \
     "./norm2/norm2_17.dat" with linespoints title "norm2 17", \
     "./norm2/norm2_18.dat" with linespoints title "norm2 18", \
     "./norm2/norm2_19.dat" with linespoints title "norm2 19", \
     "./norm2/norm2_20.dat" with linespoints title "norm2 20"