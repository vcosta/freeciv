/**********************************************************************
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/
#ifndef FC__CONNECTHAND_H
#define FC__CONNECTHAND_H

#include "shared.h"		/* bool type */

struct connection;
struct conn_list;
struct packet_login_request;
struct packet_authentication_reply;
struct player;
struct user;

bool handle_login_request(struct connection *pconn,
                          struct packet_server_join_req *req);

void unfail_authentication(struct connection *pconn);

void lost_connection_to_client(struct connection *pconn);

void send_conn_info(struct conn_list *src, struct conn_list *dest);
void send_conn_info_remove(struct conn_list *src, struct conn_list *dest);

bool attach_connection_to_player(struct connection *pconn, 
                                 struct player *pplayer);
bool unattach_connection_from_player(struct connection *pconn);
bool handle_authentication_reply(struct connection *pc, char *password);

#endif /* FC__CONNECTHAND_H */
