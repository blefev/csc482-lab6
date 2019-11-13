# gnu plot
set key autotitle columnhead
set ylabel "Time in milliseconds"

stats '../output/FibRecurDP' using 1:3
set title 'FibRecurDP N vs Time (ms)'
set xlabel "N"
n = STATS_max_x
t = STATS_max_y
a = t / (n**2)
f(x) = a*x**2
set yrange [0:t]
set xrange [0:n]
plot '../output/FibRecurDP' using 1:3 lw 3, f(x) with lines lw 3

