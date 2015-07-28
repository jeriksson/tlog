/*
 * Tlog file descriptor message reader.
 *
 * Copyright (C) 2015 Red Hat
 *
 * This file is part of tlog.
 *
 * Tlog is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Tlog is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tlog; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _TLOG_FD_READER_H
#define _TLOG_FD_READER_H

#include <assert.h>
#include "tlog/reader.h"

/**
 * Minimum reader-specific error code value, must be above any
 * enum json_tokener_error value.
 */
#define TLOG_FD_READER_ERROR_MIN    0x10000000

/**
 * File descriptor message reader error codes.
 *
 * These list only reader-specific error codes. Actual codes returned by
 * functions also include negated errno values and enum json_tokener_error
 * values.
 */
enum tlog_fd_reader_error {
    /* Incomplete message object line encountered */
    TLOG_FD_READER_ERROR_INCOMPLETE_LINE    = TLOG_FD_READER_ERROR_MIN,
};

/**
 * File descriptor message reader type
 *
 * Creation arguments:
 *
 * int  fd      File descriptor to read messages from.
 */
extern const struct tlog_reader_type tlog_fd_reader_type;

/**
 * Create a file descriptor reader.
 *
 * @param preader   Location for the created reader pointer, will be set to
 *                  NULL in case of error.
 * @param fd        File descriptor to read messages from.
 *
 * @return Zero on success, negated errno value, or reader-specific code on
 *         failure.
 */
static inline int
tlog_fd_reader_create(struct tlog_reader **preader, int fd)
{
    assert(preader != NULL);
    assert(fd >= 0);
    return tlog_reader_create(preader, &tlog_fd_reader_type, fd);
}

#endif /* _TLOG_FD_READER_H */
