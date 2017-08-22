require "benchmark"

require_relative "../example/rubex/fibonacci/fibonacci.so"

def fib(n)
  i = 1
  prev = 1
  current = 1
  temp = nil
  arr = []

  while i < n
    temp = current
    current = current + prev
    prev = temp
    arr.push(prev)
    i += 1
  end

  arr
end

Benchmark.bmbm do |job|
  fibonacci = Fibonacci.new

  job.report("Rubex: 100") do
    fibonacci.compute(100)
  end

  job.report("Ruby: 100") do
    fib(100)
  end

  job.report("Rubex: 10000") do
    fibonacci.compute(10000)
  end

  job.report("Ruby: 10000") do
    fib(10000)
  end
end
