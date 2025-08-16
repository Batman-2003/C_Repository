#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Arena {
	const size_t ARENA_SIZE;

	void* arena_ptr = NULL;
	size_t curr_ind = 0;

	Arena(size_t _arena_size): ARENA_SIZE(_arena_size) {
		arena_ptr = calloc(ARENA_SIZE, 1);
		curr_ind = 0;
		if (arena_ptr == NULL) {
			printf("Arena Initialization failed\n");
			return;
		}
		printf("Arena of size: %zu Initialized Successfully\n", this->ARENA_SIZE);
	}

	~Arena() {
		free(arena_ptr);

		arena_ptr = NULL;
		curr_ind = 0;

		printf("Arena Freed\n");
	}

	// * Deleted Copy Construtors
	Arena (const Arena&) = delete;
	Arena& operator=(const Arena&) = delete;

	void* allocate(const size_t num_of_bytes) {
		void* return_ptr = this->arena_ptr + this->curr_ind;
		this->curr_ind += num_of_bytes;
		if (this->curr_ind > this->ARENA_SIZE) {
			printf("Arena limit exceeded!!!, Handle this error\n");
			return NULL;
		}
		return return_ptr;
	}

	void reset() {
		memset(this->arena_ptr, 0, this->ARENA_SIZE);
		printf("Arena was reset\n");
	}
};



int main(void) {
	printf("========================\n\n\n");
	printf("10 12 +\n");

	Arena arena1 = Arena(4096);
	int* array1 = (int*)arena1.allocate(3 * sizeof(int));
	array1[0] = 0;
	array1[1] = 1;
	array1[2] = 2;

	for (size_t i = 0; i < 2; i++) {
		printf("%2d, ", array1[i]);
	}
	printf("%2d\n", array1[2]);

	arena1.reset();
	for (size_t i = 0; i < 2; i++) {
		printf("%2d, ", array1[i]);
	}
	printf("%2d\n", array1[2]);

	char* newStr = (char*)arena1.allocate(sizeof("Hello, there!!, Vsauce Here!!\n"));
	strncpy(newStr, "Hello, there!! Vsauce Here!!\n", sizeof("Hello, there!! Vsauce Here!!\n"));
	printf("%s\n", newStr);
	arena1.reset();
	printf("%s\n", newStr);



	return 0;
}