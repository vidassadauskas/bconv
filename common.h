/* in order not to redefine when this header file is included several times */
#ifndef _BCONV_COMMON_
#define _BCONV_COMMON_

#ifdef LINUXOS
#include <linux/limits.h>
#include <limits.h>
#else
#include <sys/syslimits.h>
#endif /* LINUXOS */

#include <stdio.h>

/**********************************************
Purpose:
constants
**********************************************/
#define USER      "BGH"
#define USER_LEN    128
#ifdef LINUXOS
#define PWD_LEN     256
#else
#define PWD_LEN     PASS_MAX
#endif /* LINUXOS */

#define WORK_DIR_LEN  PATH_MAX
#define FILENAME_LEN  NAME_MAX
#define SLEEP_TIME    1000
#define CHUNK_SIZE    30000
#define BATCH_SIZE    100
#define XML_DIR_NAME  "XML"
#define PS_DIR_NAME   "PS"
#define PDF_DIR_NAME  "PDF"
#define LOG_DIR_NAME  "LOG"
#define DATE_LENGTH   10
#define DATE_TIME_LENGTH 19
#define DATE_FMT    "YYYY-MM-DD"
#define DATE_TIME_FMT "YYYY-MM-DD HH24:MI:SS"
#define DATE_FMT_LEN  80
#define DATE_TIME_FMT_LEN 80
#define NOW_FMT     "%Y.%m.%d %H:%M:%S"
#define NOW_EXT_FMT     "%Y-%m-%d %H:%M:%S"
#define NOW_FN_FMT      "%Y%m%d%H%M%S"
#define NOW_FN_FMT_LEN 14
#define ARGS    "vhc:s:d:n:C:b:"
#define NO_OF_PROCESSES 10
#define ORAERR_MAX 512
#define VERSION_INFO_LEN 100
#define DIR_SEPARATOR "/"
#define DIR_SEPARATOR_LEN 1
#define EXT_SEPARATOR "."
#define EXT_SEPARATOR_LEN 1
#define OPTARG_LEN 15


/* a constant used in match function */
#define SLENGTH 128


/**********************************************
Purpose:
Definition of custom data types.
**********************************************/

/* A structure to store parsed command line arguments */
typedef struct TAGcmd_params {
  char  prog_name[FILENAME_LEN+1];
  int   sleep_time;
  int   batch_size;
  int   chunk_size;
  int   from_cust_id;
  int   to_cust_id;
  char  bi_date[DATE_LENGTH+1];
  char  work_dir[WORK_DIR_LEN+1];
  int   processes;
  char  version_info[VERSION_INFO_LEN+1];
} t_cmd_params;

/* A structure to store process registration params */
typedef struct TAGreg_params {
  int proc_id;
  char  proc_name[FILENAME_LEN+1];
  int srv_id;
  int pid;
} t_reg_params;


/****************************************************/
/**********************************************
Purpose:
Global variables.
**********************************************/
int sig_term;
sql_context ctx1; /* SQLLIB runtime context for which memory is to be allocated. */


/****************************************************/
/**********************************************
Purpose:
External variables.
**********************************************/


/**********************************************
Purpose:
Function prototypes
**********************************************/

char *substr(char *sstr, char *str, int m, int n);

void signal_handler(int signo);

void termination(t_reg_params reg_params);

void parse_params(int argc, char **argv, t_cmd_params *cmd_params);

void error_handler(int exit_code);

int get_usr_pwd(char *usr, char *pwd);

void do_connect(char *usr, char *pwd);

void sql_error(char *routine);

void sql_commit(void);

void do_register(t_reg_params *reg_params);

void do_unregister(t_reg_params reg_params);

int match(char *pattern, char *string);

void do_disconnect(void);

char *now(char *fmt);

#ifdef LINUXOS
ssize_t my_getpass (char **lineptr, size_t *n, FILE *stream);
#endif /* LINUXOS */

void help(char *prog_name);

void version(char *version_info);

#endif /* _BCONV_COMMON_ */
