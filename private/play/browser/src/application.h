#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <glib.h>
#include <gtk/gtk.h>

//
// GTK OOP BOILERPLATE
//
typedef struct _WinTCBrowserApplicationClass WinTCBrowserApplicationClass;
typedef struct _WinTCBrowserApplication      WinTCBrowserApplication;

#define WINTC_TYPE_BROWSER_APPLICATION            (wintc_browser_application_get_type())
#define WINTC_BROWSER_APPLICATION(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WINTC_TYPE_BROWSER_APPLICATION, WinTCBrowserApplication))
#define WINTC_BROWSER_APPLICATION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), WINTC_TYPE_BROWSER_APPLICATION, WinTCBrowserApplicationClass))
#define IS_WINTC_BROWSER_APPLICATION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WINTC_TYPE_BROWSER_APPLICATION))
#define IS_WINTC_BROWSER_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), WINTC_TYPE_BROWSER_APPLICATION))
#define WINTC_BROWSER_APPLICATION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), WINTC_TYPE_BROWSER_APPLICATION, WinTCBrowserApplicationClass))

GType wintc_browser_application_get_type(void) G_GNUC_CONST;

//
// PUBLIC FUNCTIONS
//
WinTCBrowserApplication* wintc_browser_application_new(void);

#endif
