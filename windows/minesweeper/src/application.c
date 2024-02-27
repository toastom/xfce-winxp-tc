#include <glib.h>
#include <gtk/gtk.h>
#include <wintc-comgtk.h>

#include "application.h"
#include "window.h"

//
// GTK OOP CLASS/INSTANCE DEFINITIONS
//
struct _WinTCMinesApplicationClass
{
    GtkApplicationClass __parent__;
};

struct _WinTCMinesApplication
{
    GtkApplication __parent__;
};

//
// FORWARD DECLARATIONS
//
static void wintc_mines_application_activate(
    GApplication* application
);

//
// GTK TYPE DEFINITIONS & CTORS
//
G_DEFINE_TYPE(WinTCMinesApplication, wintc_mines_application, GTK_TYPE_APPLICATION)

static void wintc_mines_application_class_init(
    WinTCMinesApplicationClass* klass
)
{
    GApplicationClass* application_class = G_APPLICATION_CLASS(klass);

    application_class->activate = wintc_mines_application_activate;
}

static void wintc_mines_application_init(
    WINTC_UNUSED(WinTCMinesApplication* self)
) { }

//
// CLASS VIRTUAL METHODS
//
static void wintc_mines_application_activate(
    GApplication* application
)
{
    GtkWidget* new_window =
        wintc_mines_window_new(WINTC_MINES_APPLICATION(application));

    gtk_widget_show_all(new_window);
}

//
// PUBLIC FUNCTIONS
//
WinTCMinesApplication* wintc_mines_application_new(void)
{
    return WINTC_MINES_APPLICATION(
        g_object_new(
            wintc_mines_application_get_type(),
            "application-id", "uk.co.oddmatics.wintc.msmines",
            NULL
        )
    );
}
