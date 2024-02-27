#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <glib.h>
#include <gtk/gtk.h>

//
// GTK OOP BOILERPLATE
//
typedef struct _WinTCMinesApplicationClass WinTCMinesApplicationClass;
typedef struct _WinTCMinesApplication      WinTCMinesApplication;

#define TYPE_WINTC_MINES_APPLICATION            (wintc_mines_application_get_type())
#define WINTC_MINES_APPLICATION(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), TYPE_WINTC_MINES_APPLICATION, WinTCMinesApplication))
#define WINTC_MINES_APPLICATION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), TYPE_WINTC_MINES_APPLICATION, WinTCMinesApplicationClass))
#define IS_WINTC_MINES_APPLICATION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), TYPE_WINTC_MINES_APPLICATION))
#define IS_WINTC_MINES_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), TYPE_WINTC_MINES_APPLICATION))
#define WINTC_MINES_APPLICATION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), TYPE_WINTC_MINES_APPLICATION, WinTCMinesApplicationClass))

GType wintc_mines_application_get_type(void) G_GNUC_CONST;

//
// PUBLIC FUNCTIONS
//
WinTCMinesApplication* wintc_mines_application_new(void);

#endif
