set terminal qt size 800, 800;

set key top right

set title 'HW6 - Eigen System - Jacobi Method - normInf'
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

plot "./normInf/normInf_3.dat" with linespoints title "normInf 3", \
     "./normInf/normInf_4.dat" with linespoints title "normInf 4", \
     "./normInf/normInf_5.dat" with linespoints title "normInf 5", \
     "./normInf/normInf_6.dat" with linespoints title "normInf 6", \
     "./normInf/normInf_7.dat" with linespoints title "normInf 7", \
     "./normInf/normInf_8.dat" with linespoints title "normInf 8", \
     "./normInf/normInf_9.dat" with linespoints title "normInf 9", \
     "./normInf/normInf_10.dat" with linespoints title "normInf 10", \
     "./normInf/normInf_11.dat" with linespoints title "normInf 11", \
     "./normInf/normInf_12.dat" with linespoints title "normInf 12", \
     "./normInf/normInf_13.dat" with linespoints title "normInf 13", \
     "./normInf/normInf_14.dat" with linespoints title "normInf 14", \
     "./normInf/normInf_15.dat" with linespoints title "normInf 15", \
     "./normInf/normInf_16.dat" with linespoints title "normInf 16", \
     "./normInf/normInf_17.dat" with linespoints title "normInf 17", \
     "./normInf/normInf_18.dat" with linespoints title "normInf 18", \
     "./normInf/normInf_19.dat" with linespoints title "normInf 19", \
     "./normInf/normInf_20.dat" with linespoints title "normInf 20"