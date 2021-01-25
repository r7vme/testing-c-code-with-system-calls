#include <stdbool.h>
#include <sys/sysinfo.h>

bool is_multicore_system(void) {
  return (get_nprocs_conf() > 1) ? true : false;
}
