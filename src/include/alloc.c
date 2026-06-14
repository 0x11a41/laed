#include <sys/mman.h>
#include <unistd.h>

size_t total_space = 4ULL * 1024 * 1024 * 1024; // 4 GB
int main() {
    void* ptr = mmap(NULL, total_space, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    mprotect(ptr, 4096, PROT_READ | PROT_WRITE);
    madvise((char*)ptr + (10 * 1024 * 1024), 10 * 1024 * 1024, MADV_DONTNEED);
    
}


