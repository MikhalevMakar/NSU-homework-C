#include <stdio.h>
#include <assert.h>
#include <omp.h>

void ParallelCopy(const float* a, float* b, int size, int threadCount) {
#pragma omp parallel num_threads(threadCount)
	for (int i = 0; i < size; ++i) {

		b[i] = a[i];

	}
}

int main() {
	int N = 10;

	float* a = malloc(N * sizeof(float));
	assert(a != NULL);

	for (int i = 0; i < N; ++i) {
		assert(scanf("%f", &a[i]) == 1);
	}

	float* b = malloc(N * sizeof(float));
	assert(b != NULL);

	ParallelCopy(a, b, N, 2);

	return 0;
}
