#include "iojack.h"

// Attention, only x86_64 for now!

// cat unistd_64.h  | grep '#define __NR_' | awk '{print "if(callnr == "$3") return \""$2"\";"}'

const char *syscallToStr(int callnr)
{
	if(callnr == 0) return "__NR_read";
	if(callnr == 1) return "__NR_write";
	if(callnr == 2) return "__NR_open";
	if(callnr == 3) return "__NR_close";
	if(callnr == 4) return "__NR_stat";
	if(callnr == 5) return "__NR_fstat";
	if(callnr == 6) return "__NR_lstat";
	if(callnr == 7) return "__NR_poll";
	if(callnr == 8) return "__NR_lseek";
	if(callnr == 9) return "__NR_mmap";
	if(callnr == 10) return "__NR_mprotect";
	if(callnr == 11) return "__NR_munmap";
	if(callnr == 12) return "__NR_brk";
	if(callnr == 13) return "__NR_rt_sigaction";
	if(callnr == 14) return "__NR_rt_sigprocmask";
	if(callnr == 15) return "__NR_rt_sigreturn";
	if(callnr == 16) return "__NR_ioctl";
	if(callnr == 17) return "__NR_pread64";
	if(callnr == 18) return "__NR_pwrite64";
	if(callnr == 19) return "__NR_readv";
	if(callnr == 20) return "__NR_writev";
	if(callnr == 21) return "__NR_access";
	if(callnr == 22) return "__NR_pipe";
	if(callnr == 23) return "__NR_select";
	if(callnr == 24) return "__NR_sched_yield";
	if(callnr == 25) return "__NR_mremap";
	if(callnr == 26) return "__NR_msync";
	if(callnr == 27) return "__NR_mincore";
	if(callnr == 28) return "__NR_madvise";
	if(callnr == 29) return "__NR_shmget";
	if(callnr == 30) return "__NR_shmat";
	if(callnr == 31) return "__NR_shmctl";
	if(callnr == 32) return "__NR_dup";
	if(callnr == 33) return "__NR_dup2";
	if(callnr == 34) return "__NR_pause";
	if(callnr == 35) return "__NR_nanosleep";
	if(callnr == 36) return "__NR_getitimer";
	if(callnr == 37) return "__NR_alarm";
	if(callnr == 38) return "__NR_setitimer";
	if(callnr == 39) return "__NR_getpid";
	if(callnr == 40) return "__NR_sendfile";
	if(callnr == 41) return "__NR_socket";
	if(callnr == 42) return "__NR_connect";
	if(callnr == 43) return "__NR_accept";
	if(callnr == 44) return "__NR_sendto";
	if(callnr == 45) return "__NR_recvfrom";
	if(callnr == 46) return "__NR_sendmsg";
	if(callnr == 47) return "__NR_recvmsg";
	if(callnr == 48) return "__NR_shutdown";
	if(callnr == 49) return "__NR_bind";
	if(callnr == 50) return "__NR_listen";
	if(callnr == 51) return "__NR_getsockname";
	if(callnr == 52) return "__NR_getpeername";
	if(callnr == 53) return "__NR_socketpair";
	if(callnr == 54) return "__NR_setsockopt";
	if(callnr == 55) return "__NR_getsockopt";
	if(callnr == 56) return "__NR_clone";
	if(callnr == 57) return "__NR_fork";
	if(callnr == 58) return "__NR_vfork";
	if(callnr == 59) return "__NR_execve";
	if(callnr == 60) return "__NR_exit";
	if(callnr == 61) return "__NR_wait4";
	if(callnr == 62) return "__NR_kill";
	if(callnr == 63) return "__NR_uname";
	if(callnr == 64) return "__NR_semget";
	if(callnr == 65) return "__NR_semop";
	if(callnr == 66) return "__NR_semctl";
	if(callnr == 67) return "__NR_shmdt";
	if(callnr == 68) return "__NR_msgget";
	if(callnr == 69) return "__NR_msgsnd";
	if(callnr == 70) return "__NR_msgrcv";
	if(callnr == 71) return "__NR_msgctl";
	if(callnr == 72) return "__NR_fcntl";
	if(callnr == 73) return "__NR_flock";
	if(callnr == 74) return "__NR_fsync";
	if(callnr == 75) return "__NR_fdatasync";
	if(callnr == 76) return "__NR_truncate";
	if(callnr == 77) return "__NR_ftruncate";
	if(callnr == 78) return "__NR_getdents";
	if(callnr == 79) return "__NR_getcwd";
	if(callnr == 80) return "__NR_chdir";
	if(callnr == 81) return "__NR_fchdir";
	if(callnr == 82) return "__NR_rename";
	if(callnr == 83) return "__NR_mkdir";
	if(callnr == 84) return "__NR_rmdir";
	if(callnr == 85) return "__NR_creat";
	if(callnr == 86) return "__NR_link";
	if(callnr == 87) return "__NR_unlink";
	if(callnr == 88) return "__NR_symlink";
	if(callnr == 89) return "__NR_readlink";
	if(callnr == 90) return "__NR_chmod";
	if(callnr == 91) return "__NR_fchmod";
	if(callnr == 92) return "__NR_chown";
	if(callnr == 93) return "__NR_fchown";
	if(callnr == 94) return "__NR_lchown";
	if(callnr == 95) return "__NR_umask";
	if(callnr == 96) return "__NR_gettimeofday";
	if(callnr == 97) return "__NR_getrlimit";
	if(callnr == 98) return "__NR_getrusage";
	if(callnr == 99) return "__NR_sysinfo";
	if(callnr == 100) return "__NR_times";
	if(callnr == 101) return "__NR_ptrace";
	if(callnr == 102) return "__NR_getuid";
	if(callnr == 103) return "__NR_syslog";
	if(callnr == 104) return "__NR_getgid";
	if(callnr == 105) return "__NR_setuid";
	if(callnr == 106) return "__NR_setgid";
	if(callnr == 107) return "__NR_geteuid";
	if(callnr == 108) return "__NR_getegid";
	if(callnr == 109) return "__NR_setpgid";
	if(callnr == 110) return "__NR_getppid";
	if(callnr == 111) return "__NR_getpgrp";
	if(callnr == 112) return "__NR_setsid";
	if(callnr == 113) return "__NR_setreuid";
	if(callnr == 114) return "__NR_setregid";
	if(callnr == 115) return "__NR_getgroups";
	if(callnr == 116) return "__NR_setgroups";
	if(callnr == 117) return "__NR_setresuid";
	if(callnr == 118) return "__NR_getresuid";
	if(callnr == 119) return "__NR_setresgid";
	if(callnr == 120) return "__NR_getresgid";
	if(callnr == 121) return "__NR_getpgid";
	if(callnr == 122) return "__NR_setfsuid";
	if(callnr == 123) return "__NR_setfsgid";
	if(callnr == 124) return "__NR_getsid";
	if(callnr == 125) return "__NR_capget";
	if(callnr == 126) return "__NR_capset";
	if(callnr == 127) return "__NR_rt_sigpending";
	if(callnr == 128) return "__NR_rt_sigtimedwait";
	if(callnr == 129) return "__NR_rt_sigqueueinfo";
	if(callnr == 130) return "__NR_rt_sigsuspend";
	if(callnr == 131) return "__NR_sigaltstack";
	if(callnr == 132) return "__NR_utime";
	if(callnr == 133) return "__NR_mknod";
	if(callnr == 134) return "__NR_uselib";
	if(callnr == 135) return "__NR_personality";
	if(callnr == 136) return "__NR_ustat";
	if(callnr == 137) return "__NR_statfs";
	if(callnr == 138) return "__NR_fstatfs";
	if(callnr == 139) return "__NR_sysfs";
	if(callnr == 140) return "__NR_getpriority";
	if(callnr == 141) return "__NR_setpriority";
	if(callnr == 142) return "__NR_sched_setparam";
	if(callnr == 143) return "__NR_sched_getparam";
	if(callnr == 144) return "__NR_sched_setscheduler";
	if(callnr == 145) return "__NR_sched_getscheduler";
	if(callnr == 146) return "__NR_sched_get_priority_max";
	if(callnr == 147) return "__NR_sched_get_priority_min";
	if(callnr == 148) return "__NR_sched_rr_get_interval";
	if(callnr == 149) return "__NR_mlock";
	if(callnr == 150) return "__NR_munlock";
	if(callnr == 151) return "__NR_mlockall";
	if(callnr == 152) return "__NR_munlockall";
	if(callnr == 153) return "__NR_vhangup";
	if(callnr == 154) return "__NR_modify_ldt";
	if(callnr == 155) return "__NR_pivot_root";
	if(callnr == 156) return "__NR__sysctl";
	if(callnr == 157) return "__NR_prctl";
	if(callnr == 158) return "__NR_arch_prctl";
	if(callnr == 159) return "__NR_adjtimex";
	if(callnr == 160) return "__NR_setrlimit";
	if(callnr == 161) return "__NR_chroot";
	if(callnr == 162) return "__NR_sync";
	if(callnr == 163) return "__NR_acct";
	if(callnr == 164) return "__NR_settimeofday";
	if(callnr == 165) return "__NR_mount";
	if(callnr == 166) return "__NR_umount2";
	if(callnr == 167) return "__NR_swapon";
	if(callnr == 168) return "__NR_swapoff";
	if(callnr == 169) return "__NR_reboot";
	if(callnr == 170) return "__NR_sethostname";
	if(callnr == 171) return "__NR_setdomainname";
	if(callnr == 172) return "__NR_iopl";
	if(callnr == 173) return "__NR_ioperm";
	if(callnr == 174) return "__NR_create_module";
	if(callnr == 175) return "__NR_init_module";
	if(callnr == 176) return "__NR_delete_module";
	if(callnr == 177) return "__NR_get_kernel_syms";
	if(callnr == 178) return "__NR_query_module";
	if(callnr == 179) return "__NR_quotactl";
	if(callnr == 180) return "__NR_nfsservctl";
	if(callnr == 181) return "__NR_getpmsg";
	if(callnr == 182) return "__NR_putpmsg";
	if(callnr == 183) return "__NR_afs_syscall";
	if(callnr == 184) return "__NR_tuxcall";
	if(callnr == 185) return "__NR_security";
	if(callnr == 186) return "__NR_gettid";
	if(callnr == 187) return "__NR_readahead";
	if(callnr == 188) return "__NR_setxattr";
	if(callnr == 189) return "__NR_lsetxattr";
	if(callnr == 190) return "__NR_fsetxattr";
	if(callnr == 191) return "__NR_getxattr";
	if(callnr == 192) return "__NR_lgetxattr";
	if(callnr == 193) return "__NR_fgetxattr";
	if(callnr == 194) return "__NR_listxattr";
	if(callnr == 195) return "__NR_llistxattr";
	if(callnr == 196) return "__NR_flistxattr";
	if(callnr == 197) return "__NR_removexattr";
	if(callnr == 198) return "__NR_lremovexattr";
	if(callnr == 199) return "__NR_fremovexattr";
	if(callnr == 200) return "__NR_tkill";
	if(callnr == 201) return "__NR_time";
	if(callnr == 202) return "__NR_futex";
	if(callnr == 203) return "__NR_sched_setaffinity";
	if(callnr == 204) return "__NR_sched_getaffinity";
	if(callnr == 205) return "__NR_set_thread_area";
	if(callnr == 206) return "__NR_io_setup";
	if(callnr == 207) return "__NR_io_destroy";
	if(callnr == 208) return "__NR_io_getevents";
	if(callnr == 209) return "__NR_io_submit";
	if(callnr == 210) return "__NR_io_cancel";
	if(callnr == 211) return "__NR_get_thread_area";
	if(callnr == 212) return "__NR_lookup_dcookie";
	if(callnr == 213) return "__NR_epoll_create";
	if(callnr == 214) return "__NR_epoll_ctl_old";
	if(callnr == 215) return "__NR_epoll_wait_old";
	if(callnr == 216) return "__NR_remap_file_pages";
	if(callnr == 217) return "__NR_getdents64";
	if(callnr == 218) return "__NR_set_tid_address";
	if(callnr == 219) return "__NR_restart_syscall";
	if(callnr == 220) return "__NR_semtimedop";
	if(callnr == 221) return "__NR_fadvise64";
	if(callnr == 222) return "__NR_timer_create";
	if(callnr == 223) return "__NR_timer_settime";
	if(callnr == 224) return "__NR_timer_gettime";
	if(callnr == 225) return "__NR_timer_getoverrun";
	if(callnr == 226) return "__NR_timer_delete";
	if(callnr == 227) return "__NR_clock_settime";
	if(callnr == 228) return "__NR_clock_gettime";
	if(callnr == 229) return "__NR_clock_getres";
	if(callnr == 230) return "__NR_clock_nanosleep";
	if(callnr == 231) return "__NR_exit_group";
	if(callnr == 232) return "__NR_epoll_wait";
	if(callnr == 233) return "__NR_epoll_ctl";
	if(callnr == 234) return "__NR_tgkill";
	if(callnr == 235) return "__NR_utimes";
	if(callnr == 236) return "__NR_vserver";
	if(callnr == 237) return "__NR_mbind";
	if(callnr == 238) return "__NR_set_mempolicy";
	if(callnr == 239) return "__NR_get_mempolicy";
	if(callnr == 240) return "__NR_mq_open";
	if(callnr == 241) return "__NR_mq_unlink";
	if(callnr == 242) return "__NR_mq_timedsend";
	if(callnr == 243) return "__NR_mq_timedreceive";
	if(callnr == 244) return "__NR_mq_notify";
	if(callnr == 245) return "__NR_mq_getsetattr";
	if(callnr == 246) return "__NR_kexec_load";
	if(callnr == 247) return "__NR_waitid";
	if(callnr == 248) return "__NR_add_key";
	if(callnr == 249) return "__NR_request_key";
	if(callnr == 250) return "__NR_keyctl";
	if(callnr == 251) return "__NR_ioprio_set";
	if(callnr == 252) return "__NR_ioprio_get";
	if(callnr == 253) return "__NR_inotify_init";
	if(callnr == 254) return "__NR_inotify_add_watch";
	if(callnr == 255) return "__NR_inotify_rm_watch";
	if(callnr == 256) return "__NR_migrate_pages";
	if(callnr == 257) return "__NR_openat";
	if(callnr == 258) return "__NR_mkdirat";
	if(callnr == 259) return "__NR_mknodat";
	if(callnr == 260) return "__NR_fchownat";
	if(callnr == 261) return "__NR_futimesat";
	if(callnr == 262) return "__NR_newfstatat";
	if(callnr == 263) return "__NR_unlinkat";
	if(callnr == 264) return "__NR_renameat";
	if(callnr == 265) return "__NR_linkat";
	if(callnr == 266) return "__NR_symlinkat";
	if(callnr == 267) return "__NR_readlinkat";
	if(callnr == 268) return "__NR_fchmodat";
	if(callnr == 269) return "__NR_faccessat";
	if(callnr == 270) return "__NR_pselect6";
	if(callnr == 271) return "__NR_ppoll";
	if(callnr == 272) return "__NR_unshare";
	if(callnr == 273) return "__NR_set_robust_list";
	if(callnr == 274) return "__NR_get_robust_list";
	if(callnr == 275) return "__NR_splice";
	if(callnr == 276) return "__NR_tee";
	if(callnr == 277) return "__NR_sync_file_range";
	if(callnr == 278) return "__NR_vmsplice";
	if(callnr == 279) return "__NR_move_pages";
	if(callnr == 280) return "__NR_utimensat";
	if(callnr == 281) return "__NR_epoll_pwait";
	if(callnr == 282) return "__NR_signalfd";
	if(callnr == 283) return "__NR_timerfd_create";
	if(callnr == 284) return "__NR_eventfd";
	if(callnr == 285) return "__NR_fallocate";
	if(callnr == 286) return "__NR_timerfd_settime";
	if(callnr == 287) return "__NR_timerfd_gettime";
	if(callnr == 288) return "__NR_accept4";
	if(callnr == 289) return "__NR_signalfd4";
	if(callnr == 290) return "__NR_eventfd2";
	if(callnr == 291) return "__NR_epoll_create1";
	if(callnr == 292) return "__NR_dup3";
	if(callnr == 293) return "__NR_pipe2";
	if(callnr == 294) return "__NR_inotify_init1";
	if(callnr == 295) return "__NR_preadv";
	if(callnr == 296) return "__NR_pwritev";
	if(callnr == 297) return "__NR_rt_tgsigqueueinfo";
	if(callnr == 298) return "__NR_perf_event_open";
	if(callnr == -1) return "FAKED";
	return "<unknown>";
}
