#ifndef _SHARED_MEMORY_HH
#define _SHARED_MEMORY_HH

#include <stdlib.h>

// the Message structure defines a message sent by a client
struct Message {
	char userCode[100]; //contains userCode
	unsigned long long userKey; //contains hashed key
	long int timeStamp; //contains time in which this request was saved
};

// The alloc_shared_memory method creates, if it does not exist, a shared
// memory segment with size bytes and shmKey key.
// It returns the shmid on success, otherwise it terminates the calling process
int alloc_shared_memory(key_t shmKey, size_t size);

// The get_shared_memory attaches a shared memory segment in the logic address space
// of the calling process.
// It returns a pointer to the attached shared memory segment,
// otherwise it terminates the calling process
void *get_shared_memory(int shmid, int shmflg);

// The free_shared_memory detaches a shared memory segment from the logic
// address space of the calling process.
// If it does not succeed, it terminates the calling process
void free_shared_memory(void *ptr_sh);

// The remove_shared_memory removes a shared memory segment
// If it does not succeed, it terminates the calling process
void remove_shared_memory(int shmid);

#endif
