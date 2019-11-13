require 'bigdecimal/math'
require_relative './fibnumbers.rb'
require 'benchmark'

SQRT5 = BigDecimal(5).sqrt(100)
PHI   = (BigDecimal(1) + SQRT5) / BigDecimal(2)

def fibFormulaBig(x)
  fib =  (PHI ** x - PHI ** (-x)) / SQRT5
  return fib.ceil
end




def benchmarkit()

  trials = 20

  unless Dir.exists? "output"
    Dir.mkdir "output"
  end

  File.open("output/" + 'fibFormulaBig', 'w') do |f|
    #f.puts "n\tTime"
    puts "n\tTime"
    #calculatedFib = 0


    10000.times do |x|
      sum = 0

      trials.times do
        bm = Benchmark.realtime do |b|
          calculatedFib = fibFormulaBig(x)
          send('fibFormulaBig', x)
        end

        sum += bm
      end

      avg = sum / trials

      n = x.to_s(2).length

      f.puts("#{n}\t#{x}\t#{avg}\t")
      puts("#{n}\t#{x}\t#{avg}\t")
    end
  end
end



def test
  puts "Testing: "
  FIBS.each_with_index do |fib, x|
    calculatedFib = fibFormulaBig(x)
    print "fibFormulaBig(#{x}): #{calculatedFib} "

    if (fib == calculatedFib.to_s)
      puts "  Passed"
    else
      puts "  Failed"
      puts "Expected #{fib}, instead got #{calculatedFib}"
      return false
    end
  end

  true
end

def writePowersOf2

  File.open('powerOf2', 'w') do |f|

    (64..256).each do |pow|
      f.print "\"#{2**pow}\", "
    end

  end
end

##test
#writePowersOf2
benchmarkit
