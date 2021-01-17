set terminal qt size 800, 800;

set key top right

set title 'HW6 - Eigen System - Jacobi Method - sumOffDiagonal'
set xlabel 'iteration time'
set ylabel 'sum of off diagonal entities'
set grid
set xrange [0:800]
set yrange [0:2000]
set xtics 50
set ytics 100
set xzeroaxis
set yzeroaxis

plot "./sumOffDiagonal/sumOffDiagonal_3.dat" with linespoints title "sumOffDiagonal 3", \
     "./sumOffDiagonal/sumOffDiagonal_4.dat" with linespoints title "sumOffDiagonal 4", \
     "./sumOffDiagonal/sumOffDiagonal_5.dat" with linespoints title "sumOffDiagonal 5", \
     "./sumOffDiagonal/sumOffDiagonal_6.dat" with linespoints title "sumOffDiagonal 6", \
     "./sumOffDiagonal/sumOffDiagonal_7.dat" with linespoints title "sumOffDiagonal 7", \
     "./sumOffDiagonal/sumOffDiagonal_8.dat" with linespoints title "sumOffDiagonal 8", \
     "./sumOffDiagonal/sumOffDiagonal_9.dat" with linespoints title "sumOffDiagonal 9", \
     "./sumOffDiagonal/sumOffDiagonal_10.dat" with linespoints title "sumOffDiagonal 10", \
     "./sumOffDiagonal/sumOffDiagonal_11.dat" with linespoints title "sumOffDiagonal 11", \
     "./sumOffDiagonal/sumOffDiagonal_12.dat" with linespoints title "sumOffDiagonal 12", \
     "./sumOffDiagonal/sumOffDiagonal_13.dat" with linespoints title "sumOffDiagonal 13", \
     "./sumOffDiagonal/sumOffDiagonal_14.dat" with linespoints title "sumOffDiagonal 14", \
     "./sumOffDiagonal/sumOffDiagonal_15.dat" with linespoints title "sumOffDiagonal 15", \
     "./sumOffDiagonal/sumOffDiagonal_16.dat" with linespoints title "sumOffDiagonal 16", \
     "./sumOffDiagonal/sumOffDiagonal_17.dat" with linespoints title "sumOffDiagonal 17", \
     "./sumOffDiagonal/sumOffDiagonal_18.dat" with linespoints title "sumOffDiagonal 18", \
     "./sumOffDiagonal/sumOffDiagonal_19.dat" with linespoints title "sumOffDiagonal 19", \
     "./sumOffDiagonal/sumOffDiagonal_20.dat" with linespoints title "sumOffDiagonal 20"