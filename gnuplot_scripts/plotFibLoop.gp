# gnu plot
set key autotitle columnhead
set ylabel "Time in milliseconds"

stats '../output/FibLoop' using 2:3
set title 'FibLoop X vs Time (ms)'
set xlabel "X"
n = STATS_max_x
t = STATS_max_y
a = t / n
f(x) = a*x
set yrange [0:t]
set xrange [0:n]
plot '../output/FibLoop' using 2:3 lw 3, f(x) lw 3
