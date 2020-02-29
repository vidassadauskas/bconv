#include "common.h"

/* in order not to redefine when this header file is included several times */
#ifndef _GETBI_
#define _GETBI_


/**********************************************
Purpose:
constants
**********************************************/
#define PROGRAM_NAME "getbi"
#define PROGRAM_NAME_LENGTH 5
#define FNAME_LEN 35
#define ROW_ID_LEN 18
#define BI_EXTENSION_LEN 3
#define VERSION "getbi 1.0.2 2005-07-12"


/**********************************************
Purpose:
Definition of custom data types.
**********************************************/

/* This is the definition of the long varraw structure.
 * Note that the first field, len, is a long instead
 * of a short.  This is because the first 4
 * bytes contain the length, not the first 2 bytes.
 */
typedef struct TAGlv_raw lvraw;
struct TAGlv_raw
{
  unsigned int    len;
  unsigned char   buf[1];
};


/* definition of BCONV_INDEX record structure */
typedef struct TAGindex_rec t_index_rec;
struct TAGindex_rec
{
  char  fname[FNAME_LEN+1];
  char  row_id[ROW_ID_LEN+1];
  int   bi_size;
  int   customer_id;
  char  bi_date[DATE_LENGTH+1];
  int   status;
  char  last_d_t[DATE_TIME_LENGTH+1];
  int   proc_id;
};


/****************************************************/
/**********************************************
Purpose:
External variables.
**********************************************/
extern int sig_term;


/****************************************************/
/**********************************************
Purpose:
Global variables.
**********************************************/
OCIEnv *oeh; /* an environment handle */
OCISvcCtx *svc; /* a service context handle for the OCI functions that requires the Service Context handle */
OCIError *err; /* an error handle */
sword retcode; /* stores return code of SQLEnvGet and other functions */


/**********************************************
Purpose:
Function prototypes
**********************************************/

static ssize_t write_file(char *filename, unsigned char *buf, size_t bufsize);

static void do_process(t_cmd_params cmd_params, t_reg_params reg_params);

static int do_reserve(t_cmd_params cmd_params, t_reg_params reg_params);

static void checkerr(OCIError *errhp, sword status);

#endif /* _GETBI_ */
