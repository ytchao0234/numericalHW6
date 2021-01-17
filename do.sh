g++ main.cpp && ./a.out > out
gnuplot --persist ./plot/size_time.plt
gnuplot --persist ./plot/norm.plt
gnuplot --persist ./plot/sumOffDiagonal.plt 