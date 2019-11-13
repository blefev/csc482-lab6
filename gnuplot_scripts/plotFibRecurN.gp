# gnu plot
set key autotitle columnhead
set ylabel "Time in milliseconds"

stats '../output/FibRecur' using 1:3
set title 'FibRecur N vs Time (ms)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (2**(2**n))
f(x) = a*2**(2**x)
set yrange [0:t]
set xrange [0:n]
plot '../output/FibRecur' using 1:3 lw 3, f(x) lw 3