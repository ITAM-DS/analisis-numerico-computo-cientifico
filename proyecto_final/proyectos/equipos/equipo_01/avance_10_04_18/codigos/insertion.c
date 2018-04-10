void Insercion(int numbers[], int array_size) {
  int i, a, index;
  for (i=1; i < array_size; i++) {
    index = numbers[i];
    a = i-1;
    while (a >= 0 && numbers[a] > index) {
      numbers[a + 1] = numbers[a];
      a--;
    }
    numbers[a+1] = index;
  }
}