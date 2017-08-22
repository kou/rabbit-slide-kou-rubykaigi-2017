public class Fibonacci {
  public long[] compute(int n) {
    int prev = 1;
    int current = 1;
    long[] results = new long[n];

    for (int i = 0; i < n; i++) {
      int temp = current;
      current += prev;
      prev = temp;
      results[i] = prev;
    }

    return results;
  }
}
