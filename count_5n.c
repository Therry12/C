/* Get 5 numbers from stdin and range for count nums sum in this ranger. */

#include <stdio.h>
#include <string.h>

#define EINVAL 22 /* Invalid argument */
#define ARR_SIZE 5
/* Colors for fancy output */
#define RED "\033[0;31m"
#define WHITE "\033[0;39m"
#define CYAN "\033[0;36m"
#define DELIM "<-------------------->"

typedef struct {
  int bottom_bound;
  int top_bound;
} range;

/* Sum all elements in array in range. Return sum if success */
int sum_in_range(int arr[], int s, range r) {
  int sum = 0;
  printf("%s\tCALCULATING...%s\n", CYAN, WHITE);

  if (arr == NULL) {
    fprintf(stderr, "%s%s%s\n", RED, strerror(EINVAL), WHITE);
    return -1;
  }

  for (int i = r.bottom_bound; i <= r.top_bound; i++) {
    if (i > s) {
      return -1;
    }
    sum += arr[i];
  }
  return sum;
}

int main(void) {
  int arr_n[ARR_SIZE] = {};
  int bottom_bound;
  int top_bound;
  printf("Enter 5 numbers.\n");

  for (int i = 0; i < ARR_SIZE; i++) {
    /* &*(n_arr + i) */
    printf("arr_n[%d]: ", i);
    if (scanf("%d", &arr_n[i]) != 1) {
      fprintf(stderr, "%s%s%s. Enter valid number.\n", RED, strerror(5), WHITE);
      return 1;
    }
  }

  printf("Enter bottom range(0-4): ");
  /* TODO: Create vars for const literals (numbers)*/
  if (scanf("%d", &bottom_bound) != 1) {
    fprintf(stderr, "%s%s%s. Enter valid range.\n", RED, strerror(5), WHITE);
    return 5;
  } else if (bottom_bound < 0 || bottom_bound > 4) {
    fprintf(stderr, "%sInvalid range. %s\n", RED, WHITE);
    return 5;
  }
  printf("Enter top bottom (%d-4): ", bottom_bound);
  if (scanf("%d", &top_bound) != 1) {
    fprintf(stderr, "%s%s%s. Enter valid range.\n", RED, strerror(5), WHITE);
    return 1;
  } else if (top_bound < bottom_bound || top_bound > 4) {
    fprintf(stderr, "%s%s%s. Enter valid range.\n", RED, strerror(5), WHITE);
    return 1;
  }

  range r = {bottom_bound, top_bound};
  int sum = sum_in_range(arr_n, ARR_SIZE, r);
  if (sum == -1) {
    return 1;
  }
  printf("%s\tRESULT: %d%s\n", CYAN, sum, WHITE);
}
