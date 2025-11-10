#define MAX_PROCS 10

typedef enum { READY, RUNNING, WAITING, TERMINATED } proc_state;

typedef struct {
    int pid;
    char name[32];
    proc_state state;
    void (*entry_point)();
} process;

void proc_init();
int proc_create(const char* name, void (*entry)());
void proc_run();
void proc_list();
process* proc_get_all();
int proc_get_count();