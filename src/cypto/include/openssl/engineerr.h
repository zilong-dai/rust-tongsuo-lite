/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2022 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_ENGINEERR_H
# define OPENSSL_ENGINEERR_H
# pragma once

# include <openssl/opensslconf.h>
# include <openssl/symhacks.h>
# include <openssl/cryptoerr_legacy.h>


# ifndef OPENSSL_NO_ENGINE


/*
 * ENGINE reason codes.
 */
#  define ENGINE_R_ALREADY_LOADED                          100
#  define ENGINE_R_ARGUMENT_IS_NOT_A_NUMBER                133
#  define ENGINE_R_CMD_NOT_EXECUTABLE                      134
#  define ENGINE_R_COMMAND_TAKES_INPUT                     135
#  define ENGINE_R_COMMAND_TAKES_NO_INPUT                  136
#  define ENGINE_R_CONFLICTING_ENGINE_ID                   103
#  define ENGINE_R_CTRL_COMMAND_NOT_IMPLEMENTED            119
#  define ENGINE_R_DSO_FAILURE                             104
#  define ENGINE_R_DSO_NOT_FOUND                           132
#  define ENGINE_R_ENGINES_SECTION_ERROR                   148
#  define ENGINE_R_ENGINE_CONFIGURATION_ERROR              102
#  define ENGINE_R_ENGINE_IS_NOT_IN_LIST                   105
#  define ENGINE_R_ENGINE_SECTION_ERROR                    149
#  define ENGINE_R_FAILED_LOADING_PRIVATE_KEY              128
#  define ENGINE_R_FAILED_LOADING_PUBLIC_KEY               129
#  define ENGINE_R_FINISH_FAILED                           106
#  define ENGINE_R_ID_OR_NAME_MISSING                      108
#  define ENGINE_R_INIT_FAILED                             109
#  define ENGINE_R_INTERNAL_LIST_ERROR                     110
#  define ENGINE_R_INVALID_ARGUMENT                        143
#  define ENGINE_R_INVALID_CMD_NAME                        137
#  define ENGINE_R_INVALID_CMD_NUMBER                      138
#  define ENGINE_R_INVALID_INIT_VALUE                      151
#  define ENGINE_R_INVALID_STRING                          150
#  define ENGINE_R_NOT_INITIALISED                         117
#  define ENGINE_R_NOT_LOADED                              112
#  define ENGINE_R_NO_CONTROL_FUNCTION                     120
#  define ENGINE_R_NO_INDEX                                144
#  define ENGINE_R_NO_LOAD_FUNCTION                        125
#  define ENGINE_R_NO_REFERENCE                            130
#  define ENGINE_R_NO_SUCH_ENGINE                          116
#  define ENGINE_R_UNIMPLEMENTED_CIPHER                    146
#  define ENGINE_R_UNIMPLEMENTED_DIGEST                    147
#  define ENGINE_R_UNIMPLEMENTED_ECP_METH                  107
#  define ENGINE_R_UNIMPLEMENTED_PUBLIC_KEY_METHOD         101
#  define ENGINE_R_VERSION_INCOMPATIBILITY                 145

# endif
#endif
