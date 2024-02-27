#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <glib.h>
#include <gtk/gtk.h>

#include "application.h"

//
// GTK OOP BOILERPLATE
//
typedef struct _WinTCMinesWindowClass WinTCMinesWindowClass;
typedef struct _WinTCMinesWindow      WinTCMinesWindow;

#define TYPE_WINTC_MINES_WINDOW            (wintc_mines_window_get_type())
#define WINTC_MINES_WINDOW(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), TYPE_WINTC_MINES_WINDOW, WinTCMinesWindow))
#define WINTC_MINES_WINDOW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), TYPE_WINTC_MINES_WINDOW, WinTCMinesWindowClass))
#define IS_WINTC_MINES_WINDOW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), TYPE_WINTC_MINES_WINDOW))
#define IS_WINTC_MINES_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), TYPE_WINTC_MINES_WINDOW))
#define WINTC_MINES_WINDOW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), TYPE_WINTC_MINES_WINDOW, WinTCMinesWindowClass))

GType wintc_mines_window_get_type(void) G_GNUC_CONST;

//
// PUBLIC FUNCTIONS
//
GtkWidget* wintc_mines_window_new(
    WinTCMinesApplication* app
);

#endif
