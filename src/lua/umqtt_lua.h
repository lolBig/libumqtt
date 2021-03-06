/*
 * MIT License
 *
 * Copyright (c) 2019 Petr Stetiar <ynezz@true.cz>
 * Copyright (c) 2019 Jianhui Zhao <jianhuizhao329@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __UMQTT_LUA_H
#define __UMQTT_LUA_H

#include <lauxlib.h>
#include <lualib.h>

#include "umqtt.h"

/* Compatibility defines */
#if LUA_VERSION_NUM <= 501

/* NOTE: this only works if nups == 0! */
#define luaL_setfuncs(L, fns, nups) luaL_register((L), NULL, (fns))

#endif

struct umqtt_client_lua {
    lua_State *L;

    struct umqtt_client cli;
    struct umqtt_connect_opts opts;
    bool connected;

    int on_conack_ref;
    int on_suback_ref;
    int on_unsuback_ref;
    int on_publish_ref;
    int on_pingresp_ref;
    int on_error_ref;
    int on_close_ref;
};

#endif
