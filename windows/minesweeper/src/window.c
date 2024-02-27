#include <glib.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include <wintc-comgtk.h>
#include <wintc-shllang.h>

#include "application.h"
#include "window.h"

//
// FORWARD DECLARATIONS
//
static void action_notimpl(
    GSimpleAction* action,
    GVariant*      parameter,
    gpointer       user_data
);

//
// STATIC DATA
//
static GActionEntry s_window_actions[] = {
    {
        .name           = "notimpl",
        .activate       = action_notimpl,
        .parameter_type = NULL,
        .state          = NULL,
        .change_state   = NULL
    }
};

//
// GTK OOP CLASS/INSTANCE DEFINITIONS
//
struct _WinTCMinesWindowClass
{
    GtkApplicationWindowClass __parent__;
};

struct _WinTCMinesWindow
{
    GtkApplicationWindow __parent__;
};

//
// GTK TYPE DEFINITION & CTORS
//
G_DEFINE_TYPE(
    WinTCMinesWindow,
    wintc_mines_window,
    GTK_TYPE_APPLICATION_WINDOW
)

static void wintc_mines_window_class_init(
    WINTC_UNUSED(WinTCMinesWindowClass* klass)
) {}

static void wintc_mines_window_init(
    WinTCMinesWindow* self
)
{
    GtkBuilder* builder;
    GtkWidget*  main_box;

    // Define GActions
    //
    g_action_map_add_action_entries(
        G_ACTION_MAP(self),
        s_window_actions,
        G_N_ELEMENTS(s_window_actions),
        self
    );

    // FIXME: Should restore window size if possible
    //
    gtk_window_set_default_size(
        GTK_WINDOW(self),
        500,
        350
    );

    // Initialize UI
    //
    builder =
        gtk_builder_new_from_resource(
            "/uk/oddmatics/wintc/msmines/msmines.ui"
        );

    wintc_preprocess_builder_widget_text(builder);

    main_box = GTK_WIDGET(gtk_builder_get_object(builder, "main-box"));

    gtk_container_add(GTK_CONTAINER(self), main_box);
}

//
// PUBLIC FUNCTIONS
//
GtkWidget* wintc_mines_window_new(
    WinTCMinesApplication* app
)
{
    return GTK_WIDGET(
        g_object_new(
            TYPE_WINTC_MINES_WINDOW,
            "application", GTK_APPLICATION(app),
            "title",       _("Mines"),
            NULL
        )
    );
}

//
// CALLBACKS
//
static void action_notimpl(
    WINTC_UNUSED(GSimpleAction* action),
    WINTC_UNUSED(GVariant*      parameter),
    WINTC_UNUSED(gpointer       user_data)
)
{
    GError* error = NULL;

    g_set_error(
        &error,
        WINTC_GENERAL_ERROR,
        WINTC_GENERAL_ERROR_NOTIMPL,
        "%s",
        "Action not implemented."
    );

    wintc_nice_error_and_clear(&error);
}
