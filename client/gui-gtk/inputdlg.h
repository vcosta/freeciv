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
#ifndef FC__INPUTDLG_H
#define FC__INPUTDLG_H

#include <gtk/gtk.h>

GtkWidget *input_dialog_create(GtkWidget * parent, char *dialogname,
			       char *text, char *postinputtest,
			       void (*ok_callback) (const char *, gpointer),
			       gpointer ok_data,
			       void (*cancel_callback) (gpointer),
			       gpointer cancel_data);

#endif  /* FC__INPUTDLG_H */
