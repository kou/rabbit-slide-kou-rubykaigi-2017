require "benchmark"

numbers = (1..100000).to_a

Benchmark.bmbm do |job|
  job.report("inject") do
    numbers.inject(&:+)
  end

  job.report("sum") do
    numbers.sum
  end
end
