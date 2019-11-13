# gnu plot
set key autotitle columnhead
set ylabel "Time in milliseconds"

stats '../output/FibRecur' using 2:3
set title 'FibRecur X vs Time (ms)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / (2**n)
f(x) = a*2**x
set yrange [0:t]
set xrange [0:n]
plot '../output/FibRecur' using 2:3 lw 3, f(x) lw 3