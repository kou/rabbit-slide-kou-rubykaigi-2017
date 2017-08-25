def fib(n)
  prev = 1
  current = 1
  1.step(n).collect do
    prev, current = current, current + prev
    prev
  end
end

p fib(10)
