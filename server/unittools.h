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
#ifndef FC__UNITTOOLS_H
#define FC__UNITTOOLS_H

#include "fc_types.h"
#include "packets.h"		/* enum unit_info_use */
#include "unit.h"

#include "gotohand.h"

/* battle related */
int find_a_unit_type(int role, int role_tech);
bool maybe_make_veteran(struct unit *punit);
void unit_versus_unit(struct unit *attacker, struct unit *defender,
		      bool bombard);

/* move check related */
bool is_airunit_refuel_point(struct tile *ptile, struct player *pplayer,
			     Unit_Type_id type, bool unit_is_on_tile);

/* turn update related */
void player_restore_units(struct player *pplayer);
void update_unit_activities(struct player *pplayer);

/* various */
char *get_location_str_in(struct player *pplayer, struct tile *ptile);
char *get_location_str_at(struct player *pplayer, struct tile *ptile);
enum goto_move_restriction get_activity_move_restriction(enum unit_activity activity);
void make_partisans(struct city *pcity);
bool enemies_at(struct unit *punit, struct tile *ptile);
bool teleport_unit_to_city(struct unit *punit, struct city *pcity, int move_cost,
			  bool verbose);
void resolve_unit_stacks(struct player *pplayer, struct player *aplayer,
                         bool verbose);
void remove_allied_visibility(struct player* pplayer, struct player* aplayer);
int get_watchtower_vision(struct unit *punit);
bool unit_profits_of_watchtower(struct unit *punit);
void pay_for_units(struct player *pplayer, struct city *pcity);
void bounce_unit(struct unit *punit, bool verbose);

/* creation/deletion/upgrading */
void upgrade_unit(struct unit *punit, Unit_Type_id to_unit, bool has_to_pay);
struct unit *create_unit(struct player *pplayer, struct tile *ptile, Unit_Type_id type,
			 int veteran_level, int homecity_id, int moves_left);
struct unit *create_unit_full(struct player *pplayer, struct tile *ptile,
			      Unit_Type_id type, int veteran_level,
			      int homecity_id, int moves_left, int hp_left,
			      struct unit *ptrans);
void wipe_unit(struct unit *punit);
void wipe_unit_spec_safe(struct unit *punit, bool wipe_cargo);
void kill_unit(struct unit *pkiller, struct unit *punit);

/* sending to client */
void package_unit(struct unit *punit, struct packet_unit_info *packet);
void package_short_unit(struct unit *punit,
			struct packet_unit_short_info *packet,
			enum unit_info_use packet_use, int info_city_id,
			bool new_serial_num);
void send_unit_info(struct player *dest, struct unit *punit);
void send_unit_info_to_onlookers(struct conn_list *dest, struct unit *punit, 
				 struct tile *ptile, bool remove_unseen);
void send_all_known_units(struct conn_list *dest);
void unit_goes_out_of_sight(struct player *pplayer, struct unit *punit);

/* doing a unit activity */
void do_nuclear_explosion(struct player *pplayer, struct tile *ptile);
bool try_move_unit(struct unit *punit, struct tile *ptile); 
bool do_airline(struct unit *punit, struct city *city2);
bool do_paradrop(struct unit *punit, struct tile *ptile);
void load_unit_onto_transporter(struct unit *punit, struct unit *ptrans);
void unload_unit_from_transporter(struct unit *punit);
bool move_unit(struct unit *punit, struct tile *ptile, int move_cost);
bool execute_orders(struct unit *punit);

#endif  /* FC__UNITTOOLS_H */
