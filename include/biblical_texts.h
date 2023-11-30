/**
 * biblical-texts.h
 *
 * Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 *  
 * Description: This program print a Bible text and versicles in the terminal.
 *
 * Date: 16/10/2023
 */

#ifndef _BIBLICAL_TEXTS_H_
#define _BIBLICAL_TEXTS_H_

/******************************************************************************
 *                                                                            *
 *                                 Includes                                   *
 *                                                                            *
 ******************************************************************************/
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>
#include <errno.h>
#include <getopt.h>
#include <locale.h>
#include <libintl.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <pwd.h>
#include "trace/trace.h"

/******************************************************************************
 *                                                                            *
 *                             Defines and macros                             *
 *                                                                            *
 ******************************************************************************/

/**
 * Program information defines
 */
#define VERSION        "1.0"
#define DESCRIPTION    "biblical-texts print a Bible text and versicles in the terminal."
#define COPYRIGHT      "Copyright (C) 2023"
#define DEVELOPER      "Gustavo Bacagine"
#define DEV_MAIL       "gustavo.bacagine@protonmail.com"
#define CONF_FILE_NAME "biblical-texts.conf"
#define LOG_FILE_NAME  "biblical-texts.log"
#define GITHUB_URL     "https://www.github.com/Gustavo Bacagine/biblical-texts"

/**
 * Program language defines
 */
#define _(STR) gettext(STR)
#define LOCALE_DIR ""

/**
 * This macro is used to remove
 * unused warnings during the
 * compilation.
 */
#define UNUSED(X) (void) X

/**
 * Quantity of biblical texts
 */
#define QTY_VERSICLES 56

/******************************************************************************
 *                                                                            *
 *                  Typedefs, structures, unions and enums                    *
 *                                                                            *
 ******************************************************************************/


/******************************************************************************
 *                                                                            *
 *                           Command Line Options                             *
 *                                                                            *
 ******************************************************************************/

/**
 * Structure that represnts
 * command line arguments
 */
typedef struct STRUCT_COMMAND_LINE
{
  char szLogFileName  [_MAX_PATH];
  char szDebugLevel   [_MAX_PATH];
  char szConfFileName [_MAX_PATH];
  char szLanguage     [32]; /* Language used in the program. */
} STRUCT_COMMAND_LINE;

/**
 * Command line structure and strings
 */
static struct option astCmdOpt[] = {
  { "help"         , no_argument      ,    0, 'h' },
  { "version"      , no_argument      ,    0, 'v' },
  { "trace"        , required_argument,    0, 't' },
  { "debug-level"  , required_argument,    0, 'd' },
  { "colored-log"  , no_argument      ,    0, 'c' },
  { "conf-filename", required_argument,    0, 'C' },
  { "language"     , required_argument,    0, 'l' },
  { NULL           , 0                , NULL,  0  }
};

/**
 * Arguments of command line options useds 
 * in usage message of program
 */
static const char *pszCmdArguments[] = {
  NULL,
  NULL,
  "file",
  "number",
  NULL,
  "file",
  "text",
  NULL
};

/**
 * Help messages that showed in usage message
 * of program
 */
static const char *pszCmdMessages[] = {
  "Show this message and exit",
  "Show the version and exit",
  "<file> is the path of the debug file (default is ./biblical-texts.log)",
  "<number> is the level of debug level (disable by default)",
  "Set a colored log",
  "<file> is the path of the .conf file of software",
  "<text> is the language of the biblical texts",
  NULL
};

/******************************************************************************
 *                                                                            *
 *                     Global variables and constants                         *
 *                                                                            *
 ******************************************************************************/

/* Receive the name of program */
extern const char *gkpszProgramName;

/**
 * Command line arguments
 */
extern STRUCT_COMMAND_LINE gstCmdLine;

/**
 * KJV versicles (enUS)
 */
extern const char *gkpszEN_BiblicalTexts[];

/**
 * ACF versicles (ptBR)
 */
extern const char *gkpszBR_BiblicalTexts[];

/******************************************************************************
 *                                                                            *
 *                            Prototype functions                             *
 *                                                                            *
 ******************************************************************************/

/**
 * Print the help message for the user
 */
void vPrintUsage(void);

/**
 * Print the version of the software
 */
void vPrintVersion(void);

/**
 * Print a formatted error message
 */
void vPrintErrorMessage(const char *kpszFmt, ...);

/**
 * Check if what wass passed on the command line is valid
 */
bool bCommandLineIsOK(int argc, char **argv);

/**
 * A detailed and excessive sample of what was passed on the command line
 */
void vTraceCommandLine(int argc, char **argv);

/**
 * \brief A detailed and excessive sampling of the system's environment variables
 */
void vTraceEnvp(char **envp);

/**
 * This function is based in the examples of the book 
 * "Aprenda em 24 horas Programacao para Linux"
 *
 * This function return the name of argv[0] withouth the path,
 * for example, if argv[0] == "/usr/bin/program", the function returns
 * only the string "program".
 */
char *szGetBaseName(const char *szPathName);

/**
 * Generate and return a random number used with iIndex in functions
 * vPrintEN_BiblicalText and vPrintBR_BiblicalText
 */
int iGenerateRandonIndex(void);

/**
 * Print a random versicle of the Bible
 * in english
 */
void vPrintEN_BiblicalText(int iIndex);

/**
 * Print a random versicle of the Bible
 * in portugues of Brazil
 */
void vPrintBR_BiblicalText(int iIndex);

/**
 * Read the conf file and get the
 * configurations.
 */
void vReadConfFile(void);

/**
 * Check the language and print a biblical text
 * in the language passed in biblical-text.conf
 */
void vPrintBiblicalText(void);

#endif /* _BIBLICAL_TEXTS_H_ */

